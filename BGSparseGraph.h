#pragma once

#include <algorithm>
#include <vector>
#include <list>

#define INVALID_INDEX -1

template <class node_type, class edge_type>
class BGSparseGraph
{
	using EdgeType = edge_type;
	using NodeType = node_type;

	using NodeVector = std::vector<NodeType>;
	using EdgeList = std::list<EdgeType>;
	using EdgeListVector = std::vector<EdgeList>;

	friend class NodeIterator;
	friend class ConstNodeIterator;
	friend class EdgeIterator;
	friend class ConstEdgeIterator;

private:
	/** ������ �߰��ϱ� ���� �̹� �����ϴ��� �˻��Ѵ�.*/
	bool UniqueEdge(int from, int to) const;

	/** ��� �׷����� ������ �˻��� INVALID_INDEX�� ���� ����� ������ �����Ѵ�.*/
	void CulInvalidEdges();

public:
	BGSparseGraph(bool digraph) : m_iNextNodeIndex(0), m_bDigragh(digraph) {}

	/** 0. �׷��� ���� Ȯ��*/
	bool isDigraph() const { return m_bDigragh; }
	bool isEmpty() const { return m_Nodes.empty(); }	
	int NumNodes() const { return m_Nodes.size(); }
	int NumEdges() const
	{ 
		int tot{ 0 };
		for (EdgeList edgeList : m_Edges)
			tot += edgeList.size();

		return tot;
	}
	int NumActiveNodes() const {
		int tot{ 0 };
		for each (NodeType node in m_Nodes)
		{
			if (node.Index() == INVALID_INDEX)
				continue;

			tot++;
		}
	}

	/** 1. �׷����� ���,���� �߰�/���� */
	bool AddNode(NodeType node);
	bool RemoveNode(int node);
	bool AddEdge(EdgeType edge);
	bool RemoveEdge(int from, int to);
	
	/** 2. ���ο� ��带 �߰��ϱ� �� �׷����� ���� ��Ű�� �۾�*/
	void Clear() { m_iNextNodeIndex = 0; m_Nodes.clear(); m_Edges.clear(); }	
	void RemoveEdges() { for (EdgeList& edgeList : m_Edges)	edgeList->clear(); }
	
	/** 3. ������ ��� ���翩�� Ȯ��*/
	bool isNodePresent(int nd) const;
	bool isEdgePresent(int from, int to) const;
	
	/** 4. Getter, Setter */
	const NodeType& GetNode(int idx) const;
	NodeType& GetNode(int idx);
	const EdgeType& GetEdge(int from, int to) const;
	EdgeType& GetEdge(int from, int to);
	void SetEdgeCost(int from, int to, double cost);


private:
	NodeVector m_Nodes;
	EdgeListVector m_Edges;

	bool m_bDigragh;
	int m_iNextNodeIndex;


	/** �ʿ��� Iterator ���� ����*/
public:
	class NodeIterator
	{

	private:
		NodeVector::iterator curNode;

		BGSparseGraph<node_type, edge_type>& G;

		void GetNextValidNode(NodeVector::iterator& it)
		{
			if (curNode == G.m_Nodes.end() || it->Index() != INVALID_INDEX)
				return;

			while (it->Index() == INVALID_INDEX) {
				it++;

				if (curNode == G.m_Nodes.end())
					break;
			}
		}
	
	public:
		NodeIterator(SparseGraph<node_type, edge_type> &graph) : G(graph)
		{
			curNode = G.m_Nodes.begin();
		}

		node_type* begin()
		{
			curNode = G.m_Nodes.begin();

			GetNextValidNode(curNode);

			return &(*curNode);
		}

		node_type* next()
		{
			++curNode;

			if (end())
				return nullptr;

			GetNextValidNode(curNode);

			return &(*curNode);

		}

		bool end()
		{
			return (curNode == G.m_Nodes.end());
		}
	
	};

	class ConstIterator
	{

	};

	class EdgeIterator
	{

	};

	class ConstIterator
	{

	};
};

template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::UniqueEdge(int from, int to) const
{
	for (EdgeList::const_iterator curEdge = m_Edges[from].begin(); curEdge != m_Edges[from].end(); curEdge++) {
		if (curEdge->To() == to)
			return false;
	}

	return to;
}

template<class node_type, class edge_type>
inline void BGSparseGraph<node_type, edge_type>::CulInvalidEdges()
{
	for (EdgeListVector::iterator curEdgeList = m_Edges.begin(); curEdgeList != m_Edges.end(); curEdgeList++) {
		for (EdgeList::iterator curEdge = (*curEdgeList).begin(); curEdge != (*curEdgeList).end(); curEdge++) {

			if (m_Nodes[curEdge->To()].Index == INVALID_INDEX || m_Nodes[curEdge->From()].Index == INVALID_INDEX)
				curEdge = (*curEdgeList).erase(curEdge);
		}

	}
}



/** 1. �׷����� ���,���� �߰�/���� */
template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::AddNode(NodeType node)
{
	if (node.Index() < m_Nodes.size()) {
		m_Nodes[node.Index()] = node;		
	}
	else {
		if (node.Index() != m_iNextNodeIndex) {
			return false;
		}

		m_Nodes.push_back(node);
		m_Edges.push_back(EdgeList());

		m_iNextNodeIndex++;
	}

	return true;
}

template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::RemoveNode(int node)
{
	if (node > m_Nodes.size())
		return false;

	m_Nodes[node].SetIndex(INVALID_INDEX);

	// ������ ���� ����, �ʿ��� �κи� ã�� ���� �� ���� (��� ���������� ã�� �����ؾ� ��)
	if (!m_bDigragh) {
		for (EdgeList::iterator curEdge = m_Edges[node].begin(); curEdge != m_Edges[node].end(); curEdge++) {
			for (EdgeList::iterator curE = m_Edges[curEdge->To()].begin(); curE != m_Edges[curEdge->To()].end(); curE++) {
				if (curE->To() == node) {
					curE = m_Edges[curEdge->To()].erase(curE);
					break;
				}
			}
		}

		m_Edges[node].clear();
	}
	// ������ ���� ���� ��� ������ �˻��ؼ� ������ ��
	else {
		CulInvalidEdges();
	}
}

template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::AddEdge(EdgeType edge)
{
	if (dege.From() == INVALID_INDEX || edge.From() >= m_iNextNodeIndex)
		return false;

	if (edge.To() == INVALID_INDEX || dege.To() >= m_iNextNodeIndex))
		return false;

	if (UniqueEdge(edge.From(), edge.To())) {
		m_Edges[edge.From()].push_back(edge);
	}

	if (m_bDigragh)
		return true;
		
	// ������ ���ٸ�, �ݴ��ʵ� ������� ��
	if (UniqueEdge(edge.To(), edge.From()) {
		EdgeType newEdge = edge;

		newEdge.SetFRom(edge.To());
		newEdge.SetTo(edge.From());

		m_Edges[edge.To()].push_back(newEdge);
	}

	return true;
}

template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::RemoveEdge(int from, int to)
{
	if (m_Nodes.size() <= from && m_Nodes.size() <= to)
		return false;
	
	EdgeList::iterator curEdge;

	if (!m_bDigragh) {
		for (curEdge = m_Edges[to].begin(); curEdge != m_Edges[to].end(); curEdge++) {
			if (curEdge->To() == from) {
				curEdge = m_Edge[to].erase(curEdge);
				break;
			}
		}
	}

	for (curEdge = m_Edges[from].begin(); curEdge != m_Edges[from].end(); curEdge++) {
		if (curEdge->To() == to)
		{
			curEdge = m_Edges[from].erase(curEdge);
			break;
		}
	}

	return true;
}


/** 3. ������ ��� ���翩�� Ȯ��*/
template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::isNodePresent(int nd) const
{
	if (m_Nodes.size() <= nd)
		return false;

	if (m_Nodes[nd].Index() == INVALID_INDEX)
		return false;

	return true;
}

template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::isEdgePresent(int from, int to) const
{
	if (!isNodePresent(from) || !isNodePresent(to))
		return false;

	for (EdgeType edge : m_Edges[from]) {
		if (edge->To() == to)
			return true;
	}

	return false;
}


/** 4. Getter, Setter */
template<class node_type, class edge_type>
inline const NodeType & BGSparseGraph<node_type, edge_type>::GetNode(int idx) const
{
	if (m_Nodes.size() <= idx)
		return nullptr;

	return m_Nodes[idx];
}

template<class node_type, class edge_type>
inline NodeType & BGSparseGraph<node_type, edge_type>::GetNode(int idx)
{
	if (m_Nodes.size() <= idx)
		return nullptr;

	return m_Nodes[idx];
}

template<class node_type, class edge_type>
inline const EdgeType & BGSparseGraph<node_type, edge_type>::GetEdge(int from, int to) const
{
	if (m_Nodes.size() <= from || from == INVALID_INDEX)
		return nullptr;

	if (m_Nodes.size() <= to || to == INVALID_INDEX)
		return nullptr;

	for (Edge& edge : m_Edges[from]) {
		if (edge.To() == to)
			return *edge;
	}

	return nullptr;
}

template<class node_type, class edge_type>
inline EdgeType & BGSparseGraph<node_type, edge_type>::GetEdge(int from, int to)
{
	if (m_Nodes.size() <= from || from == INVALID_INDEX)
		return nullptr;

	if (m_Nodes.size() <= to || to == INVALID_INDEX)
		return nullptr;

	for (Edge& edge : m_Edges[from]) {
		if (edge.To() == to)
			return *edge;
	}

	return nullptr;
}

template<class node_type, class edge_type>
inline void BGSparseGraph<node_type, edge_type>::SetEdgeCost(int from, int to, double cost)
{
	if (m_Nodes.size() <= from || m_Nodes.size() <= to)
		return;

	for (EdgeType& edge : m_Edges[from]) {
		if (edge.To() == to) {
			edge.SetCost(cost);
			break;
		}
	}
}


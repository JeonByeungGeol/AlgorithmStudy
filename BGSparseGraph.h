#pragma once

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


public:
	BGSparseGraph(bool digraph) : m_iNextNodeIndex(0), m_bDigragh(digraph) {}

	/** 1. 그래프에 노드/엣지 추가/삭제 */
	bool AddNode(NodeType node);

	bool RemoveNode(int node);

	bool AddEdge(EdgeType edge);

	bool RemoveEdge(int from, int to);





private:
	NodeVector m_Nodes;
	EdgeListVector m_Edges;

	bool m_bDigragh;
	int m_iNextNodeIndex;
};


/** 1. 그래프에 노드/엣지 추가/삭제 */
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
}

template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::AddEdge(EdgeType edge)
{
	if (dege.From() == INVALID_INDEX || edge.From() >= m_iNextNodeIndex)
		return false;

	if (edge.To() == INVALID_INDEX || dege.To() >= m_iNextNodeIndex))
		return false;


	return true;
}

template<class node_type, class edge_type>
inline bool BGSparseGraph<node_type, edge_type>::RemoveEdge(int from, int to)
{
}

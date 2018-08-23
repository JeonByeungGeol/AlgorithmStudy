#pragma once

#include <vector>

class Heuristic_Eclid
{

};
class Heuristic_Simple
{

};

template <class graph_type, class heuristic>
class BGAStartAlgorithm
{
	using Edge = graph_type::EdgeType;

public:
	BGAStartAlgorithm(graph_type& graph, int source, int target)
		: m_Graph(graph), m_ShortestPathTree(graph.NumNodes()), m_SearchFrontier(graph.NumNodes()),
		m_GCosts(graph.NumNodes(), 0.0), m_HCosts(graph.NumNodes(), 0.0)
		,m_iSource(source), m_iTarget(target)
	{
		Search();
	}

	/** AStar Algorithm*/
	void Search();



private:
	const graph_type& m_Graph;
	
	std::vector<double> m_GCosts;
	std::vector<double> m_HCosts;

	std::vector<const Edge*> m_ShortestPathTree;
	std::vector<const Edge*> m_SearchFrontier;

	int m_iSource;
	int m_iTarget;
};



template<class graph_type, class heuristic>
inline void BGAStartAlgorithm<graph_type, heuristic>::Search()
{

}

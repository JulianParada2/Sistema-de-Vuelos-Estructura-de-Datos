#ifndef __GRAPH__H__
#define __GRAPH__H__

#include <vector>
#include <list>
#include <map>


	template < class V, class C>
	class Graph
	{
		public:
			typedef V TValue;
			typedef C TCost;
			typedef Graph Self;
			typedef std::vector < TValue > Vertices;
			typedef std::map< long, std::map< long, TCost > > Costs;

		public:
			Graph();
			virtual ~Graph();

			long AddNode(TValue value);
			void AddArc (long a, long b, TCost costo);
			bool HasArc(long a, long b);
			TValue GetNode(long a);
			std::vector< long > GetDijkstra( long seed );
			std::vector < long > GetShortestPath ( long a, long b);
			std::vector < TValue > GetShortestPath ( TValue a, TValue b, bool n);
			std::list < TValue > PrintLevels( long seed );

			long GetVerticesSize();

			void PrintAsPNG( std::string file );

			std::vector < TValue > getVertices();
			long getIndexof(TValue a);

 
		private:
			Vertices m_Vertices;
			Costs m_Matrix;
	};



	template < class C >
	struct Triple
	{
		long father;
		long son;
		C cost;
	};

	template < class C >
	struct comparador
	{
    	bool operator()(const Triple<C>& a,const Triple<C>& b) const
   		{
        	return a.cost > b.cost;
    	}
    };


#include "Graph.hxx"

#endif

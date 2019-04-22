#pragma once


#include <vector>
#include <string>
#include <algorithm>
#include <memory>


using std::vector;
using std::pair;
using std::string;
using std::shared_ptr;
using std::make_shared;


namespace algorithms_on_graphs
{
	class Vertex
	{
		vector<int> adjacent_vertices;

	public:
		Vertex(vector<int> vertices);
		~Vertex();

		vector<int> adjacent();
	};


	class Graph;


	class Graph_iterator
	{
		unsigned index;
		Graph &graph;

	public:
		Graph_iterator(Graph &graph, unsigned index);
		
		Graph_iterator &operator ++();
	};

	   
	class Graph
	{
		bool direct;

		vector<Vertex> vertices;

	public:
		Graph();
		Graph(vector<vector<int> > vertices);
		Graph(vector<vector<int> > vertices, bool direct);
		
		~Graph();


		auto begin();
		auto end();


		bool is_direct();
		int get_size();
		Vertex at(int index);
	};
}
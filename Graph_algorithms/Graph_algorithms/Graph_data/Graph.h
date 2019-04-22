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
		
		unsigned get_index();

		Graph_iterator &operator ++();
		vector<int> operator *();

		bool operator != (Graph_iterator &right);
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


		Graph_iterator begin();
		Graph_iterator end();


		bool is_direct();
		int get_size();
		Vertex at(int index);
	};
}
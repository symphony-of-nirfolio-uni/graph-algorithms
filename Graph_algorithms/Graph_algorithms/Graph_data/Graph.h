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
		int vertex;
		vector<int> adjacent_vertices;

	public:
		Vertex(vector<int> vertices);
		Vertex(vector<int> vertices, int vertex);
		~Vertex();

		vector<int>::iterator begin();
		vector<int>::iterator end();

		int id();
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
		Vertex operator *();

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
		unsigned size();
		Vertex at(int index);
		Vertex at(unsigned index);
	};
}
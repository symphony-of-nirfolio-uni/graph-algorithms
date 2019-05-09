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

		vector<int> used_mark,
			black_mark;

		int highlight;

	public:
		Graph();
		Graph(vector<vector<int> > vertices);
		Graph(vector<vector<int> > vertices, bool direct);
		
		~Graph();


		Graph_iterator begin();
		Graph_iterator end();


		bool is_direct();
		int get_size();
		unsigned size();
		Vertex at(int index);
		Vertex at(unsigned index);

		void set_used_mark(vector<int> verteces);
		void add_used_mark(int vertex);
		vector<int> get_used_mark();

		void set_black_mark(vector<int> verteces);
		void add_black_mark(int vertex);
		vector<int> get_black_mark();

		void set_highlight(int vertex);
		int get_highlight();
	};
}

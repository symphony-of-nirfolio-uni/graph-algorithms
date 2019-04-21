#pragma once


#include <vector>
#include <string>
#include <algorithm>


using std::vector;
using std::pair;
using std::string;


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


	class Graph
	{
		bool direct;

		vector<Vertex> vertices;

	public:
		Graph();
		Graph(vector<vector<int> > vertices);
		Graph(vector<vector<int> > vertices, bool direct);
		
		~Graph();


		bool is_direct();
		int get_size();
		Vertex at(int index);
	};
}
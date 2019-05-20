#include "Graph.h"


namespace algorithms_on_graphs
{
	Vertex::Vertex(vector<int> vertices) : adjacent_vertices(vertices)
	{

	}

	Vertex::Vertex(vector<int> vertices, int vertex) : adjacent_vertices(vertices), vertex(vertex)
	{

	}


	Vertex::~Vertex()
	{
		adjacent_vertices.clear();
	}

	vector<int>::iterator Vertex::begin()
	{
		return adjacent_vertices.begin();
	}
	vector<int>::iterator Vertex::end()
	{
		return adjacent_vertices.end();
	}


	int Vertex::id()
	{
		return vertex;
	}

	vector<int> Vertex::adjacent()
	{
		return adjacent_vertices;
	}


	Graph_iterator::Graph_iterator(Graph &graph, unsigned index) : graph(graph), index(index)
	{

	}

	unsigned Graph_iterator::get_index()
	{
		return index;
	}


	Graph_iterator &Graph_iterator::operator ++()
	{
		++index;
		return *this;
	}

	Vertex Graph_iterator::operator *()
	{
		return graph.at(index);
	}


	bool Graph_iterator::operator != (Graph_iterator &right)
	{
		return index != right.get_index();
	}


	Graph::Graph() : highlight(-1)
	{

	}

	Graph::Graph(vector<vector<int> > vertices) : Graph()
	{
		this->vertices.clear();
        for (size_t i = 0; i < vertices.size(); ++i)
		{
			this->vertices.push_back(Vertex(vertices[i], int(i)));
		}
	}

	Graph::Graph(vector<vector<int> > vertices, bool direct) : Graph(vertices)
	{
		this->direct = direct;
	}

	
	Graph::~Graph()
	{
		vertices.clear();
	}


	Graph_iterator Graph::begin()
	{
		return Graph_iterator(*this, 0);
	}

	Graph_iterator Graph::end()
	{
		return Graph_iterator(*this, size() - 1);
	}


	bool Graph::is_direct()
	{
		return direct;
	}

	unsigned Graph::size()
	{
		return unsigned(vertices.size());
	}

	Vertex Graph::at(int index)
	{
		return at(unsigned(index));
	}

	Vertex Graph::at(unsigned index)
	{
		index = std::max(index, unsigned(0));
		index = std::min(index, size() - 1);

		return vertices[index];
	}

	void Graph::set_used_mark(vector<int> verteces)
	{
		used_mark = verteces;
	}

	void Graph::add_used_mark(int vertex)
	{
		used_mark.push_back(vertex);
	}

	vector<int> Graph::get_used_mark()
	{
		return used_mark;
	}


	void Graph::set_black_mark(vector<int> verteces)
	{
		black_mark = verteces;
	}

	void Graph::add_black_mark(int vertex)
	{
		black_mark.push_back(vertex);
	}

	vector<int> Graph::get_black_mark()
	{
		return black_mark;
	}


	void Graph::set_highlight(int vertex)
	{
		highlight = vertex;
	}

	int Graph::get_highlight()
	{
		return highlight;
	}
}

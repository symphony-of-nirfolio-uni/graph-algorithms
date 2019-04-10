#pragma once


#include "Read_graph_builder.h"
#include <string>
#include <fstream>


using std::string;
using std::ifstream;
using std::atoi;


namespace algorithms_on_graphs
{
	class Read_graph
	{
		bool weight;
		bool direct;

		string get_file_name();
		string get_file_name(string prefix);

		Graph build_graph(string prefix);

	public:
		Read_graph(shared_ptr<Read_graph_builder> builder);

		~Read_graph();

		Graph get_graph();
		Graph get_graph(string prefix);

		bool get_weight();
		bool get_direct();
	};

}
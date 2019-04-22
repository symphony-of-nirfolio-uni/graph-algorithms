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
		bool direct;

		string get_file_name();
		string get_file_name(string prefix);

		Graph build_graph(string prefix);

	public:
		Read_graph(shared_ptr<Read_graph_builder> builder);

		~Read_graph();

		Graph get_graph();
		Graph get_graph(string prefix);

		static Graph get_graph_from_file(string file_name, bool direct = false);

		bool get_direct();
	};

}
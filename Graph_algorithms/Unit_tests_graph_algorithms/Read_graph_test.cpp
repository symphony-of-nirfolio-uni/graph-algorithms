#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Graph_algorithms/Graph_data/Read_graph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace algorithms_on_graphs;

namespace Unit_tests_graph_alorithms
{
	TEST_CLASS(Read_graph_test)
	{
	public:

		TEST_METHOD(builder_work)
		{
			{
				Read_graph read_graph = make_shared<Read_graph_builder>()->build();

				Assert::IsFalse(read_graph.get_direct());
			}

			{
				Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->build();

				Assert::IsTrue(read_graph.get_direct());
			}
		}

		TEST_METHOD(read_graph)
		{
			Read_graph read_graph = make_shared<Read_graph_builder>()->build();
			Graph graph = read_graph.get_graph("../Graph_algorithms/Graph_data/Data/");

			Assert::IsTrue(graph.size() > 0);
		}
	};
}
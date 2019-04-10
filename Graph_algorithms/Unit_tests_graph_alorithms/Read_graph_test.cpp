#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Graph_algorithms/Read_graph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace algorithms_on_graphs;

namespace Unit_tests_graph_alorithms
{
	TEST_CLASS(Read_graph_test)
	{
	public:

		TEST_METHOD(Builder_work)
		{
			{
				Read_graph read_graph = make_shared<Read_graph_builder>()->build();

				Assert::IsFalse(read_graph.get_Weight());
				Assert::IsFalse(read_graph.get_Direct());
			}

			{
				Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->build();

				Assert::IsFalse(read_graph.get_Weight());
				Assert::IsTrue(read_graph.get_Direct());
			}

			{
				Read_graph read_graph = make_shared<Read_graph_builder>()->add_weight()->build();

				Assert::IsTrue(read_graph.get_Weight());
				Assert::IsFalse(read_graph.get_Direct());
			}

			{
				Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->add_weight()->build();

				Assert::IsTrue(read_graph.get_Weight());
				Assert::IsTrue(read_graph.get_Direct());
			}
		}

	};
}
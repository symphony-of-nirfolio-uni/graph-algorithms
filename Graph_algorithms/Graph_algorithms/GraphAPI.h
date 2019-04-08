#pragma once
#include <memory>

using std::unique_ptr;

class GraphAPI // singleton
{
private:
	static unique_ptr<GraphAPI> instance;
public:
	void used_vertex(int v);
	bool can_move_on();
	GraphAPI();
	~GraphAPI();
};


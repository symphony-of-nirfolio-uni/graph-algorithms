#pragma once
#include <memory>

using std::unique_ptr;

class GraphAPI // singleton
{
private:
public:
	static GraphAPI instance;
	void used_vertex(int v);
	bool can_move_on();
	GraphAPI();
	~GraphAPI();
};


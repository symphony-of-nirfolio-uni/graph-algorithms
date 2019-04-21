#pragma once
#include "GraphAPI.h"

void create_api()
{
	GraphAPI api;
	GraphAPI::instance = api;
}

GraphAPI GraphAPI::instance = GraphAPI();

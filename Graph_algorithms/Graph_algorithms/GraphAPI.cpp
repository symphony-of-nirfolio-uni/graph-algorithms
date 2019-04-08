#include "GraphAPI.h"



GraphAPI::GraphAPI()
{
	if (instance == unique_ptr<GraphAPI>(nullptr))
	{
		//creating
	}
	else
	{
		delete this; // forbidden to have more than one instance
	}
}


GraphAPI::~GraphAPI()
{

}

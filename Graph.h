#pragma once


struct gnode
{
	int data;
	bool visited = false;
	vector<gnode*> neighbours;
};

class Graph
{

public:
	void BuildAdjancyMatrix()
	{

	}

	void BuildAdjancyList()
	{

	}

	void BuildNeighbours()
	{

	}

	void BFS(gnode* start, gnode* end)
	{
		queue<gnode*> tn;
		start->visited = true;
		tn.push(start);
		while (tn.front() != end)
		{
			for (auto& n : tn.front()->neighbours)
			{
				if (!n->visited)
				{
					n->visited = true;
					tn.push(n);
				}
			}
			tn.pop();
		}

	}


};

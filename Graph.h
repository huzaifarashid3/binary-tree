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
		tn.push(start);
		gnode* temp = tn.front();
		while (temp != end)
		{
			temp = tn.front();
			tn.pop();
			temp->visited = true;
			for (auto& n : temp->neighbours)
			{
				if (!n->visited)
				{
					tn.push(n);
				}
			}
			
		}

	}


};

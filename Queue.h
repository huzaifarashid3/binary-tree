#pragma once

#if 0

class Queue
{
	int capacity;
	int front;
	int rear;
	int size;
	Heap* h;



public:
	Queue(int c) : rear(-1), front(0), capacity(c), h(new Heap(c)), size(0) {}


	void Enqeue(int data)
	{
		if (Full())
		{
			cout << "bleh" << endl;
			return;
		}
		size++;
		rear = (rear + 1) % capacity;
		h->Insert(data);
	}

	void Deqeue()
	{
		if (Empty())
		{
			cout << "bleh" << endl;
			return;
		}
		size--;
		front = (front + 1) % capacity;
		h->Extract();
	}

	int Peek()
	{
		return h->Peek();
	}

	bool Empty()
	{
		return size == 0;
	}

	bool Full()
	{
		return size == capacity;
	}

};

#endif
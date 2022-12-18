#pragma once

template<typename T>
class Heap
{
	int capacity;
	int size;
	T* arr;
public:
	Heap(int capacity = 10): size(0), capacity(capacity), arr(new T[capacity]) {}
	T Insert(T data)
	{	
			arr[size] = data;
			size++;
			HeapifyUp();
			return data;

	}

	T Extract()
	{
		T temp = arr[0];

		arr[0] = arr[size - 1];
		size--;

		HeapifyDown();



		return temp;
	}

	void HeapifyDown()
	{
		int me = 0;
		int l = 2 * me + 1;
		int r = 2 * me + 2;

		while (l < size)
		{
			int t = l;
			if (r < size && arr[r]->frequency < arr[l]->frequency)
				t = r;

			if (arr[me]->frequency < arr[t]->frequency)
				break;
			else
				swap(arr[me], arr[t]);


			me = t;

			l = 2 * me + 1;
			r = 2 * me + 2;
		}	
	}

	void HeapifyUp()
	{
		int me = size - 1;
		while ((me - 2) / 2 >= 0 && arr[me]->frequency < arr[(me - 2) / 2]->frequency)
		{
			swap(arr[me], arr[(me - 2) / 2]);
			me = (me - 2) / 2;
		}	
	}

	T Peek()
	{
		return arr[0];
	}

	~Heap()
	{
		delete[] arr;
	}
};
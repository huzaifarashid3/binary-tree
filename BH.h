#pragma once

class BinaryHeap
{
	int capacity;
	int size;
	int* arr;
public:
	BinaryHeap(int capacity): capacity(capacity), size(0), arr(new int[capacity]) {}
	
	int LeftChildI(int i) {	return 2 * i + 1; }
	
	int RightChildI(int i) { return 2 * i + 2; }

	int ParentI(int i) { return (i - 2) / 2; }

	int LeftChild(int i) { return arr[LeftChildI(i)]; }

	int RightChild(int i) { return arr[RightChildI(i)]; }

	int Parent(int i) { return arr[ParentI(i)]; }

	bool HasParent(int i)
	{ 
		if (ParentI(i) >= 0) return true;
		return false;
	}

	bool HasLeftChild(int i) 
	{ 
		if (LeftChildI(i) < size) 
			return true;
		return false;
	}

	bool HasRightChild(int i)
	{
		if (RightChildI(i) < size)
			return true;
		return false;
	}

	void Insert(int data)
	{
		EnsureCapacity();
		arr[size] = data;
		size++;
		HeapifyUp();
	}
	
	void HeapifyUp()
	{
		int i = size - 1;
		while (HasParent(i) && Parent(i) > arr[i])
		{
			swap(arr[ParentI(i)], arr[i]);
			i = ParentI(i);
		}
	}

	void HeapifyDown()
	{
		int i = 0;
		while (HasLeftChild(i))
		{
			int child = LeftChildI(i);
			if (HasRightChild(i))
				if (RightChild(i) < LeftChild(i))
					child = RightChildI(i);
			if (arr[i] > arr[child])
				swap(arr[child], i);
			i = child;
		}

	}

	void EnsureCapacity()
	{
		if (size == capacity)
		{
			int* temp = new int[2 * capacity];
			for (int i = 0; i < size; i++)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
			capacity *= 2;
		}
	}

	int peek()
	{
		if (size == 0)
		{
			cout << "empty" << endl;
			return -1;
		}
		return arr[0];
	}
	
	int Extract()
	{
		if (size == 0)
		{
			cout << "empty" << endl;
			return -1;
		}
		int data = peek();
		arr[0] = arr[size-1];
		size--;
		HeapifyDown();
		return data;
	}
	
	~BinaryHeap()
	{
		delete[] arr;
	}

};

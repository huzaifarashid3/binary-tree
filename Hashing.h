#pragma once


class HashTable
{
	int* table;
	int size;
public:
	HashTable(int size) : size(size), table(new int[size])
	{
		for (int i = 0; i < size; i++)
		{
			table[i] = -1;
		}
	}
	int Hash(int data)
	{
		return data % size;
	}

	void Insert(int data)
	{

		if (table[Hash(data)] == -1)
		{
			table[Hash(data)] = data;
		}
		else
		{
			int j = 1;
			while (table[Hash(Hash(data) + j * j)] != -1)
			{
				j++;
				if (j == size)
				{
					cout << "table is full" << endl;
					return;
				}
			}
			table[Hash(Hash(data) + j * j)] = data;
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << table[i] << " ";
		}
		cout << endl;

	}



	~HashTable()
	{
		delete[] table;
	}
};
#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _MyList;

public:
	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		_MyList.DeleteFirstItem();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.OriginalArray[0];
	}

	T back()
	{
		return _MyList.OriginalArray[_MyList.Size() - 1];
	}

	void Print()
	{
		_MyList.PrintList();
	}

	//Extension #1
	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	//Extension #2
	void Reverse()
	{
		_MyList.Reverse();
	}

	//Extension #3
	bool UpdateItem(int Index, T value)
	{
		return _MyList.SetItem(Index, value);
	}

	//Extension #4
	bool InsertAfter(int Index, T value)
	{
		return _MyList.InsertAfter(Index, value);
	}

	//Extension #5
	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);
	}

	//Extension #6
	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	//Extension #7
	void Clear()
	{
		_MyList.Clear();
	}
};


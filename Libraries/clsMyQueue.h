#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue 
{
protected:
	clsDblLinkedList<T> _list;

public:
	void push(T value)
	{
		_list.InsertAtEnd(value);
	}

	void pop()
	{
		_list.DeleteFirstNode();
	}

	T front()
	{
		return _list.head->value;
	}

	T back()
	{
		return _list.tail->value;
	}

	int Size()
	{
		return _list.Size();
	}

	bool IsEmpty()
	{
		return (Size() == 0);
	}

	void Print()
	{
		_list.PrintList();
	}

	//Extension #1
	T GetItem(int Index)
	{
		return _list.GetItem(Index);
	}

	//Extension #2
	void Reverse()
	{
		_list.Reverse();
	}

	//Extension #3
	bool UpdateItem(int Index, T value)
	{
		return _list.UpdateItem(Index, value);
	}

	//Extension #4
	bool InsertAfter(int Index, T value)
	{
		return _list.InsertAfter(Index, value);
	}

	//Extension #5
	void InsertAtFront(T value)
	{
		_list.InsertAtBeginning(value);
	}

	//Extension #6
	void InsertAtBack(T value)
	{
		_list.InsertAtEnd(value);
	}

	//Extension #7
	void Clear()
	{
		_list.Clear();
	}
};


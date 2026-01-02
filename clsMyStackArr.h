#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyStackArr : public clsDynamicArray<T>
{
protected:
public:
	void push(T value)
	{
		clsDynamicArray<T>::InsertAtBeginning(value);
	}

	void pop()
	{
		clsDynamicArray<T>::DeleteFirstItem();
	}

	T Top()
	{
		return clsDynamicArray<T>::OriginalArray[0];
	}

	T Bottom()
	{
		return clsDynamicArray<T>::OriginalArray[Size() - 1];
	}

	int Size()
	{
		return clsDynamicArray<T>::Size();
	}

	bool IsEmpty()
	{
		return (Size() == 0);
	}

	void Print()
	{
		clsDynamicArray<T>::PrintList();
	}

	//Extension #1
	T GetItem(int Index)
	{
		return clsDynamicArray<T>::GetItem(Index);
	}

	//Extension #2
	void Reverse()
	{
		clsDynamicArray<T>::Reverse();
	}

	//Extension #3
	bool UpdateItem(int Index, T value)
	{
		return clsDynamicArray<T>::SetItem(Index, value);
	}

	//Extension #4
	bool InsertAfter(int Index, T value)
	{
		return clsDynamicArray<T>::InsertAfter(Index, value);
	}

	//Extension #5
	void InsertAtTop(T value)
	{
		clsDynamicArray<T>::InsertAtBeginning(value);
	}

	//Extension #6
	void InsertAtBottom(T value)
	{
		clsDynamicArray<T>::InsertAtEnd(value);
	}

	//Extension #7
	void Clear()
	{
		clsDynamicArray<T>::Clear();
	}

};


#pragma once
#include <iostream>
#include "clsMyQueue.h"
using namespace std;

template <class T>
class clsMyStack : public clsMyQueue<T>
{
public:
	void push(T value)
	{
		clsMyQueue<T>::_list.InsertAtBeginning(value);
	}

	T Top()
	{
		return clsMyQueue<T>::front();
	}

	T Bottom()
	{
		return clsMyQueue<T>::back();
	}

	//Extension #5
	void InsertAtTop(T value)
	{
		clsMyQueue<T>::InsertAtFront(value);
	}

	//Extension #6
	void InsertAtBottom(T value)
	{
		clsMyQueue<T>::InsertAtBack(value);
	}

};


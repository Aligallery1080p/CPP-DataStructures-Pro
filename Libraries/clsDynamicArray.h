#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
private:
	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[Size];
	}

	~clsDynamicArray()
	{
		delete[]OriginalArray;
	}

	bool SetItem(int Index, T value)
	{
		if (Index < 0 || Index >= _Size)
			return false;

		OriginalArray[Index] = value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}

		cout << "\n";
	}

	//Extension #1
	void ReSize(int NewSize = 0)
	{
		if (NewSize == _Size) return;

		_TempArray = new T[NewSize];

		int ElementsToCopy = (NewSize < _Size) ? NewSize : _Size;

		for (int i = 0; i < ElementsToCopy; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		_Size = NewSize;
	}

	//Extension #2
	T GetItem(int Index)
	{
		if (Index < 0 || Index >= _Size) return T{};

		return OriginalArray[Index];
	}

	//Extension #3
	void Reverse()
	{
		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	//Extension #4
	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	//Extension #5
	bool DeleteItemAt(int Index)
	{
		if (Index < 0 || Index >= _Size) return false;

		_TempArray = new T[_Size - 1];

		int Counter = 0;
		for (int i = 0; i < _Size; i++)
		{
			if (Index != i)
			{ 
				_TempArray[Counter] = OriginalArray[i];
				Counter++;
			}
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		
		_Size--;
		return true;
	}

	//Extension #6
	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	//Extension #7
	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	//Extension #8
	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
		}

		return -1;
	}

	//Extension #9
	bool DeleteItem(T value)
	{
		int Index = Find(value);

		if (Index == -1)
			return false;

		return DeleteItemAt(Index);
	}

	//Extension #10
	bool InsertAt(int Index, T value)
	{
		if (Index < 0 || Index > _Size) return false;

		_Size++;

		_TempArray = new T[_Size];

		for (int i = 0, j = 0; i < _Size; i++)
		{
			if (Index != i)
			{
				_TempArray[i] = OriginalArray[j];
				j++;
			}
			else
				_TempArray[i] = value;
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	//Extension #11
	bool InsertAtBeginning(T value)
	{
		return InsertAt(0, value);
	}

	//Extension #12
	bool InsertBefore(int Index, T value)
	{
		if (Index < 1)
			return InsertAt(0, value);
		else
			return InsertAt(Index - 1, value);
	}

	//Extension #13
	bool InsertAfter(int Index, T value)
	{
		if (Index >= _Size)
			return InsertAt(_Size, value);
		else
			return InsertAt(Index + 1, value);
	}

	//Extension #14
	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size, value);
	}

};

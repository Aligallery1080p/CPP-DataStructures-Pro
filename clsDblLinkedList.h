#pragma once
#include <iostream>
//#include "clsNode.h"
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;

public:
	class Node
	{
	public:
		T value;
		Node* prev;
		Node* next;

		Node(T data)
		{
			value = data;
			prev = nullptr;
			next = nullptr;
		}
		
	};

	Node* head = nullptr;
	Node* tail = nullptr;

	void InsertAtBeginning(T value)
	{
		Node* new_node = new Node(value);
		_Size++;

		if (head == nullptr)
		{ 
			head = new_node;
			tail = new_node;
			return;
		}

		new_node->next = head;
		head->prev = new_node;

		head = new_node;
	}

	void InsertAfter(Node* prev_node, T value)
	{
		if (head == nullptr || prev_node == nullptr) return;

		Node* new_node = new Node(value);

		new_node->next = prev_node->next;
		new_node->prev = prev_node;

		if (new_node->next != nullptr)
			new_node->next->prev = new_node;
		else
			tail = new_node;

		prev_node->next = new_node;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* new_node = new Node(value);
		_Size++;

		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
			return;
		}

		new_node->prev = tail;
		tail->next = new_node;

		tail = new_node;
	}

	void DeleteNode(Node* NodeToDelete)
	{
		if (head == nullptr || NodeToDelete == nullptr) return;

		if (head == NodeToDelete)
			head = NodeToDelete->next;

		if (tail == NodeToDelete)
			tail = NodeToDelete->prev;

		if (NodeToDelete->next != nullptr)
			NodeToDelete->next->prev = NodeToDelete->prev;

		if (NodeToDelete->prev != nullptr)
			NodeToDelete->prev->next = NodeToDelete->next;

		delete NodeToDelete;
		_Size--;
	}
		
	void DeleteFirstNode()
	{
		if (head == nullptr) return;

		Node* current = head;
		head = head->next;
		
		if (head != nullptr)
			head->prev = nullptr;
		else
			tail = nullptr;
		
		delete current;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == nullptr) return;

		Node* current = tail;
		tail = tail->prev;

		if (tail != nullptr)
			tail->next = nullptr;
		else
			head = nullptr;

		delete current;
		_Size--;
	}

	Node* Find(T value)
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->value == value)
				return current;

			current = current->next;
		}

		return nullptr;
	}

	void PrintList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << "\n";
	}

	//Extension #1
	int Size()
	{
		return _Size;
	}

	//Extension #2
	bool IsEmpty()
	{
		return (_Size == 0);
	}

	//Extension #3
	void Clear()
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* temp = current->next;
			delete current;
			current = temp;
		}

		head = nullptr;
		tail = nullptr;
		_Size = 0;
	}

	//Extension #4
	void Reverse()
	{
		if (head == nullptr || head->next == nullptr)
			return;
	
		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr)
		{ 
			temp = head;
			head = tail;
			tail = temp;
		}
	}

	//Extension #5
	Node* GetNode(int Index)
	{
		if (Index < 0 || Index >= _Size) return nullptr;

		int Counter = 0;
		Node* current = head;
		while (current != nullptr)
		{
			if (Counter == Index)
				return current;

			current = current->next;
			Counter++;
		}

		return nullptr;
	}

	//Extension #6
	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != nullptr)
			return ItemNode->value;
		else
			return T{};
	}

	//Extension #7
	bool UpdateItem(int Index, T value)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != nullptr)
		{
			ItemNode->value = value;
			return true;
		}
		
		return false;
	}

	//Extension #8
	bool InsertAfter(int Index, T value)
	{
		Node* ItemNode = GetNode(Index);
		
		if (ItemNode != nullptr)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
			
		return false;
	}
};
#include<iostream>
#include "List.h"
using namespace std;

void List::reset_list()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

List::List()
{
	reset_list();
}

List::~List()
{
	if (head)
	{
		while (head->next)
		{
			head = head->next;
			delete head->prev;
		}
		reset_list();
	}
}

void List::push_back(int x)
{
	Node* temp = new Node(x);
	temp->next = NULL;
	if (size == 0)
	{
		temp->prev = NULL;
		head = tail = temp;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	size++;
}

void List::push_front(int x)
{
	Node* temp = new Node(x);
	temp->next = NULL;
	if (size == 0)
	{
		temp->prev = NULL;
		head = tail = temp;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	size++;
}


void List::pop_back()
{
	if (size == 0)
	{
		throw out_of_range("Nothing to delete");
	}
	if (size == 1)
	{
		delete head;
		reset_list();
	}
	else
	{
		Node* temp = tail->prev;
		temp->next = NULL;
		delete tail;
		tail = temp;
		size--;
	}
}

void List::pop_front()
{
	if (size == 0)
	{
		throw out_of_range("Nothing to delete");
	}
	if (size == 1)
	{
		delete head;
		reset_list();
	}
	else
	{
		head = head->next;
		delete head->prev;;
		size--;
	}
}

void List::insert(int x, size_t index)
{
	if (index < 0)
		throw out_of_range("Index is less then 0");
	if (index > size - 1)
		throw out_of_range("Index is greater then list size");
	if (index == 0)
		push_front(x);
	else
	{
		Node* add = new Node(x);
		Node* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		} // tmp - before adding
		add->prev = temp;
		add->next = temp->next;
		temp->next = add;
		size++;
	}
}

int List::at(size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) {
		throw out_of_range("Index is less than zero");
	}
	Node* temp = head;
	size_t tempindex = 0;
	while (tempindex != index)
	{
		temp = temp->next;
		tempindex++;
	}
	return temp->x;
}

void List::remove(size_t index)
{
	Node* temp = head;
	if (index > size - 1) 
	{
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) 
	{
		throw out_of_range("Index is less than zero");
	}
	if (index == 0)
	{ // delete head
		pop_front();
	}
	else if (index == size - 1)
	{ // delete tail
		pop_back();
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		} // tmp should be deleted
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		size--;
	}
}

size_t List::get_size()
{
	return size;
}

void List::print_to_console()
{
	system("CLS");
	cout << "Size = " << size << endl;
	if (size != 0)
	{
		Node* temp = head;
		do
		{
			cout << temp->x << endl;
			temp = temp->next;
		} while (temp->next);
		cout << temp->x << endl;
	}
	else
		cout << "There is nothing to print" << endl;
	system("pause");
}

void List::clear()
{
	if (head)
	{
		while (head->next)
		{
			head = head->next;
			delete head->prev;
		}
		reset_list();
	}
}

void List::set(size_t index, int NewElem)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) {
		throw out_of_range("Index is less than zero");
	}
	else
	{
		Node* temp = head;
		while (index > 0)
		{
			temp = temp->next;
			index--;
		}
		temp->x = NewElem;
	}
}

bool List::isEmpty()
{
	return (size == 0);
}

bool List::contains(List newList)
{
	new_size = size + newList.get_size();
	if (size == new_size)
		return true;
	else
		return false;
}
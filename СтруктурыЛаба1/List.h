#pragma once

class List
{
private:
	void reset_list();

	class Node
	{
	public:
		Node(int data, Node* next = nullptr, Node* prev = nullptr) {
			this->x = data;
			this->next = next;
			this->prev = prev;
		};
		~Node() {};

		int x;
		Node* prev, * next;
	};

	Node* head, * tail;
	size_t size, new_size;

public:

	List();
	~List();

	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void insert(int, size_t);
	int at(size_t);
	void remove(size_t);
	size_t get_size();
	void print_to_console();
	void clear();
	void set(size_t, int);
	bool isEmpty();
	bool contains(List);
};
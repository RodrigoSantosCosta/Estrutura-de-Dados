#ifndef LIST_H
#define LIST_H


class Node{
	public:
		Node *prev;
		Node *next;
		int data;

		Node();
};

class List{
	public:
		Node *head;
		Node *tail;
		int nElements;

		List();
		
		Node begin();
		Node end();
		
		
		int size();
		bool empty();
		int getElement(int p);
		bool insert(int p, int d);
		bool push_front(int d);
		bool insert_any(int p, int d);
		bool remove_any(int p);
		bool push_back(int d);
		bool erase(int p);
		bool pop_frontUnit();
		bool pop_front();
		bool pop_back();
};

#endif // LIST_H


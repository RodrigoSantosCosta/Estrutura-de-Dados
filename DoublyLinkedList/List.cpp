#include <iostream>
#include "List.h"

	Node::Node(){

		prev = nullptr;
		next = nullptr;
	}

    List::List(){
		head = nullptr;
		tail = nullptr;
		nElements = 0;
	}

    bool List::empty(){
        if(nElements == 0){
            return true;
        }else{
            return false;
        }
    }

    int List::size(){
        return nElements;
    }

    int List::getElement(int p){
        Node *aux = head;
        int cont = 1;
        if(empty())
            return -1;
        if((p < 1) || (p > nElements))
            return -1;
        while(cont < p){
            aux = aux->next;
            cont++;
        }
        return aux->data;
        delete (aux);
    }

	bool List::insert(int p, int d){

		if((empty()) && (p != 1)){
			return false;
		}

		if(p == 1){
			push_front(d);
		}

		else if(p + 1 == nElements){
			return push_back(d);
		}

		else{
			return insert_any(p,d);
		}
		return true;
	}

	bool List::insert_any(int p, int d){
		Node *newNode = new Node();
		newNode->data = d;
		Node *tmp = head;
		int i = 1;

		while((i < p - 1) && (tmp != nullptr)){
			tmp = tmp->next;
			i++;
		}

		if(tmp == nullptr){
			return false;
		}

		newNode->prev = tmp;
		newNode->next = tmp->next;
		tmp->next = newNode-> prev;
		tmp->next = newNode;

		nElements++;
		return true;
	}



    bool List::push_front(int d){
        Node *newNode = new Node();

       	newNode->data = d;
        newNode->next = head;
        newNode->prev = nullptr;

        if(empty()){
            tail = newNode;
        }else{
            head->prev = newNode;
        }
        head = newNode;
        nElements++;
        return true;
        delete (newNode);
    }



    bool List::push_back(int d){
      	Node *newNode = new Node();

       	newNode->data = d;
        newNode->prev = tail;
        newNode->next = nullptr;

        if(empty()){
            head = newNode;
        }else{
            tail->next = newNode;
        }
        tail = newNode;
        nElements++;
        return true;
        delete (newNode);
    }

	bool List::erase(int p){
		if(empty()){
			return false; // Empty list
		}

		if((p == 1) && (size() == 1)){
			return pop_frontUnit();
		}

		else if(p == 1){
			return pop_front();
		}

		else if(p == size()){
			return pop_back();
		}

		else{
			return remove_any(p);
		}
	}


	bool List::remove_any(int p){
        Node *tmp1 = head;
        Node *tmp2;
        int n = 1;

        while((n <= p - 1) &&(tmp1 != nullptr)){
            tmp2 = tmp1;
            tmp1 = tmp1->next;
            n++;
        }

		if(tmp1 == nullptr){
			return false;
		}

        tmp2->next = tmp1->next;
        tmp2->prev = tmp1->prev;

        nElements--;
        delete(tmp1);
		return true;
    }

	bool List::pop_back(){
        if(nElements == 1){
			return pop_frontUnit();
		}
		Node *tmp = tail;

        tail = tmp->prev;
        tail->next = nullptr;

        nElements--;
        delete(tmp);
		return true;
    }

    bool List::pop_front(){

		if(nElements == 1){
			return pop_frontUnit();
		}

		Node *tmp = head;


        head = tmp->next;
        head->prev = nullptr;

        nElements--;
        delete(tmp);
		return true;
    }

	bool List::pop_frontUnit(){
		head = nullptr;
		tail = nullptr;
		nElements--;
		return true;
	}

int main(){
    List l;

    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);


    std::cout << "Size of list:" << l.size() << "\n";


    std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

	l.pop_back();

    std::cout << "Size of list: " << l.size() << "\n";

	std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

	l.pop_front();

    std::cout << "Size of list: " << l.size() << "\n";

	std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

	l.erase(2);

    std::cout << "Size of list: " << l.size() << "\n";

	std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

	l.erase(3);

    std::cout << "Size of list: " << l.size() << "\n";

	std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

	l.erase(1);
	l.erase(1);
    l.erase(1);

    std::cout << "Size of list: " << l.size() << "\n";

	std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";
}








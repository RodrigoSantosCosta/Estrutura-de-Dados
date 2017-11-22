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
	if(size() == 0){
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
	int cont = 0;
	if(empty())
		return -1;
	if((p < 0) || (p + 1  > size()))
		return -1;
	while(cont < p ){
		aux = aux->next;
		cont++;
	}
	return aux->data;
	delete (aux);
}

bool List::insert(int p, int d){

	if((empty()) && (p != 0)){
		return false;
	}

	if(p == 0){
		push_front(d);
	}

	else if(p == size()){
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
	Node *tmp2;
	int i = 1;

	while((i <  p ) && (tmp != nullptr)){
		tmp = tmp->next;
		i++;
	}

	if(tmp == nullptr){
		return false;
	}

	/*newNode->prev = tmp;
	newNode->next = tmp->next;
	tmp->next = newNode->prev;
	tmp->next = newNode;*/
	tmp2 = tmp->next;
	tmp->next = newNode;
	newNode->prev = tmp;
	newNode->next = tmp2;
	tmp2->prev = newNode;

	nElements++;
	return true;
}			



bool List::push_front(int d){
	Node *newNode = new Node();

	newNode->data = d;
	newNode->next = head;
	newNode->prev = nullptr;

	if(empty()){
		head = tail = newNode;
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
		head = tail = newNode;
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
		std::cout << "Lista vazia!\n";
		return false; // Empty list		
	}

	if((p == 0) && (size() == 0)){
		return pop_frontUnit();		

	}

	else if(p == 0){
		return pop_front();	
	}

	else if(p == size() - 1){
		return pop_back();
	}

	else{
		return remove_any(p);
	}	
}


bool List::remove_any(int p){
	Node *tmp1 = head;
	Node *tmp2;
	int n = 0;

	while((n < p) &&(tmp1 != nullptr)){
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
	if(size() == 1){
		return pop_frontUnit();		
	}

	if(empty()){
		return false;
	}
	Node *tmp = tail;


	tail = tmp->prev;
	tail->next = nullptr;

	nElements--;
	delete(tmp);
	return true;
}

bool List::pop_front(){
	if(size() == 1){
		return pop_frontUnit();		
	}

	if(empty()){
		return false;
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
	nElements= 0;
	return true;
}	

/*int main(){
    List l;

    l.push_front(1);
	l.push_front(2);
	l.push_front(1);
	l.push_front(3);
	l.push_front(4);
	l.push_front(5);
	l.push_front(6);
	l.push_front(7);
	
	std::cout << "\nSize of list:" << l.size() << "\n";
	
	for(int i = 0; i < 12; i++){
		std::cout << l.getElement(i) << " ";
	}

	l.erase(1);
	
	std::cout << "\nSize of list:" << l.size() << "\n";
	
	for(int i = 0; i < 12; i++){
		std::cout << l.getElement(i) << " ";
	}
	
	l.erase(6);
	
	std::cout << "\nSize of list:" << l.size() << "\n";
	
	for(int i = 0; i < 12; i++){
		std::cout << l.getElement(i) << " ";
	}

	l.erase(4);
	
	std::cout << "\nSize of list:" << l.size() << "\n";
	
	for(int i = 0; i < 12; i++){
		std::cout << l.getElement(i) << " ";
	}
	
	l.erase(1);
	
	std::cout << "\nSize of list:" << l.size() << "\n";
	
	for(int i = 0; i < 12; i++){
		std::cout << l.getElement(i) << " ";
	}
}*/


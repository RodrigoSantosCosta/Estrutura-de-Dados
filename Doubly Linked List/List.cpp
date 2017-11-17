#include <iostream>

class Node{
public:
    Node *prev;
    Node *next;
    int data;

    Node(){
        prev = nullptr;
        next = nullptr;
    }
};

class List{
public:
    Node *head;
    Node *tail;
    int nElements;

    List(){
        head = nullptr;
        tail = nullptr;
        nElements = 0;
    }

    bool empty(){
        if(nElements == 0){
            return true;
        }else{
            return false;
        }
    }

    int size(){
        return nElements;
    }

    int getElement(int p){
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
        delete aux;
    }

    bool push_front(int d){
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

    bool remove_any(int p){
        Node *newNode = head;
        Node *tmp;
        int n = 1;
        int d;

        while(n <= p - 1){
            tmp = newNode;
            newNode = newNode->next;
            n++;
        }

        d = newNode->data;
        tmp->next = newNode->next;
        tmp->prev = newNode->prev;

        nElements--;
        delete(newNode);
    }

    bool push_back(int d){
        Node *newNode = new Node();

        newNode->data = d;
        newNode->next = nullptr;
        newNode->prev = tail;

        if(empty()){
            head = newNode;
        }else{
            tail->next = newNode;
        }
        tail = newNode;
        nElements++;
        return true;
        delete(newNode);
    }

    bool pop_back(){

        Node *newNode = tail;
        int d = newNode->data;

        tail = newNode->prev;
        tail->next = nullptr;

        nElements--;
        delete(newNode);
    }

    bool pop_front(){

        Node *newNode = head;
        int d = newNode->data;

        head = newNode->next;
        head->prev = nullptr;

        nElements--;
        delete(newNode);
    }
};

int main(){
    List l;

    if(l.empty()){std::cout << "Empty\n";}

    else{std::cout << "mec\n";}


    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    if(l.empty()){std::cout << "Empty\n";}

    else{std::cout << "mec\n";}

    l.remove_any(5);

    std::cout << "Size of list:" << l.size() << "\n";


    std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

    l.pop_back();
    l.pop_front();

    std::cout << "Size of list: " << l.size() << "\n";

    std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

    l.pop_back();

    std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

    std::cout << "Size of list: " << l.size() << "\n";

    l.pop_front();

    std::cout << l.getElement(1);
    std::cout << l.getElement(2);
    std::cout << l.getElement(3);
    std::cout << l.getElement(4);
    std::cout << l.getElement(5);
    std::cout << l.getElement(6) << "\n";

}


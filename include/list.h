#include<iostream>

using namespace std;
namespace my{
template<typename T>
class Mylist
{
private:
//d
    class Node
    {
        public:
        T data;
        Node* next;
        Node(T data=T(), Node* next=nullptr)
        {
            this->data = data;
            this->next = nullptr;
        }
    };
public:
    Node* head;
    Mylist()
    {
        this->head = nullptr;
    }
    ~Mylist();
    void pop_front();
    void pop_back();
    void push_front(const T& item);
    void push_back(const T& item);
    friend ostream& operator<<(std::ostream& os, const Mylist& list) {

    for(Node* current = list.head; current != nullptr; current = current->next) {

        os << current->data << " ";

    }

    return os;

}
};

template<typename T>
void Mylist<T>::pop_front()
{
    if(head!=nullptr)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    else
    {
        throw out_of_range("Cannot pop front from an empty list");
    }
}

template<typename T>
Mylist<T>::~Mylist()
{
    Node* current = head;
    while(current!=nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}


template<typename T>
void Mylist<T>::push_front(const T& item)
{
    Node* new_node = new Node;
    new_node->data = item;
    new_node->next = head;
    if(head!=nullptr){

        head = new_node;
    }
    else
    {
        head = new_node;
        new_node->next = nullptr;
    }
}


template<typename T>
void Mylist<T>::push_back(const T& item)
{
    Node* new_node = new Node;
    new_node->data = item;
    new_node->next = nullptr;
    if(head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node* current = head;
        while(current->next!=nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}


template<typename T>

void Mylist<T>::pop_back()
{
    if(head!=nullptr)
    {
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
        } else 
        {
            Node* tmp = head;
            Node* prev = nullptr;
            while(tmp->next!=nullptr)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            delete tmp;
            prev->next = nullptr;
        }
    }
    else
    {
        throw out_of_range("Cannot pop back from an empty list");
    }

}


}
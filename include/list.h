#include<iostream>

using namespace std;
namespace my{
template<typename T>
class Mylist
{
private:
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
    Mylist(const Mylist<T>& other);
    ~Mylist();
    void pop_front();
    void pop_back();
    void push_front(const T& item);
    void push_back(const T& item);
    void insert(const T& item, int index);
    void destroy(int index);
    T& operator[](int index);
    void  push_front(const Mylist<T> other);
    void  push_back(const Mylist<T> other);
    void delete_node(const T& item);
    Mylist<T>& operator=(Mylist<T> other);
    friend ostream& operator<<(std::ostream& os, const Mylist& list) {
    for(Node* current = list.head; current != nullptr; current = current->next) {
        os << current->data << " ";
    }
    return os;
    }
    void swap(Mylist<T>& other);
};

template<typename T>
Mylist<T>::Mylist(const Mylist<T>& other): head(nullptr)
{
    Node* tmp = other.head;
    while(tmp!=nullptr)
    {
        this->push_back(tmp->data);
        tmp = tmp->next;
    }
}

template<typename T>
void Mylist<T>::swap(Mylist<T>& other)
{
    Node* tmp = head;
    head = other.head;
    other.head = tmp;
}


template<typename T>
Mylist<T>& Mylist<T>::operator=(Mylist other)
{
    if(this == &other)
    {
        return *this;
    }
    swap(other);
    return *this;
}

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

template<typename T>
T& Mylist<T>::operator[](int index)
{
    int count = 0;
    Node* tmp = head;
    while(tmp!=nullptr)
    {
        if(count == index)
        {
            return tmp->data;
        }
        count++;
        tmp = tmp->next;
    }
    throw out_of_range("wrong index of list");
}
//n n n    n t n n  
template<typename T>
void Mylist<T>::insert(const T& item, int index)
{
    if(index < 0)
    {
        throw out_of_range("index cannot be negative");
    }
    else if(index == 0)
    {
        this->push_front(item);
    }
    else
    {
        Node* tmp = head;
        for(int i = 0; i < index - 1; i++)
        {
            if(tmp==nullptr)
            {
                throw out_of_range("wrong index to insert");
            }
            tmp = tmp->next;
        }
        if(tmp == nullptr)
        {
            throw out_of_range("wrong index to insert");
        }
        Node* nextNode = tmp->next;
        Node* new_node = new Node(item);
        new_node->next = nextNode;
        tmp->next = new_node;
    }
}

template<typename T>
void Mylist<T>::destroy(int index)
{
    if(index < 0)
    {
        throw out_of_range("wrong index to destroy");
    }
    else if(index == 0)
    {
        this->pop_front();
    }
    else
    {
    Node* tmp = head;
        for(int i = 0; i < index - 1; i++)
        {
            if(tmp == nullptr)
            {
                throw out_of_range("wrong index to destroy");
            }
            tmp = tmp->next;
        }
        if(tmp == nullptr || tmp->next == nullptr)
        {
            throw out_of_range("wrong index to destroy");
        }
        Node* node_to_delete = tmp->next;
        tmp->next = node_to_delete->next;
        delete node_to_delete;
    }
}

template<typename T>
void Mylist<T>::push_front(const Mylist<T> other)
{
    Node* tmp = other.head;
    Mylist<T> list;
    
    while(tmp!=nullptr)
    {
        list.push_front(tmp->data);
        tmp = tmp->next;
    }
    Node* kk = list.head;
    while(kk!=nullptr)
    {
        this->push_front(kk->data);
        kk = kk->next;
    }
}

template<typename T> 
void Mylist<T>::push_back(const Mylist<T> other)
{
    Node* tmp = other.head;
    while(tmp!=nullptr)
    {
        this->push_back(tmp->data);
        tmp = tmp->next;
    }
}


template<typename T>
void Mylist<T>::delete_node(const T& item)
{
    Node* current = head;

    Node* prev = nullptr;

    while(current != nullptr) {

        if(current->data == item) {

            Node* to_delete = current;

            current = current->next;

            if(prev == nullptr) {

                head = current;

            } else {

                prev->next = current;

            }

            delete to_delete;

        } else {

            prev = current;

            current = current->next;

        }

    }
}
}
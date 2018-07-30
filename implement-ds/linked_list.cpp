#include <iostream>

template<class T>
class Node {
    public:
        T data;
        Node *next;
        Node<T>(const T& d) : data(d), next() { }

    private:
        Node<T>& operator=(const Node<T>&);
};

template<class T>
class LinkedList {
    public:
        LinkedList();
        T get_begin();
        T get_end();
        void insert_begin(T data);
        void insert_end(T data);
        void delete_begin();
        void delete_end();
        void print();
        int get_size();
    private:
        int size;
        Node<T>* head;
        Node<T>* tail;

};

template<class T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = NULL;
    this->tail = this->head;
}

template<class T>
int LinkedList<T>::get_size() {
    return this->size;
}

template<class T>
void LinkedList<T>::insert_begin(T data) {
    Node<T>* new_node = new Node<T>(data);
    new_node->next = this->head;
    this->head = new_node;
    
    if(this->head->next == NULL) {
        this->tail = new_node;
    }
    this->size++;
}

template<class T>
void LinkedList<T>::insert_end(T data) {
    Node<T>* new_node = new Node<T>(data);

    if(this->tail == NULL) {
        new_node->next = this->tail;
        this->tail = new_node;
        this->head = new_node;
    } else {
        this->tail->next = new_node;
        this->tail = this->tail->next;
    }
    this->size++;
}

template<class T>
void LinkedList<T>::print() {
    Node<T>* t = this->head;
    while(t) {
        std::cout << t->data << std::endl;
        t = t->next;
    }
}

template<class T>
T LinkedList<T>::get_begin() {
    return this->head->data;
}

template<class T>
T LinkedList<T>::get_end() {
    return this->tail->data;
}

template<class T>
void LinkedList<T>::delete_begin() {
    if(this->size == 0) return;
    if(this->size == 1) {
        delete this->head;
        this->head = NULL;
        this->tail = this->head;
        this->size = 0;
        return;
    }

    Node<T> *temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->size--;
}

template<class T>
void LinkedList<T>::delete_end() {
    if(this->size == 0) return;
    if(this->size == 1) {
        delete this->tail;
        this->head = NULL;
        this->tail = this->head;
        this->size = 0;
        return;
    }

    Node<T>* t = this->head;

    while(t->next->next != NULL) {
        t = t->next;
    }

    delete tail;

    this->tail = t;
    this->tail->next = NULL;
    this->size--;
}

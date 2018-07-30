#include <iostream>
#include "linked_list.cpp"

template<class T>
class Queue {
    public:
        Queue();
        bool empty();
        void push(T data);
        T front();
        T pop();

    private:
        LinkedList<T> ll;
};

template<class T>
Queue<T>::Queue() {
}

template<class T>
T Queue<T>::front() {
    return ll.get_begin();
}

template<class T>
bool Queue<T>::empty() {
    return ll.get_size() == 0;
}

template<class T>
void Queue<T>::push(T data) {
    ll.insert_begin(data); 
}

template<class T>
T Queue<T>::pop() {
    T f = this->front();
    ll.delete_begin();
    return f;
}

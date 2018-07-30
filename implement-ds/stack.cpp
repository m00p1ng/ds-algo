#include <iostream>
#include "linked_list.cpp"

template<class T>
class Stack {
    public:
        Stack();
        T top();
        T pop();
        bool empty();
        void push(T data);

    private:
        LinkedList<T> ll;
};

template<class T>
Stack<T>::Stack() {
}

template<class T>
bool Stack<T>::empty() {
    return ll.get_size() == 0;
}

template<class T>
T Stack<T>::top() {
    return ll.get_end();
}

template<class T>
T Stack<T>::pop() {
    int t = this->top();
    ll.delete_end();
    return t;
}

template<class T>
void Stack<T>::push(T data) {
    ll.insert_end(data);
}

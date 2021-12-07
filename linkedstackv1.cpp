#include <iostream>

template<typename T>
class Stack {
public:
    Stack() : size(0), top(nullptr) {}

    ~Stack() { Clear(); };

    T &Top() const { return top->data_; }

    bool Empty() { return size == 0; }

    void Clear();

    int Size() const { return size; }

    void Push(T element);

    T Pop();

    Stack(const Stack<T> &stack); //-

    Stack &operator=(const Stack &stack); //-

private:
    template<typename A>
    class Node {
    public:
        Node(A data = A(), Node *prevN = nullptr) : data_(data), prevN_(prevN) {}

        Node *prevN_;
        A data_;
    };

    int size;
    Node<T> *top;
};

template<typename T>
void Stack<T>::Push(T element) {
    Node<T> *new_top = new Node<T>(element, top);
    top = new_top;
    size++;
}

template<typename T>
T Stack<T>::Pop() {
    if (size == 1) {
        size = 0;
        delete top;
        top = nullptr;
        return T();
    }
    T value = top->data_;
    Node<T> *temp = top;
    top = top->prevN_;
    delete temp;
    size--;
    return value;
}

template<typename T>
void Stack<T>::Clear() {
    while (size) {
        Pop();
    }
}

template<typename T>
Stack<T>::Stack(const Stack<T> &stack) {
//-----------------------------------------------------------
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
//-----------------------------------------------------------
}


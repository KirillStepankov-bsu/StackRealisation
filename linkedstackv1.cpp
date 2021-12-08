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

    Stack(const Stack<T> &rhs);

    bool operator==(const Stack &rhs) const;

    Stack &operator=(const Stack &stack);

private:
    void Assignment(const Stack<T> &rhs);

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
Stack<T>::Stack(const Stack<T> &rhs) {
    Assignment(rhs);
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
    Clear();
    if (rhs.top == nullptr) {
        return *this;
    }
    Assignment(rhs);
    return *this;
}

template<typename T>
void Stack<T>::Assignment(const Stack<T> &rhs) {
    top = new Node<T>(rhs.top->data_, rhs.top);
    size = rhs.size;
    Node<T> *temp1 = top;
    Node<T> *temp2 = rhs.top;
    int counter = 0;
    while (counter != rhs.size) {
        temp1->prevN_ = temp2->prevN_;
        temp1 = temp1->prevN_;
        temp2 = temp2->prevN_;
        counter++;
    }
    delete temp1;
    delete temp2;
    temp1 = nullptr;
    temp2 = nullptr;
}

template<typename T>
bool Stack<T>::operator==(const Stack &rhs) const {
    if (size != rhs.size)
        return false;

    Node<T> *temp1 = top;
    Node<T> *temp2 = rhs.top;
    int counter = 0;
    while(counter != size){
        if(temp1->prevN_ != temp2->prevN_) return false;
        temp1 = temp1->prevN_;
        temp2 = temp2->prevN_;
        counter++;
    }
    delete temp1; temp1 = nullptr;
    delete temp2; temp2 = nullptr;
    return true;
}


template<typename T>
class Stack {
public:
    Stack() : stack(nullptr), size_(0) {}

    Stack(const Stack &st);

    void push(T item);

    T pop();

    T top();

    ~Stack();

    [[nodiscard]] int Size() const { return size_; }

    [[nodiscard]] bool IsEmpty() const { return size_ == 0; }

private:
    T *stack;
    int size_;
};

template<typename T>
Stack<T>::Stack(const Stack &st) {
    stack = new T[st.size_];
    size_ = st.size_;
    for (int i = 0; i < size_; i++)
        stack[i] = st.stack[i];
}

template<typename T>
void Stack<T>::push(T item) {
    T *tmp = stack;
    stack = new T[size_ + 1];

    size_++;
    for (int i = 0; i < size_ - 1; i++)
        stack[i] = tmp[i];

    stack[size_ - 1] = item;
    if (size_ > 1)
        delete[] tmp;
}

template<typename T>
T Stack<T>::pop() {
    if (size_ == 0)
        return 0;
    return stack[size_--];
}

template<typename T>
T Stack<T>::top() {
    if (size_ == 0)
        return 0;
    return stack[size_ - 1];
}

template<typename T>
Stack<T>::~Stack() {
    if (size_ > 0)
        delete[] stack;
}


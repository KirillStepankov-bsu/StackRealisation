template<typename T>
class Stack {
public:
    Stack() : size(0) { data = new T; }

    void push(const T& element) { data[size++] = element; }

    T pop() { return data[--size]; }

    [[nodiscard]] int length() const { return size; }

    [[nodiscard]] T top() const { return data[size - 1]; }

    [[nodiscard]] bool isEmpty() const { return size == 0; }

    ~Stack() {
        delete[] data;
        data = nullptr;
    }

private:
    T *data;
    int size;
};

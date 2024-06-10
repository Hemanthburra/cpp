#include <iostream>

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x) {
        if (top == capacity - 1) {
            std::cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top != -1) {
            return arr[top];
        }
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element is " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top element after pop is " << stack.peek() << std::endl;

    return 0;
}

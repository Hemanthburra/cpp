#include <iostream>

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (count == capacity) {
            std::cout << "Queue overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (count == 0) {
            std::cout << "Queue underflow\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    int peek() {
        if (count != 0) {
            return arr[front];
        }
        return -1;
    }

    bool isEmpty() {
        return count == 0;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element is " << queue.peek() << std::endl;

    queue.dequeue();
    std::cout << "Front element after dequeue is " << queue.peek() << std::endl;

    return 0;
}

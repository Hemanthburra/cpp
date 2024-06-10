#include <iostream>

class Array {
private:
    int* arr;
    int size;

public:
    Array(int size) {
        this->size = size;
        arr = new int[size];
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    int get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return -1; // Return -1 for invalid index
    }

    ~Array() {
        delete[] arr;
    }
};

int main() {
    Array array(5);
    array.set(0, 1);
    array.set(1, 2);
    array.set(2, 3);
    array.set(3, 4);
    array.set(4, 5);

    for (int i = 0; i < 5; i++) {
        std::cout << "Element at index " << i << " is " << array.get(i) << std::endl;
    }

    return 0;
}

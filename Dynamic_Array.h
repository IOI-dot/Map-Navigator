#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* arr;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity) {
        T* new_arr = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

public:
    // Constructor
    DynamicArray() : size(0), capacity(2) {
        arr = new T[capacity];
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // Copy constructor
    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) {
        arr = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] arr;

            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];

            for (size_t i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Get the size of the array
    size_t get_size() const {
        return size;
    }

    // Get the capacity of the array
    size_t get_capacity() const {
        return capacity;
    }

    // Access elements by index
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Add an element to the array
    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        arr[size++] = value;
    }

    // Remove the last element from the array
    void pop_back() {
        if (size == 0) {
            throw std::underflow_error("Cannot pop from an empty array");
        }
        --size;
    }

    // Insert an element at a given index
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        ++size;
    }

    // Remove an element at a given index
    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
    }

    // Clear the array
    void clear() {
        size = 0;
    }

    // Print the array elements (for debugging purposes)
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};


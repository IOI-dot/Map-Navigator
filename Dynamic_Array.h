#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template<typename T>
class DynamicArray {
private:
    T* data;
    int size;
    int capacity;

    void resize();

public:
    DynamicArray();
    ~DynamicArray();

    void push_back(const T& value);
    T& operator[](int index);
    int getSize() const;
    bool isEmpty() const;
};

// Constructor
template<typename T>
DynamicArray<T>::DynamicArray() {
    capacity = 4;
    size = 0;
    data = new T[capacity];
}

// Destructor
template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

// Resize function to double the capacity when full
template<typename T>
void DynamicArray<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

// Adds a value at the end of the array
template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (size == capacity)
        resize();
    data[size++] = value;
}

// Accessor for array elements
template<typename T>
T& DynamicArray<T>::operator[](int index) {
    return data[index];
}

// Get the current size of the array
template<typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

// Check if the array is empty
template<typename T>
bool DynamicArray<T>::isEmpty() const {
    return size == 0;
}

#endif

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
    const T& operator[](int index) const;
    int getSize() const;
    bool isEmpty() const;
};

#endif


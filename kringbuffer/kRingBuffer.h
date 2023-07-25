#pragma once
template <typename T>
class KRingBuffer {
public:
    KRingBuffer(size_t initialCapacity = 10) : capacity(initialCapacity), size(0), head(0), tail(0) {
        buffer = new T[initialCapacity];
    }

    ~KRingBuffer() {
        delete[] buffer;
    }

    void push(const T& item);

    T pop();

    size_t getSize() const;

    size_t getCapacity() const;

private:
    T* buffer;
    size_t capacity;
    size_t size;
    size_t head;
    size_t tail;

    void expand();

    void shrink();
};

template <typename T>
void KRingBuffer<T>::push(const T& item) {
    if (size == capacity) {
        expand();
    }
    buffer[tail] = item;
    tail = (tail + 1) % capacity;
    size++;
}

template <typename T>
T KRingBuffer<T>::pop() {
    if (size == 0) {
        throw "RingBuffer is empty";
    }

    T item = buffer[head];
    head = (head + 1) % capacity;
    size--;

    if (size < capacity / 2) {
        shrink();
    }

    return item;
}

template <typename T>
size_t KRingBuffer<T>::getSize() const {
    return size;
}

template <typename T>
size_t KRingBuffer<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void KRingBuffer<T>::expand() {
    size_t newCapacity = capacity * 2;
    T* newBuffer = new T[newCapacity];
    for (size_t i = 0; i < size; i++) {
        newBuffer[i] = buffer[(head + i) % capacity];
    }
    delete[] buffer;
    buffer = newBuffer;
    head = 0;
    tail = size;
    capacity = newCapacity;
}

template <typename T>
void KRingBuffer<T>::shrink() {
    size_t newCapacity = capacity / 2;
    T* newBuffer = new T[newCapacity];
    for (size_t i = 0; i < size; i++) {
        newBuffer[i] = buffer[(head + i) % capacity];
    }
    delete[] buffer;
    buffer = newBuffer;
    head = 0;
    tail = size;
    capacity = newCapacity;
}
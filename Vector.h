//
// Created by Ilia on 5/1/2021.
//

#ifndef TRAVELLER_S_APP_VECTOR_H
#define TRAVELLER_S_APP_VECTOR_H

#include <cstddef>

template<typename T>
class Vector {
public:
    Vector();

    Vector(const size_t &size);

    Vector(const size_t &size, const T &value);

    Vector(const Vector &other);

    Vector &operator=(const Vector &other);

    void eraseData();

    void reserve(const size_t &newCapacity);

    void resize(const size_t &newSize);

    void pushBack(const T& value);

    void popBack();

    void print() const;

    bool elem(const T& element) const;

    T &operator[](size_t index) const {
        return this->data[index];
    }


    size_t getSize() const {
        return this->size;
    }
    size_t getCapacity() const {
        return this->capacity;
    }
    T* getData() const {
        return this->data;
    }

    ~Vector();
private:
    T *data;
    size_t size;
    size_t capacity;

    /**
     * Задаля памет за типа T с капацитет capacity
     * @param capacity размер на заделената памет
     * @return указател към заделената памет
     */
    T *allocateMemory(const size_t &capacity) {
        return reinterpret_cast<T *> (operator new(sizeof(T) * capacity));
    }

    /**
    * Конструира с подразбиращ се конструктор обектите върху паметта, опредлена от обхвана begin и end
    * @param begin - указател към началото на обхвата
    * @param end - указател към края на обхвата
     * @param fillValue стойността с която да бъде запълнен масива
    */
    static void constructRange(T *begin, T *end, const T &fillValue) {
        while (begin != end) {
            new((void *) begin) T(fillValue);
            ++begin;
        }
    }

    /**
   * Конструира с подразбиращ се конструктор обектите върху паметта, опредлена от обхвана begin и end
   * @param begin - указател към началото на обхвата
   * @param end - указател към края на обхвата
   */
    static void constructRange(T *begin, T *end) {
        while (begin != end) {
            new((void *) begin) T();
            ++begin;
        }
    }


    /**
     * Конструира с конструктор за копиране на обектите върху паметта, опредлена от обхвана begin и end
     * @param begin - указател към началото на обхвата
     * @param end - указател към края на обхвата
     */
    static void copyRange(T *begin, T *end, T *destination) {
        while (begin != end) {
            new((void *) destination) T(*begin);
            ++begin;
            ++destination;
        }
    }

    /**
     * Извика деструктурите на обектите върху паметта, определена от обхвата begin до end
     * @param begin укзател към началот
     * @param end указател към края
     */
    static void destructRange(T *begin, T *end) {
        while (begin != end) {
            begin->~T();
            ++begin;
        }
    }

    static void destructAndDeleteRange(T *begin, T *end) {
        destructRange(begin, end);
        operator delete(begin);
    }
};


template<typename T>
Vector<T>::Vector() : data(allocateMemory(8)), size(0), capacity(8) {
    constructRange(this->data, this->data + this->capacity);
}

template<typename T>
Vector<T>::Vector(const size_t &size) : data(allocateMemory(size)), size(size), capacity(size) {
    constructRange(this->data, this->data + size);
}

template<typename T>
Vector<T>::Vector(const size_t &size, const T &value) : data(allocateMemory((size))), size(size),
                                                        capacity(size) {
    constructRange(this->data, this->data + size, value);
}

template<typename T>
Vector<T>::Vector(const Vector &other) :
        data(allocateMemory(other.capacity)), size(other.size), capacity(other.capacity) {
    copyRange(other.data, other.data + other.size, this->data);
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this == &other) {
        return *this;
    }

    T *newData = allocateMemory(other.capacity);
    destructAndDeleteRange(this->data, this->data + this->size);
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = newData;
    copyRange(other.data, other.data + other.size, this->data);
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    destructAndDeleteRange(this->data, this->data + this->size);
}

template<typename T>
void Vector<T>::reserve(const size_t &newCapacity) {
    if (newCapacity > this->capacity) {
        T *newData = allocateMemory(newCapacity);
        copyRange(this->data, this->data + this->size, newData);
        destructAndDeleteRange(this->data, this->data + this->size);
        this->capacity = newCapacity;
        this->data = newData;
    }
}

template<typename T>
void Vector<T>::resize(const size_t &newSize) {
    if (newSize <= this->size) {
        destructRange(this->data + newSize, this->data + this->size);
        this->size = newSize;
        return;
    }

    if (newSize <= this->capacity) {
        constructRange(this->data + this->size, this->data + newSize);
        this->size = newSize;
        return;
    }

    while(newSize > this->capacity) {
        reserve(this->capacity * 2);
    }
    this->size = newSize;
}

template<typename T>
void Vector<T>::pushBack(const T &value) {
// TODO: To implement
    if (this->size >= this->capacity) {
        reserve(this->capacity * 2);
    }
    new ((void*) (this->data + this->size)) T(value);
    this->size++;
}

template<typename T>
void Vector<T>::popBack() {
// TODO: To implement
    if (this->size == 0) {
        return;
    }
    destructRange(this->data + this->size - 1, this->data + this->size);
    this->size--;
}

template<typename T>
void Vector<T>::eraseData() {
    if (this->size == 0) {
        return;
    }
    destructRange(this->data, this->data + this->size);
    allocateMemory(8);
    this->size = 0;
    this->capacity = 8;
    constructRange(this->data, this->data + this->capacity);
}

template<typename T>
bool Vector<T>::elem(const T &element) const {
    for (int i = 0; i < this->size; ++i) {
        if (this->data[i] == element) {
            return true;
        }
    }
    return false;
}

template <class T>
void Vector<T>::print() const {
    for (int i = 0; i < this->size; ++i) {
        std::cout << this->data[i] << std::endl;
    }
}

#endif //TRAVELLER_S_APP_VECTOR_H
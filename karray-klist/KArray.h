#pragma once
#include<iostream>

template <class T>
class KArray
{
private:
	T* data;
	unsigned int size;
	unsigned int capacity;

public:
	KArray();
	KArray(int num);
	~KArray();

public:
	void reserve(int cap);
	void push(const T& ele);
	void insert(int index, const T& ele);
	void remove(int index);
	void clear();
	void print();

	int findIndex(const T& ele);

	T& pop();

};

template<class T>
inline KArray<T>::KArray() : data(nullptr),size(0),capacity(0)
{
}

template<class T>
inline KArray<T>::KArray(int num)
{
	data = new T[num];
	size = 0;
	capacity = num;
}

template<class T>
inline KArray<T>::~KArray()
{
	if (data != nullptr)
	{
		delete[] data;
	}
}

template<class T>
inline void KArray<T>::reserve(int new_cap)
{
	if (capacity < new_cap)
	{
		T* ndata = new T[new_cap]();
		for (int i = 0; i < size; i++)
		{
			ndata[i] = data[i];
		}
		delete[] data;
		data = nullptr;
		data = ndata;

		capacity = new_cap;
	}
}

template<class T>
inline void KArray<T>::push(const T& ele)
{
	if (size < capacity)
	{
		data[size] = ele;
		size++;
	}
	else
	{
		this->reserve(2 * capacity);
		this->push(ele);
	}
}

template<class T>
inline void KArray<T>::insert(int index, const T& ele)
{
	if (size >= capacity)
	{
		this->reserve(2 * capacity);
		this->insert(index, ele);
	}
	else
	{
		for (int i = 1; i <= size - index; i++)
		{
			data[size - i + 1] = data[size - i];
		}
		data[index] = ele;
		size++;
	}
}

template<class T>
inline void KArray<T>::remove(int index)
{
	if (index >= 0 && index < size)
	{
		for (int i = index; i < size - index; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}
}

template<class T>
inline void KArray<T>::clear()
{
	size = 0;
}

template<class T>
inline void KArray<T>::print()
{
	if (size == 0)
	{
		std::cout << "Array is empty!" << std::endl;
		return;
	}
	std::cout << "Array data : " ;
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << "  ";
	}
	std::cout << std::endl;
}

template<class T>
inline int KArray<T>::findIndex(const T& ele)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] = ele)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
inline T& KArray<T>::pop()
{
	T& temp = data[size - 1];
	this->remove(size - 1);
	return temp;
}

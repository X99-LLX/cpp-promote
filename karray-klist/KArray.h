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
	size = num;
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
inline void KArray<T>::reserve(int cap)
{
	if (capacity < cap)
	{
		T* ndata = new T[cap]();
		for (int i = 0; i < size; i++)
		{
			ndata[i] = data[i];
		}
		delete[] data;
		data = ndata;
	}
}

template<class T>
inline void KArray<T>::push(const T& ele)
{

}

template<class T>
inline void KArray<T>::insert(int index, const T& ele)
{

}

template<class T>
inline void KArray<T>::remove(int index)
{

}

template<class T>
inline void KArray<T>::clear()
{

}

template<class T>
inline void KArray<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << *data[i] << std::endl;
	}
}

template<class T>
inline int KArray<T>::findIndex(const T& ele)
{
	return 0;
}

template<class T>
inline T& KArray<T>::pop()
{
	// TODO: 在此处插入 return 语句
}

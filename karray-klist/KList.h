#pragma once
template<class T>
struct KNode
{
	KNode(T data, KNode<T>* next = nullptr) : data(data), next(next) {}

	T data;
	KNode* previous;
	KNode* next;
};

template<class T>
class KList
{
private:
	KNode<T>* head;
	KNode<T>* tail;
	int length;

public:
	KList() : head(nullptr), tail(nullptr), length(0) {}
	~KList();

	KNode<T>& push(T data);
	KNode<T>& insert(KNode<T> node, int index);
	int size();
	void print();
	T& operator[](int index);
};

template<class T>
inline KList<T>::~KList()
{
	while (head != nullptr) {
		KNode<T>* node = head;
		head = head->next;
		delete node;
	}
}

template<class T>
inline KNode<T>& KList<T>::push(T data)
{
	KNode<T>* node = new KNode<T>(data);
	if (head == nullptr) {
		head = tail = node;
	}
	else {
		auto temp = tail;
		node->previous = temp;
		tail->next = node;
		tail = node;
	}
	length++;
	return *node;
}

template<class T>
inline KNode<T>& KList<T>::insert(KNode<T> node, int index)
{
	
}

template<class T>
inline int KList<T>::size()
{
	return this->length;
}

template<class T>
inline void KList<T>::print()
{
	for(int i = 0;i < length;i++) 
	{
		std::cout << (*this)[i] << std::endl;
	}
}

template<class T>
inline T& KList<T>::operator[](int index)
{
	if (index >= length || index < 0)
	{
		throw "index is out of range!";
	}

	KNode<T>* current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}


	return current->data;
}

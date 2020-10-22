#include "stdafx.h"


template<class T>
class vector
{
public:
	typedef T*		pointer;
	typedef T*		iterator;
	typedef size_t	size_type;
	typedef T&		reference;
	typedef const T&const_reference;

public:
	vector();
	vector(int nCount, const T& value);
	void fill_init(int nCount, const T& value);
	pointer alloc_and_fill(int nCount, const_reference value);

public:
	//�Ƿ�Ϊ��
	bool empty();
	//�׵�����
	iterator begin();
	//β������
	iterator end();
	//������С
	size_t size();
	//������С
	size_t capacity();						

	//Add ��غ���
	//β��
	void push_back(const_reference value);
	//ָ��λ�ò���
	void insert(iterator pos, const_reference value);
	//������ָ����С��ֻ�����ݣ������������κβ��������ı�������С��
	void reserve(size_type new_capacity);
	//�ض���������С��ֻ���������С�����ض����������С���ڵ�ǰ�������������仹�ǰ���������
	void resize(size_type new_size, const_reference value);

	//Delete
	//βɾ
	void pop_back();
	//���ָ����Χ
	iterator erase(iterator first_pos, iterator last_pos);
	//���
	void clear();

	//Modify
	reference operator[](int nIndex);	//���������[]

private:
	iterator	start;
	iterator	finish;
	iterator	end_of_storage;
};

template<class T>
void vector<T>::resize( size_type new_size, const_reference value )
{
	if (new_size > capacity())
	{
		size_type temp = 2*capacity();
		while (temp < new_size)
		{
			temp *= 2;
		}
		reserve(temp);
	}

	if (new_size > size())
	{
		for (size_t i=size(); i!=new_size; i++)
		{
			start[i] = value;
		}
	}
	else
	{
		for (size_t i=new_size; i!=size(); i++)
		{
			start[i] = value;
		}
	}

	finish = start + new_size;
}

template<class T>
void vector<T>::reserve( size_type new_capacity )
{
	if (new_capacity > capacity())
	{
		//renew 
		pointer ptemp = alloc_and_fill(new_capacity,T());
		if(!ptemp)
			return;

		//copy
		size_t unsize = size();
		for (size_t i=0; i<unsize; i++)
		{
			ptemp[i] = start[i];
		}

		//free
		delete []start;

		//reassign
		start = ptemp;
		finish = start + unsize;
		end_of_storage = start + new_capacity;
	}
}

template<class T>
void vector<T>::insert( iterator pos, const_reference value )
{
	if (size() == capacity())
		reserve(2*capacity());

	if (pos - begin() < size())
	{
		//����
		for (iterator it = end()+1; it != pos; )
		{
			iterator temp = it;
			*temp = *(--it);
		}
	}

	*pos = value;
}

template<class T>
void vector<T>::push_back( const_reference value )
{
	if (size() == capacity())
		reserve(2*capacity());

	*finish = value;
	finish++;
}

template<class T>
void vector<T>::pop_back()
{

}

template<class T>
bool vector<T>::empty()
{
	return (begin() == end());
}

template<class T>
T& vector<T>::operator[]( int nIndex )
{
	return *(begin()+nIndex);
}

template<class T>
size_t vector<T>::capacity()
{
	return end_of_storage - start;
}

template<class T>
size_t vector<T>::size()
{
	return end() - begin();
}

template<class T>
T*  vector<T>::end()
{
	return finish;
}

template<class T>
T*  vector<T>::begin()
{
	return start;
}

template<class T>
void vector<T>::fill_init( int nCount, const T& value )
{
	start= alloc_and_fill(nCount,value);
	finish = start + nCount;
	end_of_storage = finish;
}


template<class T>
T* vector<T>::alloc_and_fill( int nCount, const_reference value )
{
	pointer ptemp = NULL;
	ptemp = new T[nCount]();
	if (ptemp)
	{
		for (int i=0; i<nCount; i++)
		{
			ptemp[i] = value;
		}
	}

	return ptemp;
}


template<class T>
vector<T>::vector():
start(NULL),
	finish(NULL),
	end_of_storage(NULL)
{

}

template<class T>
vector<T>::vector(int nCount, const T& value):
start(NULL),
	finish(NULL),
	end_of_storage(NULL)
{
	fill_init(nCount,value);
}
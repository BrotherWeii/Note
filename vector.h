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
	//是否为空
	bool empty();
	//首迭代器
	iterator begin();
	//尾迭代器
	iterator end();
	//向量大小
	size_t size();
	//容量大小
	size_t capacity();						

	//Add 相关函数
	//尾插
	void push_back(const_reference value);
	//指定位置插入
	void insert(iterator pos, const_reference value);
	//扩容至指定大小（只可扩容，否则函数不做任何操作，不改变向量大小）
	void reserve(size_type new_capacity);
	//重定义向量大小（只针对向量大小，当重定义的向量大小大于当前容量，容量扩充还是按照两倍）
	void resize(size_type new_size, const_reference value);

	//Delete
	//尾删
	void pop_back();
	//清除指定范围
	iterator erase(iterator first_pos, iterator last_pos);
	//清空
	void clear();

	//Modify
	reference operator[](int nIndex);	//运算符重载[]

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
		//后移
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
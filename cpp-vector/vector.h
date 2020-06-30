#include "cstdint"
#include <exception>
#include "cstdio"
#include <iostream>

template <typename T>
class Vector
{
public:
	Vector();
	explicit Vector(size_t n, const T& val = T());
	Vector(const Vector<T>& vec);
	~Vector();
	
	Vector& operator=(const Vector<T>&);
	const T& operator[](size_t index)const;
	T& operator[](size_t index);
	Vector operator+(const Vector& v);
	Vector& operator+=(const Vector& v);
	
	size_t size()const;
	size_t max_size()const;
	void resize(size_t n,const T& val = T());
	size_t capacity()const;
	bool empty()const;
	void reserve(size_t n);
	
	const T& at(size_t index)const;
	const T& front()const;
	const T& back()const;
	const T* data() const noexcept;
	T& at(size_t index);
	T& front();
	T& back();
	T* data() noexcept;
	void assign (size_t n, const T& val);
	void insert(size_t pos,T val,size_t n=1);
	void push_back(const T& val);
	void pop_back();
	T* erase (T* position);
	T* erase (T* first, T* last);
	void swap(Vector& x);
	void clear();
	
private:
	T* m_vector;
	size_t m_size;
	size_t m_capacity;
};
template  <typename T>
Vector<T>::Vector():m_vector(NULL),m_size(0),m_capacity(0)
{
}
template  <typename T>
Vector<T>::Vector(size_t n, const T& val):m_vector(new T[n]),m_size(n),m_capacity(n)
{
	for(size_t i = 0; i < n ; i++)
	{
		m_vector[i] = val;
	}
}
template  <typename T>
Vector<T>::Vector(const Vector<T>& vec):m_vector(new T[vec.size()]),m_size(vec.size()),m_capacity(vec.capacity())
{
	for(size_t i = 0; i<m_size ; i++)
	{
		m_vector[i] = vec[i];
	}
}
template  <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if(&other!=this)
	{
		if(m_capacity >= other.m_size)
		{
			for(size_t i = 0; i < m_size; ++i)
			{
				m_vector[i].~T();
			}
			for(size_t i = 0; i < other.m_size; ++i)
			{
				m_vector[i] = other.m_vector[i];
			}
		}
		else
		{
			reserve(other.m_size);
			for(size_t i = 0; i < other.m_size; ++i)
				m_vector[i] = other.m_vector[i];
			//m_capacity = other.m_size;
		}
		m_size = other.m_size;
	}
	return *this;
}
template  <typename T>
Vector<T>::~Vector()
{
	delete [] m_vector;
}
template  <typename T>
const T& Vector<T>::operator[](size_t index)const
{
	return m_vector[index];
}
template  <typename T>
const T& Vector<T>::at(size_t index)const
{
	if(index>m_size)
	{
		throw std::out_of_range("index out of range");
	}
	return m_vector[index];
}
template  <typename T>
const T& Vector<T>::front()const
{
	return m_vector[0];
}
template  <typename T>
const T& Vector<T>::back()const
{
	return m_vector[m_size-1];
}
template  <typename T>
const T* Vector<T>::data()const noexcept
{
	return m_vector;
}
template  <typename T>
T& Vector<T>::operator[](size_t index)
{
	return m_vector[index];
}
template  <typename T>
T& Vector<T>::at(size_t index)
{
	if(index>m_size)
	{
		throw std::out_of_range("index out of range");
	}
	return m_vector[index];
}
template  <typename T>
T& Vector<T>::front()
{
	return m_vector[0];
}
template  <typename T>
T& Vector<T>::back()
{
	return m_vector[m_size-1];
}
template  <typename T>
T* Vector<T>::data() noexcept
{
	return m_vector;
}
template  <typename T>
inline size_t Vector<T>::size()const
{
	return m_size;
}
template  <typename T>
inline size_t Vector<T>::max_size()const
{
	return SIZE_MAX;
}
template  <typename T>
inline void Vector<T>::resize(size_t n,const T& val)
{
	size_t len=m_size;
	if (n<m_size)
	{
		for(size_t i=0; i<len-n; i++)
		{
			pop_back();
			m_vector[m_size-i].~T();	
		}
	}
	if(n>m_size)
	{
		for(size_t i=0;i<n-len;i++)
		{
			push_back(val);	
		}
	}
	m_size=n;
}
template  <typename T> 
inline size_t Vector<T>::capacity()const
{
	return m_capacity;
}
template  <typename T>
inline bool Vector<T>::empty()const
{
	return (m_size == 0);
}

template  <typename T>
inline void Vector<T>::reserve(size_t n)
{
	if(n > m_capacity)
	{
		T* tmp = new T[n];
		for(size_t i = 0; i < m_size; i++)
		{
			 tmp[i] = m_vector[i];
		}
		if(m_vector != NULL)
		{
			for(size_t i = 0; i < m_size; ++i)
				m_vector[i].~T();
			delete[] m_vector;
		}
		m_vector = tmp;
		m_capacity = n;
	}
}
template<typename T>
void Vector<T>::push_back(const T& val)
{	
	size_t tmp = m_size>0?m_size:0;
	insert(tmp,val);
}
template<typename T>
void Vector<T>::pop_back()
{
	m_vector[m_size-1].~T();
	m_size-=1;
}
template<typename T>
void Vector<T>::assign(size_t n, const T& val)
{
	if(n<m_size)
	{
		for(size_t i=m_size;i<n;i++)
		{
			m_vector[i].~T();
		}
	}
	else
	{
		reserve(n);
	}
	
	for(size_t i=0; i<n; i++)
	{
		m_vector[i] = val;
	}
	m_size=n;
	m_capacity=n;
}
template<typename T>
void Vector<T>::insert(size_t pos,T val,size_t n)
{
	if(pos>m_size)
	{
		throw std::out_of_range("index out of range");
	}
	T* tmp = new T[m_size+n];
	m_capacity += n;
	for(size_t i = 0; i< pos; i++)
	{
		tmp[i] = m_vector[i];
	}
	for(size_t i = pos; i< pos+n; i++)
	{
		tmp[i] = val;
	}
	m_size = m_size+n;
	for(size_t i = pos + n; i< m_size; i++)
	{
		tmp[i] = m_vector[i-n];
	}
	if(m_vector != NULL)
	{
		for(size_t i = 0; i < m_size; ++i)
			m_vector[i].~T();
		delete[] m_vector;
	}
	m_vector = tmp;
	
}
template<typename T>
void Vector<T>::swap(Vector& x)
{
	Vector y(x);
	x=*this;
	*this=y;
}
template<typename T>
void Vector<T>::clear()
{
	for(size_t i=0;i<m_size;i++)
		m_vector[i].~T();
	m_size=0;
}
template<typename T>
inline Vector<T> Vector<T>::operator+(const Vector<T>& v)
{
	Vector<T> v1=*this;
	for(size_t i=0;i<v.size();i++)
	{
		v1.push_back(v[i]);
	}
	return v1;
}
template<typename T>
inline Vector<T>& Vector<T>::operator+=(const Vector& v)
{
	for(size_t i=0;i<v.size();i++)
	{
		push_back(v[i]);
	}
	return *this;
}
template<typename T>
inline std::ostream& operator << (std::ostream& cout,const Vector<T>& v)
{
	cout<<"size: "<<v.size()<<"\ncapacity: "<<v.capacity()<<"\n";
	for(size_t i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\t";
	}
	cout<<std::endl;

	return cout;
}
template<typename T>
inline T* Vector<T>::erase(T* pos)
{

	size_t i=0;
	while(true)
	{
		if(m_vector+i==pos)
		{
			m_vector[i].~T();
			break;
		}
		i++;
	}
	for(;i<m_size;i++)
	{
		m_vector[i] = m_vector[i+1];
	}
	m_size--;
	return m_vector;
}

template<typename T>
inline T* Vector<T>::erase(T* first, T* last)
{
	for(T* i = first; i < last; i++)
		erase(i);
	return m_vector;
}

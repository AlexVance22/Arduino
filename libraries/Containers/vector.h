#ifndef VECTOR_H
#define VECTOR_H

#include <string.h>


template<typename Ty>
class vector
{
private:
	Ty* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;


	void reallocate(size_t capacity)
	{
		Ty* data = new Ty[capacity];
		memcpy(data, m_data, min(m_capacity, capacity));
		delete[] m_data;
		m_data = data;
	}


public:
	vector() { reallocate(4); }
	~vector() { delete[] m_data; }

	void reserve(size_t size)
	{
		reallocate(size);
	}

	void push_back(const Ty& item)
	{
		if (++m_size > m_capacity)
			reallocate(m_capacity * 1.5);

		m_data[m_size] = item;
	}

	const Ty& operator[](size_t index) const { return m_data[index]; }

	Ty& operator[](size_t index) { return m_data[index]; }
};

#endif
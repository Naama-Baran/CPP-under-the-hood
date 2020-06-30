#ifndef __ZOO_H__
#define __ZOO_H__
#include "animal.h"
#include "stdlib.h"
#include "stdio.h"
#include <vector>

class Zoo
{
public:
	Zoo(){};
	~Zoo();
	
	void addAnimal(Animal *a);
	void print();
	
private:
	std::vector<Animal*> m_zoo;
};

inline Zoo::~Zoo()
{
	/*std::vector<Animal*>::iterator it = m_zoo.begin();
	for (; it != m_zoo.end(); ++it) 
	{
		delete *it;
	}*/
}

inline void Zoo::addAnimal(Animal *a)
{
	m_zoo.push_back(a);
}

inline void Zoo::print()
{
	std::vector<Animal*>::iterator it;
	for (it = m_zoo.begin();it != m_zoo.end(); it++)
	{
		std::cout << **it << std::endl;
	}
}
#endif
#ifndef __BIRDS_H__
#define __BIRDS_H__
#pragma once
#include "animal.h"

class Birds: public Animal
{
public:
	Birds(const std::string& name):Animal(name){};
	
	virtual unsigned short getTypicalHight() const =0;
	virtual unsigned short getWingSpan() const =0;	

protected:	
	/*virtual*/ std::ostream& print(std::ostream& os) const;

};
inline std::ostream& Birds::print(std::ostream& os)const
{
	Animal::print(os)<< "typical hight: " <<getTypicalHight() << std::endl;
	os<< "wing span: " <<getWingSpan() << std::endl;
	return os;
}
#endif
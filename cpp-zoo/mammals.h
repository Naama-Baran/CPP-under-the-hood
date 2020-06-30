#ifndef __MAMMALS_H__
#define __MAMMALS_H__
#pragma once
#include "animal.h"

class Mammal: public Animal, public IMammals
{
public:
	Mammal(const std::string& name):Animal(name){};
	
	virtual unsigned short getPregnancyDuration() const =0;
	virtual unsigned short getNumberOfYoungBorn() const =0;		
	
protected:
	/*virtual*/ std::ostream& print(std::ostream& os) const;
};
inline std::ostream& Mammal::print(std::ostream& os)const
{
	Animal::print(os)<< "pregnancy duration: " <<getPregnancyDuration() << std::endl;
	os<< "number of young born: " <<getNumberOfYoungBorn() << std::endl;
	return os;
}
#endif

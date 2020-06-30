#ifndef __FISH_H__
#define __FISH_H__
#pragma once
#include "animal.h"

class FishAndSeaCreatures: public Animal
{
public:
	FishAndSeaCreatures(const std::string& name):Animal(name){};
	
	virtual unsigned short getLowestDepth() const =0;

protected:	
	/*virtual*/ std::ostream& print(std::ostream& os) const;
	
};
inline std::ostream& FishAndSeaCreatures::print(std::ostream& os)const
{
	Animal::print(os)<< "lowest depth: " << getLowestDepth() << std::endl;
	return os;
}
#endif
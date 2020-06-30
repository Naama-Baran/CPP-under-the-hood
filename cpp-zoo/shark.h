#ifndef __SHARK_H__
#define __SHARK_H__
#pragma once
#include "fish.h"
#include <vector>
class Shark: public FishAndSeaCreatures
{
public:
	Shark(const std::string& name):FishAndSeaCreatures(name){};
			
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ unsigned short getLifeExpectancy() const;
	/*virtual*/ const std::vector<EContinant>& getContinants() const;
	/*virtual*/ const std::vector<EFood>& getFoodType() const;
	/*virtual*/ unsigned short getSpeed() const;
	/*virtual*/ unsigned short getLowestDepth() const;
	
private:
	static const std::string m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<EContinant> m_continants;
	static const std::vector<EFood> m_foodType;
	static const unsigned short m_speed;
	static const unsigned short m_lowestDepth;
};
inline const std::string& Shark::getSpecies() const
{
	return m_species;
}
inline unsigned short Shark::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline unsigned short Shark::getLowestDepth()const
{
	return m_lowestDepth;
}
inline unsigned short Shark::getSpeed()const
{
	return m_speed;
}
inline const std::vector<EContinant>& Shark::getContinants()const
{
	return m_continants;
}
inline const std::vector<EFood>& Shark::getFoodType()const
{
	return m_foodType;
}
#endif
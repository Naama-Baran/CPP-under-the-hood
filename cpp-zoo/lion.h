#ifndef __LION_H__
#define __LION_H__
#pragma once
#include "mammals.h"
#include <vector>

class Lion: public Mammal
{
public:
	Lion(const std::string& name):Mammal(name){};
	
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ unsigned short getLifeExpectancy() const;
	/*virtual*/ const std::vector<EContinant>& getContinants() const;
	/*virtual*/ const std::vector<EFood>& getFoodType() const;
	/*virtual*/ unsigned short getSpeed() const;
	/*virtual*/ unsigned short getPregnancyDuration() const;
	/*virtual*/ unsigned short getNumberOfYoungBorn() const;
	
private:
	static const std::string m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<EContinant> m_continants;
	static const std::vector<EFood> m_foodType;
	static const unsigned short m_speed;
	static const unsigned short m_pregnancyDuration;
	static const unsigned short m_numberOfYoungBorn;
};

inline const std::string& Lion::getSpecies() const
{
	return m_species;
}
inline unsigned short Lion::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline const std::vector<EContinant>& Lion::getContinants()const
{
	return m_continants;
}
inline unsigned short Lion::getPregnancyDuration()const
{
	return m_pregnancyDuration;
}
inline unsigned short Lion::getNumberOfYoungBorn()const
{
	return m_numberOfYoungBorn;
}
inline unsigned short Lion::getSpeed()const
{
	return m_speed;
}
inline const std::vector<EFood>& Lion::getFoodType()const
{
	return m_foodType;
}
#endif

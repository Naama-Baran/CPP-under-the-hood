#ifndef __GOOSE_H__
#define __GOOSE_H__
#pragma once
#include "birds.h"
#include <vector>

class Goose: public Birds
{
public:
	Goose(const std::string& name):Birds(name){};
	
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ unsigned short getLifeExpectancy() const;
	/*virtual*/ const std::vector<EContinant>& getContinants() const;
	/*virtual*/ const std::vector<EFood>& getFoodType() const;
	/*virtual*/ unsigned short getSpeed() const;
	/*virtual*/ unsigned short getTypicalHight() const;
	/*virtual*/ unsigned short getWingSpan() const;
	
private:
	static const std::string m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<EContinant> m_continants;
	static const std::vector<EFood> m_foodType;
	static const unsigned short m_speed;
	static const unsigned short m_typicalHight;
	static const unsigned short m_wingSpan;
};

inline const std::string& Goose::getSpecies() const
{
	return m_species;
}
inline unsigned short Goose::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline const std::vector<EContinant>& Goose::getContinants()const
{
	return m_continants;
}
inline unsigned short Goose::getTypicalHight()const
{
	return m_typicalHight;
}
inline unsigned short Goose::getWingSpan()const
{
	return m_wingSpan;
}
inline unsigned short Goose::getSpeed()const
{
	return m_speed;
}
inline const std::vector<EFood>& Goose::getFoodType()const
{
	return m_foodType;
}
#endif
#ifndef  __WHALE_H__
#define __WHALE_H__

#pragma once
#include "fish.h"
#include "imammals.h"
class Whale :public FishAndSeaCreatures, public IMammals
{
public:
    Whale(const std::string& name):FishAndSeaCreatures(name){};
	
	/*virtual*/ std::ostream& print(std::ostream& os)const;
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ unsigned short getLifeExpectancy() const;
	/*virtual*/ const std::vector<EContinant>& getContinants() const;
	/*virtual*/ const std::vector<EFood>& getFoodType() const;
	/*virtual*/ unsigned short getSpeed() const;
	/*virtual*/ unsigned short getLowestDepth() const;
	/*virtual*/ unsigned short getPregnancyDuration() const;
	/*virtual*/ unsigned short getNumberOfYoungBorn() const;
	
private:
	static const std::string m_species;
	static const unsigned short m_lifeExpectancy;
	static const std::vector<EContinant> m_continants;
	static const std::vector<EFood> m_foodType;
	static const unsigned short m_speed;
	static const unsigned short m_lowestDepth;
	static const unsigned short m_pregnancyDuration;
	static const unsigned short m_numberOfYoungBorn;
};
inline const std::string& Whale::getSpecies() const
{
	return m_species;
}
inline unsigned short Whale::getLifeExpectancy() const
{
	return m_lifeExpectancy;
}
inline const std::vector<EContinant>& Whale::getContinants()const
{
	return m_continants;
}
inline unsigned short Whale::getLowestDepth()const
{
	return m_lowestDepth;
}
inline unsigned short Whale::getSpeed()const
{
	return m_speed;
}
inline const std::vector<EFood>& Whale::getFoodType()const
{
	return m_foodType;
}
inline unsigned short Whale::getPregnancyDuration()const
{
	return m_pregnancyDuration;
}
inline unsigned short Whale::getNumberOfYoungBorn()const
{
	return m_numberOfYoungBorn;
}
inline std::ostream& Whale::print(std::ostream& os) const
{
	FishAndSeaCreatures::print(os);
	os<< "pregnancy duration: " <<m_pregnancyDuration << std::endl;
	os<< "number of young born: " <<m_numberOfYoungBorn << std::endl;
	return os;
}

#endif
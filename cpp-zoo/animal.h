#ifndef ANIMAL_H
#define ANIMAL_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
typedef enum EContinant
{
	E_AMERICA,
	E_ASIA,
	E_EUROPE,
	E_AUSTRALIA,
	E_ANTARTICA,
	E_AFRICA
}EContinant;
static const std::string continant[6] = { "America", "Asia", "Europ", "Australia", "Antartica", "Africa" };
typedef enum EFood
{
	E_MILK,
	E_MEET,
	E_GRASS,
	E_VEGTABLES,
	E_BIRDS,
	E_FISH
}EFood;
static const std::string food[7] = { "Milk", "Meet", "Grass", "Veg.", "Birds", "Worms", "fish" };
class Animal
{
public:	
	Animal(const std::string& name):m_name(name){};
	virtual ~Animal(){};
	
	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
	virtual const std::string& getSpecies() const =0;
	virtual unsigned short getLifeExpectancy() const =0;
	virtual const std::vector<EContinant>& getContinants() const =0;
	virtual const std::vector<EFood>& getFoodType() const =0;
	virtual unsigned short getSpeed() const =0;
	
protected:
	virtual std::ostream& print(std::ostream& os) const;
	
private:
	const std::string m_name;
};

inline std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
	animal.print(os);
	return os;
}
inline std::ostream& Animal::print(std::ostream& os) const
{
	std::vector <EContinant> tmp1 = getContinants();
	std::vector<EFood> tmp2 = getFoodType();
	
	os << "Name: " << m_name << std::endl;
	os<< "species: " << getSpecies() << std::endl;
	os<< "life expectancy: " <<  getLifeExpectancy() << std::endl;
	os<< "continants:";
	for (std::vector <EContinant>::iterator it = tmp1.begin(); it != tmp1.end(); it++)
	{
		os<< continant[*it] << " ";
	}
	os<< std::endl;
	os<< "food type:";
	for (std::vector <EFood>::iterator it = tmp2.begin(); it != tmp2.end(); it++)
	{
		os << food[*it] << " ";
	}
	os<< std::endl;
	os<< "get speed: " << getSpeed()<< std::endl;
	return os;
}


#endif
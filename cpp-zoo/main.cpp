
#include <iostream>
#include <string>
#include "stdlib.h"
#include "stdio.h"

#include "zoo.h"
#include "goose.h"
#include "lion.h"
#include "snowy_owl.h"
#include "shark.h"
#include "whale.h"

int main()
{
	Zoo zoo;
	Lion lion1("Simba");
	Lion lion2("Musafa");
	Owl owl("Hedwig");
	Shark shark("Jaws");
	Goose goose1("Akka");
	Goose goose2("Morten");
	Whale whale("Jeem");
	zoo.addAnimal(&lion1);
	zoo.addAnimal(&lion2);
	zoo.addAnimal(&goose1);
	zoo.addAnimal(&goose2);
	zoo.addAnimal(&owl);
	zoo.addAnimal(&shark);
	zoo.addAnimal(&whale);
	zoo.print();
	
	return 0;
}

	
	


#include "cpp2c_inheritance_defs.h"

void CTOR__PHYSICALBOX__3DOUBLE(PhysicalBox* const this, double l, double w, double h)
{
	CTOR__BOX__3DOUBLE(&(this->box),l,w,h);
	this->material.material = OTHER;
	printf("Material created, set to %s\n", "Other");
	PHYSICALBOX__printp(this);
	
}

void CTOR__PHYSICALBOX__3DOUBLE__MATERIAL(PhysicalBox* const this, double l, double w, double h, MATERIALS__Types m)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	CTOR__BOX__3DOUBLE(&(this->box),l,w,h);
	this->material.material = m;
	printf("Material created, set to %s\n", names[this->material.material]);
	PHYSICALBOX__printp(this);
}

void CTOR__PHYSICALBOX__MATERIAL(PhysicalBox* const this, MATERIALS__Types m)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	CTOR__BOX__DOUBLE(&(this->box),1);
	this->material.material = m;
	printf("Material created, set to %s\n", names[this->material.material]);
	PHYSICALBOX__printp(this);	
}

void PHYSICALBOX__printp(const PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox, made of %s; ", names[this->material.material]);
	BOX__print(&(this->box));
}

void DTOR__PHYSICALBOX(PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box.length, this->box.width, this->box.height, names[this->material.material]);
    DTOR__BOX(&(this->box));
}
void WEIGHTBOX__printw(WeightBox* const this)
{
    printf("WeightBox, weight: %f; ", this->weight);
    BOX__print(&(this->box));
}
void CTOR__WEIGHTBOX__4DOUBLE(WeightBox* const this ,double l, double w, double h, double wgt)
{
	CTOR__BOX__3DOUBLE(&(this->box),l,w,h);
	this->weight=wgt;
	WEIGHTBOX__printw(this);
}
void COPY__CTOR__WEIGHTBOX(WeightBox* const this ,const WeightBox* other)
{
	this->weight=other->weight;
	CTOR__BOX__DOUBLE(&(this->box),1);
    WEIGHTBOX__printw(this);
}

void DTOR__WEIGHTBOX(WeightBox* const this )
{
    printf("Destructing WeightBox; ");
    WEIGHTBOX__printw(this);
    DTOR__BOX(&(this->box));
}  

WeightBox* WEIGHTBOX__OPERATOR__EQ(WeightBox* const this ,const WeightBox* other)
{
	this->weight=other->weight;
	return this;
}  




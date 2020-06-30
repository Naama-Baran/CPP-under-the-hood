
#include "cpp2c_encapsulation_defs.h"

const char* SHELF_message = "The total volume held on the shelf is";
const char SHELF_DEF_MSG[] = "The total volume held on the shelf is";
void CTOR__BOX__DOUBLE(Box* const this, double dim)
{
	this->length=dim;
	this->width=dim;
	this->height=dim;
	BOX__print(this);
}

void CTOR__BOX__3DOUBLE(Box* const this, double l, double w, double h)
{
	this->length=l;
	this->width=w;
	this->height=h;
	BOX__print(this);
}

void DTOR__BOX(Box* const this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

/*double BOX__getWidth(const Box* const this)
{
    return this->width;
}
double BOX__getLength(const Box* const this)
{
    return this->length;
}

double BOX__getHeight(const Box* const this)
{
    return this->height;
}

double BOX__getVolume(const Box* const this)
{
    return this->width * this->length * this->height;
}*/

void BOX__print(const Box* const this)
{
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height); 
}

Box* BOX__OPERATOR__ME(Box* const this, double mult)
{
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;

    return this;
}


/*Box OPERATOR__M__BD(const Box* box, double mult)
{
    Box ret = *box;
    BOX__OPERATOR__ME(&ret, mult);
    return ret;
}
/*{
    Box *ret = malloc(sizeof(Box));
    *ret = *box
    BOX__OPERATOR*=(ret, mult);
    return *ret;
}*/
/*
Box OPERATOR__M__DB(double mult, const Box* box)
{
    return OPERATOR__M__BD(box, mult);
}*/

/*bool OPERATOR__EQ(const Box* lhs, const Box* rhs)
{
    return BOX__getWidth(lhs) == BOX__getWidth(rhs) && BOX__getHeight(lhs) == BOX__getHeight(rhs) && BOX__getLength(lhs) == BOX__getLength(rhs);
}

bool OPERATOR__NE(const Box* lhs, const Box* rhs)
{
    return !OPERATOR__EQ(lhs, rhs);
}
*/
void CTOR__DEFAULT__SHELF(Shelf* this)
{
	for(int i=0;i<3;i++)
	{
		Box b;
		CTOR__BOX__DOUBLE(&b,1);
		this->boxes[i] = b;
	}
}
void DTOR__SHELF(Shelf* this)
{
	for(int i=0;i<3;i++)
		DTOR__BOX(&(this->boxes[i]));
}
void SHELF__setBox(Shelf* this, int index, const Box* dims)
{
    this->boxes[index] = *dims;
}
double SHELF__getVolume(Shelf* this)
{
    double vol = 0;
    for (size_t i = 0; i < 3; ++i)
        vol += this->boxes[i].width * this->boxes[i].length * this->boxes[i].height;

    return vol;
}

/*Box SHELF__getBox(Shelf* s, int index)
{
	return s->boxes[index];
}*/
void SHELF__print(Shelf* this)
{
    printf("%s %f\n", SHELF_message, SHELF__getVolume(this));
}
    
/*int STATIC__SHELF__getNumBoxes()
{
    return SHELF_NUM_BOXES;
}
void STATIC__SHELF__setSHELF_message(const char* msg)
{
    SHELF_message = msg;
}*/


//// Box ////////////
/*
//// Box ////////////

Box::Box(double dim) 
:   length(dim)
,   width(dim)
,   height(dim) 
{ 
    print();
}

Box::Box(double l, double w, double h) 
:   length(l)
,   width(w)
,   height(h) 
{ 
    print(); 
}

Box::~Box()
{
    std::printf("Box destructor, %f x %f x %f\n", width, height, length);
}

Box& Box::operator*=(double mult)
{
    width *= mult;
    height *= mult;
    length *= mult;

    return *this;
}

void Box::print() const
{
    printf("Box: %f x %f x %f\n", length, width, height); 
}


//// Shelf ////////////

const char* const Shelf::SHELF_DEF_MSG = "The total volume held on the shelf is";
const char* Shelf::SHELF_message = Shelf::SHELF_DEF_MSG;

void Shelf::setBox(int index, const Box& dims)
{
    boxes[index] = dims;
}

double Shelf::getVolume() const
{
    double vol = 0;
    for (size_t i = 0; i < NUM_BOXES; ++i)
        vol += boxes[i].getVolume();

    return vol;
}

void Shelf::print() const
{
    std::printf("%s %f\n", SHELF_message, getVolume());
}

*/

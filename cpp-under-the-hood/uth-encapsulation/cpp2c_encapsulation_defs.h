#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
//#define SHELF_NUM_BOXES 3

//const char* SHELF_message;
//const char[] SHELF_DEF_MSG;

typedef struct Box 
{
	double length;
	double width;
	double height;
}Box;

void CTOR__BOX__DOUBLE(Box* const this, double dim);
void CTOR__BOX__3DOUBLE(Box* const this, double l, double w, double h);
void DTOR__BOX(Box* b);

/*double BOX__getWidth(const Box* const this);
double BOX__getLength(const Box* const this);
double BOX__getHeight(const Box* const this);
double BOX__getVolume(const Box* const this);*/

Box* BOX__OPERATOR__ME(Box* const this, double mult);

void BOX__print(const Box* const this);

/*Box OPERATOR__M__BD(const Box* box, double mult);
Box OPERATOR__M__DB(double mult, const Box* box);
bool OPERATOR__EQ(const Box* lhs, const Box* rhs);
bool OPERATOR__NE(const Box* lhs, const Box* rhs);*/
//// Box ////////////
/*
class Box
{
public:
    Box(double dim = 1);
    Box(double l, double w, double h);
    ~Box();

    double getWidth() const;
    double getLength() const;
    double getHeight() const;

    double getVolume() const;
    
    Box& operator*=(double mult);

protected:
    void print() const;

private:    
    double length;
    double width;
    double height;
};

Box operator*(const Box& box, double mult);
Box operator*(double mult, const Box& box);
bool operator==(const Box& lhs, const Box& rhs);
bool operator!=(const Box& lhs, const Box& rhs);


//// Box Defs ////////////

inline double Box::getWidth() const
{
    return width;
}

inline double Box::getLength() const
{
    return length;
}

inline double Box::getHeight() const
{
    return height;
}

inline double Box::getVolume() const
{
    return width * length * height;
}

inline Box operator*(const Box& box, double mult)
{
    Box ret = box;
    ret *= mult;
    return ret;
}

inline Box operator*(double mult, const Box& box)
{
    return box * mult;
}

inline bool operator==(const Box& lhs, const Box& rhs)
{
    return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
}

inline bool operator!=(const Box& lhs, const Box&rhs)
{
    return !(lhs == rhs);
}

*/
typedef struct Shelf 
{
	Box boxes[3];
}Shelf;

/*const char* const SHELF_DEF_MSG;
const char* SHELF_message;*/
void CTOR__DEFAULT__SHELF(Shelf* this);
void DTOR__SHELF(Shelf* this);
void SHELF__setBox(Shelf* this, int index, const Box* dims);
double SHELF__getVolume(Shelf* this);
//Box SHELF__getBox(Shelf* this, int index);
void SHELF__print(Shelf* this);
    
//int STATIC__SHELF__getNumBoxes();
//void STATIC__SHELF__setSHELF_message(const char* msg);
/*
//// Shelf ////////////

class Shelf
{
public:
    void setBox(int index, const Box& dims);
    double getVolume() const;
    Box& getBox(int index);
    void print() const;
    
    static int getNumBoxes();
    static void setSHELF_message(const char* msg);
    
private:
    static const unsigned int NUM_BOXES = 3;
    static const char* const SHELF_DEF_MSG;
    static const char* SHELF_message;

    Box boxes[NUM_BOXES];
};

//// Shelf Defs ////////////

inline Box& Shelf::getBox(int index)
{
    return boxes[index];
}

inline int Shelf::getNumBoxes()
{
    return NUM_BOXES;
}

inline void Shelf::setSHELF_message(const char* msg)
{
    SHELF_message = msg;
}
*/
#endif // __CPP2C_ENCAPSULATION_DEFS_H__


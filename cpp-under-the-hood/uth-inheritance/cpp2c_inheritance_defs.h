#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include "cpp2c_encapsulation_defs.h"
typedef enum MATERIALS__Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER  
}MATERIALS__Types;

typedef struct Materials
{
	char a;
}Materials;

typedef struct Material_t
{
	MATERIALS__Types material;
}Material_t;

typedef struct PhysicalBox
{
	Box box;
	Material_t material;
}PhysicalBox;

void CTOR__PHYSICALBOX__3DOUBLE(PhysicalBox* const this, double l, double w, double h);
void CTOR__PHYSICALBOX__3DOUBLE__MATERIAL(PhysicalBox* const this, double l, double w, double h, MATERIALS__Types m);
void CTOR__PHYSICALBOX__MATERIAL(PhysicalBox* const this, MATERIALS__Types m);
void PHYSICALBOX__printp(const PhysicalBox* const this);
void DTOR__PHYSICALBOX(PhysicalBox* const this);

typedef struct WeightBox
{
	Box box;
	double weight;
}WeightBox;

void WEIGHTBOX__printw(WeightBox* const this);
void CTOR__WEIGHTBOX__4DOUBLE(WeightBox* const this ,double l, double w, double h, double wgt);
void COPY__CTOR__WEIGHTBOX(WeightBox* const this ,const WeightBox* other);
void DTOR__WEIGHTBOX(WeightBox* const this );
WeightBox* WEIGHTBOX__OPERATOR__EQ(WeightBox* const this ,const WeightBox* other);

//// Materials ////////////
/*
struct Materials
{
    enum Types
    {
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
    };

    static const char* getName(Types type)
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        return names[type];
    }
};

struct Material_t: public Materials
{
    Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }
    const char* name() const { return getName(material); }

    Types material;
};


//// PhysicalBox ////////////

class PhysicalBox: public Box
{
public:
    PhysicalBox(double l, double w, double h);
    PhysicalBox(double l, double w, double h, Materials::Types t);
    PhysicalBox(Materials::Types t);
    ~PhysicalBox();

    Materials::Types getMaterial() const;
    void printp() const;

private:
    Material_t material;
};

bool operator==(const PhysicalBox&, const PhysicalBox&);
bool operator!=(const PhysicalBox&, const PhysicalBox&);

//// PhysicalBox Defs ////////////

inline Materials::Types PhysicalBox::getMaterial() const
{
    return material.material;
}

inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return !(lhs == rhs);
}

//// WeightBox ////////////

class WeightBox: public Box
{
public:
    WeightBox(double l, double w, double h, double wgt = 0.0);
    WeightBox(const WeightBox& other);
    ~WeightBox();

    WeightBox& operator=(const WeightBox& other);

    double getWeight() const;
    void printw() const;

private:
    double weight;
};

bool operator==(const WeightBox&, const WeightBox&);
bool operator!=(const WeightBox&, const WeightBox&);

//// WeightBox Defs ////////////

inline double WeightBox::getWeight() const
{
    return weight;
}

inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}

inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
{
    return !(lhs == rhs);
}







*/

#endif // __CPP2C_INHERITANCE_DEFS_H__



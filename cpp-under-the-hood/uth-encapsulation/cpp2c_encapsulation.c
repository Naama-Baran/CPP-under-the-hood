
#include "cpp2c_encapsulation_defs.h"
extern const char* SHELF_message;
extern const char SHELF_DEF_MSG[];
static Box largeBox;

static Box Sbox99;
static bool flag_box99;

void GthisFunc()
{
    printf("\n--- thisFunc() ---\n\n"); 

    if(flag_box99==0)
    	CTOR__BOX__3DOUBLE(&Sbox99, 99, 99, 99);
    flag_box99 = 1;
    BOX__OPERATOR__ME(&Sbox99, 10);
}

static Box Sbox88;
static bool flag_box88;

void GthatFunc()
{
    printf("\n--- thatFunc() ---\n\n"); 
    
    if(flag_box88==0)
    	CTOR__BOX__3DOUBLE(&Sbox88, 88, 88, 88);
    flag_box88 = 1;
    BOX__OPERATOR__ME(&Sbox88, 10);
}

void GdoBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1;
    Box b2;
    CTOR__BOX__DOUBLE(&b1,3);
    
    CTOR__BOX__3DOUBLE(&b2, 4, 5, 6);
    printf("b1 volume: %f\n", b1.height*b1.length*b1.width);
    printf("b2 volume: %f\n", b2.height*b2.length*b2.width);

    BOX__OPERATOR__ME(&b1, 1.5);
    BOX__OPERATOR__ME(&b2 , 0.5);

    printf("b1 volume: %f\n", b1.height*b1.length*b1.width);
    printf("b2 volume: %f\n", b2.height*b2.length*b2.width);

    Box b3 = b2;
    BOX__OPERATOR__ME(&b2 , 3);
    Box b4 = b2;
    printf("b3 %s b4\n", (b3.height==b4.height)&&(b3.length==b4.length)&&(b3.width==b4.width) ? "equals" : "does not equal");

    BOX__OPERATOR__ME(&b3 , 1.5);
    BOX__OPERATOR__ME(&b4 , 0.5);
 
    printf("Now, b3 %s b4\n", (b3.height==b4.height)&&(b3.length==b4.length)&&(b3.width==b4.width) ? "equals" : "does not equal");
    printf("\n--- End doBoxes() ---\n\n");
    
    DTOR__BOX(&b4);
    DTOR__BOX(&b3);
    DTOR__BOX(&b2);
    DTOR__BOX(&b1);
    
}


void GdoShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox;
    CTOR__BOX__DOUBLE(&aBox ,5);
    Shelf aShelf;
    CTOR__DEFAULT__SHELF(&aShelf);
    SHELF__print(&aShelf);
    aShelf.boxes[1] = largeBox;
    aShelf.boxes[0] = aBox;

    SHELF__print(&aShelf);
    SHELF_message = "This is the total volume on the shelf:";
    SHELF__print(&aShelf);
    SHELF_message = "Shelf's volume:";
    SHELF__print(&aShelf);
    //aShelf.setBox(1, Box(2, 4, 6));
    Box tmp1;
    CTOR__BOX__3DOUBLE(&tmp1 ,2 , 4, 6);
    SHELF__setBox(&aShelf, 1, &tmp1);
    DTOR__BOX(&tmp1);
    //aShelf.setBox(2, 2);
    Box tmp2;
    CTOR__BOX__DOUBLE(&tmp2 ,2);
    SHELF__setBox(&aShelf, 2, &tmp2);
    DTOR__BOX(&tmp2);
    SHELF__print(&aShelf);
    
    printf("\n--- end doShelves() ---\n\n");
    
    DTOR__SHELF(&aShelf);
    DTOR__BOX(&aBox);
}

int main()
{
    CTOR__BOX__3DOUBLE(&largeBox ,10 ,20 ,30);

    printf("\n--- Start main() ---\n\n");
   
    GdoBoxes();
    
    GthisFunc();
    GthisFunc();
    GthisFunc();
    GthatFunc();
    GthatFunc();

    GdoShelves();
    
    printf("\n--- End main() ---\n\n"); 
      
    if(flag_box88!=0)
    	DTOR__BOX(&Sbox88);
    if(flag_box99!=0)
    	DTOR__BOX(&Sbox99);
    DTOR__BOX(&largeBox);
    
    
    return 0;
}


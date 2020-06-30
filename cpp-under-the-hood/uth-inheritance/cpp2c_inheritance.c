
#include "cpp2c_inheritance_defs.h"




void GdoMaterials()
{

    printf("\n--- Start doMaterials() ---\n\n");
    
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    struct MatTest { Materials mat; Material_t mat_t; };
    Materials mat;
    printf("Size of Materials: %lu\n",sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(MATERIALS__Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));
    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest));
    
    Material_t mat1;
    mat1.material = OTHER;
    printf("Material created, set to %s\n", names[mat1.material]);
    
    Material_t mat2;
    mat2.material = METAL;
    printf("Material created, set to %s\n", names[mat2.material]);

    printf("\n--- End doMaterials() ---\n\n");
}

void GdoPhysicalBox()
{
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox pb1;
    CTOR__PHYSICALBOX__3DOUBLE__MATERIAL(&pb1, 8, 6, 4, PLASTIC);
    PhysicalBox pb2;
    CTOR__PHYSICALBOX__MATERIAL(&pb2, WOOD);
    PhysicalBox pb3;
    CTOR__PHYSICALBOX__3DOUBLE(&pb3, 7, 7, 7);
    
    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox pb4 = pb1;
    PHYSICALBOX__printp(&pb4);
    PHYSICALBOX__printp(&pb1);
    printf("pb4 %s pb1\n", (pb4.box.height==pb1.box.height)&&(pb4.box.length==pb1.box.length)&&(pb4.box.width==pb1.box.width)&&(pb4.material.material == pb1.material.material) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    PHYSICALBOX__printp(&pb4);
    PHYSICALBOX__printp(&pb3);
    printf("pb4 %s pb3\n", (pb4.box.height==pb3.box.height)&&(pb4.box.length==pb3.box.length)&&(pb4.box.width==pb3.box.width)&&(pb4.material.material == pb3.material.material)  ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    DTOR__PHYSICALBOX(&pb4);
    DTOR__PHYSICALBOX(&pb3);
    DTOR__PHYSICALBOX(&pb2);
    DTOR__PHYSICALBOX(&pb1);
}

void GdoWeightBox()
{
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox pw1;
    CTOR__WEIGHTBOX__4DOUBLE(&pw1, 8, 6, 4, 25);
    WeightBox pw2;
    CTOR__WEIGHTBOX__4DOUBLE(&pw2,1, 2, 3, 0.0);
    WeightBox pw3;
    CTOR__WEIGHTBOX__4DOUBLE(&pw3,10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox pw4;
    COPY__CTOR__WEIGHTBOX(&pw4, &pw1);
    WEIGHTBOX__printw(&pw4);
    WEIGHTBOX__printw(&pw1);
    printf("pw4 %s pw1\n", (pw4.box.height==pw1.box.height)&&(pw4.box.length==pw1.box.length)&&(pw4.box.width==pw1.box.width)&&(pw4.weight == pw1.weight) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    WEIGHTBOX__OPERATOR__EQ(&pw4, &pw3);
    WEIGHTBOX__printw(&pw4);
    WEIGHTBOX__printw(&pw3);
    printf("pw4 %s pw3\n", (pw4.box.height==pw3.box.height)&&(pw4.box.length==pw3.box.length)&&(pw4.box.width==pw3.box.width)&&(pw4.weight == pw3.weight) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    DTOR__WEIGHTBOX(&pw4);
    DTOR__WEIGHTBOX(&pw3);
    DTOR__WEIGHTBOX(&pw2);
    DTOR__WEIGHTBOX(&pw1);
}





int main()
{
    printf("\n--- Start main() ---\n\n");

    GdoMaterials();

    GdoPhysicalBox();

    GdoWeightBox();

    printf("\n--- End main() ---\n\n");
    
    return 0;

}

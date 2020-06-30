#include "cpp2c_polymorphism_defs.h"
#include "stdio.h"
#include "malloc.h"

extern int next_id;
funcptr Multiplier_vtable[] = 
{
	(funcptr)Multiplier__DTOR, 
	(funcptr)Multiplier__print
};
void GdoPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
    PPF__CTOR__CPCP(&angleBrackets, "<<< ", " >>>");
    PPF__print(&angleBrackets, "Hello World!");
    PPF__print__LC(&angleBrackets,-777, '\0');
    PPF__print__LC(&angleBrackets, 350, '#');
    PPF__print__LC(&angleBrackets, (long int)3.14, '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    PPF__DTOR(&angleBrackets);
}

void GdoPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks;
    PPDF__CTOR(&asterisks, "***** ", " *****");
    PPDF__print__IC(&asterisks,-777,'$');
    PPDF__print__IC(&asterisks, 350, '#');
    PPDF__print__DC(&asterisks, 3.14, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    PPDF__DTOR(&asterisks);
}

void GdoPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    PPC__CTOR(&check);
    PPC__printThisSymbolUsingFunc(&check);
    PPC__printThisSymbolDirectly(&check);
    PPC__printDollarSymbolByCastDirectly(&check);
    PPC__printDollarSymbolByScopeDirectly(&check);
    PPC__printDollarSymbolByCastUsingFunc(&check);
    PPC__printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    PPC__DTOR(&check);
}

void GdoPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes;
    PPFDF__CTOR(&hashes, "### ", " ###");
    PPFDF__print__F(&hashes, -777);
    PPFDF__print__FC(&hashes, 350, '#');
    PPFDF__print__F(&hashes, 3.14);

    PrePostDollarFixer hashes2;
    PPDF__COPY__CTOR(&hashes2, (PrePostDollarFixer*)&hashes);
    PPDF__print__DC(&hashes2, 7.5, '$');
    PPDF__print__IC(&hashes2, 100, '$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    PPDF__DTOR(&hashes2);
    PPFDF__DTOR(&hashes);
}

void GrunAsPrePostFixerRef(const PrePostFixer* const pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

   ((void(*)(const void *const this,long,char))pp->dtf.tf.vptr[2])(pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void GrunAsPrePostDollarFixerRef(const PrePostDollarFixer* const pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    PPDF__print__IC(pp, 123, '$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void GrunAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    //PrePostDollarFixer p;
    //PPDF__COPY__CTOR(&p,&pp);
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    PPDF__print__IC(&pp, 123, '$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
    //PPDF__DTOR(&p);
}

void GrunAsPrePostHashFixerRef(const PrePostHashFixer* const pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    PPHF__print__IC(pp,123, '#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void GdoMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1;
    DTF__CTOR(&(m1.dtf));
    m1.dtf.tf.vptr = Multiplier_vtable;
    m1.times = 3;
    printf("--- Multiplier CTOR: times = %d\n",  m1.times);
    Multiplier m2;
    DTF__CTOR(&(m2.dtf));
    m2.dtf.tf.vptr = Multiplier_vtable;
    m2.times = 5;
    printf("--- Multiplier CTOR: times = %d\n",  m2.times);
    Multiplier m3;
    DTF__COPY__CTOR(&(m3.dtf),&(m1.dtf));
    m3.dtf.tf.vptr = Multiplier_vtable;
    m3.times = 3;
    m3.times = m1.times;
    m3.dtf.tf.vptr = Multiplier_vtable;
    Multiplier m4;
    DTF__COPY__CTOR(&(m4.dtf),&(m2.dtf));
    m4.dtf.tf.vptr = Multiplier_vtable;
    m4.times = 3;
    m4.times = m2.times;
    
    Multiplier__print(&m1, "abc ");
    Multiplier__print(&m2, "abc ");
    Multiplier__print(&m3, "abc ");
    Multiplier__print(&m4, "abc ");

    printf("\n--- start doMultiplier() ---\n\n");
    Multiplier__DTOR(&m4);
    Multiplier__DTOR(&m3);
    Multiplier__DTOR(&m2);
    Multiplier__DTOR(&m1);
}

void GdoFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");
    DefaultTextFormatter d1, d2,d3;
    PrePostDollarFixer ppdf;
    PPDF__CTOR(&ppdf, "!!! ", " !!!");
    DTF__COPY__CTOR(&d1,(DefaultTextFormatter*)&ppdf);
    PPDF__DTOR(&ppdf);    
    Multiplier m;
    DTF__CTOR(&(m.dtf));
    m.dtf.tf.vptr = Multiplier_vtable;
    m.times = 4;
    printf("--- Multiplier CTOR: times = %d\n",  m.times);
    DTF__COPY__CTOR(&d2,(DefaultTextFormatter*)&m);
    Multiplier__DTOR(&m);
    PrePostChecker ppc;
    PPC__CTOR(&ppc);
    DTF__COPY__CTOR(&d3,(DefaultTextFormatter*)&ppc);
    PPC__DTOR(&ppc);
    DefaultTextFormatter formatters[] =
    {
        d1,
        d2,
        d3
    };

    for (int i = 0; i < 3; ++i)
        DTF__print(&formatters[i],"Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
    
    DTF__DTOR(&d3);
    DTF__DTOR(&d2);
    DTF__DTOR(&d1);

}

void GdoFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");
    PrePostDollarFixer ppdf;
    PPDF__CTOR(&ppdf, "!!! ", " !!!");
    Multiplier m;
    DTF__CTOR(&(m.dtf));
    m.dtf.tf.vptr = Multiplier_vtable;
    m.times = 4;
    printf("--- Multiplier CTOR: times = %d\n",  m.times);
    PrePostChecker ppc;
    PPC__CTOR(&ppc);
    
    DefaultTextFormatter* pfmt[] =
    {
        (DefaultTextFormatter*)&(ppdf.ppf.dtf),
        (DefaultTextFormatter*)&(m.dtf),
        (DefaultTextFormatter*)&(ppc.ppfdf.ppdf.ppf.dtf)
    };

    for (int i = 0; i < 3; ++i)
    {     
        ((void(*)(const void * const this , const char* ))pfmt[i]->tf.vptr[1])(pfmt[i], "Hello World!");
    }

    PPC__DTOR(&ppc);
    Multiplier__DTOR(&m);
    PPDF__DTOR(&ppdf);  

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void GdoFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();
    
    for (int i = 0; i < 3; ++i)
        DTF__print(&(formatters[i]), "Hello World!");

    for (int i = 2; i >= 0; --i)
        DTF__DTOR(&(formatters[i]));
        
    free(formatters);    

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    GdoPrePostFixer();
    GdoPrePostDollarFixer();
    GdoPrePostFloatDollarFixer();
    GdoPrePostChecker();

    PrePostHashFixer hfix;
    PPHF__CTOR(&hfix, 4);
    GrunAsPrePostFixerRef((PrePostFixer*)&hfix);
    GrunAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
    PrePostDollarFixer p;
    PPDF__COPY__CTOR(&p,( PrePostDollarFixer*)&hfix);
    GrunAsPrePostDollarFixerObj(p);
    PPDF__DTOR(&p);
    GrunAsPrePostHashFixerRef((PrePostHashFixer*)&hfix);

    GdoMultiplier();

    GdoFormatterArray();
    GdoFormatterPtrs();
    GdoFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");
    PPHF__DTOR(&hfix);
    return 0;
}




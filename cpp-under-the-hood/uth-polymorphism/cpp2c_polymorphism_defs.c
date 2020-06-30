#include "cpp2c_polymorphism_defs.h"
#include "stdio.h"
#include "malloc.h"

extern funcptr* Multiplier_vtable;


funcptr TF_vtable[] = 
{
	(funcptr)TF__DTOR, 
	NULL
};
void TF__DEFAULT__CTOR(TextFormatter* const this)
{
	this->vptr = TF_vtable;
}

void TF__DTOR()
{
}

//// DefaultTextFormatter Defs ////////////

funcptr DTF_vtable[] = 
{
	(funcptr)DTF__DTOR, 
	(funcptr)DTF__print
};

int next_id = 0;

void DTF__CTOR(DefaultTextFormatter* const this)
{
	
	TF__DEFAULT__CTOR(&(this->tf));
	this->tf.vptr = DTF_vtable;
	this->id = next_id++;
	printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void DTF__DTOR(DefaultTextFormatter* const this)
{
	printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
	this->tf.vptr = TF_vtable;
}  

void DTF__COPY__CTOR(DefaultTextFormatter* const this, const DefaultTextFormatter* const other)
{
	
	TF__DEFAULT__CTOR(&(this->tf));
	this->tf.vptr = DTF_vtable;
	this->id = next_id++;
	printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

DefaultTextFormatter* DTF__OPERATOR__EQ(DefaultTextFormatter* const this, const DefaultTextFormatter* const other)
{
	
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}

void DTF__print(const DefaultTextFormatter* const this, const char* text)
{
	printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");  
	printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    DefaultTextFormatter* arr =  malloc(sizeof( DefaultTextFormatter)*3);
    DTF__CTOR(&(arr[0]));
    DTF__CTOR(&(arr[1]));
    DTF__CTOR(&(arr[2]));
    return arr;
}


//// PrePostFixer Defs ////////////

funcptr PPF_vtable[] = 
{
	(funcptr)PPF__DTOR, 
	(funcptr)PPF__print,
	(funcptr)PPF__print__LC,
	(funcptr)PPF__getDefaultSymbol
};

void PPF__CTOR__CPCP(PrePostFixer* const this, const char* prefix, const char* postfix)
{
	
	DTF__CTOR(&(this->dtf));
	this->dtf.tf.vptr = PPF_vtable;
	this->pre = prefix;
	this->post = postfix;
	printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}


void PPF__DTOR(PrePostFixer* const this)
{
	printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	this->dtf.tf.vptr = DTF_vtable;
	DTF__DTOR(&(this->dtf));
}

void PPF__print(const PrePostFixer* const this, const char* text)
{
	printf("%-60s | ", "[PrePostFixer::print(const char*)]");  
	printf("%s%s%s\n", this->pre, text, this->post);
}

char PPF__getDefaultSymbol()
{
    return '\0';
}
/*
void PPF__print_num__L(const PrePostFixer* const this, long num)
{
	printf("%-60s | ", "[PrePostFixer::print_num(long)]");
	printf("%s%ld%s\n", this->pre, num, this->post);
}

void PPF__print_num__LC(const PrePostFixer* const this, long num, char symbol)
{
	printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
	printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
}
*/
void PPF__print__LC(const PrePostFixer* const this, long num, char symbol)
{
	printf("%-60s | ", "[PrePostFixer::print(long, char)]"); 
	printf("-->\n");
    
	if(symbol)
	{    
		printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
		printf("%s%c%ld%s\n", this->pre, symbol, num, this->post); 
	}
	else
	{
		printf("%-60s | ", "[PrePostFixer::print_num(long)]");
		printf("%s%ld%s\n", this->pre, num, this->post);
	}
}
//// PrePostDollarFixer Defs ////////////

funcptr PPDF_vtable[] = 
{
	(funcptr)PPDF__DTOR, 
	(funcptr)PPF__print,
	(funcptr)PPDF__print__LC,
	(funcptr)PPDF__getDefaultSymbol
};
void PPDF__CTOR(PrePostDollarFixer* const this,const char* prefix, const char* postfix)  
{
	PPF__CTOR__CPCP(&(this->ppf),prefix, postfix);
	this->ppf.dtf.tf.vptr = PPDF_vtable;
	printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
}

void PPDF__COPY__CTOR(PrePostDollarFixer* const this, const PrePostDollarFixer* const other)
{

	//----PPF Default Copy Ctor ----:
	
	this->ppf = other->ppf;
	DTF__COPY__CTOR(&(this->ppf.dtf), &(other->ppf.dtf));
	this->ppf.pre = other->ppf.pre;
	this->ppf.post = other->ppf.post;

	//this->ppf =  other->ppf;
	this->ppf.dtf.tf.vptr = PPDF_vtable;
	
	printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
}

void PPDF__DTOR(PrePostDollarFixer* const this)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
    this->ppf.dtf.tf.vptr = PPF_vtable;
    PPF__DTOR(&(this->ppf));
}

void PPDF__print__IC(const PrePostDollarFixer* const this, int num, char symbol)
{
	printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
	printf("-->\n");

	this->ppf.dtf.tf.vptr[2](this,(long int)num, symbol);
}

void PPDF__print__LC(const PrePostDollarFixer* const this, long num, char symbol)
{
	printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
	printf("-->\n");

	PPF__print__LC(&(this->ppf), num, symbol);
}

void PPDF__print__DC(const PrePostDollarFixer* const this, double num, char symbol)
{
	printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
	printf("%s%c%f%s\n", this->ppf.pre,  symbol, num, this->ppf.post);
}

char PPDF__getDefaultSymbol()
{
    return '$';
}

//// PrePostHashFixer Defs ////////////

funcptr PPHF_vtable[] = 
{
	(funcptr)PPHF__DTOR, 
	(funcptr)PPF__print,
	(funcptr)PPHF__print__LC,
	(funcptr)PPHF__getDefaultSymbol
};
void PPHF__CTOR(PrePostHashFixer* const this, int prc)
{
	PPDF__CTOR(&(this->ppdf), "===> ", " <===");
	this->ppdf.ppf.dtf.tf.vptr = PPHF_vtable;
	this->precision = prc;
	printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->ppdf.ppf.pre, this->ppdf.ppf.post, this->precision);   

	//print(9999.9999);
	printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
       printf("%s[%c%.*f]%s\n", this->ppdf.ppf.pre,  '#', this->precision, 9999.9999, this->ppdf.ppf.post);
}

void PPHF__DTOR(PrePostHashFixer* const this)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->ppdf.ppf.pre, this->ppdf.ppf.post);
    this->ppdf.ppf.dtf.tf.vptr = PPDF_vtable;
    PPDF__DTOR(&(this->ppdf));
}
/*void PPHF__print__DC(const PrePostHashFixer* const this, double num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->ppdf.ppf.pre,  symbol, this->precision, num, this->ppdf.ppf.post);
}*/

void PPHF__print__IC(const PrePostHashFixer* const this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

   // print(double(num), symbol);
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->ppdf.ppf.pre,  symbol, this->precision, (double)num, this->ppdf.ppf.post);
}

void PPHF__print__LC(const PrePostHashFixer* const this, long num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]"); 
    printf("-->\n");

    //PPHF__print(double(num), symbol);
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->ppdf.ppf.pre,  symbol, this->precision, (double)num, this->ppdf.ppf.post);
}
char PPHF__getDefaultSymbol()
{
    return '#';
}
//// PrePostFloatDollarFixer Defs ////////////
funcptr PPFDF_vtable[] = 
{
	(funcptr)PPFDF__DTOR, 
	(funcptr)PPF__print,
	(funcptr)PPDF__print__LC,
	(funcptr)PPFDF__getDefaultSymbol
};
void PPFDF__CTOR(PrePostFloatDollarFixer* const this, const char* prefix, const char* postfix)
{
	PPDF__CTOR(&(this->ppdf),prefix, postfix);
	this->ppdf.ppf.dtf.tf.vptr = PPFDF_vtable;
	printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->ppdf.ppf.pre, this->ppdf.ppf.post);
}

void PPFDF__DTOR(PrePostFloatDollarFixer* const this)
{
	printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n",this->ppdf.ppf.pre, this->ppdf.ppf.post);
        this->ppdf.ppf.dtf.tf.vptr = PPDF_vtable;
        PPDF__DTOR(&(this->ppdf));
}

void PPFDF__print__F(const PrePostFloatDollarFixer* const this, float num)
{
	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
	printf("-->\n");

	PPFDF__print__FC(this, num, '@');
}

void PPFDF__print__FC(const PrePostFloatDollarFixer* const this, float num, char symbol) 
{
	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]"); 

	printf("%s%c%.2f%s\n", this->ppdf.ppf.pre, symbol, num, this->ppdf.ppf.post);
}
char PPFDF__getDefaultSymbol()
{
    return '@';
}
//// PrePostChecker Defs ////////////
funcptr PPC_vtable[] = 
{
	(funcptr)PPC__DTOR, 
	(funcptr)PPF__print,
	(funcptr)PPDF__print__LC,
	(funcptr)PPFDF__getDefaultSymbol
};

void PPC__CTOR(PrePostChecker* const this)
{
	PPFDF__CTOR(&(this->ppfdf), "[[[[ ", " ]]]]");
	this->ppfdf.ppdf.ppf.dtf.tf.vptr = PPC_vtable;
	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->ppfdf.ppdf.ppf.pre, this->ppfdf.ppdf.ppf.post);
}    

void PPC__DTOR(PrePostChecker* const this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",this->ppfdf.ppdf.ppf.pre, this->ppfdf.ppdf.ppf.post);
    this->ppfdf.ppdf.ppf.dtf.tf.vptr = PPFDF_vtable;
    PPFDF__DTOR(&(this->ppfdf));
}

void PPC__printThisSymbolUsingFunc(const PrePostChecker* const this) 
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]"); 

    printf("Default symbol is %c\n", ((char(*)())this->ppfdf.ppdf.ppf.dtf.tf.vptr[3])());
}

void PPC__printThisSymbolDirectly(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]"); 

    printf("Default symbol is %c\n", '@');
}

void PPC__printDollarSymbolByCastUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]"); 

    printf("Default symbol is %c\n", ((char(*)())this->ppfdf.ppdf.ppf.dtf.tf.vptr[3])());
}

void PPC__printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]"); 

    printf("Default symbol is %c\n", PPDF__getDefaultSymbol());
}

void PPC__printDollarSymbolByCastDirectly(const PrePostChecker* const this)
{
	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]"); 

    printf("Default symbol is %c\n", '$');
}

void PPC__printDollarSymbolByScopeDirectly(const PrePostChecker* const this)
{
	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", '$');
}


//// Multiplier Defs ////////////
/*funcptr Multiplier_vtable[] = 
{
	(funcptr)Multiplier__DTOR, 
	(funcptr)Multiplier__print
};*/
void Multiplier__CTOR(Multiplier* const this,int t)
{
	
	DTF__CTOR(&(this->dtf));
	this->dtf.tf.vptr = Multiplier_vtable;
	this->times = t;
	printf("--- Multiplier CTOR: times = %d\n",  this->times);
	
}
void Multiplier__DTOR(Multiplier* const this)
{
	printf("--- Multiplier DTOR: times = %d\n", this->times); 
	this->dtf.tf.vptr = DTF_vtable;
	DTF__DTOR(&(this->dtf)); 
}
void Multiplier__print(const Multiplier* const this ,const char* text)
{
    printf("%-60s | ", "[Multiplier::print(const char*)]"); 
    
    for (int i = 0; i < this->times; ++i)
        printf("%s", text);
    printf("\n");
}



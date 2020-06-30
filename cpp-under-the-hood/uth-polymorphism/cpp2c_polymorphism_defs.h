#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__


#include "stdio.h"
#include "string.h"
#include "malloc.h"

typedef void(*funcptr)();
/*
inline void printFunc(const char* fname)
{
    printf("%-60s | ", fname); 
}
*/
//// TextFormatter ////////////
/*
class TextFormatter
{
public:
    virtual ~TextFormatter() { };    
    virtual void print(const char* text) const = 0;
};
*/

typedef struct TextFormatter
{
	funcptr *vptr;
}TextFormatter;
void TF__DEFAULT__CTOR(TextFormatter* const this);
void TF__DTOR();

//// DefaultTextFormatter ////////////
/*
class DefaultTextFormatter: public TextFormatter
{
public:
    DefaultTextFormatter();
    DefaultTextFormatter(const DefaultTextFormatter&);
    DefaultTextFormatter& operator=(const DefaultTextFormatter&);
    ~DefaultTextFormatter();

    virtual void print(const char* text) const;

private: 
    class Ider
    {
    private:
        static int next_id;
    public:
        static int getId() { return next_id++; }
    };

    const int id;
};

DefaultTextFormatter* generateFormatterArray();
*/

typedef struct DefaultTextFormatter
{
	TextFormatter tf;
	int id;
	
}DefaultTextFormatter;

typedef struct Ider
{
	char c;
}Ider;

void DTF__CTOR(DefaultTextFormatter* const this);
void DTF__DTOR(DefaultTextFormatter* const this);
void DTF__COPY__CTOR(DefaultTextFormatter* const this, const DefaultTextFormatter* const other);
DefaultTextFormatter* DTF__OPERATOR__EQ(DefaultTextFormatter* const this, const DefaultTextFormatter* const other);
void DTF__print(const DefaultTextFormatter* const this, const char* text);
DefaultTextFormatter* generateFormatterArray();
//// PrePostFixer ////////////
/*
class PrePostFixer: public DefaultTextFormatter
{
public:
    PrePostFixer(const char* prefix, const char* postfix);
    ~PrePostFixer();

    virtual void print(const char* text) const;
    virtual void print(long num, char symbol = '\0') const;

    virtual char getDefaultSymbol() const;

protected:
    const char* getPrefix() const;
    const char* getPostfix() const;

private:
    void print_num(long num) const;
    void print_num(long num, char symbol) const;

    const char* pre;
    const char* post;
};
*/
typedef struct PrePostFixer
{
	DefaultTextFormatter dtf;
	const char* pre;
    	const char* post;
}PrePostFixer;

void PPF__CTOR__CPCP(PrePostFixer* const this, const char* prefix, const char* postfix);
void PPF__DTOR(PrePostFixer* const this);
void PPF__print(const PrePostFixer* const this, const char* text);
char PPF__getDefaultSymbol();
void PPF__print_num__L(const PrePostFixer* const this, long num);
void PPF__print_num__LC(const PrePostFixer* const this, long num, char symbol);
void PPF__print__LC(const PrePostFixer* const this, long num, char symbol);

//// PrePostFixer Defs ////////////
/*
inline const char* PrePostFixer::getPrefix() const
{
    return pre;
}

inline const char* PrePostFixer::getPostfix() const
{
    return post;
}

inline char PrePostFixer::getDefaultSymbol() const
{
    return '\0';
}

inline void PrePostFixer::print(long num, char symbol) const
{
    printFunc("[PrePostFixer::print(long, char)]");
    printf("-->\n");
    
    if (symbol)    
        print_num(num, symbol);
    else
        print_num(num);
}

inline void PrePostFixer::print_num(long num) const
{
    printFunc("[PrePostFixer::print_num(long)]"); 
    printf("%s%ld%s\n", pre, num, post);
}

inline void PrePostFixer::print_num(long num, char symbol) const
{
    printFunc("[PrePostFixer::print_num(long, char)]"); 
    printf("%s%c%ld%s\n", pre, symbol, num, post);
}
*/

//// PrePostDollarFixer ////////////
/*
class PrePostDollarFixer: public PrePostFixer
{
protected:
    static const char DEFAULT_SYMBOL = '$';

public:
    PrePostDollarFixer(const char* prefix, const char* postfix);
    PrePostDollarFixer(const PrePostDollarFixer& other);
    ~PrePostDollarFixer();

    void print(int num, char symbol = DEFAULT_SYMBOL) const;
    void print(long num, char symbol = DEFAULT_SYMBOL) const;
    void print(double num, char symbol = DEFAULT_SYMBOL) const;
    char getDefaultSymbol() const;
};
*/
typedef struct PrePostDollarFixer
{
	PrePostFixer ppf;

}PrePostDollarFixer;
void PPDF__CTOR(PrePostDollarFixer* const this,const char* prefix, const char* postfix);
void PPDF__COPY__CTOR(PrePostDollarFixer* const this, const PrePostDollarFixer* const other);
void PPDF__DTOR(PrePostDollarFixer* const this);
void PPDF__print__IC(const PrePostDollarFixer* const this, int num, char symbol);
void PPDF__print__LC(const PrePostDollarFixer* const this, long num, char symbol);
void PPDF__print__DC(const PrePostDollarFixer* const this, double num, char symbol);
char PPDF__getDefaultSymbol();
//// PrePostDollarFixer Defs ////////////
/*
inline char PrePostDollarFixer::getDefaultSymbol() const
{
    return '$';
}
*/
//// PrePostHashFixer ////////////
/*
class PrePostHashFixer: public PrePostDollarFixer
{
private:
    static const char DEFAULT_SYMBOL = '#';
public:
    PrePostHashFixer(int prc = 4);
    ~PrePostHashFixer();

    void print(int num, char symbol = DEFAULT_SYMBOL) const;
    void print(long num, char symbol = DEFAULT_SYMBOL) const;
    void print(double num, char symbol = DEFAULT_SYMBOL) const;
    char getDefaultSymbol() const;

private:
    int precision;
};
*/

typedef struct PrePostHashFixer
{
	PrePostDollarFixer ppdf;
	int precision;

}PrePostHashFixer;

void PPHF__CTOR(PrePostHashFixer* const this, int prc);
void PPHF__DTOR(PrePostHashFixer* const this);
//void PPHF__print__DC(const PrePostHashFixer* const this, double num, char symbol);
void PPHF__print__IC(const PrePostHashFixer* const this, int num, char symbol);
void PPHF__print__LC(const PrePostHashFixer* const this, long num, char symbol);
char PPHF__getDefaultSymbol();
//// PrePostHashFixer Defs ////////////
/*
inline void PrePostHashFixer::print(double num, char symbol) const
{
    printFunc("[PrePostHashFixer::print(double, char)]"); 

    printf("%s[%c%.*f]%s\n", getPrefix(), symbol, precision, num, getPostfix());
}

inline char PrePostHashFixer::getDefaultSymbol() const
{
    return '#';
}

*/

//// PrePostFloatDollarFixer ////////////
/*
class PrePostFloatDollarFixer: public PrePostDollarFixer
{
protected:
    static const char DEFAULT_SYMBOL = '@';

public:
    PrePostFloatDollarFixer(const char* prefix, const char* postfix);
    ~PrePostFloatDollarFixer();
    void print(float num) const;
    void print(float num, char symbol) const;
    char getDefaultSymbol() const;
};
*/

typedef struct PrePostFloatDollarFixer
{
	PrePostDollarFixer ppdf;

}PrePostFloatDollarFixer;
void PPFDF__CTOR(PrePostFloatDollarFixer* const this, const char* prefix, const char* postfix);
void PPFDF__DTOR(PrePostFloatDollarFixer* const this);
void PPFDF__print__F(const PrePostFloatDollarFixer* const this, float num);
void PPFDF__print__FC(const PrePostFloatDollarFixer* const this, float num, char symbol);
char PPFDF__getDefaultSymbol();
//// PrePostFloatDollarFixer Defs ////////////
/*
inline char PrePostFloatDollarFixer::getDefaultSymbol() const
{
    return '@';
}
*/
//// PrePostChecker ////////////
/*
class PrePostChecker: public PrePostFloatDollarFixer
{
public:
    PrePostChecker();
    ~PrePostChecker();
    
    void printThisSymbolUsingFunc() const;
    void printThisSymbolDirectly() const;    
    void printDollarSymbolByCastUsingFunc() const;
    void printDollarSymbolByScopeUsingFunc() const;
    void printDollarSymbolByCastDirectly() const;
    void printDollarSymbolByScopeDirectly() const;
};
*/

typedef struct PrePostChecker
{
	PrePostFloatDollarFixer ppfdf;

}PrePostChecker;

void PPC__CTOR(PrePostChecker* const this);
void PPC__DTOR(PrePostChecker* const this);
void PPC__printThisSymbolUsingFunc(const PrePostChecker* const this);
void PPC__printThisSymbolDirectly(const PrePostChecker* const this);
void PPC__printDollarSymbolByCastUsingFunc(const PrePostChecker* const this);
void PPC__printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this);
void PPC__printDollarSymbolByCastDirectly(const PrePostChecker* const this);
void PPC__printDollarSymbolByScopeDirectly(const PrePostChecker* const this);

//// Multiplier ////////////
/*
class Multiplier: public DefaultTextFormatter
{
public:
    Multiplier(int t = 2);
    ~Multiplier();

    void print(const char*) const;
    int getTimes() const;
    void setTimes(int);
private:
    int times;
}; 
*/

typedef struct Multiplier
{
	DefaultTextFormatter dtf;
	int times;

}Multiplier;

void Multiplier__CTOR(Multiplier* const this,int t);
void Multiplier__print(const Multiplier* const this ,const char* text);
void Multiplier__DTOR(Multiplier* const this);
//// Multiplier Defs ////////////
/*
inline Multiplier::Multiplier(int t)
:   times(t)
{
    printf("--- Multiplier CTOR: times = %d\n", times);
}

inline Multiplier::~Multiplier()
{
    printf("--- Multiplier DTOR: times = %d\n", times);
}
    
inline int Multiplier::getTimes() const
{
    return times;
}

inline void Multiplier::setTimes(int t)
{
    times = t;
}
*/


#endif // __CPP2C_POLYMORPHISM_H__


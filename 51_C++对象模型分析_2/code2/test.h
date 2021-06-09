#ifndef TEST_H_
#define TEST_H_

typedef struct
{
    int (*pAdd)(void *, int);
}VTable;

typedef struct
{
    VTable * vptr;
    int i;
    int j;
}Base;

typedef struct
{
    Base base;
    int k;
}Derived;

void Base_init(Base * pThis, int i, int j);
int Base_GetI(Base * pThis);
int Base_GetJ(Base * pThis);
int Base_Add(Base * pThis, int value);

void Derived_init(Derived * pThis, int i, int j, int k);
int Derived_GetK(Derived * pThis);
int Derived_Add(Derived * pThis, int value);

#endif

#include "test.h"

static int Base_Vritaul_Add(void * pThis, int value)
{
    Base * p = (Base *) pThis;

    return p->i + p->j + value;
}

static int Derived_Vritual_Add(void * pThis, int value)
{
    Derived *p = (Derived *) pThis;

    return p->k + value;
}

/**
 * Base类虚函数表
 */
static VTable g_Base_vtbl = 
{
    Base_Vritaul_Add
};

/**
 * Derived 类虚函数表
 */
static VTable g_Derived_vtbl = 
{
    Derived_Vritual_Add
};


void Base_init(Base * pThis, int i, int j)
{
    pThis->i = i;
    pThis->j = j;

    /* 初始化虚函数表 */
    pThis->vptr = & g_Base_vtbl;
}

int Base_GetI(Base * pThis)
{
    return pThis->i;
}

int Base_GetJ(Base * pThis)
{
    return pThis->j;
}

int Base_Add(Base * pThis, int value)
{
    return pThis->vptr->pAdd(pThis, value);
}


void Derived_init(Derived * pThis, int i, int j, int k)
{
    Base_init(&pThis->base, i, j);
    pThis->k = k;

    /* 初始化虚函数表 */
    pThis->base.vptr = & g_Derived_vtbl;
}

int Derived_GetK(Derived * pThis)
{
    return pThis->k;
}

int Derived_Add(Derived * pThis, int value)
{
    return pThis->base.vptr->pAdd(pThis, value);
}

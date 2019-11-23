#include "51-2.h"
#include "malloc.h"

static int Demo_Virtual_Add(Demo* pThis, int value);
static int Derived_Virtual_Add(Demo* pThis, int value);

struct VTable     // 2. �����麯�������ݽṹ
{
    int (*pAdd)(void*, int);   // 3. �麯��������洢ʲô������
};

struct ClassDemo
{
    struct VTable* vptr;     // 1. �����麯����ָ��  ==�� �麯����ָ�����ͣ�����
    int mi;
    int mj;
};

struct ClassDerived
{
    struct ClassDemo d;
    int mk;
};

static struct VTable g_Demo_vtbl = 
{
    Demo_Virtual_Add
};

static struct VTable g_Derived_vtbl = 
{
    Derived_Virtual_Add
};

Demo* Demo_Create(int i, int j)
{
    struct ClassDemo* ret = (struct ClassDemo*)malloc(sizeof(struct ClassDemo)); 

    if( ret != NULL )
    {
        ret->vptr = &g_Demo_vtbl;   // 4. ����������麯����
        ret->mi = i;
        ret->mj = j;
    }
    
    return ret;
}

int Demo_GetI(Demo* pThis)
{
     struct ClassDemo* obj = (struct ClassDemo*)pThis;    

     return obj->mi;
}

int Demo_GetJ(Demo* pThis)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;

    return obj->mj;
}

// 6. �����麯������ָ����ָ��ľ��庯��
static int Demo_Virtual_Add(Demo* pThis, int value)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;
    
    return obj->mi + obj->mj + value;
}


// 5. ����������麯����������
int Demo_Add(Demo* pThis, int value)
{

    struct ClassDemo* obj = (struct ClassDemo*)pThis;

    return obj->vptr->pAdd(pThis, value);
}

void Demo_Free(Demo* pThis)
{
    free(pThis);
}

Derived* Derived_Create(int i, int j, int k)
{
    struct ClassDerived* ret = (struct ClassDerived*)malloc(sizeof(struct ClassDerived));
    
    if( ret != NULL )
    {
        ret->d.vptr = &g_Derived_vtbl;
        ret->d.mi = i;
        ret->d.mj = j;
        ret->mk = k;
    }
    
    return ret;
}

int Derived_GetK(Derived* pThis)
{
    struct ClassDerived* obj = (struct ClassDerived*)pThis;
    
    return obj->mk;
}

static int Derived_Virtual_Add(Demo* pThis, int value)
{
    struct ClassDerived* obj = (struct ClassDerived*)pThis; 

    return obj->mk + value;
}

int Derived_Add(Derived* pThis, int value)
{   
    struct ClassDerived* obj = (struct ClassDerived*)pThis;
    
    return obj->d.vptr->pAdd(pThis, value);
}
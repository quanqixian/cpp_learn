#include "test.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
    Base base;

    /* 模拟类的构造函数 */
    Base_init(&base, 1, 2);

    /* 模拟调用类的成员函数 */
    printf("base.i = %d\n", Base_GetI(&base));
    printf("base.j = %d\n", Base_GetJ(&base));

    printf("base.add() = %d\n", Base_Add(&base, 3));
    printf("\n");


    Derived derived;

    /* 模拟类的构造函数 */
    Derived_init(& derived, 1, 2, 0);

    /* 模拟调用类的成员函数 */
    printf("derived.i = %d\n", Base_GetI((Base*)&derived));          /* 模拟子类当作父类使用 */    
    printf("derived.j = %d\n", Base_GetJ((Base*)&derived));          /* 模拟子类当作父类使用 */
    printf("derived.k = %d\n", Derived_GetK(&derived));

    printf("derived.add() = %d\n", Derived_Add(&derived, 3));
    printf("\n");

    /* 模拟多态 */
    Base * p = NULL;

    p = &base;
    printf("p->add() = %d\n", Base_Add(p, 3));

    p = (Base*)&derived;
    printf("p->add() = %d\n", Base_Add(p, 3));

    return 0;
}

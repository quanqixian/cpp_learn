#include <stdio.h>
/**
 * 引用在c++中的内部实现是一个指针常量 
 * Type &name;     <-->   Type* const name;
 * void f(int &a)         void f(int* const a)
 * {                      {
 * 	a = f;         <-->       *a = 5;
 * }                      }
 * 注意：
 * 	1.c++编译器在编译过程中，用指针常量作为引用的内部实现，因此引用占用的空间大小与指针相同。
 * 	2.从使用的角度，引用是一个别名，c++为了实用性而隐藏了引用的存储空间这一细节。
 */
struct TRef
{
	char & r;
};
int main(int argc, const char *argv[])
{
	char c = 'c';
	char & rc = c;
	TRef ref = {c};
	printf("sizeof(char &)=%d\n",sizeof(char&));
	printf("sizeof(rc) = %d\n",sizeof(rc));

	printf("sizeof(TRef) = %d\n",sizeof(TRef));
	printf("sizoef(ref.r) = %d\n",sizeof(ref.r));

	return 0;
}

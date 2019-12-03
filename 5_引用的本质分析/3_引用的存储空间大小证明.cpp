#include <stdio.h>
#pragma pack(1)
struct TRef 
{
	char * before;
	char & ref;
	char * after;
};
#pragma pack()
int main(int argc, const char *argv[])
{
	char a = 'a';
	char &b = a;
	char c = 'c';
	TRef r = {&a, b, &c};

	printf("sizeof(r) = %d\n",sizeof(r));
	printf("sizoef(r.before) = %d\n",sizeof(r.before));
	printf("sizoef(r.after) = %d\n",sizeof(r.after));
	printf("&r.before = %p\n",&r.before);
	printf("&r.after = %p\n",& r.after);
	return 0;
}

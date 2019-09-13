#include <stdio.h>
class Test
{
	int mi;
public:
	Test(int i)
	{
		mi=i;
	}
	Test() 
	{
		Test(0);
	}
	void print() 
	{
		printf("mi=%d\n",mi);
	}

};
int main(int argc, const char *argv[])
{
	Test t;
	t.print(); //打印的值是否为0为什么不是0，而是随机数?
	return 0;
}

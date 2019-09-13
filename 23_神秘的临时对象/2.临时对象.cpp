#include <stdio.h>
class Test
{
	int mi;
	void init(int i)
	{
		mi=i;
	}
public:
	Test(int i)
	{
		printf("Test(int i)\n");
		init(i);
	}
	Test()
	{
		printf("Test()\n");
		init(0);
	}
	void print()
	{
		printf("mi=%d\n",mi);
	}
	~Test()
	{
		printf("~Test()\n");
	}
};
int main(int argc, const char *argv[])
{
	printf("begin\n");

	Test().print();
	Test(10).print();

	printf("end\n");
	return 0;
}

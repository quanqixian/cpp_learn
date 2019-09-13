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
		init(i);
	}
	Test()
	{
		init(0);
	}
	void print()
	{
		printf("mi=%d\n",mi);
	}
};
int main(int argc, const char *argv[])
{
	Test t;
	t.print();
	return 0;
}

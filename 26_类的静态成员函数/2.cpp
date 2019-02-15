/*使用静态成员函数统计 程序运行工程中某个类的个数*/
#include<stdio.h>
class Test
{
private:
	static  int cCount;
public:
	Test()
	{
		cCount++;
	}
	~Test()
	{
		--cCount;
	}
	static int GetCount()
	{
		return cCount;
	}
}; 
int Test::cCount=0;
int main()
{
	printf("count=%d\n",Test::GetCount());//没有创建对象的时候可以通过类名进行访问 
	                                      //静态成员函数
	Test t1;
	Test t2;
	printf("count=%d\n",t1.GetCount());
	printf("count=%d\n",t2.GetCount());
	Test *pt=new Test();
	printf("count=%d\n",pt->GetCount());
	delete pt;
	printf("count=%d\n",Test::GetCount());
	return 0;

}

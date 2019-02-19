#include<stdio.h>
class TwoPhaseCons
{
private: //第一阶段构造函数与第二阶段构造函数放到private里面了，外部无法调用。
	TwoPhaseCons()//第一阶段构造函数 
	{
	}
	bool construct()//第二阶段构造函数
	{
		return true;
	}
public:
	static TwoPhaseCons* NewInsatance();//对象创建函数
};
TwoPhaseCons*TwoPhaseCons::NewInsatance()
{
	/*用了二阶构造模式后，对象只能在堆空间上进行构造而不能在栈空间上构造，
	 * 这样好么？答案是肯定的，因为工程上的对象往往是巨大的，
	 * 一般都会放到堆空间上进行构造。*/
	TwoPhaseCons*ret=new TwoPhaseCons();//调用第一阶段的构造函数，做一些初始化操作，不会引起异常的操作
	//若第二阶段构造失败，返回null 
	if(!ret&&ret->construct())
	{
		delete ret;
		ret=NULL;
	}
	return ret; 
}
int main()
{
	TwoPhaseCons*obj=TwoPhaseCons::NewInsatance();
	printf("obj=%p\n",obj);
	delete obj;
	return 0;
}

#include <stdio.h>
/**
 * 两个特殊的构造函数 
 * -无参构造函数
 *  当类转给你没有定义构造函数时，编译器默认提供一个无参构造函数，并且其函数体为空
 * -拷贝构造函数
 *  当类中没有定义拷贝构造函数时，编译器默认提供农耕一个拷贝构造函数，简单减小成员变量的值复制
 */
class Test
{
private:
	int i;
	int j;
public:
	int getI()
	{
		return i;
	}
	int getJ()
	{
		return j;
	}
	/*
	 Test(const Test& t)
	 {
	 	i = t.i;
		j = t.j;
	 }
	 Test()
	 {
	 }
	 */
};
int main(int argc, const char *argv[])
{
	Test t1;
	Test t2 = t1;
	return 0;
}

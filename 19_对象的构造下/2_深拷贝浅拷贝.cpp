#include <stdio.h>
/**
 * 拷贝构造函数的意义
 * -浅拷贝
 *  拷贝后对象的物理状态相同
 * -深拷贝
 *  拷贝后对象的逻辑状态相同 
 * 什么时候需要进行深拷贝?
 * -对象中有成员指代了系统的资源
 *   成员指向了动态内存空间
 *   成员打开了外中的文件
 *   成员使用了系统中的网络端口
 */
class Test 
{
private:
	int i;
	int j;
	int *p;
public:
	int getI()
	{
		return i;
	}
	int getJ()
	{
		return j;
	}
	int *getP()
	{
		return p;
	}
	Test(const Test&t)
	{
		i = t.i;
		j = t.j;
		p = new int;
		*p = *t.p;
	}
	Test(int v)
	{
		i = 1;
		j = 2;
		p = new int ;
		*p = v;
	}
	void free()
	{
		delete p;
	}
};
int main(int argc, const char *argv[])
{
	Test t1(3);
	Test t2(t1);
	
	printf("t1.i = %d,t1.j = %d, *t1.p = %d\n",t1.getI(),t1.getJ(),*t1.getP());
	printf("t1.i = %d, t2.j = %d,*t2,p = %d\n",t2.getI(),t2.getJ(),*t2.getP());
	t1.free();
	t2.free();
	return 0;
}

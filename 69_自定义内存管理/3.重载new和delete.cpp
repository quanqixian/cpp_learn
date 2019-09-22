/*重载new/delet 的意义在于改变动态对象创建时的内存分配方式*/
#include <iostream>
#include <string>
using namespace std;
class Test
{
	static const unsigned int COUNT=16;
	static char c_buffer[];
	static char c_map[];

	char  m_value;
public:
	void * operator new(long unsigned int size)
	{
		void * ret=NULL;
		for(int i=0;i<COUNT;i++)
		{
			if(!c_map[i])
			{
				c_map[i]=1;
				ret=c_buffer+i*sizeof(Test);
				cout<<"succeed to allocate memory:"<<ret<<endl;
				break;
			}
		}
		return ret;
	}
	void operator delete (void *p)
	{
		if(p!=NULL)
		{
			char *mem=reinterpret_cast<char *>(p);
			int index=(mem-c_buffer)/sizeof(Test);
			int flag=(mem-c_buffer)%sizeof(Test);
			if( (flag==0)&&(0<=index)&&(index<COUNT) )
			{
				c_map[index]=0;
				cout<<"succeed to free memory:"<<p<<endl;
			}
		}
	}
};
char Test::c_buffer[sizeof(Test)*Test::COUNT]={0};
char Test::c_map[Test::COUNT]={0};
int main(int argc, const char *argv[])
{
	cout<<"========Test Single OBJECT ======"<<endl;
	Test *pt=new Test;
	delete pt;
	cout<<"======= Test Object Array======="<<endl;
	Test *pa[5]={0};
	for(int i=0;i<5;i++)
	{
		pa[i]=new Test;
		cout<<"pa["<<i<<"]="<<pa[i]<<endl;

	}
	for (int i=0;i<5;i++)
	{
		cout<<"delete "<<pa[i]<<endl;
		delete pa[i];
	}
	return 0;
}

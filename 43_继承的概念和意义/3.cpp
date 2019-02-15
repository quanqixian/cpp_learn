#include <iostream>
#include <string>
using namespace std;
class Memory
{
	public:
		Memory()
		{
			cout<<"Memory()"<<endl;
		}
		~Memory()
		{
			cout<<"~Memory()"<<endl;
		}
};
class Disk
{
public:
	Disk()
	{
		cout<<"Disk()"<<endl;
	}
	~Disk()
	{
		cout<<"~Disk()"<<endl;
	}
};
class cpu
{
public:
	cpu()
	{
		cout<<"cpu()"<<endl;
	}
	~cpu()
	{
		cout<<"~cpu()"<<endl;
	}
};
class mainboard
{
public:
	mainboard()
	{
		cout<<"mainboard"<<endl;
	}
	~mainboard()
	{
		cout<<"~mainboard"<<endl;
	}
};
class computer
{
	Memory m_mem;
	Disk   m_disk;
	cpu    m_cpu;
	mainboard m_mainboard;
public:
	computer()
	{
		cout<<"computer()"<<endl;
	}
	void power()
	{
		cout<<"power()"<<endl;
	}
	void reset()
	{
		cout<<"resert()"<<endl;
	}
	~computer()
	{
		cout<<"~computer()"<<endl;
	}
};
class hpbook:public computer 
{
	string mos;
public:
	hpbook()
	{
		mos="windows 8";
	}
	void install (string os)
	{
		mos=os;
	}
	void os()
	{
		cout<<mos<<endl;
	}
};
class macbook:public computer 
{
public:
	void os()
	{
		cout<<"mac os"<<endl;
	}
};
int main()
{
	hpbook hp;
	hp.power();
	hp.install("ubuntu 16");
	hp.os();
	cout<<endl;
	macbook mac;
	mac.os();
	return 0;
}


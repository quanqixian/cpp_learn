#include <iostream>
#include <string>
#include "Array.h"
using namespace std;
int main(int argc, const char *argv[])
{
	Array<double ,5> ad;
	for(int i = 0;i<ad.length();i++)
	{
		ad[i]= i*i;
	}
	for(int i=0;i<ad.length();i++)
	{
		cout<<ad[i]<<endl;
	}
	cout <<endl;

	return 0;
}

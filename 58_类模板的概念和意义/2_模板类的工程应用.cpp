#include <iostream>
#include <string>
#include "Operator.h"
using namespace std;
int main(void)
{
	Operator<int >a;
	cout<<a.add(1,2)<<endl;
	Operator<string>b;
	cout<<b.add("hello","world")<<endl;
	//cout<<b.sub("hello","world")<<endl;
	return 0;
}

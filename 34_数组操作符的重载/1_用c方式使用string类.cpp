#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char *argv[])
{
	string s = "a1b2c3";
	int n = 0;
	for (int i=0;i<s.length();i++)
	{
		if( isdigit(s[i]) )
		{
			n++;
		}
	}
	cout<<n<<endl;
	return 0;
}

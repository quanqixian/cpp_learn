#ifndef _OPERATOR_H 
#define _OPERATOR_H 
/*****************
 * 类模板的工程应用
* 1.类模板必须在头文件中定义
* 2.类模板的实现,不能分开在不同的文件 
* 3.类模板外部定义的函数类模板外部定义的函数 需要加上 模板<>声明 
*****************/
#include <string>
template <typename T>
class Operator 
{
public:
	T add(T a,T b);
	T sub(T a,T b);
	T mul(T a,T b);
	T div(T a,T b);
//	string operator -(string &p1,string &p2);
};
template <typename T>
T Operator<T>::add(T a,T b)
{
	return a+b;
}
template <typename T>
T Operator<T>::sub(T a,T b)
{
	return a-b;
}
template <typename T>
T Operator<T>::mul(T a,T b)
{
	return a*b;
}
template <typename T>
T Operator<T>::div(T a,T b)
{
	return a/b;
}
/*
string Operator::operator-(string &p1,string &p2)
{
	return "sub";
}
*/
#endif

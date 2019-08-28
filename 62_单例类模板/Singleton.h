#ifndef _SINGLETON_H
#define _SINGLETON_H

template <typename T>
class Singleton
{
	static T* c_instance;//声明
public:
	static T* GetInstance();
};
template <typename T>
T*Singleton<T>::c_instance=NULL;//定义

template<typename T>
T* Singleton<T>::GetInstance()
{
	if(c_instance==NULL)
	{
		c_instance=new T();
	}
	return c_instance;
}

#endif

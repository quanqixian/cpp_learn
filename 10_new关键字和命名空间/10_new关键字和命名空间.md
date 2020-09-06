## **1.C++中的动态内存分配**

- C++通过new关键字进行动态内存申请
- C++中动态内存申请是基于类型进行的
- delete关键字用于内存释放

变量申请及释放：

```c++
Type * pointer = new Type; 
//...... 
delete pointer;
```

数组申请及释放：

```c++
Type * pointer = new Type[N]; 
//......
delete[] pointer;
```

### 1.1编程实验 C++中的动态内存分配

```c++
#include <stdio.h>

int main()
{
    int* p = new int;
    
    *p = 5;
    *p = *p + 10;
    
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    
    delete p;
    
    /**
     *p所指向的这一片数组空间是40个字节吗？
     *p所指向的这片空间至少占用40个字节，可能分配更多的空间。
     */
    p = new int[10];
    
    for(int i=0; i<10; i++)
    {
        p[i] = i + 1;
        
        printf("p[%d] = %d\n", i, p[i]);
    }
    
    delete[] p;
    
    return 0;
}
```

- [x]   **数组的释放需要在delete关键字之后加`[]`，如果没加[]，仅仅释放了第一个元素，剩下的内存空间依然没有释放，就会造成内存泄漏**


## 2.new关键字与malloc函数的区别

- new关键字是C++的一部分，malloc是C库提供的函数
- new以`具体类型`为单位进行内存分配，malloc以`字节`为单位进行内存分配
- new在申请单个类型变量时可以进行初始化，malloc不具备内存初始化的特性

## **3.new关键字的初始化**

申请单个类型变量时并进行初始化

```c++
int * pi = new int(1);
float * pf = new float(2.0f);
char * pc = new char('c');
```

### 3.1编程实验：初始化动态内存

```c++
#include <stdio.h>

int main()
{
    /* 这两行很相似，但本质是不同的 */
    int* pi = new int(1);    /* 申请单个的变量，并且初始化为1 */
    // int* pa = new int[1]; /* 申请一片数组的空间，数组的空间大小为一个int元素的大小 */
    
    float* pf = new float(2.0f);
    char* pc = new char('c');

    printf("*pi = %d\n", *pi);
    printf("*pf = %f\n", *pf);
    printf("*pc = %c\n", *pc);
    
    delete pi;
    delete pf;
    delete pc;
    
    return 0;
}
```

## **4、C++中的命名空间**

**在C语言中只有`一个全局作用域`**

- C语言中`所有的全局标识符共享同一个作用域`

- 
    标识符之间可能发生冲突


**C++中提出了`命名空间`的概念**

- 命名空间`将全局作用域分成不同的部分`
- 不同命名空间中的标识符可以同名而不会发生冲突
- 命名空间可以相互嵌套
- 全局作用域也叫`默认命名空间`

### **4.1 C++命名空间的定义**

```c++
namespace Name 
{    namespace Internal    
	{            
	} 
}
```

### **4.2命名空间的使用**

- 使用整个命名空间：`using namespace name;`

- 使用命名空间中de变量：`using name::variable;`

- 使用默认命名空间中的变量： `::variable`


### 4.3 命名空间的使用

```c++
#include <stdio.h>

namespace First
{
    int i = 0;
}

namespace Second
{
    int i = 1;
    
    namespace Internal
    {
        struct P
        {
            int x;
            int y;
        };
    }
}

int main()
{
    using namespace First;
    using Second::Internal::P;
    
    printf("First::i = %d\n", i);
    printf("Second::i = %d\n", Second::i);
    
    P p = {2, 3};
    
    printf("p.x = %d\n", p.x);
    printf("p.y = %d\n", p.y);
    
    return 0;
}
```

- [x] First::i 和Second::i这两个i都是全局变量，而且名字也相同，但是他们在不同的命名空间中，所以不冲突

## 5.总结

- c++中内置了动态内存分配的专用关键字

- c++中的动态内存分配可以同时进行初始化

- C++中的动态内存分配是基于类型进行的

- C++中命名空间的概念用于解决名称冲突问题
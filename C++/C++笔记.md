## 面向对象

### 基本概念

1.对象

2.类

​	类是对具有相同数据结构和相同操作的一类对象的描述

3.消息与方法

​	通过函数实现

### 基本特征

1. 抽象
2. 封装
3. 继承
4. 多态

### 面向对象的优点



##非面向对象方面的扩充

### 输入输出

`cin`和`cout`

- 需要头文件`iostream`
- `endl`等价于`\n`用作换行
- 不同进制的输出

转换基数的操作符：

```c++
#include <iostream>

using namespace std;

int main() {
	int x = 25;
	cout << hex << x << endl;//hex转换为十六进制
	cout << dec << x << endl;//dec转换为十进制
	cout << oct << x << endl;//oct转换为八进制
	system("pause");
	return 0;
}
```



### 结构体名、联合名和枚举名可直接作为变量名

```c++
enum Bool{
	False,
	True
};
struct String {
    char* ptr;
    int length;
};

//定义变量时可省略关键字
Bool done;
String str;
```



### `const`修饰符

- 消除了`#define`的不安全性 
- 修饰整形时可省略`int`
- 可用`const`修饰形参，优化函数

`const`修饰指针的用法

```c++
const char* name = "chen";//不能改变地址中的常量，但指针的指向可以被改变
char* const name = "chen";//可以改变地址中的数据，但不能改变指针的指向（常指针）
const char* const name = "chen";//都不能改变，指向常量的常指针
```



### 内联函数

- 将`inline`加在函数之前
- 以该内联函数函数体的**代码直接代替**函数的调用，以实参代替形参，**以空间换时间**
- 通常将**规模很小**且需要**频繁调用**的函数定义为内联函数

```c++
#include <iostream>
using namespace std;

inline int doub(int num) {
	return num * 2;
}

int main() {
	inline int doub(int);
	for (int i = 1; i <= 3; i++) {
		cout << doub(i) << endl;
	}
	system("pause");
	return 0;
}
```



### 带有默认参数的函数



### 函数的重载

- 函数名可以重复，但**参数类型和数量不同**
- 只有返回值类型不同则不允许重载
- 

### 作用域运算符`::`

- 在变量名前加上`::`可以在局部变量的作用域内访问被屏蔽的全局变量
- 可用来解决局部变量与全局变量的重名问题

### 强制类型转换

```c++
int i = 10;
double x;
x = (double)i;//c语言
x = double(i);//c++
```

- 更推荐后一种



### `new`和`delete`



### 引用



## 类和对象

### 基本概念

#### 结构体与类



#### 成员函数的定义
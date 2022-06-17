## C++核心编程

###1 非面向对象方面的扩充

#### 1.1 输入输出

`cin`和`cout`

- 需要头文件`iostream`
- `endl`等价于`\n`用作换行
- 不同进制的输出

#### 1.2 转换基数的操作符

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



#### 1.3 结构体名、联合名和枚举名可直接作为变量名

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



#### 1.4 `const`修饰符

- 消除了`#define`的不安全性 
- 修饰整形时可省略`int`
- 可用`const`修饰形参，优化函数

`const`修饰指针的用法

```c++
const char* name = "chen";//不能改变地址中的常量，但指针的指向可以被改变
char* const name = "chen";//可以改变地址中的数据，但不能改变指针的指向（常指针）
const char* const name = "chen";//都不能改变，指向常量的常指针
```

#### 1.5 作用域运算符`::`

- 在变量名前加上`::`可以在局部变量的作用域内访问被屏蔽的全局变量
- 可用来解决局部变量与全局变量的重名问题

#### 1.6 强制类型转换

```c++
int i = 10;
double x;
x = (double)i;//c语言
x = double(i);//c++
```

- 更推荐后一种

#### 1.7 内存分区模型

C++程序在执行时，将内存大方向划分为**4个区域**

- 代码区：存放函数体的二进制代码，由**操作系统进行管理**的
- 全局区：存放全局变量和静态变量以及常量
- 栈区：由**编译器自动分配释放**, 存放函数的参数值,局部变量等
- 堆区：由**程序员分配和释放**,若程序员不释放,程序结束时由操作系统回收



### 2.引用

#### 2.1 引用的基本使用

引用：给变量起别名

```c++
int a = 10;
int &b = a;
```



#### 2.2 引用的注意事项

- 定义时必须初始化
- 初始化之后就不可更改

#### 2.3 引用作函数参数

以引用作为形参，可以简化指针操作

#### 2.4 引用做函数返回值



#### 2.5 引用的本质

本质：引用的本质在c++内部实现是一个**指针常量.**

引用转换为 `int* const ref = &a;`

C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了



### 3.函数提高

#### 内联函数

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



#### 带有默认参数的函数

在C++中，函数的形参列表中的形参是可以有默认值的。

语法：` 返回值类型  函数名 （参数= 默认值）{}`



**示例：**

```C++
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main() {

	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func(100) << endl;

	system("pause");

	return 0;
}
```





#### 函数的重载

- 函数名可以重复，但**参数类型和数量不同**
- 只有返回值类型不同则不允许重载



### 4 类和对象

C++面向对象的三大特性：封装、继承、多态

#### 4.1 封装

##### 4.1.1 封装的意义

* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制

##### 4.1.2 `struct`和`class`的区别

默认权限不同

##### 4.1.3 成员属性设置为私有

- 访问权限有三种：


1. `public`      公共权限  
2. `protected` 保护权限
3. `private`     私有权限

- 优点1：可以自己控制读写权限（用getter和setter）
- 优点2：对于写，可以验证数据的有效性（例如在setter函数中限定年龄为0~150）

#### 4.2 对象的初始化和清理



##### 4.2.1构造函数和析构函数

编译器强制我们对对象进行**初始化和清理**，如果我们不提供构造和析构，编译器会自动提供这两个函数的**空实现**

**构造函数**：`类名(){}`

- 没有返回值也不写void
- 函数名与类名相同
- 可以有参，可以重载
- 在创建对象时自动调用,而且只会调用一次

**析构函数**：`~类名(){}`

- 没有返回值也不写void
- 函数名与类名相同，**记得加`~`**
- **不能有参，不能重载**
- 在销毁对象时自动调用,而且只会调用一次



##### 4.2.2 构造函数的分类及调用

两种分类方式：

​	按参数分为： 有参构造和无参构造

​	按类型分为： 普通构造和拷贝构造

三种调用方式：

​	括号法

​	显示法

​	隐式转换法

注意事项

- `Person(10)`单独写就是**匿名对象** ，当前行结束之后，马上析构
- 调用**无参**构造函数**不能加括号**，如果加了编译器认为这是一个函数声明：`Person p2();`错误
- 不能利用 拷贝构造函数 初始化匿名对象， 编译器会认为是对象声明：`Person (p3);`错误

```c++
//1、构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int a) {
		age = a;
		cout << "有参构造函数!" << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

//2、构造函数的调用
//调用无参构造函数
void test01() {
	Person p; //调用无参构造函数
}

//调用有参的构造函数
void test02() {

	//2.1  括号法，常用
	Person p1(10);
	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	//Person p2();

	//2.2 显式法
	Person p2 = Person(10); 
	Person p3 = Person(p2);
	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构

	//2.3 隐式转换法
	Person p4 = 10; // Person p4 = Person(10); 
	Person p5 = p4; // Person p5 = Person(p4); 

	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
	//Person (p4);
}

int main() {
	test01();
	//test02();
	system("pause");

	return 0;
}
```



##### 4.2.3 拷贝构造函数调用时机

拷贝构造函数的三种调用场景：

* 使用一个已经创建完毕的对象来初始化一个新对象
* **值传递**的方式给函数参数传值
* 以值方式返回局部对象



##### 4.2.4 构造函数调用规则

编译器默认给一个类添加3个函数

1．默认构造函数(无参，函数体为空)

2．默认析构函数(无参，函数体为空)

3．默认拷贝构造函数，对属性进行值拷贝



构造函数调用规则如下：

* 如果**用户定义有参**构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造


* 如果**用户定义拷贝**构造函数，c++不会再提供其他构造函数



##### 4.2.5 深拷贝与浅拷贝

面试经典问题

浅拷贝：简单的赋值拷贝操作

深拷贝：在**堆区**重新申请空间，进行拷贝操作



```C++
class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int age ,int height) {
		
		cout << "有参构造函数!" << endl;

		m_age = age;
		m_height = new int(height);
		
	}
	//拷贝构造函数  
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		m_age = p.m_age;
		m_height = new int(*p.m_height);
		
	}

	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
		if (m_height != NULL)
		{
			delete m_height;
		}
	}
public:
	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18, 180);

	Person p2(p1);

	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;

	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

> 

总结：如果属性有**在堆区开辟的**，一定要自己提供拷贝构造函数，防止浅拷贝带来的**重复释放堆区**的问题



##### 4.2.6 初始化列表

**语法：**`构造函数()：属性1(值1),属性2（值2）... {}`

```c++
class Person {
public:
    
//初始化列表方式初始化
	Person(int a,int b,int c) :m_A(a),m_B(b),m_C(c) {}
}
private:
	int m_A;
	int m_B;
	int m_C;
};

int main() {
	Person p(1, 2, 3);
    
	system("pause");
	return 0;
}
```



##### 4.2.7 类对象作为类成员

```c++
class Point{}
class Line{
    Point p; 
}
```



- 构造的顺序是 ：先调用对象成员的构造，再调用本类构造，在例子中先调用Point类的构造，再调用Line类的构造、
- 析构顺序与构造**相反**



##### 4.2.8 静态成员

在成员变量和成员函数前加上关键字static，称为静态成员

1. 静态成员变量

	- 所有对象共享同一份数据
	- 在编译阶段分配内存（全局区）
	- 类内声明（示例一：6、14行），类外初始化（示例1：16、17行）
	- 静态成员变量两种访问方式：通过对象进行访问、通过类名进行访问

	

2. 静态成员函数

	*  所有对象共享同一个函数
	*  静态成员函数**只能访问**静态成员变量
	*  两种访问方式同上

	

**示例1 ：**静态成员变量

```C++
class Person
{
	
public:

	static int m_A; //静态成员变量

	//静态成员变量特点：
	//1 在编译阶段分配内存
	//2 类内声明，类外初始化
	//3 所有对象共享同一份数据

private:
	static int m_B; //静态成员变量也是有访问权限的
};
int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	//静态成员变量两种访问方式

	//1、通过对象
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
	cout << "p2.m_A = " << p2.m_A << endl;

	//2、通过类名
	cout << "m_A = " << Person::m_A << endl;


	//cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
}

int main() {

	test01();

	system("pause");

	return 0;
}
```





**示例2：**静态成员函数

```C++
class Person
{

public:

	//静态成员函数特点：
	//1 程序共享一个函数
	//2 静态成员函数只能访问静态成员变量
	
	static void func()
	{
		cout << "func调用" << endl;
		m_A = 100;
		//m_B = 100; //错误，不可以访问非静态成员变量
	}

	static int m_A; //静态成员变量
	int m_B; // 
private:

	//静态成员函数也是有访问权限的
	static void func2()
	{
		cout << "func2调用" << endl;
	}
};
int Person::m_A = 10;


void test01()
{
	//静态成员变量两种访问方式

	//1、通过对象
	Person p1;
	p1.func();

	//2、通过类名
	Person::func();


	//Person::func2(); //私有权限访问不到
}

int main() {

	test01();

	system("pause");

	return 0;
}
```







#### 4.3 C++对象模型和this指针

##### 4.3.1 成员变量和成员函数分开存储

- 一个空对象占1个字节
- 在C++中，类内的成员变量和成员函数分开存储，只有**非静态成员变量**才属于类的对象上，不占对象空间
- 函数、静态成员变量、静态成员函数都不占对象空间



##### 4.3.2 this指针概念

*  this指针指向被调用的成员函数所属的对象
*  当形参和成员变量同名时，可用this指针来区分
*  在类的非静态成员函数中返回对象本身，可使用return *this

```c++
class Person
{
public:

	Person(int age)
	{
		//1、当形参和成员变量同名时，可用this指针来区分
		this->age = age;
	}

	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		//返回对象本身
		return *this;
	}

	int age;
};

void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



##### 4.3.3 空指针访问成员函数

- C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
- 如果用到this指针，需要判断，以保证代码的健壮性



##### 4.3.4 `const`修饰成员函数

**常函数：**

* 成员函数后加`const`后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改



**常对象：**

* 声明对象前加`const`称该对象为常对象
* 常对象只能调用常函数



#### 4.4 友元

友元的关键字为  ==friend==

友元的目的就是让一个函数或者类能够访问另一个类中的**私有成员**

友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元



##### 4.4.1 全局函数做友元

在类定义的第一行声明：`friend + 返回值 + 函数名 ;`

##### 4.4.2 类做友元

在类定义的第一行声明：`friend + class + 类名 ;`

##### 4.4.3 成员函数做友元

在类定义的第一行声明：`friend + 返回值 + 类名:: + 函数名 ;`



#### 4.5 运算符重载

运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

##### 4.5.1 加号运算符重载

- 可用成员函数或全局函数实现
- 对于内置的数据类型的表达式的运算符是不可能改变的
- 不要滥用运算符重载



4.5.2 左移运算符重载

- 配合友元可以输出自定义数据类型
- 只能用全局函数实现
- `cout`的数据类型是`ostream`

```c++
class Person {
	friend ostream& operator<<(ostream& out, Person& p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//成员函数 实现不了  p << cout 不是我们想要的效果
	//void operator<<(Person& p){
	//}

private:
	int m_A;
	int m_B;
};

//全局函数实现左移重载
//ostream对象只能有一个
ostream& operator<<(ostream& out, Person& p) {
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;
}

void test() {

	Person p1(10, 20);

	cout << p1 << "hello world" << endl; //链式编程
}

int main() {
	test();
	system("pause");
	return 0;
}
```





##### 4.5.3 递增运算符重载

```c++
#include<iostream>
using namespace std;

class MyInteger {
	friend ostream& operator<< (ostream& cout, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	}
	//重载前置++运算符
	//此处返回引用是为了一直对一个数据进行递增操作
	MyInteger& operator++() {
		//先进行++运算
		m_Num++;
		//再返回自身
		return *this;
	}
	//重载后置++运算符
	//int代表占位参数，可以用于区分前置和后置递增
	//此处返回值
	MyInteger operator++(int){
		//先记录当前值
		MyInteger temp = *this;
		//再递增
		m_Num++;
		//再返回
		return temp;
	}
private:
	int m_Num;
};

//重载<<运算符
ostream& operator<< (ostream& cout, MyInteger myint) {
	cout << myint.m_Num;
	return cout;
}

void test01() {
	MyInteger myint;
	cout << ++myint << endl;
	cout << myint << endl;
}

void test02() {
	MyInteger myint;
	cout << myint++<< endl;
	cout << myint << endl;
}

int main() {
	test01();
	test02();

	system("pause");
	return 0;
}

```





##### 4.5.4 赋值运算符重载

c++编译器至少给一个类添加4个函数

1. 默认构造函数(无参，函数体为空)
2. 默认析构函数(无参，函数体为空)
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=, 对属性进行值拷贝

如果类中有属性指向**堆区**，做赋值操作时也会出现**深浅拷贝问题**

```c++
class Person
{
public:

	Person(int age)
	{
		//将年龄数据开辟到堆区
		m_Age = new int(age);
	}

	//重载赋值运算符 
	Person& operator=(Person &p)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;

		//提供深拷贝 解决浅拷贝的问题
		m_Age = new int(*p.m_Age);

		//返回自身
		return *this;
	}


	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//年龄的指针
	int *m_Age;

};
```





##### 4.5.5 关系运算符重载

- 重载关系运算符，可以让两个自定义类型对象进行对比操作

```c++
#include <iostream>
using namespace std;
#include<string>

class Person {
public:
	string m_Name;
	int m_Age;

	Person(string name,int age) {//构造函数
		this->m_Age = age;
		this->m_Name = name;
	}

	bool operator==(Person &p) {
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name) {
			return true;
		}
		return false;
	}

	bool operator!=(Person& p) {
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name) {
			return false;
		}
		return true;
	}
};

void test01() {
	Person p1("小王", 18);
	Person p2("小王", 18);
	Person p3("小李", 18);
	if (p1 == p2) {
		cout << "p1和p2相等" << endl;
	}
	else {
		cout << "p1和p2不相等" << endl;
	}
	if (p1 == p3) {
		cout << "p1和p3相等" << endl;
	}
	else {
		cout << "p1和p3不相等" << endl;
	}
}

int main() {
	test01();

	system("pause");
	return 0;
}

```





##### 4.5.6 函数调用运算符重载

* 函数调用运算符 ()  也可以重载
* 由于重载后使用的方式非常像函数的调用，因此称为**仿函数**
* 仿函数没有固定写法，非常灵活
* ***匿名对象的使用**

```c++
class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}

};
void test01()
{
	//重载的（）操作符 也称为仿函数
	MyPrint myFunc;
	myFunc("hello world");
}


class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名对象调用  
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}
```





#### 4.6  继承

下级别的成员除了拥有上一级的共性，还有自己的特性

这个时候我们就可以考虑利用继承的技术，减少重复代码

##### 4.6.1 继承的基本语法

继承的好处：==可以减少重复的代码==

`class 子类 : 继承方式  父类`

A 类称为子类 或 派生类

B 类称为父类 或 基类



**派生类中的成员，包含两大部分**：

一类是从基类继承过来的，一类是自己增加的成员。

从基类继承过过来的表现其共性，而新增的成员体现了其个性。





##### 4.6.2 继承方式

- 三种继承方式：公共、保护、私有
- 继承的语法：`class 子类 : 继承方式  父类`

![image-20220425095823691](https://s2.loli.net/2022/04/25/aI9CKhDSg1O7fbr.png)



##### 4.6.3 继承中的对象模型

- 父类中所有非静态成员属性都会被子类继承下去
- 可以通过`sizeof`验证



##### 4.6.4 继承中构造和析构顺序

- 继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反




##### 4.6.5 继承同名成员处理方式

问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？



* 访问子类同名成员   直接访问即可
* 访问父类同名成员   需要加作用域
* 同名成员函数同理
* 当子类与父类拥有同名的成员函数，子类会**隐藏**父类中同名成员函数，**加作用域**可以访问到父类中同名函数



##### 4.6.6 继承同名静态成员处理方式

- 同名静态成员处理方式**和非静态处理方式一样**
- 有两种访问的方式（通过对象 和 通过类名）







##### 4.6.7 多继承语法

- C++允许**一个类继承多个类**


语法：` class 子类 ：继承方式 父类1 ， 继承方式 父类2...`



- 多继承可能会引发父类中有同名成员出现，需要加作用域区分


- C++实际开发中**不建议用多继承**



##### 4.6.8 菱形继承

**菱形继承概念：**

​	两个派生类继承同一个基类

​	又有某个类同时继承者两个派生类

​	这种继承被称为菱形继承，或者钻石继承

![image-20220425145144401](https://s2.loli.net/2022/04/25/xTEPajz1Q3dI2D5.png)



**菱形继承问题：**

1.     羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。

2.     草泥马继承自动物的数据继承了两份，其实这份数据我们只需要一份就可以。



* 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
* 利用**虚继承**可以解决菱形继承问题：继承前加`virtual`关键字后，变为虚继承，此时公共的父类Animal称为**虚基类**



```C++
class Animal
{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}


int main() {

	test01();

	system("pause");

	return 0;
}
```







#### 4.7  多态

##### 4.7.1 多态的基本概念

**多态是C++面向对象三大特性之一**

多态分为两类

* 静态多态: **函数重载** 和 **运算符重载 **属于静态多态，复用函数名
* 动态多态: 派生类和**虚函数**实现运行时多态



静态多态和动态多态区别：**地址绑定的早晚**

* 静态多态的函数地址早绑定  -  编译阶段确定函数地址
* 动态多态的函数地址晚绑定  -  运行阶段确定函数地址

函数前面加上virtual关键字，变成**虚函数**，那么编译器在编译的时候就不能确定函数调用了

多态满足条件： 

- 有继承关系
- 子类**重写**父类中的虚函数

多态使用：

- **父类指针或引用指向子类对象**





```c++
class Animal
{
public:
	//Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:

	void speak()
	{
		cout << "小狗在说话" << endl;
	}

};
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编

void DoSpeak(Animal & animal)
{
	animal.speak();
}
//
//多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象

void test01()
{
	Cat cat;
	DoSpeak(cat);


	Dog dog;
	DoSpeak(dog);
}


int main() {

	test01();
	system("pause");
	return 0;
}
```

多态的原理：

![image-20220509094334759](https://s2.loli.net/2022/05/09/1AVWSauGtkiL5ph.png)



使用虚函数前：

![image-20220509095538516](https://s2.loli.net/2022/05/09/UhFRVu6qCv9rpyG.png)

使用虚函数后：

![image-20220509095627956](https://s2.loli.net/2022/05/09/XGmLQzuRi3Kql7j.png)

未重写子类：

![image-20220509095855475](https://s2.loli.net/2022/05/09/dj7PIKm9X8cSQqC.png)

重写子类：

![image-20220509095925359](https://s2.loli.net/2022/05/09/XkTPq4deQrVAvE5.png)





##### 4.7.2 多态案例一-计算器类

多态的优点：

* 代码组织结构清晰
* 可读性强
* 利于前期和后期的扩展以及维护



##### 4.7.3 纯虚函数和抽象类



在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容



因此可以将虚函数改为**纯虚函数**



纯虚函数语法：`virtual 返回值类型 函数名 （参数列表）= 0 ;`



当类中有了纯虚函数，这个类也称为==抽象类==



**抽象类特点**：

 * 无法实例化对象
 * 子类必须重写抽象类中的纯虚函数，否则也属于抽象类





**示例：**

```C++
class Base
{
public:
	//纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func() 
	{
		cout << "func调用" << endl;
	};
};

void test01()
{
	Base * base = NULL;
	//base = new Base; // 错误，抽象类无法实例化对象
	base = new Son;
	base->func();
	delete base;//记得销毁
}

int main() {

	test01();

	system("pause");

	return 0;
}
```







##### 4.7.4 多态案例二-制作饮品

制作饮品的大致流程为：煮水 -  冲泡 - 倒入杯中 - 加入辅料



利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶

```c++
#include <iostream>
using namespace std;

class AbstractDrinking {
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//流程
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrinking {
public:
	//烧水
	virtual void Boil() {
		cout << "烧水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "把咖啡倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加牛奶" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	//烧水
	virtual void Boil() {
		cout << "烧水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "把茶倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加枸杞" << endl;
	}
};

//1.父类引用指向子类对象
//void doWork(AbstractDrinking& a) {
//	a.makeDrink();
//}
//
//void test01() {
//	Coffee c;
//	doWork(c);
//	Tea t;
//	doWork(t);
//}

//2.父类指针指向子类对象
void doWork(AbstractDrinking * a) {
	a->makeDrink();
	delete a;
}

void test01() {
	doWork(new Coffee);
	doWork(new Tea);
}

int main() {
	test01();
	system("pause");
	return 0;
}

```





##### 4.7.5 虚析构和纯虚析构



多态使用时，如果**子类中有属性开辟到堆区**（虚析构使用场景），那么父类指针在释放时无法调用到子类的析构代码



解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构**



虚析构和纯虚析构共性：

* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：

* 如果是纯虚析构，该类属于抽象类，无法实例化对象



虚析构语法：

`virtual ~类名(){}`

纯虚析构语法：

` virtual ~类名() = 0;`

`类名::~类名(){}`



**示例：**

```C++
class Animal {
public:

	Animal()
	{
		cout << "Animal 构造函数调用！" << endl;
	}
	virtual void Speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用！" << endl;
	//}


	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal 纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat : public Animal {
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用！" << endl;
		m_Name = new string(name);
	}
	virtual void Speak()
	{
		cout << *m_Name <<  "小猫在说话!" << endl;
	}
	~Cat()
	{
		cout << "Cat析构函数调用!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}

public:
	string *m_Name;
};

void test01()
{
	Animal *animal = new Cat("Tom");
	animal->Speak();

	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



总结：

​	1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象

​	2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构

​	3. 拥有纯虚析构函数的类也属于抽象类



##### 4.7.6 多态案例三-电脑组装



```c++
#include<iostream>
using namespace std;

class CPU {
public:
	virtual void calculate() = 0;
};

class VirtualCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class Computer {
public:
	Computer(CPU* cpu, VirtualCard* vc, Memory* mem) {
		m_CPU = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	~Computer() {
		if (m_CPU != NULL) {
			delete m_CPU;
			m_CPU = NULL;
			cout << "CPU停止工作了" << endl;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
			cout << "显卡停止工作了" << endl;

		}	
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
			cout << "内存停止工作了" << endl;

		}
	}
	void work() {
		cout << "电脑开始工作了" << endl;
		m_CPU->calculate();
		m_vc->display();
		m_mem->storage();
	}

private:
	CPU* m_CPU;
	VirtualCard* m_vc;
	Memory* m_mem;
};

class ICPU :public CPU {
public:
	virtual void calculate() {
		cout << "I的CPU开始工作了" << endl;
	}
};

class IVirtualCard :public VirtualCard {
public:
	virtual void display() {
		cout << "I的显卡开始工作了" << endl;
	}
};

class IMemory :public Memory {
public:
	virtual void storage() {
		cout << "I的内存开始工作了" << endl;
	}
};

class ACPU :public CPU {
public:
	virtual void calculate() {
		cout << "A的CPU开始工作了" << endl;
	}
};

class AVirtualCard :public VirtualCard {
public:
	virtual void display() {
		cout << "A的显卡开始工作了" << endl;
	}
};

class AMemory :public Memory {
public:
	virtual void storage() {
		cout << "A的内存开始工作了" << endl;
	}
};



void test01(){
	Computer* c1=new Computer(new ICPU, new AVirtualCard, new IMemory);
	c1->work();
	delete c1;
	cout << "c1停止工作了" << endl << endl;

	Computer* c2 = new Computer(new ACPU, new AVirtualCard, new AMemory);
	c2->work();
	delete c2;
	cout << "c2停止工作了" << endl << endl;

}

int main() {
	test01();
	system("pause");
	return 0;
}

```



### 5 文件操作

程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过**文件可以将数据持久化**

C++中对文件操作需要包含头文件 ==&lt; fstream &gt;==



文件类型分为两种：

1. **文本文件**     -  文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件** -  文件以文本的**二进制**形式存储在计算机中，用户一般不能直接读懂它们



操作文件的三大类:

1. `ofstream`：写操作
2. `ifstream`： 读操作
3. `fstream` ： 读写操作



#### 5.1文本文件

##### 5.1.1写文件

写文件步骤如下：

1. 包含头文件   

	\#include <fstream\>

2. 创建流对象  

	ofstream ofs;

3. 打开文件

	ofs.open("文件路径",打开方式);

4. 写数据

	ofs << "写入的数据";

5. 关闭文件

	ofs.close();

	

文件打开方式：

| 打开方式    | 解释                       |
| ----------- | -------------------------- |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建 |
| ios::binary | 二进制方式                 |

**注意：** 文件打开方式可以配合使用，利用|操作符

**例如：**用二进制方式写文件 `ios::binary |  ios:: out`

```c++
#include <iostream>
#include <fstream>
using namespace std;

void test01() {
	//文本文件 写入操作
	//1.头文件fstream
	
	//2.创建流对象
	ofstream a;

	//3.指定打开方式
	a.open("C:\\Users\\lenovo\\Desktop\\test.txt", ios::out);

	//4.写内容
	a << "姓名：小王" << endl;
	a << "年龄：18" << endl;
	a << "性别：男" << endl;

	//5.关闭文件
	a.close();
}

int main() {

	test01();
	system("pause");
	return 0;
}

```



总结：

* 文件操作必须包含头文件 `fstream`
* 读文件可以利用 `ofstream` ，或者`fstream`类
* 打开文件时候需要指定操作文件的路径，以及打开方式
* 利用<<可以向文件中写数据
* 操作完毕，要关闭文件



##### 5.1.2读文件

读文件与写文件步骤相似，但是读取方式相对于比较多



读文件步骤如下：

1. 包含头文件   

	\#include <fstream\>

2. 创建流对象  

	ifstream ifs;

3. 打开文件并判断文件是否打开成功

	ifs.open("文件路径",打开方式);

4. 读数据

	四种方式读取

5. 关闭文件

	ifs.close();



```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01() {
	//文本文件 读文件

	//1.包含头文件

	//2.创建流对象
	ifstream a;

	//3.打开文件 并且判断是否打开成功
	a.open("C:\\Users\\lenovo\\Desktop\\test.txt", ios::in);

	if (!a.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读数据

	//第一种方式（字符数组）
	//char buf[1024] = { 0 };
	//while (a >> buf) {
	//	cout << buf << endl;
	//}

	//第二种方式（字符数组）
	//char buf[1024] = { 0 };
	//while (a.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}

	//第三种方式（字符串）
	string buf;
	while (getline(a, buf)) {
		cout << buf << endl;
	}

	//第四种（不推荐）
	//char c;
	//while ((c = a.get()) != EOF) {
	//	cout << c;
	//}

	//5.关闭文件
	a.close();

}

int main() {

	test01();
	system("pause");
	return 0;
}
```



总结：

- 读文件可以利用 ifstream  ，或者fstream类
- 利用is_open函数可以判断文件是否打开成功
- close 关闭文件 



#### 5.2 二进制文件

以二进制的方式对文件进行读写操作

打开方式要指定为 ==ios::binary==



##### 5.2.1 写文件

二进制方式写文件主要利用流对象调用成员函数write

函数原型 ：`ostream& write(const char * buffer,int len);`

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数



```c++
#include <iostream>
#include <fstream>
using namespace std;

//二进制文件 写文件
class Person {
public:
	char m_Name[64];
	int m_Age;
};

void test01() {
	//1.包含头文件
	//2.创建流对象
	ofstream a;

	//3.打开文件（打开方式为二进制写入）
	a.open("C:\\Users\\lenovo\\Desktop\\person.txt", ios::out | ios::binary);

	//4.写文件
	Person p = { "张三",18 };
	a.write((const char*)&p, sizeof(Person));
	//5.关闭文件
	a.close();
}

int main() {

	test01();
	system("pause");
	return 0;
}
```



- 文件输出流对象 可以通过write函数，以二进制方式写数据



##### 5.2.2 读文件



二进制方式读文件主要利用流对象调用成员函数read

函数原型：`istream& read(char *buffer,int len);`

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数



```c++
include <iostream>
#include <fstream>
using namespace std;


class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//二进制文件 读文件
void test01() {
	//1.包含头文件
	//2.创建流对象
	ifstream a;

	//3.打开文件 判断文件是否打开成功
	a.open("C:\\Users\\lenovo\\Desktop\\person.txt", ios::in | ios::binary);
	if (!a.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读文件
	Person p;
	a.read((char*)&p, sizeof(Person));

	cout << p.m_Name << endl << p.m_Age << endl;

	//5.关闭文件
	a.close();
}


int main() {

	test01();
	system("pause");
	return 0;
}

```



- 文件输入流对象 可以通过read函数，以二进制方式读数据







## C++提高编程

- C++==泛型编程==和==STL==技术

### 1 模板

#### 1.1 模板的概念

模板就是建立**通用的模具**，大大提高复用性

模板的特点：

* 模板不可以直接使用，它只是一个框架
* 模板的通用并不是万能的



#### 1.2 函数模板

- 泛型编程思想


* 两种模板机制:**函数模板**和**类模板** 



##### 1.2.1 函数模板语法

**作用**：

建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个**虚拟的类型**来代表。

**语法：** 

```C++
template<typename T>
函数声明或定义
```

**解释：**

template  ---  声明创建模板

typename  --- 表面其后面的符号是一种数据类型，可以用class代替

T    ---   通用的数据类型，名称可以替换，通常为大写字母

```c++
#include <iostream>
using namespace std;

//利用模板提供通用的交换函数
template <typename T>

void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 3, b = 4;
	double c = 1.1, d = 2.2;
	//方法1：自动类型推导
	mySwap(a, b);
	cout << "a=" << a << '\t' << "b=" << b << endl;

	mySwap(c, d);
	cout << "c=" << c << '\t' << "d=" << d << endl;

	//方法2：指定类型
	mySwap<int>(a, b);
	cout << "a=" << a << '\t' << "b=" << b << endl;

	mySwap<double>(c, d);
	cout << "c=" << c << '\t' << "d=" << d << endl;

}


int main() {
	test01();

	system("pause");
	return 0;
}
```

总结：

* 函数模板利用关键字 `template`
* 使用函数模板有两种方式：自动类型推导、显示指定类型
* 模板的目的是为了提高复用性，将类型参数化



##### 1.2.2 函数模板注意事项

注意事项：

* 自动类型推导，必须推导出一致的数据类型T,才可以使用


* 模板必须要确定出T的数据类型，才可以使用



##### 1.2.3 函数模板案例

案例描述：

* 利用函数模板封装一个排序的函数，可以对**不同数据类型数组**进行排序
* 排序规则从大到小，排序算法为**选择排序**
* 分别利用`char`数组和`int`数组进行测试

```c++
#include <iostream>
using namespace std;

//使用模板函数对数组进行排序
//排序规则 从小到大
//排序算法 选择排序
//测试用例 int char double 数组

//显示函数模板
template<typename T>
void showArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//交换函数模板
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//排序函数模板
template<typename T>
void mySort(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		int min = i;//设定默认最小值
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			//交换min与i
			mySwap(arr[min], arr[i]);
		}
	}
}


void test01() {
	char charArr[] = "bdacef";
	cout << "排序前的字符数组：";
	showArray(charArr, sizeof(charArr)-1);

	mySort(charArr, sizeof(charArr)-1);
	
	cout << "排序后的字符数组：";
	showArray(charArr, sizeof(charArr)-1);
}

void test02() {
	int intArr[6] = { 3,2,4,6,5,1 };
	cout << "排序前的整形数组：";
	showArray(intArr, sizeof(intArr)/4);

	mySort(intArr, sizeof(intArr)/4);

	cout << "排序后的整形数组：";
	showArray(intArr, sizeof(intArr)/4);
}

int main() {
	
	test01();
	test02();

	system("pause");
 	return 0;
}

```





##### 1.2.4 普通函数与函数模板的区别

普通函数与函数模板区别：

* 普通函数调用时可以发生自动类型转换（隐式类型转换）
* 函数模板调用情况1：如果利用自动类型推导，不会发生隐式类型转换
* 函数模板调用情况2：如果利用**显示指定类型**的方式，可以发生隐式类型转换



**示例：**

```C++
//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myAdd02(T a, T b)  
{
	return a + b;
}

//使用函数模板时，如果用自动类型推导，不会发生自动类型转换,即隐式类型转换
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	
	cout << myAdd01(a, c) << endl; //正确，将char类型的'c'隐式转换为int类型  'c' 对应 ASCII码 99

	//myAdd02(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换

	myAdd02<int>(a, c); //正确，如果用显示指定类型，可以发生隐式类型转换
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

总结：**建议使用显示指定类型的方式**，调用函数模板，因为可以自己确定通用类型T





##### 1.2.5 普通函数与函数模板的调用规则

调用规则如下：

1. 如果函数模板和普通函数都可以实现，优先调用普通函数
2. 可以通过空模板参数列表来强制调用函数模板
3. 函数模板也可以发生重载
4. 如果函数模板可以产生更好的匹配,优先调用函数模板





**示例：**

```C++
//普通函数与函数模板调用规则
void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b) 
{ 
	cout << "调用的模板" << endl;
}

template<typename T>
void myPrint(T a, T b, T c) 
{ 
	cout << "调用重载的模板" << endl; 
}

void test01()
{
	//1、如果函数模板和普通函数都可以实现，优先调用普通函数
	// 注意 如果告诉编译器  普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
	int a = 10;
	int b = 20;
	myPrint(a, b); //调用普通函数

	//2、可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b); //调用函数模板

	//3、函数模板也可以发生重载
	int c = 30;
	myPrint(a, b, c); //调用重载的函数模板

	//4、 如果函数模板可以产生更好的匹配,优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //调用函数模板
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性



##### 1.2.6 模板的局限性

局限性：

* 模板的通用性并不是万能的



**例如：**

```C++
	template<class T>
	void f(T a, T b)
	{ 
    	a = b;
    }
```

在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了



再例如：

```C++
	template<class T>
	void f(T a, T b)
	{ 
    	if(a > b) { ... }
    }
```

在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行



因此C++为了解决这种问题，提供模板的重载，可以为这些**特定的类型**提供**具体化的模板**



**示例：**

```C++
#include<iostream>
using namespace std;

#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<> bool myCompare(Person &p1, Person &p2)
{
	if ( p1.m_Name  == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	//内置数据类型可以直接使用通用的函数模板
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main() {

	test01();

	test02();

	system("pause");

	return 0;
}
```

总结：

* 利用具体化的模板，可以解决自定义类型的通用化
* 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板



#### 1.3 类模板

##### 1.3.1 类模板语法






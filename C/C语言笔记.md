## 变量和常量

### 标识符

对象的名字

- 只能出现下划线、字母或数字


- 必须以字母或者下划线开头


- 区分大小写

###常量的类型

`char`、`short`、`int`、`long`、`long long`、`float`、`double`

```c
printf("%d",sizeof(int));
//sizeof显示变量大小
```



### 常量的分类

1. 字面常量

	```c
	3.14;10;'a';"abcd"
	```

	

2. `const`修饰的常变量

	

	```c
	const int num =10;
	//不能被改变
	```

	

3. `#define`定义的标识符常量

	

	```c
	#define max = 10000;
	```

	

4. 枚举常量

	可以一一列举的常量

	```c
	enum Sex 
	{
	    //变量的未来可能取值
	    MALE,
	    FEMALE,
	    SECRET
	    //MALE=3赋初值后，printf输出3,4,5
	};
	int main()
	{
	    enum Sex s = MALE;
	    printf("%d\n",MALE);//0
	    printf("%d\n",FEMALE);//1
	    printf("%d\n",SECRET);//2
	    return 0;
	}
	```



### 局部变量和全局变量

1. **全局变量**

	- 函数{ }外部定义的，作用域是**整个工程**

	- 如果要使用（在另外的文件定义的）全局变量需要声明 

		```c
		extern int a;
		```

		

2. **局部变量**

	- 函数{ }内部定义的，作用域是所在的{ }
	- 二者冲突时**局部优先**

### 变量的储存方式和生存期

#### 动态存储和静态存储

- 三种存储空间：程序区、静态存储区和动态存储区

- 四种存储类别：`auto`、`statis`、`register`、`extern`

#### 局部变量的存储类别（3种）

1. 自动变量（auto）—— 默认

2. 静态局部变量（[static](#static)）

	`static int n = 3;`

	- 函数调用结束后不释放，保留当前值
	- 若非必要尽量少用

3. 寄存器变量（register）

	- 存储在CPU寄存器中
	- 频繁调用时提高存取速度
	- 不必要

#### 全局变量的存储类别

1. `extern`将外部变量作用域扩展到其他函数

2. `extern`将外部变量作用域扩展到其他文件

	```c
	extern int a;
	```

3. 限制外部变量的作用域在本文件中

	```c
	static int a;
	```

#### 用`static`修饰变量

<a name="static"></a>

1. 修饰局部变量——整个程序运行期间保留内存
2. 修饰全局变量——限制作用域在当前文件

-  函数中加“static”的含义不是指存储方式，而是指对**函数的作用域仅局限于本文件**。

## 循环结构

### while循环

```c
int main(){
	int ch = 0;
    whlie((ch = getchar()) != EOF)		//输入正确字符时打印
        putchar(ch);
    return 0;
}
```



```C
int main(){
    char password[20] = {0};
    printf("请输入密码：>");
    scanf("s", password);
    printf("请确认密码（Y/N）：>");
    //清理缓冲区
    //getchar();					//只能处理'\n'
    int tmp = 0;
    whlie((tmp = getchar()) !=  '\n'){//清理缓冲区
        ;
    }
    int ch = getchar();
    if (ch = 'Y'){
        printf("确认成功\n");
    }
    if (ch = 'N'){
        printf("确认失败\n");
    }
    return 0;
}
```



### for循环

- 不要在循环体内部改变循环变量

- 变量取值建议**前闭后开**

	`for ( i = 0; i < 10; i++)`

- 可以用多个循环变量控制



### `goto`语句跳转

```c
int main(){
flag:
	printf("111");
	printf("222");
    goto flag;
	return 0;
}
```

- **只能在本函数内跳转**，不能跨函数
- 可用于**一次跳出多层循环**
- 不建议滥用



## 操作符

### 算数操作符

除法：/，默认做整数除法，得到商

若符号两端有一个为小数，默认做double型的除法，得到double型

取模：%，左右必须为整数，得到余数

### 移位操作符

`<<` 左移操作符				`>>` 右移操作符

- 移位操作符的**操作数只能是整数**。
- 移动整数的二进制位，且**不改变自身的值**
- 不能移动负数位   eg：`num << -1` 是错误的

#### 整数的三种二进制位表示

<a name="complement"></a>

原码反码补码的转换

原码<->补码：**取反加1**

1. 原码：原数值的二进制表示
2. 反码：原码**符号位不变**，其余位取反
3. 补码：反码+1

- **正数**原码反码补码一致，负数不同

- 在计算机系统中，数值一律用补码来表示和存储。

	原因在于，使用补码，可以将符号位和数值域统一处理； 同时，加法和减法也可以统一处理（CPU只有加法器）此外，补码与原码相互转换，其运算过程是相同的，不需要额外的硬件电路。

左移操作符——左边抛弃，右边补0

<img src="https://s2.loli.net/2021/12/19/wXHW6xzmot9qLiu.png" alt="image-20211219143413532" style="zoom:80%;" />

右移运算分两种： 

1. 逻辑右移——左边用0填充，右边丢弃
2. 算术右移——左边用**原符号填充**，右边丢弃（更常用）

<img src="https://s2.loli.net/2021/12/19/l4TquAiQBnxjEh3.png" alt="image-20211219143442158" style="zoom:50%;" />

### 位操作符

`&` —— 按位与	 `|` —— 按位或	 `^` —— 按位异或

异或：**相同为0，相异为1**（可用于交换两个变量的值）

- 操作数必须是整数
- 按二进制位计算

### 赋值操作符

- 可以连用（从右向左）
- 复合赋值   `+=` `-=`

### 单目操作符

<img src="https://s2.loli.net/2021/12/19/jsnIz6BYrxFZDNa.png" alt="image-20211219173058202" style="zoom: 80%;" />

#### `sizeof`求内存大小

```c
int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
a = sizeof(arr1) / sizeof(arr[0]);		//求数组元素个数
char c[] = "abcdefg";
b = sizeof(c) / sizeof(c[0]) -1;		//求字符串字符个数——由于包含'\0'，所以要减1
sz = sizeof c;							
//sizeof加变量名时，可省略括号，这说明sizeof是个操作符，而不是函数
```

- `sizeof`括号内的表达式不参与运算

### 关系操作符

<img src="https://s2.loli.net/2021/12/19/4Hak2O5q3zpNx1u.png" alt="image-20211219181349474" style="zoom:50%;" />

###逻辑操作符

<img src="https://s2.loli.net/2021/12/19/8IemuWs4ZUSVDfz.png" alt="image-20211219181431450" style="zoom:67%;" />

### 条件操作符（三目）

`exp1 ? exp2 : exp3`

exp1真，执行exp2，为假则执行exp3

### 逗号表达式

`exp1, exp2, exp3, …expN`

- 用逗号隔开的多个表达式。
- 从左向右依次执行
- 整个表达式的结果是最后一个表达式的结果

### 转义字符

```c
int main()      //转义字符
 {
    printf("c:\test\32\test.c");
    printf("c:\\test\\32\\test.c");
    //	\\ 表示将\变为一个普通字符
    printf("%c", '\'');           
    //	\' 表示将'变为一个普通字符
    printf("%c", '\"');            
    //	\" 表示将"变为一个普通字符
    printf("%s", "abc");           				// 	printf("%s"，)打印字符串
    printf("%c\n%c\n%c\n",'\132',90,'Z'); 
    // \132 表示132的八进制数字--90--Z
    printf("%c\n%c\n%c\n", '\x61',97,'a');
    //  \x61 同理表示61的16进制数字--97--a
    printf("123\t321\n");   
    //	\t为tab(水平制表符），\n为换行
    return 0;
}
```





### 下标引用、函数调用和结构成员

#### 下标引用操作符

<img src="https://s2.loli.net/2021/12/19/py3hk7nidOVQZ6C.png" alt="image-20211219182829797" style="zoom: 50%;" />

####  函数调用操作符( ) 

- 接受一个或者多个操作数
- 第一个操作数是函数名，剩余的操作数就是传递给函数的参数

####  [访问结构体成员](#struct)

<img src="https://s2.loli.net/2021/12/19/CD8hwegRskI1FqV.png" alt="image-20211219183037374" style="zoom: 50%;" />

### 表达式求值

有些表达式的操作数在求值的过程中可能需要**转换为其他类型**

#### 整形提升

CPU一般运算整形，char short 在运算时就需要整形提升

提升方法：**补符号位**

#### 算术转换

例如int转化为float再进行运算



## 注释

`//`和`/*  */`------用来解释复杂代码

- `/*	*/`不支持嵌套注释



## 数组

一组相同类型元素的集合

### 一维数组

#### 数组的定义

`int arr[3]`

- c99标准才支持变量为数组大小

#### 数组的初始化

`int arr[10]={0};`

- 可以不完全初始化
- 可以不指定大小，以初始化的内容确定数组大小

#### 数组的引用

- 以下标引用，下标从0开始
- 还可用指针引用

####  一维数组在内存中的存储

- %p--按地址格式打印，十六进制
- 数组在内存中是连续存放的
- 随着数组下标增长，地址由低到高变化

### 二维数组的创建和初始化

#### 二维数组的初始化

```c
//数组初始化
int arr[3][4] = {1,2,3,4};
int arr[3][4] = {{1,2},{4,5}};
int arr[][4] = {{2,3},{4,5}};//二维数组如果有初始化，行可以省略，列不能省略
```

- 不完全初始化：后面补0，字符型补'\0'

#### 二维数组的使用

- 行标列标从0开始

#### 二维数组在内存中的存储

- 与一维数组类似
- 可以这样理解“二维数组由几个一维数组构成”
- 注意写代码时不要使数组越界

### 数组作为函数参数

1. 数组元素作函数参数

  - 只能用作**实参**


  - **“值传递”** 单向传递

2. 数组名作函数参数

	- 传递**数组首元素的地址**


**数组大小不能在函数内计算！！！！！**



## 字符串

字符数组

### 初始化

```c
char c[]={'i','','a','m','','h','a','p','p','y'};		//长度为10
char c[]={'i','','a','m','','h','a','p','p','y','\0'};	//长度为11	
char c[]={"i am happy"};	//长度为11
char c[]="i am happy";		//长度为11
```

### 结束标志

`\0`是字符串的结束标志，值为0

### 输入输出

1. `%c`逐个输入输出

2. `%s`整个输入输出

	```c
	char c=[10];
	scanf("%s",c);
	char str1[5],str2[5],str3[5];
	scanf("%s%s%s",str1,str2,str3);
	```

### 字符串处理函数

除了`gets`和`puts`，都需要头文件`#include<string.h>`

```c
#include<stdio.h>
#include<string.h>
int main()
{
    char str1[10]="abc";
    char str2[10]="def";
    char str3="aabbcc";
    char str4;
    char str5[10];
    gets(str1);//输入字符串
    puts(str1);//输出字符串
    printf("%s",strcat(str1,str2));//字符串连接
    strcpy(str5,str3);//字符串3复制到5中
    strcpy(str5,"i am happy");
    printf("%s",strncpy(str1,str2,2));//deabc
    printf("%d",strcmp(str1,str2));//字符串比较(ASCII码)得出结果：0或正整数或负整数
    printf("%d",strlen(str3));//6--计算长度（不包括\0）
    printf("%d",strlen("China"));//5
    strlwr(str);//转小写
    strupr(str);//转大写
    return 0;
}
```





## 函数

### 定义函数

```c
int max(int a,int b)
{
    a>b?(z=a):(z=b);
    return z;
}
//类型 函数名 ( 形参 )
//{ 函数体 }
```

- 可以无参数，可以无函数体
- **函数类型决定返回值类型**
- 不返回值的函数应该定义为void类型
- 一个函数如果不写返回类型，默认返回`int`类型

### 调用函数

```c
a=max(x,y);
//函数名 ( 实参表列 );
```

- **传值调用**：传递实参的值给形参，不改变实参
- **传址调用**：把外部变量的内存地址传递给函数参数，函数内部可以直接操作函数外部的变量，**可以改变**实参的值

### 对被调用函数的声明

- 若函数写在主函数**后面**，则需要在主函数中对被调用函数作声明，写在前面则不用

```c
int main()
{
    int max(int a, int b);	//声明函数的两种写法
    int max(int,int);		//可以只写形参的类型
    
    return 0;
}
int max(int a,int b)
{
    
}
```

- 函数原型：函数的首行

### 形参和实参

- 实参可以是**常量**、**变量**、**表达式**、**函数**等

- 形参只在函数中有效，只建立临时内存空间

- 形参实例化之后相当于实参的一份**临时拷贝**

	

### 嵌套调用和递归调用

拆解、简化、分段

Hanoi塔问题

#### 栈溢出 `Stack Overflow`

递归层次太深可能出现栈溢出

内存中分为**栈区**、**堆区**、**静态区**

- 栈区存放局部变量和函数形参等临时变量
- 堆区动态分配内存：`malloc/free`,`calloc`,`realloc`
- 静态区存放全局变量和静态变量



## 指针

### 初识指针

指针就是地址

指针的大小：4/8个字节

32位平台——4个字节，64位——8个字节

```c
int a = 10;
int * pointer_a = &a;
*pointer_a = 20;			//解引用操作 通过pointer_a里的地址找到a
char ch = 'w';
char* poiner_c = &ch;
```

- pointer_a是指针变量，用来存放地址
- `*`说明pointer_a是指针变量
- `int`说明pointer_a执行的对象是`int`型的

### 指针的概念

- 一个变量的**地址**叫做**指针**


- 存放地址的变量叫做**指针变量**，他用来指向另一个对象


### 定义指针变量

类型名 * 指针变量名		`int * p  `

`int`为**基类型**，是指针指向变量的数据类型

### 引用指针变量

```c
int a = 1;
int * p = &a;
//p = &a;
printf("%d", *p);
```

- 指针作为函数参数——**地址传递，双向**
- 值作为函数参数——值传递，单向

### 通过指针引用数组

```c
int * p = &a[0];
int * p = a;			//两语句等价

for(i=0;i<10;i++) printf("%d",a[i]);					//第一种
for(i=0;i<10;i++) printf("%d",*(a+i));					//第二种
for(p=a;p<(a+10);p++) printf("%d",*p);					//第三种(可不写*)
//第一第二种较明确，第三种效率较高
```



- 自动根据数组元素的类型加上对应字节数，使它**指向下一个元素**
- 指向同一数组的指针变量**可以相减**，代表两元素之间相差几个元素，**指针变量不能相加**
- `*p++`的意义：先引用*p的值，再使p++
- 单目运算符**自右向左**结合

```c
//输出a数组的100个元素
p = a;
while(p < (a + 100)){
    printf("%d", *p++);
//printf("%d",*p); 
//p++;
}
```



### 指针引用多维数组

- 二维数组中，`a[i]`表示第i行第0列元素的地址，a+2代表第二行首地址

- *(a+2)



### 指针指向一个格式字符串

可代替`printf`中的格式字符串

```c
char* format;
format = "a=%d,b=%d\n";
printf("format,a,b");
//等价于printf("a=%d,b=%d\n,a,b");
```



### *多个概念的区分

- 指针
	1. 列指针 `int *p`
	2. 行指针 `int(*p)[m]`
	3. 指向函数的指针`int(*p)(int,int)`
	4. 多重指针`int**p`

- 非指针
	1. 指针数组——数组  `int *p[m]`
	2. 返回指针的函数`int*max(int,int)`





## 自定义类型

自定义类型：结构体 枚举 联合（共用体）

### 结构体

<a name="struct"></a>

结构体可以让c语言创建新的类型



```c
struct Student{			//结构体的创建
    char name[20];
    int age;
    double score;
};

int main(){
    struct Student s = {"张三", 20, 85.5};  //结构体的初始化
    printf("%s %d %lf\n", s.name, s.age, s.score);
    				//结构体变量.成员变量
    struct Student * ps = &s;
    printf("%s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
    				//等价
    printf("%s %d %lf\n", ps->name, ps->age, ps->score);
    				//结构体指针->成员名
    retuen 0;
}
	
```



- 定义和初始化

```c
struct Stu        //类型声明
{
 char name[15];//名字
 int age;      //年龄
};

struct Stu s = {"zhangsan", 20};//初始化

struct Node
{
 int data;
 struct Point p;
 struct Node* next; 	//结构体的自引用，链表
}n1 = {10, {4,5}, NULL}; //结构体嵌套初始化
struct Node n2 = {20, {5, 6}, NULL};//结构体嵌套初始化
```



- 结构体内存对齐

结构体的对齐规则：

1. 第一个成员在与结构体变量偏移量为0的地址处。
2.  其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。 对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。 VS中默认的值为8 
3.  结构体总大小为最大对齐数的整数倍。 
4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

设计结构体时节省空间：**将占用空间小的成员尽量放在一起**

- 修改默认对齐数

	`# pragma pack()`

- 计算偏移量

	`offsetof()`

```c
#include <stdio.h>
#pragma pack(4)//设置默认对齐数为4
struct S1
{
 char c1;
 int i;
 char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
int main(){
    printf("%d\n",offsetof(struct S1, i));//求结构体中某个元素的偏移量
    return 0;
}
```



### 结构体传参

**传地址**效率较高



### 位段

#### 位段的定义

位段的声明和结构是类似的，有两个不同： 

1.位段的成员必须是 `int`、`unsigned int` 或`signed int` 。 

2.位段的成员名后边有一个冒号和一个数字。

```c
struct A
{
 int _a:2;			//_a成员占2个bit位，可用来节省空间
 int _b:5;
 int _c:10;
 int _d:30;
};
```



#### 位段的内存分配

1. 位段的成员可以是 `int、 unsigned int 、signed int` 或者是 `char` （属于整形家族）类型
2. 位段的空间上是按照需要以4个字节（ `int` ）或者1个字节（ `char` ）的方式来开辟的。
3. 位段涉及很多不确定因素，位段是**不跨平台**的，注重可移植的程序应该避免使用位段。



### 枚举

- 定义枚举类型

```c
enum Sex//性别
{
 MALE,
 FEMALE,
 SECRET
}；
enum Sex s1 = MALE;
```

值依次递增1

默认从0开始



## C语言文件操作

### 文件的分类

- 程序文件

1. 源程序文件（后缀为.c）
2. 目标文件（windows环境后缀为.obj）
3. 可执行程序（windows环境 后缀为.exe）

- 数据文件

程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件。

### 文件名

一个唯一的文件标识，以便用户识别和引用。

包含3部分：文件路径+文件名主干+文件后缀 

例如： `c:\code\test.txt`

### 文件的打开和关闭

- 文件指针

`stdio.h`中定义的结构体，取名为`FILE`

- 打开和关闭

`fopen`和`fclose`

<img src="https://s2.loli.net/2021/12/25/XVFN8S9iIZxzgQe.png" alt="image-20211225151630581" style="zoom:50%;" />

```c
/* fopen fclose example */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  //打开文件
  pFile = fopen ("myfile.txt","w");
  if (pfile == NULL){
      perror("fopen");
      return 1;
  }
  //文件操作
  fputs("abcd",pFile);
  //关闭文件
  fclose (pFile);
  return 0;
}
```



### 文件的顺序读写

<img src="C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211225151801688.png" alt="image-20211225151801688" style="zoom:50%;" />









## 数据的存储

### 整形在内存中的的存储

#### [1.原码、反码、补码](#complement)

#### 2.大小端

数据在内存中的存放顺序

大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位保存在内存的低地址中

小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位保存在内存的高地址中（逆序）

可通过共用体简单判断

```c
union a{
    short s;
    char c[2];
};
a1.s=0x1234;
//查看c[1]和c[2]的值即可判断大小端存储
```



### 浮点型在内存中的存储

与整数的存储有区别

- 浮点数存储规则：**(-1) ^ S * M * 2 ^ E** 

(-1)^s表示符号位，当s=0，V为正数；当s=1，V为负数

 M表示有效数字，大于等于1，小于2（小数点前的1不存，默认）

 2^E表示指数位（存储时要加上127或1023以表示负数）

![image-20220105225826024](https://s2.loli.net/2022/01/05/pRTZ7xLGOXaukhz.png)













## 其他

### 用`typedef`声明新类型名

类型重命名			

```c
typedef unsigned int ui;
int main()
{
	unsigned int num1=100;
    ui num2=300；
    return 0;
}
```



### C语言中生成随机数

`srand` -- 初始化随机种子

`time` -- 生成秒数

`rand` -- 生成伪随机值

```c++
void test_rand(void)
    {
    unsigned long n;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 100; i++)
    {
        n = rand();
        printf("d\n", n);
    }
}
```


## 《C语言进阶》 ilearning课程
- const 主要看const在*的左侧还是右侧  
  const int* p1; // p1指向的const变量不能更改，const在*左侧  
  int const *p2; // p2指向的const变量不能更改，const在*左侧，只是写法不同

  int* const p3; // p3常量指针，指向固定的一个地址，const在*右侧  
  const int *const p4; // 常量指针，指向的const内容都不能更改



- 不同的数据模型（操作系统或者配置），int，long占用的字节不一致。
例如：  
(ILP32)32bit Linux: sizeof(int) == sizeof(long) == sizeof(char*) == 4  
(LP64)64bit Linux: sizeof(long) == sizeof(char*) == 8

- 浮点数据类型float,double是不能用unsigned修饰的。
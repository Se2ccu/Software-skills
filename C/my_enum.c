#include <stdio.h>

typedef enum {
    E1,                 // 默认从0开始，并依次递增
    E2 = 0x123456789,   // 尽量不要超过4字节,否者出现异常，有的编译器会对其进行截断
    E3 = 1,             // 中间可以单独指定值
    E4                  // 基于上一个值增加
} MyEnum;


int main()
{
    /* 不要对枚举变量或者其成员进行sizeof()操作，因为其大小与编译器有关，因此结构体中不要用枚举 */
    printf("sizeof(MyEnum) = %d\n", sizeof(MyEnum));
    printf("sizeof(E1) = %d\n", sizeof(E1));
    printf("sizeof(E2) = %d\n", sizeof(E2));
    return 0;
}
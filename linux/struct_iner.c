#include <stdio.h>
/* 嵌套结构体赋值 
    1.memcpy实现
    2.定义局部变量，然后用结构体赋值
*/
typedef struct {
    int a;
    int b;
} Stu1;

typedef struct {
    int c;
    char d;
} Stu2;

typedef struct {
    Stu1 st1;
    Stu2 st2;
} Stu3;

int main ()
{
    // 适用于小端CPU
    char data[16] = {1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0};
    char data1[16] = {5, 0, 0, 0, 6, 0, 0, 0, 7, 0, 0, 0, 8, 0, 0, 0};
    printf("struct inner sizeof(int) = %d\n", sizeof(int));

    Stu1 *s1 = (Stu1 *)data;
    printf("s1.a = %d s1.b = %d \n", s1->a, s1->b);
    Stu2 *s2 = (Stu2 *)(s1 + 1);
    printf("s2.c = %d s2.d = %d \n", s2->c, s2->d);
    Stu2 *s22 = (Stu2 *)((char *)data1 + sizeof(Stu1));    
    printf("s22.c = %d s22.d = %d \n", s22->c, s22->d);
    
    Stu3 *s3 = (Stu3 *)data;
    printf("s3->st1.a = %d s3->st1.b = %d s3->st2.c = %d s3->st2.d = %d  \n",
        s3->st1.a, s3->st1.b, s3->st2.c, s3->st2.d);

    /* 1.malloc 申请内存，然后memcpy拷贝拼接 */
    Stu3 *s4 = (Stu3 *)malloc(sizeof(Stu3));
    memcpy(s4, s1, sizeof(Stu1));
    memcpy((char *)s4 + sizeof(Stu1), s22, sizeof(Stu2));
    printf("s4->st1.a = %d s4>st1.b = %d s4->st2.c = %d s4->st2.d = %d  \n",
        s4->st1.a, s4->st1.b, s4->st2.c, s4->st2.d);
    
    /* 2.局部结构体栈内存 直接赋值拼接 */
    Stu3 s5;
    s5.st1 = *s1;
    s5.st2 = *s22;
    /* memcpy等效实现 */
    //memcpy(&s5, s1, sizeof(Stu1));
    //memcpy((char *)&s5 + sizeof(Stu1), s22, sizeof(Stu2));
    printf("s5.st1.a = %d s5.st1.b = %d s5.st2.c = %d s5.st2.d = %d  \n",
        s5.st1.a, s5.st1.b, s5.st2.c, s5.st2.d);
    return 0;
}
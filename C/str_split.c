 /******************************************************************************
  文 件 名   : my_string.c
  作    者   : Zhoutaoccu
  生成日期   : 2021年4月23日
  功能描述   : 字符串处理,拼接
******************************************************************************/ 

#include <stdio.h>
#include <string.h>

int main()
{
    printf("Hello String!\n\r");

    char localname[128] = {0};
    int len;

    char str1[128] = "/tftpboot/can_fan_.bin";
    char str2[128] = "/tftpboot/can_fan_v22.bin";
    char str3[128] = "/tftpboot/can_fan.bin";

    char *p = strstr(str1, "_v");
    if (p == NULL) {
        len = strlen(str1);
    }
    len = p - str1;

    strncpy(localname, str1, len);
    printf("localname = %s\n", localname);

    strcat(localname, "_v21.bin");

    printf("localname = %s\n", localname);
    return 0;
}
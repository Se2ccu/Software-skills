#include <stdio.h>
#include <string.h>


int strStr(char * haystack, char * needle){
    if (haystack == NULL || needle == NULL) {
        return -1;
    }
    int len_hay = strlen(haystack);
    int len_needle = strlen(needle);
    int begin, i, j;
    for (i = 0; i < len_hay; i++) {
        begin = i;
        for (j = 0; j < len_needle; j++) {
            if (begin + j > len_hay) {
                break;
            }
            if (haystack[i] == needle[j]) {
                begin++;
                continue;
            } else {
                break;
            }
        }
    }
    return begin;
}

int main()
{
    printf("Hello String!\n\r");

    char localname[128] = {0};

    char str1[128] = "an_v.bin";

    printf("result = %d\n", strStr(str1, "_v.bin1"));
    return 0;
}

#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc,qsort */
#include <string.h>  /* strcpy,strcmp */

int isnum(char a) {
    if (a >= '0' && a <= '9') {
        return 1;
    }
    return 0;
}

char lowcase(char a) {
    if (a >= 'A' && a <= 'Z') {
        a += 32; 
    }
    return a;
}

int isPalindrome(char * s) {
    if (s == NULL) {
        return 1;
    }
    int length = strlen(s);
    int i, j;
    i = 0;
    j = length - 1;
    while (i < j) {
        if (!(isalpha(s[i]) || isnum(s[i]))) {
            i++;
            continue;
        }
        if (!(isalpha(s[j]) || isnum(s[j]))) {
            j--;
            continue;
        }
        printf("%c %c\n", s[i], s[j]);

        if (lowcase(s[i]) != lowcase(s[j])) {
            printf("%c %c\n", s[i], s[j]);
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{

	printf("TEST BEGIN.\n");
	printf("%d\n", isalpha('a'));

    printf("%d \n", isPalindrome("A man, a plan, a canal: Panama"));

    return 0;
}

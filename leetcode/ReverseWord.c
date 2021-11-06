#include <stdio.h>
#include <string.h>
/* 实现单词的反转 
    I am a student. 
->  .tneduts a ma I     // 全翻转
    student. a am I     // 逐个翻转
*/

/* 给定字符串的起始地址和接收地址，进行字符翻转 */
void reverseAll(char *s1, char *s2) {
    if ((s1 == NULL) || (s2 == NULL)) {
        return;
    }
	
    while (s1 < s2) {
        char temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        s1++;
        s2--;
    }
}

char *reverseWords(char *s) {
    if (s == NULL) return NULL;

    // char *end = s + strlen(s) - 1;
    char *end = s;

    while (*end != '\0') {
        end++;
    }
    end--;

    reverseAll(s, end);
	printf("%s\n", s);

    char *temp_begin = s;
    char *temp_end = s;

    while (*temp_begin != '\0') {
		if (*temp_begin == ' ') {
			temp_begin++;
			temp_end++;
		} else if ((*temp_end == ' ') || (*temp_end == '\0')) {
            temp_end--;
            reverseAll(temp_begin, temp_end);
            temp_end++;
            temp_begin = temp_end;
		} else {
            temp_end++;
        }
    }
    return s;
}

int main() {
    char input[] = "hello world. my love!";
    
    printf("%s\n", reverseWords(input));
}
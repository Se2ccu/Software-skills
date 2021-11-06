/* 2020.11.1 Linux Library Study */
/* popen: create a pipe, and fork a kid-pid to exce a shell command, like "cat /proc/pid-num/state", and output the content to a FILE.
    two more pid: one is kid-pid, the other is shell.
    FILE *popen( const char *command, const char* mode )
    int pclose(FILE stream_to_close)
    */

#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    FILE *fh = NULL;
    char buffer[128] = {0};
    fp = popen("ipconfig", "r");
    if (fp == NULL) {
        printf("#1.popen fp failed.");
        return -1;
    }
    fh = fopen("shell.txt", "w+");
    if (fh == NULL) {
        printf("#2.popen fh failed.");
        return -1;
    }
    fread(buffer, 1, 127, fp);
    fwrite(buffer, 1, 127, fh);
    pclose(fp);
    pclose(fh);
    return 0;
}
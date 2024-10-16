#include <stdio.h>
void main()
{
    char ch;
    while((ch=getchar())!='\n') {
        if(ch>='A'&&ch<='Z') {
            ch=ch+32;
        }
        else if(ch>='a'&&ch<='z') {
            ch=ch-32;
        }
        putchar(ch);
    }
    putchar('\n');
}
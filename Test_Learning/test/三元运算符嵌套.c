#include <stdio.h>

/*
int main() {
    int a = 3, b = 2, c = 1, max;
    max = a > b ? a > c ? a : c : b > c ? b : c;
    // max = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("max = %d\n", max);
    return 0;
}
*/
int main() {
    int x = 10, y = 20, z = 30 ,h = 40, w = 50;
    int number;
    number = x > h ? z > w ? x > z ? x > y ? x : y : z : w : w > h ? w : h;
    // number = x > h ? {z > w ? [x > z ? ( x > y ? x : y ) : z ] : w } : { w > h ? w : h};
    printf("number = %d\n", number); 
}
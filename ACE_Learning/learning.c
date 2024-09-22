#include<stdio.h>
#define PI 3.14
void calculate(float r, float *c, float *s)
{
	*c = 2 * r * PI;
	*s = r * r * PI;
}
int main(void)
{
	float r,c,s;
	r = 5;
    
	calculate(r,&c,&s);
	printf("c is %.2f\n", c);
	printf("s is %.2f\n", s);
	return 0;
}

#include <stdio.h>
#include <math.h>

int main () {
    double cm, inch, foot;
    scanf("%lf", &cm);
    inch = cm * 12 / (145 * 30.48);
    foot = 12 * inch;
    printf ("%.0lf %.0lf", round(foot), round(inch));
    return 0;
}
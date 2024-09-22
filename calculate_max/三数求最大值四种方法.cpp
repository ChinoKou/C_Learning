#include <stdio.h>
#include <algorithm>
#include <string>

int max1(int a, int b, int c);
int max2(int a, int b, int c);
int max3(int a, int b, int c);

using namespace std;
bool cmp(const int& s1, const int& s2) {
	return s1 > s2;
}
int main() {

	int a, b, c;
	int g[3] = {0,0,0};

	scanf("%d%d%d", &a,&b,&c);
	g[0] = a; g[1] = b; g[2] = c;

	int d = max1(a, b, c);
	int e = max2(a, b, c);
	int f = max3(a, b, c);

	sort(g,g+3,cmp);

	printf("%d\n%d\n%d\n%d\n", d,e,f,g[0]);
}
int max1(int a, int b, int c) {
	int e = (a > b) ? a : b;
	int f = (e > c) ? e : c;
	return (f);
}
int max2(int a, int b, int c) {
	int output;
	if (a > b && a > c) {
		output = a;
	}
	if (b > a && b > c) {
		output = b;
	}
	if (c > a && c > b) {
		output = c;
	}
	return (output);
}
int max3(int a, int b, int c) {
	int output;
	if (a > b) {
		if (a > c) {
			output = a;
		}
	}
	else {
		if (b > c) {
			output = b;
		}
		else
			output = c;
	}
	return (output);
}
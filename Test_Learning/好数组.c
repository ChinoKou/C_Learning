#include <stdio.h>

int is_hao(int arr[], int n);

int main () {
    int n, k, arr[1000] = {0};
    scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (is_hao(arr, n)) {
		for (int i = 1; i <= k; i++) {
			if (is_hao(arr, n) == 0) {}
		}
	}
    return 0;
}

int is_hao(int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n / 2; i++) {
		if (arr[i] != arr[n - i - 1]) {
			count ++;
		}
	}
	if (count == 1) {
		return 1;
	}
	return 0;
}
#include <stdio.h>

int statistics (char arr[], char character);
void p_statistics(char* arr, char character, int* count);

int main () {
    char arr[] = "f65g6g54gs65waey6854qt465q456gvGUIKQJHB#QUIKJFG1age35a35g1A6G4A65G4A2G1AGARQ635R3Q";
    char character = '3';
    int count = statistics(arr, character);
    printf("%d", count);
    p_statistics(arr, character, &count);
    printf("%d", count);
    return 0;
}

int statistics (char arr[], char character) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == character) {
            count++;
        }
    }
    return count;
}

void p_statistics(char* arr, char character, int* count) {
    *count = 0;
    for (int i = 0; *(arr + i) != '\0'; i++) {
        if (*(arr + i) == character) {
            *count++;
        }
    }
}
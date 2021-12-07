// Ryan Ma
#include <stdio.h>

int main() {
    int x;

    printf(">> ");
    scanf("%i", &x);

    for(int i = 7; i >= 0; i = i-1) {
        int bit = x & (1 << i);
        if (bit != 0)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
// Ryan Ma
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%i %i, &a, &b");

    printf("Bit-wise AND: %x\n", a & b);
    printf("Bit-wise OR: %x\n", a | b);
    printf("A shifted by one bit left: %x\n", a << 1);
    printf("B shifted by one bit right: %x\n", b >> 1);
}
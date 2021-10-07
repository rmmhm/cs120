// Calculate the sum of the numbers 1 to MAX
// Ryan Ma

#include <stdio.h>

#define MAX 10

int main()
{
    int sum, i;

    sum = 0;
    for (i = 1; i <= MAX, i += 1)
        sum += 1;

    printf("The sum from 1 to %d is %d\n", MAX, sum);
}
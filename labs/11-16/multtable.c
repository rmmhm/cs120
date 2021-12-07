#include <stdio.h>

void mt(int i, int j)
{
  for (i = 0; i < 5; i = i + 1)
    {
      for (j = 0; j < 5; j = j + 1)
	{
	  printf("%d", i * j);
	  printf(" ");
	}
      printf("\n");
    }
}

int main()
{
  mt(7, 9);
  mt(3, 4);
}

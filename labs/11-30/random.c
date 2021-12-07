// Ryan Ma

#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 100000
int x[ARRAYSIZE];

int compare(const void *a, const void *b)
{
  if (*(int *)a < *(int *)b) return -1;
  if (*(int *)a > *(int *)b) return 1;
  return 0;
}

void bubblesort(int *data, int length)
{
  int i, j;
  int temp;

  for (i = 0; i < length; ++i)
    {
      for (j = i + 1; j < length; ++j)
	{
	  if (data[i] > data[j])
	    {
	      temp = data[i];
	      data[i] = data[j];
	      data[j] = temp;
	    }
	}
    }
}

void print_array(int *data, int length)
{
  for (int i = 0; i < length; ++i)
    {
      printf("%d\n", data[i]);
    }
}

int main()
{
  for (int i = 0; i < ARRAYSIZE; ++i)
    {
      x[i] = random();
    }

  //print_array(x,20);
  //qsort(x, ARRAYSIZE, sizeof(int), compare);

  print_array(x,20);
  bubblesort(x,20);

  print_array(x, 20);  
}

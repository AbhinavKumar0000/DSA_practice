#include <stdio.h>

int main()
{
  int x, y;
  x = 0;
  y = 0;
  scanf("%d", &y);
  for (int i = 1; i <= y; i++)
  {
    x = x + i;
  }

  printf("%d\n", x);
  return 0;
}
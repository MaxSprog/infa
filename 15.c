#include<stdio.h>

int main()
{
  int y = 0;
  scanf("%d", &y);
  if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){  
    printf("Високосный");
  }
  else{
    printf("Невисокосный");
  }
  return 0;
}
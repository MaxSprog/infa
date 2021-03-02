#include <stdio.h>

int max(int a, int b, int c){
  if(a > b && a > c){
    return a;
  }
  else if(b > c){
    return b;
  }
  else{
    return c;
  }
}

int min(int a, int b, int c){
  if(a < b && a < c){
    return a;
  }
  else if(b < c){
    return b;
  }
  else{
    return c;
  }
}

void triangleType(int ab, int bc, int ca){
  //int tup = 0, ostr = 0, pryam = 0, ravb = 0, ravs = 0;
  int a, b, c;
  c = max(ab, bc, ca);
  a = min(ab, bc, ca);
  b = ab + bc + ca - c - a;
  if(a + b < c || a <= 0){
    printf("Не существует\n");
    return 0;
  }
  if(a*a + b*b < c*c){
    printf("Тупоугольный\n");
  }
  else if(a*a + b*b > c*c){
    printf("Остроугольный\n");
  }
  else{
    printf("Прямоугольный\n");
  }
  if (ab == bc || bc == ca || ca == ab){
    printf("Равнобедренный\n");
    if(ab == bc && bc == ca){
      printf("Равносторонний\n");
    }
  }
  //printf("%d %d\n", 1*pryam + 2*tup + 3*ostr, 1*ravs + 2*ravb);
}

int main(void) {
  printf("max: %d\n", max(2,3,5) == 5);
  printf("min: %d\n", min(2,3,5) == 2);
  printf("triangleType (0):\n");
  triangleType(-1,3,5);
  printf("triangleType (0):\n");
  triangleType(-1,-10,0);
  printf("triangleType (0):\n");
  triangleType(0,0,0);
  printf("triangleType (0):\n");
  triangleType(10,3,5);
  printf("triangleType (1pryam):\n");
  triangleType(5,4,3);
  printf("triangleType (1ravs):\n");
  triangleType(4,4,4);
  printf("triangleType (2ravb):\n");
  triangleType(4,4,5);
  printf("triangleType (2tup):\n");
  triangleType(6,4,3);
  printf("triangleType (3ostr):\n");
  triangleType(6,5,7);
  return 0;
}
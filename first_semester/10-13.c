#include <stdio.h>

int abs(int n){
  if(n < 0)
    return n * -1;
  return n;
}

int canbeAttacked(int fig, int xP, int yP, int xF, int yF){
  if(fig == 1){
    if(abs(xP - xF) == 1 && abs(yP - yF) == 2){
      return 1;
    }
    else if(abs(xP - xF) == 2 && abs(yP - yF) == 1){
      return 1;
    }
  }
  else if(fig == 2){
    if(abs(xP - xF) == abs(yP - yF)){
      return 1;
    }
  }
  else if(fig == 3){
    if(xP == xF || yP == yF){
      return 1;
    }
  }
  else if(fig == 4){
    if(abs(xP - xF) == abs(yP - yF)){
      return 1;
    }
    else if(xP == xF || yP == yF){
      return 1;
    }
  }
  return 0;
}

int main(void) {
  /*
  1 - knight
  2 - bishop
  3 - rook
  4 - queen
  */
  int fig, xP, yP, xF, yF;
  printf("Enter the name of the figure first: ");
  scanf("%d", &fig);
  printf("Enter the pawn's coords(x, y): ");
  scanf("%d %d", &xP, &yP);
  printf("Enter the figure's coords(x, y): ");
  scanf("%d %d", &xF, &yF);
  printf("%d", canbeAttacked(fig, xP, yP, xF, yF));
  return 0;
}
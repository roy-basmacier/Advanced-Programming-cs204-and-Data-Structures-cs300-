#include <stdio.h>

//The function update sets 
//a = a + b
//b = |a - b|
//Please complete the function

void update(int *a, int *b) {
  int temp = *a;
  *a += *b;
  *b -= temp;
  if(*b <0)
	  *b *= -1;
}

int main() {
  int a, b;
  int *pa = &a, *pb = &b;
    
  scanf("%d %d", &a, &b); //reads two integers from the command line, store it in a and b
  update(pa, pb);
  printf("%d\n%d", a, b); //output the new values of a and b

  return 0;
}

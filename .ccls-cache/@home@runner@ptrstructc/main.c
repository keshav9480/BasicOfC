#include <stdio.h>
void passByReference(int *c);

void passByReference(int *c) {
  printf("\npass by reference: %d",*c);
  *c = 200;  
  return;
}

int main(void) {
  int n = 10;
  int *c = &n;
  printf("Adress of n %x\n", &n);
  printf("Adress of c %x\n", c);
  printf("value of c %d\n",*c);
  passByReference(c);
  printf("\nAfter pass by reference %d\n",*c);
  return 0;
}
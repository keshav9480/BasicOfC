#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "pointer_structure.h";

typedef struct Person person;

#define typecheck(var) _Generic((var), \
                  int: "int", \
                  char: "char", \
                  default: "pointer")

void passByReference(int *c);

void passByReference(int *c) {
  printf("\npass by reference: %d",*c);
  *c = 200;  
  return;
}

int main(void) {
  float f;
  char *cp;
  char ch;
  int i;
  int *ip;
  int n = 10;
  int *c = &n;
  char *name = "keshn";
  char *place = "manvi";
  int uid = 100;
  //struct Person *info = {"keshn", "manvi", 10};
  person *p;
  

  /*
  size of pointer and other data types
  */
  printf("size of char ptr: %d\n",sizeof(cp));
  printf("size of int ptr: %d\n",sizeof(ip));
  printf("size of int: %d\n",sizeof(i));
  printf("size of char: %d\n",sizeof(ch));
  printf("size of flaot: %d",sizeof(f));
  
  
  /*
  here address of n and c are same. pointer c is pointing
  to the address of n which has value of n.
  */
  printf("Adress of n %x\n", &n);
  printf("Adress of c %x\n", c);
  printf("value of c %d\n",*c);
  passByReference(c);
  //expected value of the c here is 200.
  printf("\nAfter pass by reference %d\n",*c);

  
  /*
  Following code allocates the memory and initialize the struct p.
  note: -> is only syntatic in c. 
  Eg: struct Person {
      int uid;
      char *name;
  } 

      struct Person *p 
      struct Person q 
      //access the var can be in two ways
      (*p).uid is same as p->uid
      q.uid

  */
  p = malloc(sizeof(person));
  if (p == NULL) {
    return -1;
  }
  assert(strcmp(typecheck(p), "pointer") == 0);
  printf("Adress of person %p\n", p);
  p->name = name;
  p->place = place;
  p->uid = uid;
  printf("size of person p: %d\n",sizeof(p));
  printf("person name: %s\n",p->name);
  printf("person place: %s\n",p->place);
  printf("person uid: %d\n",p->uid);
  free(p);
  
  // printf("Address of person after deallocation of memory %x\n",person);
  return 0;
}
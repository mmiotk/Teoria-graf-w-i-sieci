#include <stdio.h>
#include <stdlib.h>

struct wierzcholek{
  int a;
  struct wierzcholek* next;
};

struct wierzcholek *head = NULL;
struct wierzcholek *curr = NULL;

struct wierzcholek* create(int val){
  struct wierzcholek *wie = (struct wierzcholek*)malloc(sizeof(struct wierzcholek));
  if(NULL == wie){
    printf("Failed");
    return NULL;
  }
  wie->a = val;
  wie->next = NULL;

  head = curr = wie;
  return wie;
}

struct wierzcholek* add(int val){
  if(NULL == head){
    return (create(val));
  }

  struct wierzcholek *wie = (struct wierzcholek*)malloc(sizeof (struct wierzcholek));

  if(NULL == wie){
    printf("Failed");
  }

  wie->a = val;
  wie->next = NULL;

  curr->next = wie;
  curr = wie;

  return wie;
}

void print(void){
  struct wierzcholek *wie = head;

  while(wie != NULL){
    printf("[%d]\n", wie->a);
    wie = wie->next;
  }
  return;
}

int main(){
  add(5);
  add(7);
  add(2);

  print();

  return 0;
}

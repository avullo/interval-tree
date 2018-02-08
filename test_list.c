#include "interval.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

interval_t* make_interval(int low, int high, int data) {
  interval_t* i = (interval_t *)malloc ( sizeof(interval_t) );

  if(i == NULL)
    return 0;

  i->low = low;
  i->high = high;
  i->data = (int*)malloc(sizeof(int));
  *((int*)i->data) = data;
    
  return i;
}

void print_interval(const interval_t* i) {
  if ( i != NULL )
    printf("[%.1f, %.1f] (%d)\n", i->low, i->high, *(int*)i->data);
}

void destroy_interval(interval_t* i) {
  free(i->data);
  free(i);
}

int main() {
  ilist_t* l = ilist_new();
  assert(1);
  
  interval_t* ints[] = { make_interval(15,20,10),
			 make_interval(10,30,20),
			 make_interval(17,19,30),
			 make_interval(5,20,40),
			 make_interval(12,15,50),
			 make_interval(30,40,25) };

  int i;
  for(i=0; i<6; ++i)
    printf("Appending [%.1f, %.1f] (%d) - %s\n",
	   ints[i]->low,
	   ints[i]->high,
	   *(int*)ints[i]->data,
	   ilist_append(l, ints[i])?"OK":"KO");

  printf("\nList size: %zu\n\n", ilist_size(l));

  ilisttrav_t* trav = ilisttrav_new(l);
  const interval_t* item;
  for(item = ilisttrav_first(trav); item!=NULL; item=ilisttrav_next(trav))
    print_interval(item);
  printf("\n");

  for(item = ilisttrav_last(trav); item!=NULL; item=ilisttrav_prev(trav))
    print_interval(item);
  printf("\n");

  ilisttrav_delete(trav);
  ilist_delete(l);

  for(i=0; i<6; ++i)
    destroy_interval(ints[i]);

}


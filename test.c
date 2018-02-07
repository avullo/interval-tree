#include "itree.h"
#include <stdlib.h>
#include <stdio.h>

typedef itree_t itree;
typedef itreetrav_t itreetrav;

/* clone an integer */
void* clone(void* p) {
  int* c = (int*)malloc(sizeof(int));
  *c = *(int*)p;
  
  return c;
}

/* destroy an integer */
void destroy(void* p) {
  free(p);
}

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

void print_interval(interval_t* i) {
  printf("[%.1f, %.1f] (%d)\n", i->low, i->high, *(int*)i->data);
}

void destroy_interval(interval_t* i) {
  free(i->data);
  free(i);
}

int main() {
  itree* t = itree_new(clone, destroy);
  interval_t* ints[] = { make_interval(15,20,10),
			 make_interval(10,30,20),
			 make_interval(17,19,30),
			 make_interval(5,20,40),
			 make_interval(12,15,50),
			 make_interval(30,40,25) };

  int i;
  for(i=0; i<6; ++i)
    printf("Inserting [%.1f, %.1f] (%d) - %s\n",
	   ints[i]->low,
	   ints[i]->high,
	   *(int*)ints[i]->data,
	   itree_insert(t, ints[i])?"OK":"KO");

  printf("\nTree size: %zu\n\n", itree_size(t));

  itreetrav* trav = itreetnew();
  interval_t* item;
  for(item = itreetfirst(trav, t); item!=NULL; item=itreetnext(trav))
    //print_interval(item);
  printf("\n");

  interval_t* query = make_interval(6,7,0);
  printf("Query: [%.1f, %.1f]\n", query->low, query->high);
  interval_t* result = itree_find(t, query);
  if(result == NULL)
    printf("No overlapping interval\n\n");
  else 
    printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high);

  query->low = 1;
  query->high = 4;
  printf("Query: [%.1f, %.1f]\n", query->low, query->high);
  result = itree_find(t, query);
  if(result == NULL)
    printf("No overlapping interval\n\n");
  else 
    printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high);

  query->low = 18;
  query->high = 25;
  printf("Query: [%.1f, %.1f]\n", query->low, query->high);
  result = itree_find(t, query);
  if(result == NULL)
    printf("No overlapping interval\n\n");
  else 
    printf("Overlap: [%.1f, %.1f]\n\n", result->low, result->high);

  printf("Deleting interval [30, 40] - ");
  itree_erase(t, ints[5])?printf("OK\n"):printf("KO\n");

  /* printf("Tree size: %zu\n", itree_size(t)); */

  /* result = (int*)itree_find(t, &query); */
  /* printf("Query: %d -- Found: %d\n", query, result == NULL?0:1); */
  
  /* query = 18; */
  /* result = (int*)itree_find(t, &query); */
  /* printf("Query: %d -- Found: %d\n", query, result == NULL?0:1); */

  for(item = itreetfirst(trav, t); item!=NULL; item=itreetnext(trav))
    //print_interval(item);
  printf("\n");
  
  /* printf("First: %d\n", *(int*)jsw_avltfirst(trav, t)); */
  /* printf("Last: %d\n", *(int*)jsw_avltlast(trav, t)); */

  itreetdelete(trav);
  itree_delete(t);

  for(i=0; i<6; ++i)
    destroy_interval(ints[i]);

  destroy_interval(query);
}


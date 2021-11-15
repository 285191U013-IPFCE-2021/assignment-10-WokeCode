#include "..\include\linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  p->next = NULL;
  p->value = 0;
}


/* print list to console */
void print_list (node * p)
{
    if(p != NULL){
      printf("%d, ", p->value);
      print_list(p->next);
    }
    else
      printf("");
    
    printf("\n");

    /*
    for(; p != NULL; p = p->next)
      printf("%d, ", p->value);
    */
}

int sum_squares (node * p)
{
  if(p != NULL)
    return (square(p->value)) + sum_squares(p->next);
  else 
    return 0;  
}

node *map (node * p, int (*f) (int))
{
  node* sq_list = make_node(square(p->value),NULL); //We create an element in a linked list with no next, and a value with the square

  if(p->next != NULL){ //As long as we're not in the last element of the list
    sq_list->next = map(p->next,square); //We will put another element to the list created with the next element
    return sq_list;
  } else {
    return sq_list; //If, on the other hand, we are looking at the last element of the list, the next value will become sentinel
  }
}


int square (int x)
{
  return x * x;
}

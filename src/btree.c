#include "..\include\btree.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct tree_node * Initialize (struct tree_node *t)
{
  struct tree_node * p = malloc (sizeof (struct tree_node));
  p->left = NULL;
  p->right = NULL;
  return p;
}

struct tree_node * Insert (int x, struct tree_node *t)
{
  if(Empty(t)){
    struct tree_node *n = malloc(sizeof(struct tree_node));
    n->item = x;
    n->right = NULL;
    n->left = NULL;
    return n;

  }else if(x <= t->item)
    t->left = Insert(x, t->left);
  else
    t->right = Insert(x, t->right);
}

struct tree_node * Remove (int x, struct tree_node *t)
{
  if(!Contains(x,t))
    return t;

  struct tree_node* p = t;
  struct tree_node * prev = p;
  while(p->item != x){ //This loop runs through the tree untill it finds the node that contains x, and it will save that node's parent
    prev = p;
    if(p->item < x)
      p = p->right;
    else
      p = p->left;
  }

  if(p->right == NULL && p->left == NULL){ //If it has no children
    free(p);
    return t;
  }
  else if(p->left == NULL && p->right != NULL) { //if it contains one right child
    prev->left = p->right;
    free(p);
    return t;
  } 
  else if(p->right == NULL && p->left != NULL) { //If it contains one left child
    prev->right = p->left;
    free(p);
    return t;
  } 
  else {
    struct tree_node* replacer = p->right;
    while(replacer->left != NULL){
      replacer = replacer->left;
    }
    p->item = replacer->item;
    p->right = p->right;
    return t;
  }

  return t;
}


int Contains (int x, struct tree_node *t)
{
  if(t == NULL)
    return 0;
  else if(x == t->item){
    return 1;
  } else if (x < t->item)
    return Contains(x, t->left);
  else if( x > t->item)
    return Contains(x, t->right);
  else return 0;
  // Return true if the tree t contains item x. Return false otherwise.
}


int Empty (struct tree_node *t)
{
  if(t == NULL)
    return 1;
  else
    return 0;
  
}

int Full (struct tree_node *t)
{
    return 0;
}

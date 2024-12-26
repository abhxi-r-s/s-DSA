#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *Left;
    int data;
    struct node *Right;
}*temp;

struct node *root=NULL;

void create();
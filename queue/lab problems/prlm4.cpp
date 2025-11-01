//implementing circular array using struct
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX INT64_MAX
struct circularqueue{
int *arr;
int front; 
int rear;
int size;
};
struct circularqueue* create(int n)
{
    struct circularqueue* cq=(struct circularqueue*)malloc(sizeof(struct circularqueue));
    cq->size=n;
    cq->front=-1;
    cq->rear=-1;
    cq->arr=(int*)malloc(n*sizeof(int));
    return cq;
}



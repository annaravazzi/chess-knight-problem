#include <stdio.h>
#include <stdlib.h>

typedef struct _cell
{
	/*Coordenadas da célula*/
	int x;
	int y;
	/*Distância da célula de origem*/
	int dist;
	/*Referência para a célula pai*/
	struct _cell *parent;
} Cell;

typedef struct
{
   int front;
   int rear;
   int size;
   Cell *array;
} Queue;

Queue* create_queue (int size);

void free_queue (Queue *q);

void enqueue (Queue *q, int x, int y, int dist, Cell *parent);

Cell* dequeue (Queue *q);

int empty_queue (Queue *q);

int full_queue (Queue *q);
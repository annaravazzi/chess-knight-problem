#include "queue.h"

/*Cria uma fila em como um vetor*/
Queue* create_queue (int size) 
{
   Queue *q = (Queue*)malloc(sizeof(Queue));

   q->front = 0;
   q->rear = 0;
   q->size = size;

   q->array = (Cell*)malloc(size*sizeof(Cell));

   return q;
}

/*Desaloca a fila*/
void free_queue (Queue *q) 
{
   free(q->array);

   free(q);
}

/*Enfilera uma célula*/
void enqueue (Queue *q, int x, int y, int dist, Cell *parent) 
{
   if(!full_queue(q))
   {
   	Cell c = (Cell){x, y, dist, parent};
      q->array[q->rear] = c;
      (q->rear)++;
   }
   else
   	  printf("Full queue\n");
}

/*Desenfilera uma célula*/
Cell* dequeue (Queue *q) 
{
   if(!empty_queue(q))
   {
   	Cell *c = &(q->array[q->front]);
      (q->front)++;
      
      return c;
   }
   else
   {
      printf("Empty queue\n");
      exit(1);
   }
}     

/*Checa se a fila está vazia*/
int empty_queue (Queue *q)
{
	return (q->front == q->rear);
}  

/*Checa se a fila está cheia*/
int full_queue (Queue *q)
{
	return (q->rear == q->size);
}
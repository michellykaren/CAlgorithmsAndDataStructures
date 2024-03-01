/*
* queue estática
* problema de espaço não utilizado que ocorre no array estático devido à operação de dequeue
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct{
  int front;    
  int rear;          //eles vao ficar rodando dentro de uma linha "infinita"
  int queue[SIZE];   //array will implement the queue
                     //global variable to be changed
}Queue;

void init(Queue *q){
  q->front   = 0;    
  q->rear    = 0;                        
}

void enqueue(Queue *q){
  int item;   //value to be pushed
  if (q->rear == (SIZE-1)) printf("Queue overflow!\n"); //case overflow is into push
  else{
    printf("Enter the item to be ENQUEUE: ");
    scanf("%d", &item);
    q->queue[q->rear]=item;    //pushing item
    q->rear=q->rear+1;         //remember that top is started to -1 
  }
}

void dequeue(Queue *q){
  if (q->front == q->rear) printf("Empty queue\n");
  else{
    printf("The deleted item is: %d\n", q->queue[q->front]);
    q->queue[q->front] = 0;
    q->front=q->front+1;
  }
}

void display(Queue *q){
  //walking through the queue
  printf("-------\t 1 \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8  \t 9 \t 10|\n");
  printf("-queue-\n");
  printf("-------");
  
  for(int i=0; i<SIZE; i++){
    printf("\t %d ", q->queue[i]);

  }
  printf("|\n");
}



int main() {
  printf("Olá, mundo!\n");
  printf("Minha queue em C\n");
  int choice;
  Queue q;
  init(&q);
  while(1){
    printf("Choices\n");
    printf("1. enfileirar\n");
    printf("2. desfileirar\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        enqueue(&q);
        break;
    case 2:
        dequeue(&q);
        break;
    case 3:
        display(&q);
        break;
    case 4:
        exit(0);    //exit() termina imediatamente a execução do prograda. 
                    //exit(1) é quando encontra um erro
        break;
    
    default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}


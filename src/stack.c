#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//create stack struct 
typedef struct {
    int stack[SIZE];
    int top;
} Stack;

void init(Stack *s){
    for (int i = 0; i < SIZE; i++) {
        s->stack[i] = 0;
    }
    s->top = -1;
}

int isFull(Stack *s){
  if (s->top==SIZE-1){
    printf("Overflow!");
    return 1;
  }
  return 0;
}

int isEmpty(Stack *s){
    if(s->top==-1){
      printf("Empty stack\n");
      return 1;
    }
    return 0;
}

void push(Stack *s){
  int item;
  if(isFull(s)){}
  else{
    printf("Enter the item to be PUSHED");
    scanf("%d", &item);
    s->top++;
    s->stack[s->top] = item;
  }
}

void pop(Stack *s){
  if(isEmpty(s)){}
  else{
    printf("The deleted item is: %d\n", s->stack[s->top]);
    s->stack[s->top] = 0;
    s->top--;
  }
}

int main() {
  Stack s;
  init(&s);

  printf("Olá, mundo!\n");
  printf("Minha stack em C\n");
  int choise;
  while(1){
      printf("Choises\n");
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Quit\n");
      scanf("%d", &choise);

      switch (choise)
      {
      case 1:
          push(&s);
          break;
      case 2:
          pop(&s);
          break;
      case 3:
          //display();
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



/*void display(){
    //walking through the stack
    printf("-------------------\n");
    printf("-------STACK-------\n");
    printf("-------------------\n");
    
    for(int i=0; i<SIZE; i++){
        printf("%d \t %d", i, stack[i]);
        if(top==i) printf("*\n");
        else printf("\n");
    }
    printf("-------------------\n");
}*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void push();
void pop();
void display();

int top = -1;       //value of top is initialised to -1
                    //global variable to be changed 
int stack[SIZE];    //array will implement the stack
                    //global variable to be changed
int main() {
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
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
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

void push(){
    int item;   //value to be pushed
    if (top == (SIZE-1)) printf("Stack overflow!\n"); //case overflow is into push
    else{
        printf("Enter the item to be PUSHED");
        scanf("%d", &item);
        top=top+1;             //remember that top is started to -1
        stack[top]=item;    //pushing item
    }
}

void pop(){
    if (top == -1) printf("Empty stack\n");
    else{
        printf("The deleted item is: %d\n", stack[top]);
        stack[top] = 0;
        top=top-1;
    }
}

void display(){
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
}

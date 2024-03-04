/*
* Binary tree
* Bom para buscar dados de forma eficiente e mais uma ruma de coisa
*
Explicação
Caso Base: Se o nó atual (ou root) é NULL, significa que encontramos a posição correta para inserir o novo elemento.
Nesse caso, usamos a função createNode para criar um novo nó com o valor desejado e retornamos esse novo nó para ser conectado à árvore.
*
Recursão
Se o nó atual não é NULL, comparamos o valor a ser inserido (item) com o valor do nó atual (root->data). 
Se item é menor, chamamos insertNode recursivamente para a subárvore esquerda (root->left); 
se item é maior, chamamos para a subárvore direita (root->right). 
Isso garante que a árvore mantenha suas propriedades de ordenação.
Observe que não tratamos o caso para quando o item é igual ao valor de base.
*
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Node{  //Defino struct nome aqui e não apenas struct para não precisar usar 
                      //struct Node sempre que passar ele como argumento para a função
  int data;
  struct Node *left;
  struct Node *right;
} Node;

void InitNewNode(Node *p, int item){
  p->data = item;
  p->left = NULL;
  p->right = NULL;
}

Node* createNode(int item){
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Erro ao alocar memória para novo nó\n");
    exit(1);
  }
  InitNewNode(newNode, item);
  return newNode;
}

Node* insertNode(Node* p, int item) {
    // Se a árvore está vazia, cria um novo nó e retorna como raiz
    if (p == NULL) {
        return createNode(item);
    }

    // Caso contrário, desce pela árvore recursivamente até encontrar a posição correta
    if (item < p->data) { // Insere na subárvore esquerda
        p->left = insertNode(p->left, item);
    } else if (item > p->data) {
        // Insere na subárvore direita
        p->right = insertNode(p->right, item);
    }

    // Retorna o ponteiro para o nó (raiz) após a inserção
    return p;
}

// Inorder: Esquerda -> Raiz -> Direita
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder: Raiz -> Esquerda -> Direita
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder: Esquerda -> Direita -> Raiz
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void searchNode(struct Node *p, int itemProcurado){
  if (p == NULL) printf("Item não encontrado \n");
  else {
    if (itemProcurado == p->data) printf("Node found %d \n",p->data);
    else if(itemProcurado < p->data) searchNode(p->left, itemProcurado);
    else if(itemProcurado > p->data) searchNode(p->right, itemProcurado);
  }
}

/* TO DO
void deleteNode(struct Node *p, int item){
}

void sortNode(struct Node *p){
}

implementar função de destruição */

int main() {
    Node* root = NULL;

    // Inserindo alguns dados
    root = insertNode(root, 10); // o primeiro é a raiz
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 18);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Raiz da arvore: %d \n", root->data);

    searchNode(root, 13);

    return 0;
}
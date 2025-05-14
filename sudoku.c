#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int arreglo[10] = {0} ;
  for(int i = 0 ; i < 9 ; i++){
    for(int k = 0 ; k< 9 ; k++){
      if (n->sudo [i][k] == 0) continue ;
      if (arreglo[n->sudo[i][k]] == 0){
        arreglo[n->sudo[i][k]] = 1 ;
        printf(" 3 numero = %d, ", arreglo[n->sudo[i][k]]) ;
      }
      else {
        return 0 ;
      }
    }
  }
  int arreglo_dos[10] = {0} ;
  for(int i = 0 ; i < 9 ; i++){
    for(int k = 0 ; k < 9 ; k++){
      if (n->sudo [k][i] == 0) continue ;
      if (arreglo_dos[n->sudo[k][i]] == 0){
        printf("numero = %d, ", arreglo_dos[n->sudo[k][i]]) ;
        arreglo_dos[n->sudo[k][i]] = 1 ;
      }
      else {
        return 0 ;
      }
    }
  }  
  return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

    int pos_vacia_i = -1 ;
    int pos_vacia_k = -1 ;
    for(int i = 0 ; i < 9 ; i++){
      for(int k = 0 ; k < 9 ; k++){
        if (n->sudo[i][k] == 0) {
          pos_vacia_i = i ;
          pos_vacia_k = k ;
          break ;
        }
      }
      if (pos_vacia_i != -1) break ; 
      
    }
    if (pos_vacia_i == -1) return list ;
    for(int i = 1 ; i <= 9; i++){
      Node * sudo_adj ;
      sudo_adj = copy(n) ; 
      sudo_adj->sudo[pos_vacia_i][pos_vacia_k] = i ;
      pushBack(list, sudo_adj) ;
    }
    return list;
}


int is_final(Node* n){
  
  
  
  return 0 ;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
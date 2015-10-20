#include <stdio.h>
#include <stdlib.h>
#include <boolean.h>

typedef struct element t_element;
struct element{
    int value;
};
typedef struct node t_node;
struct node{
    t_element elem;
    t_node *left;
    t_node *right;
    t_node *root;
    bool color;
};
t_element *create_element(int value){
    t_element *elem=(t_element *)malloc(sizeof(t_element));
    elem=value;
    return elem;
}
t_node *create_node(t_element *new_element){
    t_node node=(t_node *)malloc(sizeof(t_node));
    node->elem=elem;
    node->left=NULL;
    node->right=NULL;
    node->root=NULL;
    node->color=red;
    return node;
}
void left_rotate(t_node *node, t_node *subtree){
    t_node *aux=subtree->right;
    subtree->right=aux->left;
    if(aux->left != nil){
        aux->left->root= subtree;
    }
    aux->root=subtree->root;
    if(subtree->root == nil){
        subtree=aux;
    }else{
        if(subtree == subtree->left->root){
            subtree->root->left=aux;
        }else{
            subtree->root->right=aux;
        }
    }
    aux->left = subtree;
    subtree->root= aux;
}
int main(){
}

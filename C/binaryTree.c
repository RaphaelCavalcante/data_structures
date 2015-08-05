/****************************************************
+
+Raphael Cavalcante Hatchwell Hounsell
+
+
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0
//TEST >>> 10, 20, 5 , 40, 2, 7
int static buff=0;

typedef struct node t_node;
struct node{
	int value;
	t_node *left;
	t_node *right;
	t_node *root;
};
/**
* Create a tree node from a integer
**
t_node *create_root(int elem){
    t_node *root;
    root=(t_node *)malloc(sizeof (t_node));
    root->value=elem;
    root->root=NULL;
    root->left=NULL;
    root->right=NULL;
return root;
}
/**
* Insert a new node element, if the tree is empty, then
* the new node is the root node. If the tree is not empty
* then compare the root value with the element, if 
* element value is greater than root value, then create a node
* on the right side, if is lesser, then insert into the left
* side of the root.
*
* If any side is not NULL, repeat the process passing the
* "tree" parameter as tree->right, if is greater or, tree->left
* if lesser.
*/
t_node *insert_tree(t_node *tree, int elem){
    t_node *leaf;
    if(tree==NULL){
        tree=create_root(elem);
    }else{
        if((tree->left == NULL) && (tree->value < elem)){
	   //insert on left
            leaf=create_root(elem);
            leaf->root=tree;
            tree->left=leaf;
        }else if((tree->right == NULL) && (tree->value > elem)){
	   //insert on right
            leaf=create_root(elem);
            leaf->root=tree;
            tree->right=leaf;
        }else if((tree->right != NULL) && (tree->value > elem)){
	   // if right leaf is not empty, repeat the process
            insert_tree(tree->right, elem);
        }else if((tree->left != NULL) && (tree->value < elem)){
	  // if left leaf is not empty, repeat the process
            insert_tree(tree->left, elem);
        }
    }
return tree;
}

/**
* Returns the value of the root element, given an array. First the tree is
* build using the array elements, then the root value is returned.
*/
int given_array_get_root(int array[]){
    t_node *root;
    int i;
    for(i=0;i<(sizeof(array)/4);i++)
    {
        root=insert_tree(root, array[i]);
    }
return root->value;
}
/************
*  MAIN     *
*************/
int main(int argc, char *argv[]){
    t_node *tree=NULL;
    int array[]={10, 20, 5 , 40, 2, 7};
    printf("%d", given_array_get_root(array));

}

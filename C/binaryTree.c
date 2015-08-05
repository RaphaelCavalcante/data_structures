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
//TEST >>> 50,100,25,150,75,35,15,20,85,10


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
*/
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
    t_node *leaf=NULL;
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
    t_node *root=NULL;
    int i;
    for(i=0;i<SIZE;i++)
    {
        root=insert_tree(root, array[i]);
    }
return root->value;
}

t_node *array_to_tree(int array[]){
    t_node *root=NULL;
    int i;
    for(i=0;i<SIZE;i++)
    {
        root=insert_tree(root, array[i]);
    }
return root;
}
/**
* print tree in post order
*/
void print_tree_post_order(t_node *tree){
	if(tree == NULL){
		return;
	}

	if(tree->left != NULL){
		print_tree_post_order(tree->left);
	}
	if(tree->right != NULL){
		print_tree_post_order(tree->right);
	}
	printf("%d\n", tree->value);
}

/**
* print tree in in order
*/
void print_tree_in_order(t_node *tree){
	if(tree==NULL){
		return;
	}
	if(tree->left!=NULL){
		print_tree_in_order(tree->left);
	}
	printf("%d\n", tree->value);
	if(tree->right!=NULL){
		print_tree_in_order(tree->right);
	}
}
/**
*print tree pre order
*/
void print_tree_pre_order (t_node *tree){
	if(tree==NULL){
		return;
	}
	printf("%d\n", tree->value);
	if(tree->left!=NULL){
		print_tree_pre_order(tree->left);
	}
	if(tree->right!=NULL){
		print_tree_pre_order(tree->right);
	}
}
/************
*  MAIN     *
*************/
int main(int argc, char *argv[]){
    t_node *tree=NULL;
    int array[SIZE]={50,100,25,150,75,35,15,20,85,10};
	tree= array_to_tree(array);	
//	print_tree(tree);
	print_tree_in_order(tree);
//    printf("%d", given_array_get_root(array));

}

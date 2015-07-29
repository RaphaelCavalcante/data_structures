/****************************************************
+
+Raphael Cavalcante Hatchwell Hounsell
+23.07.2015
+
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0

int static buff=0;

typedef struct node t_node;
struct node{
	int value;
	t_node *next;
	t_node *prev;
};
typedef struct list t_list;
struct list{
	t_node *start;
	t_node *end;
	int size;
};
/**
*create a list of t_node elements
*/
t_list *create_list(){
	t_list *new_list=(t_list *)malloc(sizeof(t_list));
	new_list->start= NULL;
	new_list->end=NULL;
	new_list->size=0;
return new_list;
}
/**
*Create a node element guiven an integer value
*/
t_node *create_node(int value){
	t_node *node=(t_node *)malloc(sizeof(t_node));
	node->value=value;
	node->next=NULL;
	node->prev=NULL;
return node;
}
/**
*Add a element at the end of the list
*/
void add_on_end(t_list *list, t_node *node){
	if(list->start == NULL){
		list->start=node;
		list->end=node;
	}else{
		list->end->next=node;
		node->prev=list->end;
		list->end=node;
	}
	list->size++;
}
/**
*Add a element on the begining of the list
*/
void add_on_begining(t_list *list, t_node *node){
	if(list->start==NULL){
		list->start=node;
		list->end=node;
	}else{
		node->next=list->start;
		list->start=node;
	}
	list->size++;
}

/**
*sum_them_all_non_recursive
*/
int sum_them_all_nr(t_list *list){
	t_node *node=list->start;
	int sum=0;
	while(node != NULL){

		sum+=node->value;
		node=node->next;
	}
return sum;
}
/**
*Returns the median value given an list
*/
int list_median(t_list *list){
	int sum= sum_them_all_nr(list);
	return sum/list->size;	
}
/**
*returns the sumatory of a given list and a starter node
*/
int sum_them_all_re(t_list *list, t_node *node){
	buff+=node->value;
	if(node == list->end || node == NULL){
		return buff;
	}else{
		sum_them_all_re(list, node->next);
	}
}
/**
* Binary search, should return true 
*/
bool binary_search(t_list *list, int x){
	t_node *start, *end;
	bool found=FALSE;
	if(list==NULL){
		printf("Empty list");
		exit(1);
	}
	start= list->start;
	end=list->end;

	while((start->next != NULL) || (end->prev != NULL)){
		if((end->value==x) || (start->value==x)){
			found = TRUE;
		}
		start=start->next;
		end=end->prev;
	}
return found;
}
/**
*print list recursive mode
*/
void print_list_recursive(t_list *list, t_node *node){
	printf("%d\n", node->value);
	if(node == list->end || node == NULL){
		return;
	}else{
		print_list_recursive(list, node->next);
	}
}

/**
*Print list in a simple way
*/
void print_list(t_list *list){
	t_node *node=list->start;
	while(node != NULL){

		printf("%d\n", node->value);
		node=node->next;
	}
}
/*************
*=====MAIN===*
************/
int main(){
	int static array_test[SIZE]={1,2,3,4,5,6,7,8,9,10};
	t_list *list=create_list();
	int index;
	if(list == NULL){
		printf("Error on allocation");
		exit(1);
	}else{
		//Primeira questão
		for(index=0;index<SIZE;index++){
			t_node *new=create_node(array_test[index]);
			if(new == NULL){
				printf("Error on element creation");
				exit(1);
			}else{
				add_on_end(list, new);
			}
		}

		print_list(list);
		printf("\n#############################\n");
	
		print_list_recursive(list, list->start);
	
		printf("\n#############################\n");
		printf("Median:%d\n", list_median(list));
	
		printf("\nSum: %d\n", sum_them_all_re(list, list->start));
		
		if(binary_search(list, 9)){
			printf("Achou\n");
		}
		free(list);
	}
return 0;
}

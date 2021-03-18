#include <stdio.h>
#include <stdlib.h>
struct node{
	int key;
	struct node *next;
};
struct node *son_eklenen =NULL;
struct node *dugum_koruma;
struct node *stack = NULL;

void insert_stack(int key){
	if(stack == NULL){
		stack = (struct node*)malloc(sizeof(struct node));
		stack->key = key;
		stack->next = NULL;
		son_eklenen = stack; 
	}else{
		son_eklenen->next = (struct node*)malloc(sizeof(struct node));
		son_eklenen->next->key= key;
		son_eklenen->next->next=NULL;
		dugum_koruma = son_eklenen;
		son_eklenen = son_eklenen->next;
	}
}
void delete_stack(){
	dugum_koruma->next =NULL;
	son_eklenen = dugum_koruma;  
}
void find_stack(int key){
	struct node *koruma;
	koruma = stack;
	while(koruma!=NULL){
		if(koruma->key == key){
			printf("Aranan sayi stack\'de mevcut \n");
			return ;
		}
		koruma = koruma->next;
	}
	printf("Aranan sayi bulunamadi");
}
void print_stack(){
	while(stack != NULL){
		printf(" %d ",stack->key);
		stack = stack->next;
	}
}

int main(){
	insert_stack(10);
	insert_stack(20);
	insert_stack(30);
	insert_stack(40);

	delete_stack();
	find_stack(30);
	print_stack();
	
}

#include <stdio.h>
#include <stdlib.h>

struct node_link{
	char *veri;
	struct node_link *next;
};

struct node{
	int counter;
	struct node_link *header;
};
int hash(char *veri, int size){
	int value = 0;
	int i = 0;
	while(veri[i]){
		value = (int)(veri[i])*i+value;		
		i++;	
	}
	return value % size;
}

struct node* initalieze(int size){
	struct node *dizi=(struct node*)malloc(sizeof(struct node)*size);
	int counter = 0;
	while(counter<size){
		(dizi+counter)->counter= 0;
		(dizi+counter)->header=(struct node_link*)malloc(sizeof(struct node_link));
		(dizi+counter)->header->veri ="NULL";
		(dizi+counter)->header->next=NULL;
		counter++;
	}
	
	return dizi;
	
}

void node_insert(struct node *dizi , char *veri, int size){
	int sira = hash(veri,size);
	(dizi+sira)->counter = (dizi+sira)->counter +1;
	if((dizi+sira)->header->veri =="NULL"){
		(dizi+sira)->header->veri=veri;
		return ;
	}
		struct node_link *iter;
		iter = (dizi+sira)->header;
		while(iter->next!=NULL){
			iter=iter->next;
		}
		iter->next=(struct node_link*)malloc(sizeof(struct node_link));
		iter->next->veri=veri;
		iter->next->next=NULL;
}

void node_print(struct node *dizi,int size){
	int counter =0;
	printf("------------dizi elemanları--------------\n");
	while(counter<size){
		printf("%d.elemananda ",counter);
		printf("%d 'kadar eleman bulunuyor->",(dizi+counter)->counter);
		struct node_link *iter = (dizi+counter)->header;
		while(iter->next !=NULL){
			printf("%s->",iter->veri);
			iter=iter->next;
		}
		printf("%s ",iter->veri);
		printf("\n");
		counter++;
		
	}
}

int main() {
	
			struct node *dizi;
			dizi=initalieze(10);
			node_insert(dizi,"Soner",10);
			node_insert(dizi,"Soner",10);
			node_insert(dizi,"Soner",10);
			node_insert(dizi,"soner",10);
			node_insert(dizi,"soner",10);
			node_insert(dizi,"deneme_kisi",10);
			node_insert(dizi,"deneme_kisi",10);
			node_insert(dizi,"mehmet",10);
			node_insert(dizi,"mehmet",10);
			node_insert(dizi,"mehmet",10);
			node_insert(dizi,"denem1",10);			
			node_insert(dizi,"denem2",10);
			node_insert(dizi,"denem3",10);


			node_print(dizi,10);	
		

			
}




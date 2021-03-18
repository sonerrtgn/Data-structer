#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *next;
};
struct node* initilaze_node(int key){
	struct node *dugum_basi = (struct node *)malloc(sizeof(struct node));
	dugum_basi->key = 10;
	dugum_basi->next =NULL;
	return dugum_basi;
}
struct node* insert_node(struct node *dugum,int key){
	if(dugum == NULL){
		dugum = (struct node *)malloc(sizeof(struct node));
		dugum->key = key;
		dugum->next=NULL;
		return dugum;
	}
	dugum->next = insert_node(dugum->next,key);
	return dugum;
}
int node_search(struct node *dugum,int key){
	while(dugum !=NULL){
		if(dugum->key = key){
			return 1;
		}	
		dugum = dugum->next;
	}
	return 0;
}
int how_node_x(struct node *dugum_basi,int sira){
	int count = 0;
	while(count < sira){
		dugum_basi = dugum_basi->next;
		count++;
	}
	return dugum_basi->key;
}
void print_node_count(struct node *dugum_basi,int sira){
	int count = 0;
	while(count < sira){
		dugum_basi = dugum_basi->next;
		count++;
	}
	printf("\n%d\n",dugum_basi->key);
}
void print_node(struct node *dugum_basi){
	printf("\n[");
	printf("%d",dugum_basi->key);
	dugum_basi = dugum_basi->next;
	while(dugum_basi!=NULL){
		printf(",%d",dugum_basi->key);
		dugum_basi=dugum_basi->next;
	}
	printf("]\n");
}
int node_uzunluk(struct node *dugum){
	int count = 0;
	while(dugum!=NULL){
		count++;
		dugum=dugum->next;
	}
	return count-1;
}

void max_sirala_node(struct node *dugum_basi){
	int count2 = node_uzunluk(dugum_basi) ;
	struct node *node_dugum_basi_tut = dugum_basi;
	while(count2 >0){
		int count = 0;
		dugum_basi = node_dugum_basi_tut;
		while(count < count2 && dugum_basi->next != NULL){
			if(dugum_basi->key < dugum_basi->next->key){
				int koruma = dugum_basi->key;
				dugum_basi->key = dugum_basi->next->key;
				dugum_basi->next->key  = koruma;
			}
			dugum_basi = dugum_basi->next;
			count++;
		}
		count2--;
	}
}

void node_son_sil(struct node *dugum){
	while(dugum->next->next !=NULL){
		dugum = dugum->next;
	}
	dugum->next = NULL;
}
struct node* node_ilk_sil(struct node *dugum){
	struct node *node_tut = dugum->next;
	dugum = NULL;
	dugum = node_tut;
	
}


int main(){
	struct node *dugum_basi;
	dugum_basi = initilaze_node(10);
	dugum_basi = insert_node(dugum_basi,15);
	dugum_basi = insert_node(dugum_basi,20);
	dugum_basi = insert_node(dugum_basi,25);
	dugum_basi = insert_node(dugum_basi,30);
	dugum_basi = insert_node(dugum_basi,35);
	dugum_basi = insert_node(dugum_basi,45);
	dugum_basi = node_ilk_sil(dugum_basi);

	max_sirala_node(dugum_basi);
	print_node(dugum_basi);

	printf("\n%d\n",node_uzunluk(dugum_basi));

	
}













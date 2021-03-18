#include <stdio.h>
#include <stdlib.h>
struct tree{
	int key;
	struct tree *left;
	struct tree *right;
};

struct tree* tree_insert(struct tree *root, int key){
	if(root == NULL){
		//Root is null == add;
		root = (struct tree *)malloc(sizeof(struct tree));
		root->key  =key;
		root->left  =NULL;
		root->right = NULL;
		return root;
	}
	if(root->key > key){
		root->left = tree_insert(root->left,key);
	}else{
		root->right = tree_insert(root->right,key);
	}
}
void tree_search(struct tree *root, int search){
	int controller = 0;
	while(root != NULL){
		if(root->key == search){
			printf("%d Bulundu",search);
			controller=1;
			break;
		}else if(root->key < search){
			root = root->right;
		}else{
			root= root->left;
		}
	}
	if(controller == 0 ){
		printf("%d not in the tree",search);
	}
}
void print_tree_preorder(struct tree *root){
	if(root == NULL){
		return ;
	}
	print_tree_preorder(root->left);
	printf("%d ",root->key);
	print_tree_preorder(root->right);
}


int tree_balance(struct tree *root){
	if(root == NULL){
		return 1;
	}
	if(root->left !=NULL){
		if(root->left->left !=NULL && root->right ==NULL){
			printf("%d \'den itibaren denge bozuldu",root->key);
			return 0;
		}
		if(root->left->right !=NULL && root->right ==NULL){
			printf("%d \'den itibaren denge bozuldu",root->key);
			return 0;
		}
	}
	if(root->right!=NULL){
		if(root->right->right !=NULL && root->left ==NULL){
			printf("%d \'den itibaren denge bozuldu",root->key);
			return 0; 
		}
		if(root->right->left !=NULL && root->left ==NULL){
			printf("%d \'den itibaren denge bozuldu",root->key);
			return 0;
		}
	}
	return (tree_balance(root->right) && tree_balance(root->left));
}
int main(){
	struct tree *root;
	root = NULL;
	root = tree_insert(root,10);
	root = tree_insert(root,20);
	root = tree_insert(root,30);
	root = tree_insert(root,40);
	root = tree_insert(root,50);
	root = tree_insert(root,60);
	root = tree_insert(root,70);
	
	tree_balance(root);
	printf("\n");
	root = tree_insert(root,5);
	print_tree_preorder(root);


	
	
	
}

#include <stdio.h>
#include <stdlib.h>

// Dinh nghia 1 nut
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//Tao ra 1 nut
Node* createNode(int data){
	//cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node* node, int data) {
    if(node == NULL) {
        return createNode(data);
    }
    if(data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else if(data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}


void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d\t",node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

void inorderTraversal(Node* node){
	if(node != NULL){
		inorderTraversal(node->left);   
        printf("%d\t", node->data);    
        inorderTraversal(node->right);
	}
}

void postorderTraversal(Node* node){
	if(node != NULL){
		postorderTraversal(node->left);   
        postorderTraversal(node->right);
        printf("%d\t", node->data);    
	}
}


int main(){
	Node* tree = NULL;
	int n;
	int value;
	printf("Nhap n: ");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		printf("Gia tri: ");
		scanf("%d",&value);
		tree = insertNode(tree, value);
	}
	printf("\nDuyet tien thu tu: \n");
	preorderTraversal(tree);
	printf("\nDuyet trung thu tu: \n");
	inorderTraversal(tree);
	printf("\nDuyet hau thu tu: \n");
	postorderTraversal(tree);


	
	return 0;
}

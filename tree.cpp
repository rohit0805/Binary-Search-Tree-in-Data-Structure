#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *create(int data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
void inorder(struct node *root){
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
struct node* insert(struct node *root,int data){
	if(root==NULL)
		return create(data);
	else if(root->data>=data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
struct node* findmin(struct node *root){
	struct node *current=root;
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}
struct node* deletenode(struct node *root,int data){
	if(root==NULL)
		return NULL;
	else if(root->data>data)
		root->left=deletenode(root->left,data);
	else if(root->data<data)
		root->right=deletenode(root->right,data);
	else{
		//if the deletednode is leaf or have only one child
		if(root->left==NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		struct node *temp=findmin(root->right);
		root->data=temp->data;
		root->right=deletenode(root->right,temp->data);
	}
	return root;
}
int main(){
	struct node *root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);	
	insert(root,70);	
	insert(root,60);	
	insert(root,80);
	cout<<"Inorder traversal of tree\n";	
	inorder(root);
	
    cout<<"\nDelete 20\n";
    root = deletenode(root, 20);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);

    cout<<"\nDelete 30\n";
    root = deletenode(root, 30);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);

    cout<<"\nDelete 50\n";
    root = deletenode(root, 50);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);

	return 0;
}
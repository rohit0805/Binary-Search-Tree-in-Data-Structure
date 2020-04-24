#include<bits/stdc++.h>
using namespace std;
struct node{
	int data,height;
	struct node *left,*right;
};
struct node *create(int data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	newnode->height=1;
	return newnode;
}
void preorder(struct node *root){
	if(root==NULL)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int height(struct node *root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
int getbalance(struct node *root){
	if(root==NULL)
		return 0;
	return height(root->left)-height(root->right);
}
struct node* rightrotate(struct node *root){
	struct node *temp=root->left->right,*ret=root->left;
	ret->right=root;
	root->left=temp;

	root->height=1+max(height(root->left),height(root->right));
	ret->height=1+max(height(ret->left),height(ret->right));
	return ret;
}
struct node* leftrotate(struct node *root){
	struct node *temp=root->right->left,*ret=root->right;
	root->right->left=root;
	root->right=temp;

	root->height=1+max(height(root->left),height(root->right));
	ret->height=1+max(height(ret->left),height(ret->right));
	return ret;
}
struct node* insert(struct node *root,int data){
	if(root==NULL)
		return create(data);
	else if(root->data>=data)
		root->left=insert(root->left,data);
	else if(root->data<data)
		root->right=insert(root->right,data);
	else
		return root;
	//updating the position
	root->height=1+max(height(root->left),height(root->right));
	int balance=getbalance(root);

	//left-left
	if(balance>=2 && data < root->left->data)
		return rightrotate(root);
	//right-right
	if(balance<=-2 && data>root->right->data)
		return leftrotate(root);
	//left-right
	if(balance>=2 && data> root->left->data){
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	//right-left
	if(balance<=-2 && data<root->right->data){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}

int main(){
	struct node *root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);	
	root=insert(root,25);	
	cout<<"Inorder traversal of tree\n";	
	preorder(root);

	return 0;
}

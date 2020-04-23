#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *create(int data){
	struct node *newnode=new node;
	newnode->left=newnode->right=NULL;
	newnode->data=data;
	return newnode;
}

void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
struct node* insert(struct node *root,int data){
	if(root==NULL){
		return create(data);
	}
	if(root->data>=data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
bool search(struct node *root,int data){
	if(root==NULL)
		return false;
	if(root->data==data){
		return true;
	}
	if(root->data>=data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

int main(){
	struct node *root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout<<search(root,700)<<endl;
    inorder(root);
	return 0;
}
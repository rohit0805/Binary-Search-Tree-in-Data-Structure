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
struct node* insert(struct node* node, int key)
{
    if (node == NULL) 
        return create(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
int floor(struct node *root,int x){
	int ans=-1;
	while(root!=NULL){
		if(root->data>x)
			root=root->left;
		else if(root->data < x){
			ans=root->data;
			root=root->right;
		}
		else{
			ans=root->data;
			break;
		}
	}
	return ans;
}
int ceil(struct node *root,int x){
	int ans=INT_MAX;
	while(root!=NULL){
		if(root->data>x){
			ans=root->data;
			root=root->left;
		}
		else if(root->data<x){
			root=root->right;
		}
		else{
			ans=root->data;
			break;
		}
	}
	return ans;
}
int main(){
	struct node *root=NULL;
	root=insert(root,10);
	insert(root,5);
	insert(root,15);
	insert(root,12);	
	insert(root,30);
	
	cout<<"Inorder traversal of tree\n";	
	inorder(root);
	cout<<"\nEnter the number whose floor you want to find: ";
	int x;
	cin>>x;
	cout<<floor(root,x)<<endl;

	cout<<"\nEnter the number whose ceil you want to find: ";
	cin>>x;
	cout<<ceil(root,x)<<endl;

	return 0;
}

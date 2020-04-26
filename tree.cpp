#include<bits/stdc++.h>
using namespace std;
struct node{
	int data,count,height;
	struct node *left,*right;
};
struct node* create(int data){
	struct node *newnode=new node;
	newnode->data=data;
	newnode->height=1;
	newnode->count=1;
	newnode->left=newnode->right=NULL;
	return newnode;
}
int height(struct node *root){
	if(root==NULL)
		return 0;
	return root->height;
}
int getbalance(struct node *root){
	if(root==NULL)
		return 0;
	return height(root->left)-height(root->right);
}
void preorder(struct node *root){
	if(root==NULL)
		return ;
	cout<<root->data<<"("<<root->count<<")"<<" ";
	preorder(root->left);
	preorder(root->right);
}
struct node* leftrotate(struct node *root){
	struct node *ret=root->right,*temp=ret->left;
	ret->left=root;
	root->right=temp;

	root->height=1+max(height(root->left),height(root->right));
	ret->height=1+max(height(ret->left),height(ret->right));

	return ret;
}
struct node* rightrotate(struct node *root){
	struct node *ret=root->left,*temp=ret->right;
	ret->right=root;
	root->left=temp;

	root->height=1+max(height(root->left),height(root->right));
	ret->height=1+max(height(ret->left),height(ret->right));
	return ret;
}
struct node* insert(struct node* root,int data){
	if(root==NULL)
		return create(data);
	if(root->data==data){
		(root->count)++;
		return root;
	}
	else if(root->data>data)
		root->left=insert(root->left,data);
	else if(root->data<data)
		root->right=insert(root->right,data);
	
	//check for balance
	root->height=1+max(height(root->left),height(root->right));
	int balance=getbalance(root);

	//left-left
	if(balance>=2 && root->left->data>data)
		return rightrotate(root);
	//right-right
	if(balance<=-2 && root->right->data<data)
		return leftrotate(root);
	//left-right
	if(balance>=2 && root->left->data<data){
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	//right-left
	if(balance<=-2 && root->right->data>data){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}
struct node* minvalue(struct node *root){
	struct node *current=root;
	while(current->left!=NULL)
		current=current->left;
	return current;
}
struct node* deletenode(struct node *root,int data){
	if(root==NULL)
		return root;
	else if(root->data>data)
		root->left=deletenode(root->left,data);
	else if(root->data<data)
		root->right=deletenode(root->right,data);
	else{
		if(root->count>=2){
			(root->count)--;
			return root;
		}
		else{
			if(root->left==NULL || root->right==NULL){
				struct node *temp=root->left?root->left:root->right;
				if(temp==NULL){
					temp=root;
					root=NULL;
				}			
				else{
					*root=*temp;
				}	
				free(temp);
			}
			else{
				struct node *temp=minvalue(root->right);
				root->data=temp->data;
				root->count=temp->count;
				temp->count=1;
				root->right=deletenode(root->right,temp->data);
			}
		}
	}
	if(root==NULL)
		return root;
	root->height=1+max(height(root->left),height(root->right));
	int balance=getbalance(root);	
	
	//left-left
	if(balance>=2 && getbalance(root->left)>=0){
		return rightrotate(root);
	}	
	//left-right
	if(balance>=2 && getbalance(root->left)<0){
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	//right-right
	if(balance<=-2 && getbalance(root->right)<=0){
		return leftrotate(root);
	}
	//right-left
	if(balance<=-2 && getbalance(root->right)>0){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}
int main(){
	struct node *root=NULL;
	root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 5); 
    root = insert(root, 9); 
    root = insert(root, 7); 
    root = insert(root, 17);
    root=insert(root,15);
    cout<<"Pre order traversal of the constructed AVL tree is \n"; 
    preorder(root); 
  
    root = deletenode(root, 9); 
  	root = deletenode(root, 9); 
  	
    printf("\nPre order traversal after deletion of 9 \n"); 
    preorder(root); 
}
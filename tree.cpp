#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
	int count;
};
struct node *create(int data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->count=1;
	newnode->left=newnode->right=NULL;
	return newnode;
}
void inorder(struct node *root){
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<root->data<<"("<<root->count<<")"<<" ";
	inorder(root->right);
}

struct node* insert(struct node* root,int data){
	if(root==NULL)
		return create(data);
	else if(data==root->data){
		root->count++;
		return root;
	}
	else if(data<root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	
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
		return NULL;
	else if(root->data>data)
		root->left=deletenode(root->left,data);
	else if(root->data<data)
		root->right=deletenode(root->right,data);
	else{
		if(root->count>=2){
			root->count--;
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
				root->right=deletenode(root->right,temp->data);
			}
		}
	}
	return root;
}

int main(){
	struct node *root=NULL;
	root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 9); 
    root = insert(root, 11); 
    root = insert(root, 10); 
    root = insert(root, 12); 
    root = insert(root, 12);
    cout<<"Inorder traversal of the tree\n";
    inorder(root);

    cout << "\nDelete 20\n"; 
    root = deletenode(root, 20); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 12\n" ; 
    root = deletenode(root, 12); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 9\n"; 
    root = deletenode(root, 9); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
	return 0;
}
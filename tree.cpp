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
int lca(struct node *root,int d1,int d2){
	if(root->data>=d1 && root->data<=d2)
		return root->data;
	else if(root->data>d1 &&root->data>d2){
		return lca(root->left,d1,d2);
	}
	else
		return lca(root->right,d1,d2);
	return root->data;
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

int main(){
	struct node *root=NULL;
	root=insert(root,20);
	insert(root,8);
	insert(root,22);
	insert(root,4);	
	insert(root,12);	
	insert(root,10);	
	insert(root,14);
	cout<<"Inorder traversal of tree\n";	
	inorder(root);
	cout<<"LCA of 10 and 14: "<<lca(root,10,14)<<endl;
	cout<<"LCA of 8 and 14: "<<lca(root,8,14)<<endl;
	cout<<"LCA of 10 and 22: "<<lca(root,10,22)<<endl;
	return 0;
}
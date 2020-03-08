#include<iostream>
#include<string>

using namespace std;

string tree;

int p = 0;

struct tree_node{
	char val;
	tree_node* left;
	tree_node* right;
	tree_node(char c): val(c), left(NULL), right(NULL){}
};
tree_node* root;

tree_node* build_tree(){
	if(p>=tree.size() || tree[p]=='#'){
		p++;
		return NULL;
	}
	tree_node* node = new tree_node(tree[p]);
	p++;
	node->left = build_tree();
	node->right = build_tree();
	return node;
}

void pre(tree_node* root){
	if(root == NULL) return;
	pre(root->left);
	cout<<root->val<<" ";
	pre(root->right);
}

int main(void){
	cin>>tree;
	root = build_tree();
	pre(root);
}


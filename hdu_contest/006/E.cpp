#include<iostream>
#include<vector>
#include<string>

using namespace std;

int k, n;

struct tree_node{
	tree_node* left;
	tree_node* right;
	int val;
	tree_node(int x): val(x), left(NULL), right(NULL){}
};



void in_visit(vector<int>& path, tree_node* node){
	if(node==NULL) return;
	path.push_back(node->val);
	in_visit(path, node->left);
	in_visit(path, node->right);
}


void Insert(tree_node*& root, int c){
	if(root==NULL){
		root = new tree_node(c);
		return; 
	}
	if(root->val>c){
		Insert(root->left, c);
	}
	else{
		Insert(root->right, c);
	}
}

string str;
int main(void){
	while(true){
		cin>>k;
		if(k==0) return 0;
		cin>>str;
		n = str.size();
		tree_node* root = NULL;
		for(int i=0; i<n; i++){
			Insert(root, str[i]-'0');
		}

		vector<int> path;
		in_visit(path, root);

		while(k--){
			cin>>str;
			vector<int> tmp;
			root = NULL;
			for(int i=0; i<n; i++){
				Insert(root, str[i]-'0');
			}

			in_visit(tmp, root);

			/*
			for(auto c:path) cout<<c<<" ";
			cout<<endl;
			for(auto c:tmp) cout<<c<<" ";
			cout<<endl;
			*/

			if(tmp == path)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}

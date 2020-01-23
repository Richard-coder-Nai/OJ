#include<iostream>
#include<vector>


using namespace std;

struct Tree_node{
	int val;
	Tree_node* left;
	Tree_node* right;
	Tree_node(int x): val(x), left(nullptr), right(nullptr){}
};


void insert(Tree_node* & root, int data){
	if(root==nullptr){
		root = new Tree_node(data);
	}
	else{
		if(root->val>data){
			insert(root->left, data);
		}else{
			insert(root->right, data);
		}
	}
}


void pre_visit(Tree_node* root, vector<int>& table){
	if(root==nullptr){
		return;
	}else{
		table.push_back(root->val);
		pre_visit(root->left, table);
		pre_visit(root->right, table);
	}
}

void post_visit(Tree_node* root, vector<int>& table){
	if(root==nullptr){
		return;
	}else{
		post_visit(root->left, table);
		post_visit(root->right, table);
		table.push_back(root->val);
	}
}

void pre_visit_M(Tree_node* root, vector<int>& table){
	if(root==nullptr){
		return;
	}else{
		table.push_back(root->val);
		pre_visit_M(root->right, table);
		pre_visit_M(root->left, table);
	}
}

void post_visit_M(Tree_node* root, vector<int>& table){
	if(root==nullptr){
		return;
	}else{
		post_visit_M(root->right, table);
		post_visit_M(root->left, table);
		table.push_back(root->val);
	}
}



int main(void){
	int n;
	cin>>n;

	Tree_node* root= nullptr;
	vector<int> input_seq;
	for(int i=0; i<n; i++){
		int val;
		cin>>val;
		input_seq.push_back(val);
		insert(root, val);
	}
	
	vector<int> pre;
	pre_visit(root, pre);

	vector<int> pre_M;
	pre_visit_M(root, pre_M);


	if(pre==input_seq){
		vector<int> post;
		post_visit(root, post);

		cout<<"YES"<<endl;
		bool first = true;
		for(auto it:post){
			if(first==false){
				cout<<" ";
			}
			first=false;
			cout<<it;
		}
		cout<<endl;
	}
	
	else if(pre_M==input_seq){
		vector<int> post;
		post_visit_M(root, post);
		cout<<"YES"<<endl;
		bool first = true;
		for(auto it:post){
			if(first==false){
				cout<<" ";
			}
			first=false;
			cout<<it;
		}
		cout<<endl;
	}

	else{
		cout<<"NO"<<endl;
	}
}

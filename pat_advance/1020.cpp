#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

struct Tree_node{
	Tree_node* left;
	Tree_node* right;
	int val;
	Tree_node(int x): val(x), left(NULL), right(NULL) {};
};


vector<int> post_seq;
vector<int> in_seq;

map<int, int> table;

Tree_node* dfs(int is, int ie, int ps, int pe) {
	if(ps>pe || is>ie) return NULL;
	int ri = table[post_seq[pe]];
	Tree_node* node = new Tree_node(post_seq[pe]);
	node->left = dfs(is, ri - 1, ps, ps + ri - is - 1);
	node->right = dfs(ri + 1, ie, ps + ri - is, pe - 1);
	return node;
}

void level_visit(Tree_node* root){
	queue<Tree_node*> q;
	q.push(root);
	bool first = true;
	while(!q.empty()){
		auto front = q.front();
		if(!first) cout<<" ";
		first = false;
		cout<<(front->val);
		q.pop();
		if(front->left) q.push(front->left);
		if(front->right) q.push(front->right);
	}
	cout<<endl;
}

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int j;
		cin>>j;
		post_seq.push_back(j);
	}
	for(int i=0; i<n; i++){
		int j;
		cin>>j;
		table[j] = i;
		in_seq.push_back(j);
	}
	
	Tree_node* root = dfs(0, n-1, 0, n-1);
	level_visit(root);
}

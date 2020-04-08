#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int post[35];
int in[35];
int n;

struct Tree_Node{
	int val;
	Tree_Node* left;
	Tree_Node* right;
	Tree_Node(int x): val(x), left(NULL), right(NULL){}
};

void bfs(Tree_Node* root){
	queue<Tree_Node*> q;
	q.push(root);
	while(q.size()){
		auto front = q.front();
		cout<<front->val<<" ";
		q.pop();
		if(front->left) q.push(front->left);
		if(front->right) q.push(front->right);
	}
	cout<<endl;
}

Tree_Node* build(int il, int ir, int pl, int pr){
	if(il>ir || pl>pr) return NULL;
	int k = post[pr];


	Tree_Node* node = new Tree_Node(k);
	if(il==ir || pl==pr) return node;

	int l_size = *find(in+il, in+ir+1, k)-il-1;
	cout<<l_size<<endl;

	node->left = build(il, il+l_size-1, pl, pl+l_size-1);
	node->left = build(il+l_size+1, ir, pl+l_size, pr-1);

	return node;
}

int main(void){
	cin>>n;
	for(int i=0; i<n; i++) cin>>post[i];
	for(int i=0; i<n; i++) cin>>in[i];
	cout<<"hi"<<endl;
	Tree_Node* root = build(0, n-1, 0, n-1);
	bfs(root);
}

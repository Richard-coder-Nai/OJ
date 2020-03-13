#include<iostream>

using namespace std;

#define MAX_LEN 1005;

int arr[6] = {1, 3, 5, 7, 9, 11};
int tree[MAX_LEN];

void build_tree(int node, int start, int end){
	if(start==end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	int left_node = 2*node + 1;
	int right_node = 2*node + 2;

	build_tree(left_node, start, mid);
	build_tree(right_node, mid+1, end);
	tree[node] = tree[left_node] + tree[right_node];
}

int main(void){
	int size = 6;
	build_tree(0, 0, size-1);

	for(int i=0; i<n; i++){
	}
}

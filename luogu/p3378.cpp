#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int opt, x;

priority_queue<int, vector<int>, greater<int> > heap;

int main(void){
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &opt);
		if(opt==1){
			scanf("%d", &x);
			heap.push(x);
		}
		else if(opt==2) cout<<heap.top()<<endl;
		else heap.pop();
	}
}

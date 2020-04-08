#include<iostream>

using namespace std;

const int N = 1e4+5;
int k, x;

struct Node{
	int start;
	int end;
	int sum;
}node[N];

int main(void){
	cin>>k;
	for(int i=0; i<k; i++){
		cin>>x;
		node[i].end = x;
		node[i].start = x;
	}

	node[0].start = node[0].end;
	node[0].sum = node[0].end;
	Node res = node[0];

	for(int i=1; i<k; i++){
		if(node[i-1].sum>0){
			node[i].sum = node[i-1].sum+node[i].end;
			node[i].start = node[i-1].start;
		}else{
			node[i].sum = node[i].end;
		}
		if(node[i].sum>res.sum){
			cout<<"hi"<<endl;
			cout<<node[i].sum<<endl;
			cout<<res.sum<<endl;
			res = node[i];
		}
	}
	cout<<res.sum<<" "<<res.start<<" "<<res.end<<endl;
}

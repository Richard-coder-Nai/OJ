#include<iostream>
#include<queue>

using namespace std;

int main(void){
	priority_queue<int, vector<int>, greater<int>> pq;	    //top: small
	int n,k;
	cin>>n>>k;

	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		pq.push(tmp);
	}

	for(int i=0; i<k-1; i++){
		pq.pop();
	}
	cout<<pq.top()<<endl;
}



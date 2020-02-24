#include<iostream>
#include<queue>

using namespace std;

int main(void){
	int n,k;
	cin>>n>>k;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		pq.push(tmp);
	}

	for(int i=0; i<k; i++){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	return 0;
}

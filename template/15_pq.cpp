#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct cmp{
	bool operator()(int x, int y){
		return x<y;
	}
};

typedef pari<int, int> PII;
struct cmp2{
    bool operator() (PII a, PII b) {
		return a.first< b.first;
	}
};

int main(void){
	// default is big heap
	priority_queue<int, vector<int>, less<int>> pq1;		//top: big
	priority_queue<int, vector<int>, greater<int>> pq2;	    //top: small

	priority_queue<int, vector<int>, cmp> pq3;

	int n = 10;
	for(int i=0; i<n; i++){
		pq1.push(i);
		pq2.push(i);
		pq3.push(i);
	}

	while(!pq1.empty()){
		cout<<pq1.top()<<" ";
		pq1.pop();
	}
	cout<<endl;

	while(!pq2.empty()){
		cout<<pq2.top()<<" ";
		pq2.pop();
	}
	cout<<endl;

	while(!pq3.empty()){
		cout<<pq3.top()<<" ";
		pq3.pop();
	}
	cout<<endl;
}

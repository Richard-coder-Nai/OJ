#include<iostream>
#include<queue>

using namespace std;

const int MAX = 1000010;
int nums[MAX];

int main(void){
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++) cin>>nums[i];

	queue<int> q;
	for(int i=0; i<k; i++){
		if(i==0) q.push(i);
		if(nums[q.back()]>nums[i]) q.push(i);
	}

	for(int i=k; i<n; i++){
		cout<<nums[q.back()]<<" ";
		while(q.front()<=i-k && !q.empty()) q.pop();
		if(nums[q.back()]>nums[i] || q.empty()) q.push(i);
	}
	cout<<nums[q.back()]<<endl;

	q = queue<int>();
	for(int i=0; i<k; i++){
		if(i==0) q.push(i);
		if(nums[q.back()]<nums[i]) q.push(i);
	}

	for(int i=k; i<n; i++){
		cout<<nums[q.back()]<<" ";
		while(q.front()<=i-k && !q.empty()) q.pop();
		if(nums[q.back()]<nums[i] || q.empty()) q.push(i);
	}
	cout<<nums[q.back()]<<endl;

}

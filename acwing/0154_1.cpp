#include <iostream>
#include <queue>

using namespace std;

// MIN:
// 我们在往队尾插入元素之前
// 先将队尾大于等于当前数的元素全部弹出即可

const int N = 1e6+10;
int nums[N];

deque<int> min_q;
deque<int> max_q;

int main(void) {
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>nums[i];
	}

	for(int i=0; i<n; i++) {
		// check if windows out of range
		if(min_q.front()<i-k+1) {
			min_q.pop_front();
		}
		while(min_q.size() && nums[min_q.back()]>=nums[i]) {
			min_q.pop_back();
		}
		min_q.push_back(i);
		if(i>=k-1) {
			cout<<nums[min_q.front()]<<" ";
		}
	}
	cout<<endl;


	for(int i=0; i<n; i++) {
		// check if windows out of range
		if(max_q.front()<i-k+1) {
			max_q.pop_front();
		}
		while(max_q.size() && nums[max_q.back()]<=nums[i]) {
			max_q.pop_back();
		}
		max_q.push_back(i);
		if(i>=k-1) {
			cout<<nums[max_q.front()]<<" ";
		}
	}
	cout<<endl;

}

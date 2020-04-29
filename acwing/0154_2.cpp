#include <iostream>
#include <queue>

using namespace std;

int n, k;
int nums[1000006];

int main(void) {
	cin>>n>>k;

	for(int i=0; i<n; i++) {
		cin>>nums[i];
	}

	deque<int> q;

	//min q
	for(int i=0; i<n; i++) {
		if(q.size() && q.front()<i-k+1) {
			q.pop_front();
		}
		while(q.size() && nums[q.back()]>=nums[i]) {
			q.pop_back();
		}
		q.push_back(i);
		if(i>=k-1) {
			cout<<nums[q.front()]<<" ";
		}
	}
	cout<<endl;

	q.clear();

	//max q
	for(int i=0; i<n; i++) {
		if(q.size() && q.front()<i-k+1) {
			q.pop_front();
		}
		while(q.size() && nums[q.back()]<=nums[i]) {
			q.pop_back();
		}
		q.push_back(i);
		if(i>=k-1) {
			cout<<nums[q.front()]<<" ";
		}
	}
	cout<<endl;
}

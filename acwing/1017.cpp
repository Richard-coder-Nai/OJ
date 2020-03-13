#include<iostream>
#include<vector>

using namespace std;

int k;
int main(void){
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		vector<int> f(n, 0);
		vector<int> nums(n, 0); 

		int idx = -1;
		int mx = -1;
		for(int i=0; i<n; i++){
			cin>>nums[i]; 
			if(nums[i]>mx){
				mx = nums[i];
				idx = i;
			}
		}

		mx = -1;
		for(int idx=0; idx<n; idx++){
			fill(f.begin(), f.end(), 0);
			f[idx] = 0;
			for(int i=idx+1; i<n; i++){
				for(int j=idx; j<i; j++){
					if(nums[i]<nums[j]){
						f[i] = max(f[i], f[j]+1);
						if(f[i]>mx)
							mx = f[i];
					}
				}
			}
			for(int i=idx-1; i>=0; i--){
				for(int j=idx; j>i; j--){
					if(nums[i]<nums[j]){
						f[i] = max(f[i], f[j]+1);
						if(f[i]>mx)
							mx = f[i];
					}
				}
			}
		}
		cout<<mx+1<<endl;
	}
}

#include<iostream> 
#include<algorithm>

using namespace std; 
int nums[100005]; 

int main(void){
    int n;
	cin>>n;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    sort(nums, nums+n);
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
	cout<<endl;
}

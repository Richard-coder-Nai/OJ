#include<iostream> 
#include<vector> 
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> nums;
    int opt,x;
    for(int i=0; i<n; i++){
        cin>>opt>>x;
        if(opt==1){
            nums.insert(upper_bound(nums.begin(),nums.end(),x),x);
        }
        if(opt==2){
            auto it = lower_bound(nums.begin(), nums.end(), x);
            nums.erase(it);
        }
        if(opt==3){
            auto it = lower_bound(nums.begin(), nums.end(), x);
            cout<<distance(nums.begin(), it)+1<<endl;
        }
        if(opt==4){
            cout<<nums[x-1]<<endl;
        }
        if(opt==5){
            auto it = lower_bound(nums.begin(), nums.end(), x);
            it--;
            cout<<*it<<endl;
        }
        if(opt==6){
            auto it = upper_bound(nums.begin(), nums.end(), x);
            cout<<*it<<endl;
        }
    }
}

/*************************************************************************
	> File Name: 1004.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 07:26:01 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>

using namespace std;


int main(void){
	int n;	
	while(cin>>n){
		if(n==0) break;
		else{
			map<string, int> counter;
			for(int i=0; i<n; i++){
				string str;	
				cin>>str;
				if(counter.count(str))
					counter[str]++;
				else
					counter[str]=1;
			}

			string max_str = "";
			int max_count = -1;
			for(auto item:counter){
				//cout<<item.first<<" "<<item.second<<endl;
				if(item.second>max_count){
					max_str = item.first;
					max_count = item.second;
				}
			}
			//cout<<max_count<<endl;
			cout<<max_str<<endl;
		}
	}
}

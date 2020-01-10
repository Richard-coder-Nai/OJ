/*************************************************************************
	> File Name: 02_score_sort.cpp
	> Author: zhangyang
	> Mail: zyziszy@foxmail.com
	> Created Time: Fri 10 Jan 2020 08:31:44 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main(void){
    map<int, string> table;

    int n, mode;
    cin>>n>>mode;
    
    for(int i=0; i<n; i++){
        int score;
        string name;
        cin>>name>>score;
        table[score]=name;
    }

    if(mode){
        for(auto item:table)
            cout<<item.second<<" "<<item.first<<endl;
    }
    else{
        for(auto item=table.rbegin(); item!=table.rend(); item++)
            cout<<(*item).second<<" "<<(*item).first<<endl;
    }
}

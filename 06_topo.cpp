/*************************************************************************
	> File Name: 06_topo.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 09:29:52 PM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<vector>
using namespace std;


struct node{
	int id;
	int wt;
	node(int _id,int _weight):id(_id),wt(_weight){}
};


int main(void){
	//adj list init
	int n,e;
	cin>>n>>e;
	vector<list<int>> adj;
	adj.assign(e, list<int>());
	vector<int> in_degree;
	vector<int> out_degree;


}

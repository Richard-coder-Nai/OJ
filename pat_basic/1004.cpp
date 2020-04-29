/*************************************************************************
	> File Name: 1004.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Wed 01 Jan 2020 08:36:16 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;


int main(void){
	string name, course;
	int score;

	map<int, string> name_map;
	map<int, string> course_map;
	int max_score, min_score;
	
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>name>>course>>score;
		name_map[score] = name;
		course_map[score] = course;
		if(i==0){
			max_score = score;
			min_score = score;
		}else{
			if(score>max_score)	
				max_score = score;
			if(score<min_score)
				min_score = score;
		}
	}
	cout<<name_map[max_score]<<" "<<course_map[max_score]<<endl;
	cout<<name_map[min_score]<<" "<<course_map[min_score]<<endl;
}


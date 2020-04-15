/*************************************************************************
  > File Name: 01_new_delete.cpp
  > Author: Yang Zhang
  > Mail: zyziszy@foxmail.com
  > Created Time: Tue 31 Dec 2019 06:27:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main(void){
	int* num = new int[10];
	for(int i=0; i<10; i++)
		num[i] = i;                                              
	for(int i=0; i<10; i++)
		cout<<num[i];
	delete[] num;
}

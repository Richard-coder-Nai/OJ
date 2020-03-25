#include<iostream>
#include<cstdio>
#include<unordered_set>

using namespace std;

int q, n, x;
int main(void){
	cin>>q;
	while(q--){
		cin>>n;
		unordered_set<int> table;
		while(n--){
			scanf("%d", &x);
			if(table.count(x)==false){
				printf("%d ", x);
				table.insert(x);
			}
		}
		printf("\n");
	}
}

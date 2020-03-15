#include<iostream>
#include<algorithm>
using namespace std;

int w, n;
int cost[30005];

int main(void){
	cin>>w>>n;
	for(int i=0; i<n; i++) cin>>cost[i];
	sort(cost, cost+n);

	int res = 0;
	int i = 0, j = n-1;
	while(i<=j){
		if(cost[i]+cost[j]<=w){
			i++;
			j--;
		}else{
			j--;
		}
		res++;
	}
	cout<<res<<endl;
}

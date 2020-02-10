#include<iostream>
#include<vector>
using namespace std;

int main(void){
	int a, b;
	vector<int> counter(10, 0);
	while(cin>>a>>b){
		if(a==0&&b==0) break;
		if(a>b) swap(a, b);
		counter = vector<int>(10, 0);
		for(int i=a; i<=b; i++){
			int n = i;
			while(n){
				counter[n%10]++;
				n /= 10;
			}
		}
		for(auto it:counter){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}

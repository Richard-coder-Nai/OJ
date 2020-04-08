#include<iostream>
#include<string>

using namespace std;

int main(void){
	int a, b;
	cin>>a>>b;
	int res = a+b;
	if(res<0){
		res = -res;
		cout<<'-';
	}
	string str = to_string(res);

	for(int i=0, n=str.size(); i<n; i++){
		if((n-i)%3==0 && i!=0){
			cout<<",";
		}
		cout<<str[i];
	}
	cout<<endl;
}


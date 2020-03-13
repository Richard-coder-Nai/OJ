#include<iostream>
#include<string>

using namespace std;

int l1,r1,l2,r2;

int main(void){
	int n, m;
	cin>>n>>m;
	
	string str;
	cin>>str;

	for(int i=0; i<m; i++){
		cin>>l1>>r1>>l2>>r2;
		l1--;
		l2--;
		string s1(str.begin()+l1, str.begin()+r1);
		string s2(str.begin()+l2, str.begin()+r2);
		if(s1==s2){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}

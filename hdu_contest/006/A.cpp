#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string a, b;

int main(void){
	while(cin>>a>>b){
		string str_a = "";
		string str_b = "";
		for(auto c:a)
			if(c!=',') str_a += c;
		for(auto c:b)
			if(c!=',') str_b += c;
		int numA = atoi(str_a.c_str());
		int numB = atoi(str_b.c_str());
		cout<<numA+numB<<endl;
	}
}

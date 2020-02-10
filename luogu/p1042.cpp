#include<iostream>
#include<string>

using namespace std;

int main(void){
	char c;
	string all="";

	while(cin>>c){
		if(c=='E') break;
		all+=c;
	}
	int counter = 0;
	for(int i=0; i<all.size(); i++){
		if(all[i]=='W') counter++;

		if(i!=0 && (i+1)%11==0){
			cout<<counter<<":"<<11-counter<<endl;
			counter = 0;
		}
		if(i==all.size()-1)
			cout<<counter<<":"<<all.size()%11-counter<<endl;
	}

	cout<<endl;

	counter = 0;
	for(int i=0; i<all.size(); i++){
		if(all[i]=='W') counter++;

		if(i!=0 && (i+1)%21==0){
			cout<<counter<<":"<<21-counter<<endl;
			counter = 0;
		}
		if(i==all.size()-1)
			cout<<counter<<":"<<all.size()%21-counter<<endl;
	}
}

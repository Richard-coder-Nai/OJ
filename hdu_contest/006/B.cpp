#include<iostream>
#include<string>

using namespace std;

string str;
int main(void){
	while(cin>>str){
		if(str=="zoj"){
			cout<<"Accepted"<<endl;
			continue;
		}
		int n = str.size();
		int num_pre = 0;
		int num_mi = 0;
		int num_suff = 0;
		int num_z = 0;
		int num_j = 0;
		int mode = 0;
		bool flag = true;
		for(auto c:str){
			if(c=='o'){
				if(mode==0){
					num_pre++;
				}
				if(mode==1){
					num_mi++;
				}
				if(mode==2){
					num_suff++;
				}
			}
			else if(c=='z'){
				num_z++;
				mode = 1;
			}
			else if(c=='j'){
				num_j++;
				mode = 2;
			}
			else{
				flag = false;
			}
		}
		if(num_z!=1) flag = false;
		if(num_j!=1) flag = false;
		if(num_mi<1) flag ==false;

		if(flag==false) cout<<"Wrong Answer"<<endl;

		else{
			if(num_pre*num_mi == num_suff ){
				cout<<"Accepted"<<endl;
			}
			else{
				cout<<"Wrong Answer"<<endl;
			}
		}
	}
}


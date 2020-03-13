#include<iostream>
#include<string>

using namespace std;

int Next[1000005];

void BuildNext(string P){	
	int m = P.length();	
	int t = Next[0] = -1;	
	int j = 0;	
	while(j < m-1){		
		if(t < 0 || P[j] == P[t]){			
			j++;			
			t++;			
			Next[j] = t;//待优化		
		}else 
			t = Next[t];	
	}
}

int main(void){
	string s1;
	string s2;

	cin>>s1>>s2;

	int pos = 0;
	while(true){
		pos = s1.find(s2, pos);
		if(pos!=s2.npos) cout<<pos<<endl;
		else break;
		pos++;
	}

	BuildNext(s2);
	for(int i=0; i<s2.size(); i++){
		cout<<Next[i]<<" ";
	}

	cout<<endl;
}


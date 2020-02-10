#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool ishw(string nums){
	string tmp = nums;
	reverse(tmp.begin(), tmp.end());
	if(tmp == nums) return true;
	return false;
}

int hex2ten(char c){
	if(c>='0'&&c<='9') return int(c-'0');
	else{
		if(c=='A'||c=='a') return 10;
		if(c=='B'||c=='b') return 11;
		if(c=='C'||c=='c') return 12;
		if(c=='D'||c=='d') return 13;
		if(c=='E'||c=='e') return 14;
		if(c=='F'||c=='F') return 15;
	}
}


string add(int N, string n1, string n2){
	string res = "";
	int n = n1.size();
	int carry = 0;
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	if(N==16){
		for(int i=0; i<n; i++){
			int c = hex2ten(n1[i]) + hex2ten(n2[i]) + carry;
			carry = 0;
			if(c>N){
				carry = 1;
				c = c%N;
			}
			if(c>=0&&c<=9)
				res+=char(c+'0');
			else{
				if(c==10) res+="A";
				if(c==11) res+="B";
				if(c==12) res+="C";
				if(c==13) res+="D";
				if(c==14) res+="E";
				if(c==15) res+="F";
			}
		}
	}

	else{
		for(int i=0; i<n; i++){
			int c = n1[i]+n2[i]-'0'-'0'+carry;
			carry = 0;
			if(c>N){
				carry = 1;
				c = c%N;
			}
			res+=char(c+'0');
		}
	}
	if(carry==1) res += "1";
	reverse(res.begin(), res.end());
	return res;
}

int main(void){
	int n;
	string nums;
	cin>>n>>nums;
		
	int counter = 0;
	while(true){
		if(counter>30){
			cout<<"Impossible!";
			break;
		}
		if(ishw(nums)==true) {
			cout<<"STEP="<<counter;
			break;
		}

		string nums2 = nums;
		reverse(nums.begin(), nums.end());
		nums =  add(n, nums, nums2);
		counter++;
	}
}


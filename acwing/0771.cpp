#include <iostream>

using namespace std;

void solver(string str) {
	char cur = str[0];
	char res = str[0];
	int cnt = 1;
	int max_len = 1;
	int len = str.size();
	for(int i=1; i<len; i++) {
		if(cur==str[i]){
			cnt++;
		}else{
			cur = str[i];
			cnt = 1;
		}
		if(max_len<cnt) {
			max_len = cnt;
			res = str[i];
		}
	}
	cout<<res<<" "<<max_len<<endl;
}

int main(void) {
	int n;
	cin>>n;
	while(n--) {
		string str;
		cin>>str;
		solver(str);
	}
}

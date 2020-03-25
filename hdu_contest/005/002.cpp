#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int t;
string str;

bool rev_str(string str){
	if(str.size()<=1) return true;

	string tmp = str;
	reverse(tmp.begin(), tmp.end());
	if(tmp==str){
		return true;
	}
	return false;
}

int longestPalindrome(string s) {
	int len=s.size();
	if(len==0||len==1)
		return s.size();
	int start=0;//回文串起始位置
	int res=1;//回文串最大长度
	vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
	for(int i=0;i<len;i++)//初始化状态
	{
		dp[i][i]=1;
		if(i<len-1&&s[i]==s[i+1])
		{
			dp[i][i+1]=1;
			res=2;
			start=i;
		}
	}
	for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
	{
		for(int i=0;i+l-1<len;i++)
		{
			int j=l+i-1;//终止字符位置
			if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
			{
				dp[i][j]=1;
				start=i;
				res=l;
			}
		}
	}
	res = 1;
	for(int i=0; i<len; i++){
		if(dp[0][i])
			res = max(res, i+1);
	}
	for(int i=0; i<len; i++){
		if(dp[i][len-1])
			res = max(res, len-i);
	}
	return res;
}

int main(void){
	cin>>t;
	while(t--){
		cin>>str;
		string tmp = str;
		reverse(tmp.begin(), tmp.end());
		if(tmp==str){
			cout<<str.size()<<endl;
			continue;
		}
		int i = 0;
		int j = str.size()-1;
		while(i<j){
			if(str[i]==str[j]){
				i++;
				j--;
			}else{
				break;
			}
		}
		int res = 0;
		res = 2*i;

		string sub = str.substr(i, j-i+1);
		int size = longestPalindrome(sub);

		/*
		char c = sub[sub.size()-1];
		int pos = 0;
		while(true){
			pos = sub.find(c, pos);
			string tmp(sub.begin()+pos, sub.end());
			if(rev_str(tmp)){
				size =  max(int(tmp.size()), size);
				break;
			}
		}
		reverse(sub.begin(), sub.end());

		c = sub[sub.size()-1];
		pos = 0;
		while(true){
			pos = sub.find(c, pos);
			string tmp(sub.begin()+pos, sub.end());
			if(rev_str(tmp)){
				size =  max(int(tmp.size()), size);
				break;
			}
		}
		*/

		res += size;
		cout<<res<<endl;
	}
}

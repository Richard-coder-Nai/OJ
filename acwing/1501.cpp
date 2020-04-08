#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

long n, k;

vector<int> add(vector<int> num){
	int n = num.size();

	vector<int> re = num;
	vector<int> res;
	reverse(re.begin(), re.end());

	int carry = 0;
	for(int i=0; i<n; i++){
		int tmp = carry+num[i]+re[i];
		carry = 0;
		if(tmp>=10){
			carry = 1;
			tmp = tmp%10;
		}
		res.push_back(tmp);
	}
	if(carry) res.push_back(1);
	reverse(res.begin(), res.end());
	return res;
}


bool judge(vector<int> nums){
	auto re = nums;
	reverse(re.begin(), re.end());
	if(nums==re) return true;
	else return false;
}

int main(void){
	cin>>n>>k;
	if(n<=9){
		cout<<n<<endl;
		cout<<0<<endl;
		return 0;
	}

	vector<int> num;

	while(n){
		num.push_back(n%10);
		n = n/10;
	}
	reverse(num.begin(), num.end());

	vector<int> res;
	for(int i=1; i<=k; i++){
		res = add(num);
		if(judge(res)){
			for(auto it:res) cout<<it;
			cout<<endl;
			cout<<i<<endl;
			return 0;
		}
		num = res;
	}

	for(auto it:res) cout<<it;
	cout<<endl;
	cout<<k<<endl;
}


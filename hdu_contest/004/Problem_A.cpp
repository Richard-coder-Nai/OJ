#include<iostream>

using namespace std;

int n;

struct NODE{
	int sum;
	int start, end;
};

NODE node[10005];

void solve(){
	node[0].sum = node[0].end;
	node[0].start = node[0].end;
	NODE res = node[0];

	for(int i=1; i<n; i++){
		if(node[i].end + node[i-1].sum>node[i].end){
			node[i].sum = node[i].end + node[i-1].sum;
			node[i].start = node[i-1].start;
		}else{
			node[i].sum = node[i].end;
			node[i].start = node[i].end;
		}
		if(node[i].sum>res.sum){
			res = node[i];
		}
	}
	cout<<res.sum<<" "<<res.start<<" "<<res.end<<endl;
}

int main(void){
	while(true){
		cin>>n;
		for(int i=0; i<n; i++){
			scanf("%d", &node[i].end);
		}
		solve();
	}
}

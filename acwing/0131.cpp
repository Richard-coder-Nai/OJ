#include<iostream>
#include<vector>

using namespace std;

int hight[2000] = {0};

int main(void){
	int n;
	while(cin>>n){
		if(n==0) break;

		for(int i=0; i<n; i++){
			cin>>hight[i];
		}

		int S_max = 0;

		for(int i=0; i<n; i++){
			int h = hight[i];
			int l = i-1;
			int r = i+1;

			while(l>=0 && hight[l]>=h) l--;
			while(r<n && hight[r]>=h) r++;
			l++;
			if(h*(r-l)>S_max) S_max = h*(r-l);
		}
		cout<<S_max<<endl;
	}
}


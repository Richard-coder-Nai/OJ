#include<iostream>
#include<string>

using namespace std;

string wind;
int n, sx, sy, ex, ey;

int main(void){
	cin>>n>>sx>>sy>>ex>>ey;
	cin>>wind;
	int res = 0;
	if(sx==ex && sy==ey){
		cout<<0<<endl;
		return 0;
	}

	for(int i=0; i<n; i++){
		if(wind[i]=='E'){
			sx++;
		}
		if(wind[i]=='S'){
			sy--;
		}
		if(wind[i]=='W'){
			sx--;
		}
		if(wind[i]=='N'){
			sy++;
		}
		if(sx==ex && sy==ey){
			cout<<res<<endl;
			break;
		}
		res++;
	}
}

#include<cstdio>

using namespace std;

int n, m, k;
int input;
int main(void){
	scanf("%d %d", &n, &m);

	int k = 0;
	int ans = 1;
	for(int i=0; i<n; i++){
		scanf("%d", &input);
		if(input+k>m){
			k = input;
			ans++;
		}else{
			k += input;
		}
	}
	printf("%d\n", ans);
}

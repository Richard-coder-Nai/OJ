#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int inf = 1e9;
const int N = 110;
int w[N][N];
int f[N][N];
int n;

int main(){

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &w[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j == 1) f[i][j] = w[i][j];
            else{
                f[i][j] = inf;
                if(i > 1) f[i][j] = min(f[i][j], f[i - 1][j]) + w[i][j];
                if(j > 1) f[i][j] = min(f[i][j], f[i][j - 1]) + w[i][j];
            }
        }
    }
    printf("%d", f[n][n]);
    return 0;
}

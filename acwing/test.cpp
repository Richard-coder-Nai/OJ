#include <cstdio>
#include <iostream>

using namespace std;

const int N = 16;

int g[N][N];

int main()
{
    int n;
    scanf("%d", &n);

    int dx[4] = {1, 0, 1, -1};
    int dy[4] = {0, 1, 1, 1};

    int state = 0, step;
    for (int i = 1; i <= n; i ++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (i % 2) g[x][y] = 1;
        else g[x][y] = 2;

        bool success = false;
        for (int j = 0; j < 4; j ++ )
        {
            int l = 0, r = 0;
            while (true)
            {
                int a = x - dx[j] * (l + 1), b = y - dy[j] * (l + 1);
                if (a < 1 || a > 15 || b < 1 || b > 15) break;  // 出界
                if (g[a][b] != g[x][y]) break;  // 没有相同棋子了
                l ++ ;
            }

            while (true)
            {
                int a = x + dx[j] * (r + 1), b = y + dy[j] * (r + 1);
                if (a < 1 || a > 15 || b < 1 || b > 15) break;  // 出界
                if (g[a][b] != g[x][y]) break;  // 没有相同棋子了
                r ++ ;
            }

            if (l + r + 1 >= 5)
            {
                success = true;
                break;
            }
        }

        if (success)
        {
            if (i % 2) state = 1;
            else state = 2;
            step = i;
            break;
        }
    }

	for(int i=1; i<=15; i++){
		for(int j=1; j<=15; j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}

    if (state == 0) puts("Tie");
    else if (state == 1) printf("A %d\n", step);
    else printf("B %d\n", step);

    return 0;
}

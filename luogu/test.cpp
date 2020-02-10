#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
unsigned long long n=0,k,len,nex;
string nn;
bool wow(unsigned long long a)
{
    unsigned long long s=0;
    for (unsigned long long i=a;i;i/=k)
        s=s*k+i%k;//最为关键的这个循环
    nex=s+a;
    return s==a;
}
unsigned long long ch(char a)
{
    if (a>='0' && a<='9') return a-'0';
    return a-'A'+10;
}
int main()
{
    cin>>k>>nn;len=nn.size();
    for (int i=0;i<len;i++)
        n=n*k+ch(nn[i]);
    unsigned long long step;
    for (step=0;!wow(n) && step<=30;step++)
        n=nex;
    if (step<=30) cout<<"STEP="<<step<<endl;
    else cout<<"Impossible!";
    return 0;
}

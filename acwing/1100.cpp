#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int n, k;

struct Node{
	int x, step;
};

bool used[200005] = {false};


int main(void){
	cin>>n>>k;
	Node node = {n, 0};
	queue<Node> q;
	q.push(node);
	used[n] = true;
	while(true){
		Node front = q.front();
		q.pop();
		int step = front.step;
		int x = front.x;
		if(x==k){
			cout<<step<<endl;
			break;
		}
		else{
			if(x-1>=0 && used[x-1]==false){
				q.push({x-1, step+1});
				used[x-1] = true;
			}
			if(x+1<200005 && used[x+1]==false){
				q.push({x+1, step+1});
				used[x+1] = true;
			}
			if(x*2<=200005 && used[x*2]==false){
				q.push({2*x, step+1});
				used[x*2] = true;
			}
		}
	}
}

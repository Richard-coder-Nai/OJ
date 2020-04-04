#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;


string state;
unordered_map<string, int> dist;

void A(){
}

void B(){
}

void C(){
}

int main(void){
	state = "";
	for(int i=0; i<8; i++){
		char c;
		cin>>c;
		state += c;
	}

	queue<string> q;
	q.push("12345678");
	
	int deep = 0;
	while(q.size()){
		int size = q.size();
		for(int i=0; i<size; i++){
			auto front = q.front();
			q.pop();
			string A = moveA(front);
			string B = moveA(front);
			string C = moveC(front);
			if()
		}
		deep++;
	}
}

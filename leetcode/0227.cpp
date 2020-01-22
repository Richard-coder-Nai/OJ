#include<iostream>
#include<string>
#include<stack>

using namespace std;


char opt_campare(char opt1, char opt2){
	char table[9][9] = {   
		//top//  +   -   *   /   ^   !   (   )   #    // current
		/* + */ '>','>','<','<','<','<','<','>','>',
		/* - */ '>','>','<','<','<','<','<','>','>',
		/* * */ '>','>','>','>','<','<','<','>','>',
		/* / */ '>','>','>','>','<','<','<','>','>',
		/* ^ */ '>','>','>','>','>','<','<','>','>',
		/* ! */ '>','>','>','>','>','>',' ','>','>',
		/* ( */ '<','<','<','<','<','<','<','=',' ',
		/* ) */ ' ',' ',' ',' ',' ',' ',' ',' ',' ',
		/* # */ '<','<','<','<','<','<','<',' ','='
	};
	
}
int compute(int num2, int num1, char opt){
	if(opt=='+') return num2+num1;
	if(opt=='-') return num2-num1;
	if(opt=='*') return num2*num1;
	if(opt=='/') return num2/num1;
	return num2+num1;
}

int calculate(string s){
}


int main(void){
	string s="1+1+1";
	cout<<calculate(s)<<endl;
}

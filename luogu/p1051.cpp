#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(void){
	int n;
	cin>>n;

	map<string, int> table;
	//name, 期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。

	for(int i=0; i<n; i++){
		string name;
		int exam_grade;
		int class_grade;
		char is_maj;
		char is_west;
		int paper_num;
		cin>>name>>exam_grade>>class_grade>>is_maj>>is_west>>paper_num;
		table[name] = 0;
		if(exam_grade>80 && paper_num>=1)
			table[name]+=8000;
		if(exam_grade>85 && class_grade>80)
			table[name]+=4000;
		if(exam_grade>90)
			table[name]+=2000;
		if(is_west=='Y' && exam_grade>85)
			table[name]+=1000;
		if(class_grade>80 && is_maj=='Y')
			table[name]+=850;
	}
	int sum = 0;
	int m=0;
	string max_name;
	for(auto it:table){
		if(m<it.second){
			max_name = it.first;
			m = it.second; 
		}
		sum+=it.second;
	}
	cout<<max_name<<endl;
	cout<<m<<endl;
	cout<<sum<<endl;
}

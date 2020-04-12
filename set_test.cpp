#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	vector<int> n1 = {1, 2, 3};
	vector<int> n2 = {2, 3, 4};

	// intersection
	cout<<"intersection test"<<endl;
	vector<int> intersection(min(n1.size(), n2.size()));

	auto end = set_intersection(n1.begin(), n1.end(), n2.begin(), n2.end(), intersection.begin());
	intersection.erase(end, intersection.end());

	for(int it:intersection) {
		cout<<it<<" ";
	}
	cout<<endl;

	// Union
	cout<<"Union test"<<endl;
	vector<int> Union(min(n1.size(), n2.size()));

	end = set_union(n1.begin(), n1.end(), n2.begin(), n2.end(), Union.begin());
	Union.erase(end, Union.end());

	for(int it:Union) {
		cout<<it<<" ";
	}
	cout<<endl;

	// difference test
	cout<<"difference test"<<endl;
	vector<int> difference(n1.size(), n2.size());
	end = set_difference(n1.begin(), n1.end(), n2.begin(), n2.end(), difference.begin());
	difference.erase(end, difference.end());

	for(int it:difference) {
		cout<<it<<" ";
	}
	cout<<endl;
}

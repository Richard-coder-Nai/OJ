#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> table;
	table.insert(1);
	cout<<*table.begin()<<endl;
}

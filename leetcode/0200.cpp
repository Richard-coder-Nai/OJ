#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<vector<char>> grid;
vector<vector<pair<int, int>>> father;


pair<int, int> find_father(pair<int, int> node){
	while(node != father[node.first][node.second]){
		node = father[node.first][node.second];
	}
	return node;
}


void Union_node(pair<int, int> node1, pair<int, int> node2){
	auto f1 = find_father(node1);
	auto f2 = find_father(node2);
	if(f1 != f2){
		father[f1.first][f1.second] = f2;
	}
}

void init(vector<vector<char>> grid){
	for(int i=0; i<grid.size(); i++){
		vector<pair<int, int>> tmp;
		for(int j=0;  j<grid[0].size(); j++){
			tmp.push_back(make_pair(i, j));
		}
		father.push_back(tmp);
	}
}


int main(void){
	for(int i=0; i<4; i++){
		vector<char> tmp;
		for(int j=0;  j<5; j++){
			char c;
			cin>>c;
			tmp.push_back(c);
		}
		grid.push_back(tmp);
	}

	init(grid);

	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid[i].size(); j++){
			if(i+1<grid.size()){
				if(grid[i][j]=='1' && grid[i+1][j]=='1'){
					Union_node(make_pair(i, j), make_pair(i+1, j));
				}
			}

			if(j+1<grid[i].size()){
				if(grid[i][j]=='1' && grid[i][j+1]=='1'){
					Union_node(make_pair(i, j), make_pair(i, j+1));
				}
			}
		}
	}
	set<pair<int, int>> table;
	for(int i=0; i<grid.size(); i++){
		for(int j=0; j<grid[i].size(); j++){
			if(grid[i][j]=='1'){
				table.insert(find_father(make_pair(i, j)));
			}
		}	
	}

	cout<<table.size()<<endl;

//	auto test1 = find_father(make_pair(3, 4));
//	auto test2 = find_father(make_pair(0, 0));
//	auto test3 = find_father(make_pair(1, 1));
//
//	Union_node(test1, test2);
//	Union_node(test2, test3);
//
//	test1 = find_father(make_pair(3, 4));
//	test2 = find_father(make_pair(0, 0));
//	test3 = find_father(make_pair(1, 1));
//
//	cout<<test1.first<<" "<<test1.second<<endl;
//	cout<<test2.first<<" "<<test2.second<<endl;
//	cout<<test3.first<<" "<<test3.second<<endl;

}

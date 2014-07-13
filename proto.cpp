#include <iostream>
#include <vector>
using namespace std;

int minimal_weight(vector<vector<int>>& vec){
	vector<int> pre_row(vec.front());
	for(int i=1;i<vec.size();i++){
		vector<int> cur_row(vec[i]);
		cur_row.front()+=pre_row.front();
		for(int j=1;j<cur_row.size()-1;j++){
			cur_row[j]+=min(pre_row[j-1],pre_row[j]);
		}
		cur_row.back()+=pre_row.back();
		pre_row.swap(cur_row);
	}
	return *min_element(pre_row.begin(),pre_row.end());
}

int main(){
	vector<vector<int>> input = {{1},
								{2,1},
								{5,3,1},
								{3,7,1,4}};
	cout<<minimal_weight(input);
}
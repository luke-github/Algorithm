#include <iostream>
#include <set>
#include <unordered_map>
#include <numeric>
#include <fstream>
using namespace std;

int find_sum_result(multiset<int>& vec){
	auto it = vec.cbegin();
	advance(it,3);
	return accumulate(vec.cbegin(),it,0);
}

string top_score(ifstream* ifs){
	unordered_map<string,multiset<int>> students_scores;
	int score;
	string name;
	while(*ifs>>name>>score){
		students_scores[name].emplace(score);
	}
	int max_score = 1<<31;
	string top_stu("there's no such student.");
	for(auto it : students_scores){
		if(it.second.size()>=3){
			int current_sum = find_sum_result(it.second);
			if(current_sum>max_score){
				max_score=current_sum;
				top_stu = it.first;
			}
		}
	}
	return top_stu;
}

int main(){
	ifstream in("15_17_input");
	string result = top_score(&in);
	cout<<result;
}
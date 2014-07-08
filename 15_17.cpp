#include <iostream>
#include <set>
#include <numeric>
#include <map>
#include <fstream>
#include <unordered_map>
using namespace std;

int get_top3_result(multiset<int>& vec){
	auto p = vec.begin();
	advance(p,3);
	return accumulate(vec.cbegin(),p,0);
}

string top_average_score(ifstream* ifs){
	unordered_map<string,multiset<int>> student_score;
	string name;
	int score;
	while(*ifs>>name>>score){
		student_score[name].emplace(score);
	}
	string top_student("there is no such student.");
	int max_average = 0;
	for(auto it : student_score){
		if(it.second.size()>=3){
			int current_sum = get_top3_result(it.second);
			if(current_sum>max_average){
				max_average=current_sum;
				top_student = it.first;
			}
		}
	}
	return top_student;
}

int main(){
	ifstream in("15_17_input");
	string result = top_average_score(&in);
	cout<<result;
}
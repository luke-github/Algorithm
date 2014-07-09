#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_palidrome(string& s){
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])
			return false;
	}
	return true;
}

void palidrome_partition_handler(string& s, int start, vector<string>* ans, vector<vector<string>>* result){
	if(start==s.size()){
		result->emplace_back(*ans);
	}
	for(int i=start+1;i<=s.size();i++){
		string cur = s.substr(start,i-start);
		if(is_palidrome(cur)){
			ans->push_back(cur);
			palidrome_partition_handler(s,i,ans,result);
			ans->pop_back();
		}
	}
}

vector<vector<string>> palidrome_partition(string& s){
	vector<vector<string>> result;
	vector<string> ans;
	palidrome_partition_handler(s,0,&ans,&result);
	return result;
}

int main(){
	string input ="abacbcde";
	auto res = palidrome_partition(input);
	for(auto x:res){
		for(auto y : x){
			cout<<y<<",";
		}
		cout<<endl;
	}
}
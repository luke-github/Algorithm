#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool check_match(const string& s, unordered_map<string,int>& dict, int start, int unit_size, int words_size);
vector<int> find_substrings(const string& s, const vector<string>& vec){
	unordered_map<string,int> hash;
	for(const string x : vec){
		hash[x]++;
	}
	int unit_size = vec.front().size();
	vector<int> res;
	for(int i=0;i+unit_size*vec.size()<=s.size();i++){
		if(check_match(s,hash,i,unit_size,vec.size())){
			res.emplace_back(i);
		}
	}
	return res;
}

bool check_match(const string& s, unordered_map<string,int>& dict, int start, int unit_size, int words_size){
	unordered_map<string,int> cur_dict;
	for(int i=0;i<words_size;i++){
		string cur_word = s.substr(start+i*unit_size,unit_size);
		auto it = dict.find(cur_word);
		if(it==dict.end()){
			return false;
		}
		++cur_dict[cur_word];
		if(cur_dict[cur_word]>it->second)
			return false;
	}
	return true;
}

int main(){
	string input1 = "abcdabcdabcdabcdabcd";
	vector<string> input2 = {"a","b","c"};
	vector<int> res = find_substrings(input1,input2);
	for(int x : res)
		cout<<x<<" ";
}
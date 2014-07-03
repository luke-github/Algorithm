#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool check_match(const string& s,unordered_map<string,int>& dict,int start,int unit_size,int words_size);

vector<int> find_substrings(const string& s,const vector<string>& words){
	unordered_map<string,int> dict;
	for(string word: words){
		dict[word]++;
	}
	vector<int> res;
	size_t unit_size = words.front().size();
	for(int i=0;i+unit_size*words.size()<s.size();i++){
		if(check_match(s,dict,i,unit_size,words.size())){
			res.emplace_back(i);
		}
	}
	return res;
}

bool check_match(const string& s,unordered_map<string,int>& dict,int start,int unit_size,int words_size){
	unordered_map<string,int> cur_dict;
	for(int i=0;i<words_size;i++){
		string cur_word = s.substr(start+i*unit_size,unit_size);
		auto it = dict.find(cur_word);
		if(it==dict.end()){
			return false;
		}
		cur_dict[cur_word]++;
		if(cur_dict[cur_word]>dict[cur_word]){
			return false;
		}
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

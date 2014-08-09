#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string add_element(vector<string>& words, int start, int end, int num_blanks){
	int num_words = end -  start +1;
	string line;
	for(int i=start;i<end;i++){
		line+=words[i];
		num_words--;
		int cur_blank = ceil(num_blanks/num_words);
		line.append(cur_blank,' ');
		num_blanks -= cur_blank;
	}
	line += words[end];
	line.append(num_blanks,' ');
	return line;
}

vector<string> adjust_text(vector<string>& words, int L){
	int last_index = 0, num_words = 0, len = 0;
	vector<string> res;
	for(int i=0;i<words.size();i++){
		num_words++;
		int line_len = len + words[i].size() + num_words -1;
		if(line_len==L){
			res.emplace_back(add_element(words,last_index,i,i - last_index));
			last_index = i+1;
			len = 0;
			num_words = 0;
		}else if(line_len>L){
			res.emplace_back(add_element(words,last_index,i-1,L-len));
			last_index = i;
			len = words[i].size();
			num_words = 1;
		}else{
			len += words[i].size();
		}
	}
	if(num_words){
		string line = add_element(words,last_index,words.size()-1,num_words-1);
		line.append(L-len-(num_words-1),' ');
		res.emplace_back(line);
	}
	return res;
}

int main(){
	vector<string> input = {"aaa","b","cc","dd","eeee","ff","g"};
	auto res = adjust_text(input,5);
	for(auto x : res){
		cout<<x<<endl;
	}
}
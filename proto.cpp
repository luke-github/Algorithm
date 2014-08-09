#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string add_element(const vector<string>& vec, int start, int end, int num_spaces){
	string line;
	int num_words = end -  start +1;
	for(int i=start;i<end;i++){
		line+=vec[i];
		num_words--;
		int cur_space = ceil(num_spaces/num_words);
		line.append(cur_space,' ');
		num_spaces -= cur_space;
	}
	line += vec[end];
	line.append(num_spaces,' ');
	return line;
}

vector<string> ajust_text(const vector<string>& vec, int L){
	int len = 0, num_words = 0, last_index = 0;
	vector<string> res;
	for(int i=0;i<vec.size();i++){
		num_words++;
		int line_len = len + vec[i].size() + num_words -1;
		if(line_len==L){
			res.emplace_back(add_element(vec,last_index,i,i - last_index));
			len = 0;
			last_index = i+1;
			num_words = 0;
		}else if(line_len>L){
			res.emplace_back(add_element(vec,last_index,i-1,L-len));
			len = vec[i].size();
			num_words=1;
			last_index = i;
		}else{
			len += vec[i].size();
		}
	}
	if(num_words){
		string line = add_element(vec,last_index,vec.size()-1,num_words-1);
		line.append(L-len-(num_words-1),' ');
		res.emplace_back(line);
	}
	return res;
}

int main(){
	
}
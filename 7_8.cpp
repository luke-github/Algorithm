#include <iostream>
#include <vector>
using namespace std;

bool is_valid(const string& s){
	if((s[0]=='0'&&s.size()>1)||s.size()>3)
		return false;
	int val = stoi(s);
	return val>=0 && val<255;
}

vector<string> generate_correct_ip(const string& s){
	vector<string> result;
	for(size_t i=1;i<4&&i<s.size();i++){
		string first = s.substr(0,i);
		if(is_valid(first)){
			for(size_t j=1;j<4&&i+j<s.size();j++){
				string second = s.substr(i,j);
				if(is_valid(second)){
					for(size_t k=1;k<4&&i+j+k<s.size();k++){
						string third = s.substr(i+j,k);
						string fourth = s.substr(i+j+k);
						if(is_valid(third)&&is_valid(fourth))
							result.push_back(first+"."+second+"."+third+"."+fourth);
					}
				}
			}
		}
	}
	return result;
}

int main(){
	vector<string> res = generate_correct_ip("192168111");
	for(string x : res){
		cout<<x<<endl;
	}
}
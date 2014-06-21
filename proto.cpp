#include <iostream>
#include <fstream>
using namespace std;

string tail(const string& file_name, int tail_num){
	string result;
	fstream file_ptr(file_name.c_str());
	int lines = 0;
	file_ptr.seekg(0,ios::end);
	int file_size = file_ptr.tellg();
	for(int i=0;i<file_size;i++){
		file_ptr.seekg(-1-i,ios::end);
		char c;
		file_ptr.get(c);
		if(c=='\n'){
			lines++;
			if(lines==tail_num)
				break;
		}
		result.push_back(c);
	}
	reverse(result.begin(),result.end());
	return result;
}

int main(){
	string result = tail("input_text",3);
	cout<<result;
}
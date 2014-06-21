#include <iostream>
#include <vector>
using namespace std;

string trans_dec_to_bin(int num);
int trans_bin_to_dec(const string& binary);

string encode(const vector<int>& vec){
	string result;
	for(int x:vec){
		string binary = trans_dec_to_bin(x);
		binary.insert(0,binary.size()-1,'0');
		result += binary;
	}
	
	return result;
}

string trans_dec_to_bin(int num){
	string result;
	while(num){
		result.push_back('0'+(num&1));
		num >>=1;
	}
	reverse(result.begin(),result.end());
	return result;
}

vector<int> decode(const string& s){
	vector<int> result;
	int index=0;
	int zero_index=0;
	while(index<s.size()){
		while(zero_index<s.size()&&s[zero_index]=='0')
			zero_index++;
		int len=zero_index - index +1;
		result.push_back(trans_bin_to_dec(s.substr(zero_index,len)));
		index = zero_index+len;
		zero_index=index;
	}
	return result;
}

int trans_bin_to_dec(const string& binary){
	int result = 0;
	for(char c : binary){
		result = (result<<1)+c-'0';
	}
	return result;

}


int main(){
	vector<int> input = {1,2,3,4,5};
	cout<<input[0]<<"####"<<input[1]<<"######"<<endl;
	string res = encode(input);
	cout<<res<<endl;
	vector<int> re_array = decode(res);
	for(int x:re_array)
		cout<<x<<":";
}
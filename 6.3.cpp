#include<iostream>
#include<vector>
using namespace std;

class BigInt{
public:
	BigInt(int capacity): digits_(capacity),sign_(1){};
	BigInt(const string &s) : sign_(s[0]=='-'?-1:1),digits_(s.size()-(s[0]=='-')){
		for(int i=s.size()-1,j=0;i>=(s[0]=='-');i--,j++){
			if(isdigit(s[i])){
				digits_[j]=s[i]-'0';
			}
		}
	}
	BigInt operator*(const BigInt& n){
		BigInt result(digits_.size()+n.digits_.size());
		result.sign_ = sign_*n.sign_;
		int i,j;
		for(int i=0;i<n.digits_.size();i++){
			int carry = 0;
			for(int j=0;j<digits_.size()||carry;j++){
				int n_digit = result.digits_[i+j]+(j<digits_.size()?n.digits_[i]*digits_[j]:0)+carry;
				result.digits_[i+j]=n_digit%10;
				carry=n_digit/10;
			}
		}
		if((digits_.size()==1&&digits_.front()==0) || (n.digits_.size()==1&&n.digits_.front()==0)){
			result.sign_=1;
			result.digits_.resize(1);
		}else{
			result.digits_.resize(i+j-1);
		}
		return result;
	}
private:
	vector<char> digits_;
	int sign_;
};

int main(){

}
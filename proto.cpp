// #include<iostream>
// #include<vector>
// using namespace std;

// class BigInt{
// public:
// 	BigInt(int capacity) : sign_(1),digits_(capacity) {}
// 	BigInt(const string &s) : sign_(s[0]=='-'?-1:1),digits_(s.size()-(s[0]=='-')){
// 		for(int i=s.size()-1,j=0;i>(s[0]=='-');i--,j++){
// 			digits_[j]=s[i]-'0';
// 		}
// 	}
// 	BigInt operator*(const BigInt &n){
// 		BigInt result(digits_.size()+n.digits_.size());
// 		int i,j;
// 		for(i=0;i<n.digits_.size();i++){
// 			int carry = 0;
// 			for(j=0;j<n.digits_.size()||carry;j++){
// 				int n_digits=result.digits_[i+j]+(j<digits_.size()?digits_[j]*n.digits_[i]:0)+carry;
// 				result.digits_[i+j]=n_digits%10;
// 				carry=n_digits/10;
// 			}
// 		}
// 		if((digits_.size()==1&&digits_.front()==0)||(n.digits_.size()==1&&n.digits_.front()==0)){
// 			result.sign_=1;
// 			result.digits_.resize(1);
// 		}else{
// 			result.digits_.resize(i+j-1);
// 		}
// 		return result;
// 	}

// private:
// 	int sign_;
// 	vector<char> digits_;
// };

// void removeElement(vector<int> &vec, int k){
// 	int m=0;
// 	for(int i=0;i<vec.size();i++){
// 		if(vec[i]!=k){
// 			vec[m++]=vec[i];
// 		}
// 	}
// 	vec[m]=0;
// }



// int main(){

// }

#include<iostream>
#include<vector>
using namespace std;

int removeDuplicated(vector<int> &vec){
	int i=0;
	for(int j=1;j<vec.size();j++){
		if(vec[i]!=vec[j]){
			vec[++i]=vec[j];
		}
	}
	return i+1;
}
int main(){
	cout<<"hello";
}












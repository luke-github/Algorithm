#include <iostream>
#include <vector>
using namespace std;

struct Player{
	int height;
	bool operator < (const Player& s) const {
		return height < s.height;
	}
};

class Team{
public:
	Team(vector<int>& heights){
		for(int x : heights){
			team_members_.emplace_back(Player{x});
		}
	}
	bool operator < (const Team& that) const{
		vector<Player> team1(sort_member());
		vector<Player> team2(that.sort_member());
		for(int i=0;i<team1.size();i++){
			if(!(team1[i]<team2[i])){
				return false;
			}
		}
		return true;
	}
private:
	vector<Player> sort_member() const{
		vector<Player> sorted_array(team_members_);
		sort(sorted_array.begin(),sorted_array.end());
		return sorted_array;
	}
	vector<Player> team_members_;
};

int main(){
	vector<int> team1 = {1,3,2,4,5,6,8};
	vector<int> team2 = {11,14,13,12,16,19,15};
	Team T1(team1);
	Team T2(team2);
	cout<<(T1<T2);
}
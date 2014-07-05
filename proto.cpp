#include <vector>
#include <iostream>
using namespace std;

struct Player{
	int height;
	bool operator < (const Player& s) const{
		return height < s.height;
	}
};

class Team{
public:
	Team(vector<int>& heights){
		for(int x: heights){
			team_members_.emplace_back(Player{x});
		}
	}
	bool operator < (const Team& another) const{
		std::vector<Player> t1(sort_member_func());
		std::vector<Player> t2(another.sort_member_func());
		for(int i=0;i<t1.size();i++){
			if(!(t1[i]<t2[i])){
				return false;
			}
		}
		return true;
	}
private:
	vector<Player> sort_member_func() const{
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
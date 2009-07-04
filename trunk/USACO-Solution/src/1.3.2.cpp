/*
ID: zinking1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct MilkSupply{
	int price;
	int amount;
	MilkSupply(int p, int m):price(p),amount(m){}
	int getAllCost(){
		return price*amount;
	}
};

bool compare_ms( MilkSupply l, MilkSupply r ){
	return l.price < r.price;
}

vector<MilkSupply> MSVec;

int main() {
    ofstream fout ("milk.out");
    ifstream fin  ("milk.in");
	int total_require = 0, fcount = 0;
	fin >> total_require >> fcount;
	int price = 0, amount = 0;
	for( int i=0; i<fcount ; i++ ){
		fin >> price >> amount;
		MSVec.push_back( MilkSupply( price,amount ) );
	}
	sort( MSVec.begin(), MSVec.end(), compare_ms);

	int cost = 0, current_amount = 0;
	for( int i=0; i<fcount ; i++ ){
		if( current_amount + MSVec[i].amount < total_require ){
			current_amount += MSVec[i].amount;
			cost += MSVec[i].getAllCost();
		}
		else{
			cost += MSVec[i].price * ( total_require - current_amount );
			break;
		}			
	}

	fout << cost << endl;




    return 0;
}

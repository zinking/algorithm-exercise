/*
ID: zinking1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
typedef map<string,int> ACC;
typedef ACC::iterator AITR;

ACC Account;
vector<string> namelist;


int main() {
    ofstream fout("gift1.out");
    ifstream fin ("gift1.in");
	int NP = 0; //friends number
	fin >> NP;
	int i=0;
	string item;
	for( i=0; i < NP ; i++ ){
		fin >> item;
		namelist.push_back( item );
		Account[item] = 0;
	}

	int sum = 0, num = 0, average = 0;
	while( !fin.eof() ){
		fin >> item;
		fin >> sum >> num;
		if( num == 0 ) continue;
		average = static_cast<int>( sum/num );
		Account[item] -= ( average*num );
		for ( i=0; i<num; i++){
			fin >> item;
			Account[item] += average;
		}
	}

	for( i=0; i < NP ; i++ ){
		fout << namelist[i] <<" " << Account[ namelist[i] ] << endl;
	}


    
    return 0;
}

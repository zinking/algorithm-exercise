/*
ID: zinking1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin  ("ride.in");
    string group,comet;
	fin >> group >> comet;
	int groupnumber = 1, cometnubmer = 1, i=0;
	for ( i=0; i < group.length(); i++ ){
		groupnumber*= ( static_cast<int>( group.at(i) ) - 64 );
	}
	for ( i=0; i < comet.length(); i++ ){
		cometnubmer*= ( static_cast<int>( comet.at(i) ) - 64 );
	}

	if( (groupnumber % 47) == (cometnubmer % 47) ){
		fout << "GO" << endl;
	}
	else{
		fout << "STAY" << endl;
	}

    return 0;
}

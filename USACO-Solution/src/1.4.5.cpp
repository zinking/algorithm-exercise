/*
ID: zinking1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAXLINE = 30;


int A=0, B=0, C=0;
bool InstanceMap[MAXLINE][MAXLINE];
bool InstanceC[MAXLINE];

void DFS( int ca, int cb, int cc ){
	if( InstanceMap[ca][cb] ) return;
	if( ca == 0 ) InstanceC[cc] = true;
	InstanceMap[ca][cb] = true;
	int pour_amount = 0;

	if( ca > 0 ){
		pour_amount = min(B-cb,ca);DFS( ca - pour_amount, cb + pour_amount, cc); //A->B
		pour_amount = min(C-cc,ca);DFS( ca - pour_amount, cb , cc + pour_amount); //A->C
	}
	if( cb > 0 ){
		pour_amount = min(A-ca,cb);DFS( ca + pour_amount, cb - pour_amount, cc); //B->A
		pour_amount = min(C-cc,cb);DFS( ca , cb - pour_amount, cc + pour_amount); //B->C
	}
	if( cc > 0 ){
		pour_amount = min(A-ca,cc);DFS( ca + pour_amount, cb , cc - pour_amount); //C->A
		pour_amount = min(B-cb,cc);DFS( ca , cb + pour_amount, cc - pour_amount); //C->B
	}
	
}


int main() {
    ofstream fout ("milk3.out");
    ifstream fin  ("milk3.in");
	fin >> A >> B >> C;
	DFS(0,0,C);

	for( int i=0; i < C; i++ ){
		if( InstanceC[i] ) fout << i << ' ';
	}
	fout << C << endl;


    return 0;
}

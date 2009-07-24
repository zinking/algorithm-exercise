/*
ID: zinking1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

int prime_len = 0;

inline bool isPrime( long int number){
	if( number == 1 ) return false;
	int prime_upper_bound = static_cast<int>( sqrt( (float)number ) );
	for( int i=2; i<=prime_upper_bound; i++ ){
		if( number % i == 0 ) return false;
	}
	return true;
}

inline char* reverse( char* digits ){
	char *p = digits, *q = p+strlen(digits)-1;
	while( p<=q ) swap(*p++ , *q--);
	return digits;
}

ofstream fout ("sprime.out");
ifstream fin  ("sprime.in");

void DFS_SuperPrime( char digits[10], int depth ){
	
	if( depth == prime_len ) {
		long int prime_number = atol( digits );
		if( isPrime( prime_number ) ) fout << prime_number << endl;
		return;
	}

	char current_digits[10];
	memcpy(current_digits,digits,depth );
	current_digits[depth+1] = '\0';
	for( int i=1; i<=9; i++){
		current_digits[depth] = '0'+i;
		long int number = atol( current_digits );
		if( isPrime(number) ) DFS_SuperPrime( current_digits,depth+1 );
		else continue;
	}

}

int main() {

	fin >> prime_len;
	if( prime_len == 1 ){
		fout << "2" << endl;
		fout << "3" << endl;
		fout << "5" << endl;
		fout << "7" << endl;

	}
	else{
		char digits[10];
		DFS_SuperPrime(digits,0);
	}
	

    return 0;
}

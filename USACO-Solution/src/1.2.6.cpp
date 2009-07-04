/*
ID: zinking1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXLEN 40

ofstream fout ("dualpal.out");
ifstream fin  ("dualpal.in");


bool toRadix( int base, int src, int result[MAXLEN], bool testPalindromes = true  ){
	int len = 0;
	do{
		result[len] = src % base;
		len ++;
	}while( src /= base );


	if( testPalindromes ){
		for( int i=0, j= len-1; i < j; i++, j-- ){
			if( result[i] != result[j] ) return false;
		}
		return true;
	}
	return false;
}

bool isDualPalindromes( int src ){
	int result[MAXLEN];
	int palindrome_count = 0;
	for( int base = 2; base <= 10; base ++ ){
		if( toRadix( base, src, result) ) palindrome_count++;
	}
	return palindrome_count > 1 ? true:false;
}


int main() {

	int N , S;
	fin >> N >> S;
	
	int dualPalindrome_number = 0;
	while( dualPalindrome_number < N ){
		S++;
		if ( isDualPalindromes( S ) ){
			dualPalindrome_number++;
			fout << S << endl;
		}
	}

    return 0;
}

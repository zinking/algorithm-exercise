/*
ID: zinking1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXLEN 40

ofstream fout ("palsquare.out");
ifstream fin  ("palsquare.in");


bool toRadix( int base, int src, int result[MAXLEN], bool testPalindromes = true  ){
	int len = 0;
	do{
		result[len] = src % base;
		len ++;
	}while( src /= base );
	result[len] = -1;

	for( int i=0, j= len-1; i < j; i++, j-- ){
		int temp  = result[i];
		result[i] = result[j];
		result[j] = temp;
	}

	if( testPalindromes ){
		for( int i=0, j= len-1; i < j; i++, j-- ){
			if( result[i] != result[j] ) return false;
		}
		return true;
	}
	return false;
}

void output_number( int result[MAXLEN] ){
	

	for( int i=0; result[i] != -1; i++ ){
		if ( result[i] < 10 ) fout << result[i];
		else{
			fout << static_cast<char>( 'A' + result[i] - 10 );
		}		
	}
	
}

int main() {

	int base = 0;
	fin >> base;
	int converted[MAXLEN];
	int converted_src[10];
	for( int N=1; N <= 300; N++ ){
		if( toRadix( base, N*N, converted) ){
			toRadix( base, N, converted_src , false );
			output_number( converted_src );
			fout << " ";
			output_number( converted );
			fout << endl;
		}
	}


    return 0;
}

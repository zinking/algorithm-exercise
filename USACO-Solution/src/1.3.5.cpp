/*
ID: zinking1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> EnumerateInt;
typedef map<char,int> DLookUp;

EnumerateInt vmul1;
EnumerateInt vmul2;


const int MAX_DIGITS = 11;
char valid_digits[MAX_DIGITS];
int  valid_digit_len = 0;

stringstream converter;
DLookUp lookup;


int required_len = 4;
char number[MAX_DIGITS];
void EnumerateDigits( char* digits,  int len , EnumerateInt& vc){
	if( len == required_len ) {
		digits[len] = '\0';
		converter.clear();
		converter << digits;
		int number = 0;
		converter >> number;
		vc.push_back( number );
		return;
	}

	for( int i=0; i < valid_digit_len; i++ ){
		digits[len] = valid_digits[i];
		EnumerateDigits( digits,len+1,vc);
	}

}

bool validate_result( const int  result , int required_result_len = 4 ){
	string result_string;
	converter.clear();
	converter << result;
	converter >> result_string;
	if( result_string.length() != required_result_len ) return false;
	for ( int i=0; i<result_string.length(); i++ ){
		char digit = result_string.at(i);
		if( lookup.find(digit) == lookup.end() ) return false;
	}
	return true;
}

bool validate_products( const int mul1, const int mul2 ){
	int firsthalf  = mul1 * (mul2%10);
	if( ! validate_result( firsthalf, 3 ) )  return false;
	int secondhalf = mul1 * (mul2/10);
	if( ! validate_result( secondhalf, 3 ) )  return false;

	int result = mul1 * mul2;
	return validate_result(result,4); 
	

}



//brute force enumerates
int main() {
    ofstream fout ("crypt1.out");
    ifstream fin  ("crypt1.in");

	fin >> valid_digit_len;
	for ( int i=0; i<valid_digit_len; i++){
		char digit;
		fin >> digit;
		valid_digits[i] = digit;
		lookup[digit] = 1;
	}

	required_len = 3;
	EnumerateDigits( number,0,vmul1);
	required_len = 2;
	EnumerateDigits( number,0,vmul2);
	int valid_enumeration_count = 0;
	for( int i=0; i<vmul1.size(); i++ ){
		for( int j=0; j<vmul2.size(); j++ ){
			if( validate_products(vmul1[i],vmul2[j])  ) {
				valid_enumeration_count ++;
				//cout << vmul1[i] << " * " << vmul2[j] << " = " << vmul1[i]*vmul2[j] << endl;
			}
			
		}
	}

	fout << valid_enumeration_count << endl;




    return 0;
}

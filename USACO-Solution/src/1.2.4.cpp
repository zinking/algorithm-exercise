/*
ID: zinking1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

typedef multimap<string, string> DICT;
typedef DICT::iterator DICT_ITR;
typedef pair<string,string> PAIR_DICT;

DICT dictionary;
DICT_ITR it;
pair<DICT_ITR,DICT_ITR> ret;


char tdict[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','#','7','7','8','8','8','9','9','9','#'};

string translate( string word ){
	string item = word;
	for (int i=0; i < word.length(); i++ ){
		item[i] = tdict[ static_cast<int>( word[i] - 'A') ];
	}
	return item;
}

//char numberpad[8][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'},
//{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
// no need , because it's slow somewhat
//int InitTransform(){
//	transform['A'] = '2';
//	transform['B'] = '2';
//	transform['C'] = '2';
//
//	transform['D'] = '3';
//	transform['E'] = '3';
//	transform['F'] = '3';
//
//	transform['G'] = '4';
//	transform['H'] = '4';
//	transform['I'] = '4';
//
//	transform['J'] = '5';
//	transform['K'] = '5';
//	transform['L'] = '5';
//
//	transform['M'] = '6';
//	transform['N'] = '6';
//	transform['O'] = '6';
//
//	transform['P'] = '7';
//	transform['R'] = '7';
//	transform['S'] = '7';
//
//	transform['T'] = '8';
//	transform['U'] = '8';
//	transform['V'] = '8';
//
//	transform['W'] = '9';
//	transform['X'] = '9';
//	transform['Y'] = '9';
//
//	return 1;
//
//}




int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
	ifstream fdict("dict.txt");
	string item;
	while( !fdict.eof() ){
		fdict >> item;
		//dictionary[ translate(item) ] = item;
		dictionary.insert( PAIR_DICT(translate(item ),item) );
	}

	fin >> item;
	ret = dictionary.equal_range(item);
	if( ret.first != ret.second ){
		for (it=ret.first; it!=ret.second; ++it)
			fout << (*it).second << endl;
	}
	else fout << "NONE" << endl;
	

	/*string name = dictionary[item];
	if ( name != "" ) fout << name << endl;
	else fout << "NONE" << endl;*/

    return 0;
}

//brute force enum exists a problem that the word len is not pre-defined so you can not decide 
//how many loops you need to enum all posssible combinations, 
//or there do exist some procedure to enum all possible combinations

/*int serial = 0;
fin >> serial;
int digit[4];
for (int i=0; i < 4; i++){
digit[3-i] = serial % 10;
serial /= 10;
}

char word[5];
word[4] = '\0';
for (int i=0; i < 3; i++){
word[3] = numberpad[digit[3]-2][i];
for( int j=0; j < 3; j++){
word[2] = numberpad[digit[2]-2][j];
for( int k=0; k < 3; k++){
word[1] = numberpad[digit[1]-2][k];
for(int l=0; l < 3; l++){
word[0] = numberpad[digit[0]-2][l];
item = word;
if( dictionary[item] == 1 ) fout << item << endl;
}
}
}
}*/
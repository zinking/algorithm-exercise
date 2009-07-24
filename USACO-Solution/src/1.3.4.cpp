/*
ID: zinking1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>


using namespace std;

const int MAX_CHAR = 20000;

char FileText[MAX_CHAR];
int  max_palindrome_len   = -1;
int  max_palindrome_index = 0;
int  plindrome_text_len		  = 0;

void debug_output( int i ){
	cout <<"I: " << i ;
	cout <<" max_plindrome_len: " << max_palindrome_len << endl;
	cout <<"Pindrome_text: ";
	for( int i= max_palindrome_index; i < max_palindrome_index+plindrome_text_len+1; i++ ) {
		cout << FileText[i];
	}
	cout << endl;
	
}


//stupidest brute force search
int checkPalindromes( ){
	int textlen = strlen( FileText );
	//int CurrentPlindromeLen = 0, plindrome_text_len = 0, index = 0;
	for( int i=1; i<textlen ; i++ ){
		if( !isalpha( FileText[i] ) ) continue;
		int m = i;

		int k = i-1, l= i+1;
		int OddPlindromeLen = 1, odd_plin_tex_len = 0, odd_index = 0;
		while( k >= 0 && l < textlen ){
			while( !isalpha(FileText[k]) && (k>0)		) k--;
			while( !isalpha(FileText[l]) && (l<textlen)	) l++;
			if( tolower(FileText[k]) == tolower(FileText[l]) ) {
				OddPlindromeLen +=2;
				odd_plin_tex_len = l - k;
				odd_index = k;
			}
			else break;
			k--;
			l++;
		}
		/*if( OddPlindromeLen > 1 ){
			odd_plin_tex_len = l - k;
			odd_index = k;
		}*/
		

		k = i, l= i+1;
		int EvenPlindromeLen = 0, even_plin_tex_len = 0, even_index = 0;
		while( k >= 0 && l < textlen ){
			while( !isalpha(FileText[k]) && (k>0)		) k--;
			while( !isalpha(FileText[l]) && (l<textlen)	) l++;
			if( tolower(FileText[k]) ==  tolower(FileText[l]) ){
				EvenPlindromeLen +=2;
				even_plin_tex_len = l - k;
				even_index = k;
			}
			else break;
			k--;
			l++;
		}
		//if( EvenPlindromeLen > 0 ){
		//	even_plin_tex_len = l - k;
		//	even_index = k;
		//}
		
		
		//update max records
		if( OddPlindromeLen > EvenPlindromeLen ){
			//odd is bigger
			if ( OddPlindromeLen > max_palindrome_len ){
				max_palindrome_len = OddPlindromeLen;
				plindrome_text_len = odd_plin_tex_len;
				max_palindrome_index =odd_index;
			}
		}
		else{
			if( EvenPlindromeLen > max_palindrome_len ){
				max_palindrome_len = EvenPlindromeLen;
				plindrome_text_len = even_plin_tex_len;
				max_palindrome_index =even_index;
			}
		}

		//debug_output(i);

	}

	return 0;
}


int main() {
    ofstream fout ("calfflac.out");
    ifstream fin  ("calfflac.in");

	//fin >> FileText;
	//fin.getline( FileText, MAX_CHAR );
	/*int number = 0;
	while( !fin.eof() ){
		fin >> FileText[number];
		number ++;
	}
	FileText[number] = '\0';*/
	// read data as a block:

	fin.read (FileText,MAX_CHAR);

	checkPalindromes();
	fout << max_palindrome_len << endl;
	for( int i= max_palindrome_index; i < max_palindrome_index+plindrome_text_len+1; i++ ) {
		fout << FileText[i];
	}
	fout << endl;



    return 0;
}


// I am not farmilar with the file operations, this causes 2 WA
// I missed the beginning index, this caused some debug time and 1 WA
// I am  confused about the plindrome number definition, still reflected in the program.

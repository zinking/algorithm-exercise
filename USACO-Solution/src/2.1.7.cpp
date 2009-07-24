/*
ID: zinking1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAXCODES = 64;
int CODES[MAXCODES];

int N=0, B=0, D=0;
int current_codes = 0;


inline int get_bit_1_cnt( int arrange){
	int sumcount = arrange;
	//calculate bit 1 count using methord stated in matrix67 blog
	sumcount = (sumcount & 0x55555555) + ((sumcount >> 1)  & 0x55555555);
	sumcount = (sumcount & 0x33333333) + ((sumcount >> 2)  & 0x33333333);
	sumcount = (sumcount & 0x0F0F0F0F) + ((sumcount >> 4)  & 0x0F0F0F0F);
	sumcount = (sumcount & 0x00FF00FF) + ((sumcount >> 8)  & 0x00FF00FF);
	sumcount = (sumcount & 0x0000FFFF) + ((sumcount >> 16) & 0x0000FFFF); 
	return sumcount;
}

void search_codes(){
	int upperbound = 1<<B;
	bool found = false;
	for( int start=0; start<upperbound; start++ ){
		CODES[0] = start;
		current_codes = 1;
		for( int i=start+1; i<upperbound; i++ ){
			bool qualified = true;
			for( int j=0; j<current_codes; j++ ){//verify current i whehter qualified
				if( get_bit_1_cnt( i^CODES[j] ) < D ){
					qualified = false;
					break;
				}
			}
			if( qualified ){
				CODES[current_codes++] = i;
			}

			if( current_codes >= N ) return;

		}
	}

}



int main() {
    ofstream fout ("hamming.out");
    ifstream fin  ("hamming.in");

	fin >> N >> B >> D;
	 search_codes();

	 //fout << CODES[0] << " ";
	 for( int i=0; i<N-1; i++ ){
		 if( (i+1)%10 ){
			 fout << CODES[i]<<" ";
		 }
		 else  fout << CODES[i] << endl;
		 
	 }
	 fout << CODES[N-1] << endl;

    return 0;
}

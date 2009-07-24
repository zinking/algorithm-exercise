/*
ID: zinking1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

//0-1 optimization
int const MAX_SCOOP_COUNT = 15;
int const MAX_VITAMIN_COUNT = 25;

int scoop_count = 0, vitamin_count = 0;
int scoop_vitamin_table[MAX_SCOOP_COUNT][MAX_VITAMIN_COUNT];
int needed_vitamin_count[MAX_VITAMIN_COUNT];

int arrangements = 0,min_arrange_count = INT_MAX;

//dual sum calculation is a problem
//or use recursion to eliminate such calculation
bool satisfy( int arrangements){
	int current_vitamins[MAX_VITAMIN_COUNT] = {0};
	for( int i=0; i<scoop_count; i++ ){
		if( arrangements & ( 1<<i ) ){
			for( int j=0; j<vitamin_count; j++ ){
				current_vitamins[j] += scoop_vitamin_table[i][j];
			}
		}
	}
	for( int j=0; j<vitamin_count; j++ ){
		if( current_vitamins[j] < needed_vitamin_count[j] ) return false;
	}
	return true;
}

inline int get_arrange_cnt( int arrange){
	int sumcount = arrange;
	//calculate bit 1 count using methord stated in matrix67 blog
	sumcount = (sumcount & 0x55555555) + ((sumcount >> 1)  & 0x55555555);
	sumcount = (sumcount & 0x33333333) + ((sumcount >> 2)  & 0x33333333);
	sumcount = (sumcount & 0x0F0F0F0F) + ((sumcount >> 4)  & 0x0F0F0F0F);
	sumcount = (sumcount & 0x00FF00FF) + ((sumcount >> 8)  & 0x00FF00FF);
	sumcount = (sumcount & 0x0000FFFF) + ((sumcount >> 16) & 0x0000FFFF); 
	return sumcount;
}

void search(){
	int upperbound = 2 << scoop_count -1;
	for( int i=1; i<upperbound; i++ ){
		if( satisfy( i ) ){
			int current_arrange_count = get_arrange_cnt(i);
			if(  current_arrange_count < min_arrange_count ){
				min_arrange_count = current_arrange_count;
				arrangements = i;
			}
		}

	}
}

int main() {
    ofstream fout ("holstein.out");
    ifstream fin  ("holstein.in");

	//input....
	fin >> vitamin_count;
	for( int i=0; i<vitamin_count; i++ ) fin >> needed_vitamin_count[i];

	fin >>scoop_count;
	for( int i=0; i<scoop_count; i++ ){
		for( int j=0; j<vitamin_count; j++ ){
			fin >> scoop_vitamin_table[i][j];
		}
	}
	//input......

	search();

	fout << min_arrange_count<<" ";
	int out_puted_scoop_count = 0;
	for(int i=0; i<scoop_count; i++ ){
		if( arrangements & ( 1<<i) ){
			out_puted_scoop_count++;
			if( out_puted_scoop_count < min_arrange_count )	fout << i+1 << " ";
			else {
				fout << i+1 << endl;
				break;
			}
		}
	}

    return 0;
}

/*
ID: zinking1
PROG: numtri
LANG: C++
*/

/*
PROBLEM EXTENDING-->1. how about I want trace the route of the max sum of the triangle
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_ROW = 1000;
//vector<int> sum_vec;

int element[MAX_ROW][MAX_ROW];
int sum_memo[MAX_ROW][MAX_ROW];
int line_count = 0;
int max_sum = -1;

void DFS( int current_row,int current_col, int sum ){
	//simple but exhausting when row grow huge
	sum += element[current_row-1][current_col-1];
	if( current_row == line_count ){
		//sum_vec.push_back( sum );
		max_sum = max( sum, max_sum );
		return;
	}
	DFS( current_row+1, current_col,   sum );
	DFS( current_row+1, current_col+1, sum );
	
}

//dynamic programming bottom up
//max_sum = current_number + max( ms(i+1,j+1),ms(i+1,j) );
int MAXIMUM_SUM( int i, int j){
	if( i == line_count ) return element[i-1][j-1];	
	if( sum_memo[i-1][j-1] != -1 ) return sum_memo[i-1][j-1];
	
	int current_max = element[i-1][j-1]+max( MAXIMUM_SUM(i+1,j), MAXIMUM_SUM(i+1,j+1) );
	sum_memo[i-1][j-1] = current_max;
	return current_max;
}

int main() {
    ofstream fout ("numtri.out");
    ifstream fin  ("numtri.in");
	fin >> line_count;
	for( int i=0; i<line_count; i++ )
		for( int j=0; j<=i; j++ ){
			fin >> element[i][j];
			sum_memo[i][j] = -1;
		}
	//memset(sum_memo,-1,sizeof(int)*MAX_ROW*MAX_ROW);
	//DFS( 1,1,0);
	//int max_sum = *max_element( sum_vec.begin(), sum_vec.end() );
	max_sum = MAXIMUM_SUM(1,1);
	fout << max_sum << endl;

    return 0;
}

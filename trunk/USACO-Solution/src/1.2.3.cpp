/*
ID: transform
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int size = 0;

#define  N 10
char origin_matrix[N][N];
char result_matrix[N][N];


void copy_matrix( const char src[N][N], char dst[N][N] ){
	for (int i=0; i < size ; i++){
		for ( int j=0; j < size ; j++){
			dst[i][j] = src[i][j];
		}
	}//get original matrix;
}


void rotate_clockwise(  char matrix[N][N] ){
	char rmatrix[N][N];
	for (int i=0; i < size ; i++){
		for ( int j=0; j < size ; j++){
			rmatrix[j][size - i-1] = matrix[i][j];
		}
	}

	for (int i=0; i < size ; i++){
		for ( int j=0; j < size ; j++){
			matrix[i][j] = rmatrix[i][j];
		}
	}
}

void reflect_horizontal( char matrix[N][N] ){
	char rmatrix[N][N];
	for (int i=0; i < size ; i++){
		for ( int j=0; j < size ; j++){
			rmatrix[i][size - j-1] = matrix[i][j];
		}
	}

	/*for (int i=0; i < size ; i++){
		for ( int j=0; j < size ; j++){
			matrix[i][j] = rmatrix[i][j];
		}
	} */
	copy_matrix( rmatrix, matrix );
}
bool compare( const char src[N][N], const char dst[N][N] ){
	for (int i=0; i < size ; i++){
		for ( int j=0; j < size ; j++){
			if( src[i][j] != dst[i][j] ) return false;
		}
	}

	return true;
}







bool T1( const char matrix[N][N] ){
	char src_matrix[N][N];
	copy_matrix( matrix, src_matrix );
	rotate_clockwise( src_matrix );
	return compare( src_matrix, result_matrix );
}

bool T2( const char matrix[N][N] ){
	char src_matrix[N][N];
	copy_matrix( matrix, src_matrix );
	rotate_clockwise( src_matrix );
	rotate_clockwise( src_matrix );
	return compare( src_matrix, result_matrix );
}

bool T3( const char matrix[N][N] ){
	char src_matrix[N][N];
	copy_matrix( matrix, src_matrix );
	rotate_clockwise( src_matrix );
	rotate_clockwise( src_matrix );
	rotate_clockwise( src_matrix );
	return compare( src_matrix, result_matrix );
}

bool T4( const char matrix[N][N] ){
	char src_matrix[N][N];
	copy_matrix( matrix, src_matrix );
	reflect_horizontal( src_matrix );
	return compare( src_matrix, result_matrix );
}

bool T5( const char matrix[N][N] ){
	char src_matrix[N][N];
	copy_matrix( matrix, src_matrix );
	reflect_horizontal( src_matrix );
	
	return T1( src_matrix ) || T2( src_matrix ) || T3( src_matrix );
}
bool T6( const char matrix[N][N] ){
	return compare( matrix, result_matrix );
}



int main() {
    ofstream fout ("transform.out");
    ifstream fin  ("transform.in");

	fin >> size;
	for( int i=0; i < size ; i++ ){
		for( int j=0; j < size ; j++ ){
			fin >> origin_matrix[i][j];
		}
	}

	for( int i=0; i < size ; i++ ){
		for( int j=0; j < size ; j++ ){
			fin >> result_matrix[i][j];
		}
	}

	
	if ( T1(origin_matrix ) ) fout << 1 << endl;
	else if ( T2(origin_matrix ) ) fout << 2 << endl;
	else if ( T3(origin_matrix ) ) fout << 3 << endl;
	else if ( T4(origin_matrix ) ) fout << 4 << endl;
	else if ( T5(origin_matrix ) ) fout << 5 << endl;
	else if ( T6(origin_matrix ) ) fout << 5 << endl;
	else fout << 7 << endl;


    return 0;
}

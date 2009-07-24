/*
ID: zinking1
PROG: checker
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;

#define MAXN 16

int n;
int nsol, nprinted;
char row[MAXN];
FILE *fout;

void
solution() {
	int i;
	for(i=0; i<n; i++) {
		if(i != 0) fprintf(fout, " ");
		fprintf(fout, "%d", row[i]+1);
	}
	fprintf(fout, "\n");
}

/* Keep track of whether there is a checker on each column, and diagonal. */
char col[MAXN];  /* (i, j) -> j */
char updiag[2*MAXN]; /* (i, j) -> i+j */
char downdiag[2*MAXN]; /* (i, j) -> i-j + N */

/*
* Calculate number of ways to place checkers
* on each row of the board starting at row i and going to row n.
*/
void
nway(int i, int lim) {
	int j;

	if(i == n) {
		nsol++;
		if (n > 6 && row[0] < n/2) nsol++;
		if (nprinted++ < 3) solution();
		return;
	}

	for(j=0; j<lim; j++){
		if(!col[j] && !updiag[i+j] && !downdiag[i-j+MAXN]){
			row[i] = j;

			col[j]++;
			updiag[i+j]++;
			downdiag[i-j+MAXN]++;

			nway(i+1,n);

			col[j]--;
			updiag[i+j]--;
			downdiag[i-j+MAXN]--;
		}
	}
}

int main(void) {
	FILE *fin = fopen("checker.in", "r");
	fout = fopen("checker.out", "w");
	fscanf(fin, "%d", &n);
	nway(0, n>6?(n+1)/2:n);
	fprintf(fout, "%d\n", nsol);
	return 0;
}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//const int MAX_NUMBER = 13;
//int N=0;
//
//ofstream fout ("checker.out");
//ifstream fin  ("checker.in");
//
//
//
//int ChessArrange[MAX_NUMBER];
//
//bool ColumnArrange[MAX_NUMBER];
//bool pDiagonalArrange[MAX_NUMBER][MAX_NUMBER];
//bool nDiagonalArrange[MAX_NUMBER][MAX_NUMBER];
////其实没有必要分配二维的数组，只要记录正负对角线哪条被占据了，然后使用的时候计算就可以了
////还是老问题，空间换时间OR时间换空间，这里开二维空间增加的计算量是给二位空间状态赋值
////所以没起到减轻计算量的任务
//
//void setDiagonalArrange( int row, int col , bool flag ){
//	int i=row, j=col;
//	for(  i=row, j=col; (i<N  && j<N )  ; i++, j++ ) pDiagonalArrange[i][j] = flag;// 4 CLOCK DIRECTION
//	for(  i=row, j=col; (i>=0 && j>=0)  ; i--, j-- ) pDiagonalArrange[i][j] = flag;//10 CLOCK DIRECTION
//	for(  i=row, j=col; (i>=0 && j<N )  ; i--, j++ ) nDiagonalArrange[i][j] = flag;//1  CLOCK DIRECTION
//	for(  i=row, j=col; (i<N  && j>=0)  ; i++, j-- ) nDiagonalArrange[i][j] = flag;//7  CLOCK DIRECTION
//}
//
//
//int find_count = 0;
//bool check_current_arrange( int placed_chess_count ){
//	
//	//for (int step = 1; step < placed_chess_count ; step ++  ){
//	//	for( int i=0; i<placed_chess_count-step; i++ ){
//	//		if( abs( ChessArrange[i] - ChessArrange[i+step] ) == step ) return false;
//	//	}
//	//}
//	//upper code include unnecessary checks
//	for( int step =1; step < placed_chess_count; step++ ){
//		if ( abs(ChessArrange[placed_chess_count-1]-ChessArrange[placed_chess_count-1-step] ) == step ) return false;
//	}
//	
//	return true;
//}
//
//void DFS_PLACECHESS( int depth){
//	//if( find_count > 3 ) return;
//	if( depth == N+1 ){
//		if( find_count < 3 ){
//			for( int i=0; i<N-1; i++ )fout << ChessArrange[i] <<" ";
//			fout << ChessArrange[N-1] << endl;
//		}
//		++find_count;
//		return;
//	}
//
//
//	for( int i=0; i<N; i++ ){// i is the index of col and depth-1 is the index of row
//		if( !ColumnArrange[i] && !pDiagonalArrange[depth-1][i]  && !nDiagonalArrange[depth-1][i] ){//找到一个空的位置
//			
//			//if( !ColumnArrange[i] || DiagonalArrange[depth-1][i] ) continue;
//			ColumnArrange[i] = true;
//			ChessArrange[depth-1] = i+1;
//			setDiagonalArrange(depth-1, i ,true);
//			//if( !DiagonalArrange[i][depth] ) DFS_PLACECHESS( depth+1 );
//			DFS_PLACECHESS( depth+1 );
//			setDiagonalArrange(depth-1, i ,false);
//			ChessArrange[depth-1] = 0;
//			ColumnArrange[i] = false;
//		}
//	}
//	
//}
//
//int main() {
//
//	fin >> N;
//	DFS_PLACECHESS( 1 );
//	fout << find_count << endl;
//
//    return 0;
//}

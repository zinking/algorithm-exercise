/*
ID: zinking1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

ifstream fin("castle.in");
ofstream fout("castle.out");


#define out fout
#define in fin


int n,m;
int c[50*50];
int data[50][50];
int colors[50][50];
int color_cnt;

const int W = 1;
const int N = 2;
const int E = 4;
const int S = 8;

void color(int i,int j,int color);

void solve()
{
	in>>m>>n;

	memset(c,0,sizeof(0));
	memset(colors,-1,sizeof(colors));

	color_cnt = 0;

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			in>>data[i][j];
		}

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(colors[i][j]==-1){
					color(i,j,color_cnt++);
				}
			}

			out<<color_cnt<<endl;

			int largest = INT_MIN;

			for(int i=0;i<color_cnt;++i){
				largest = max(largest,c[i]);
			}


			out<<largest<<endl;

			largest = INT_MIN;
			int walli,wallj;
			char dir;

			for(int j=0;j<m;++j)
				for(int i=n-1;i>=0;--i)
				{
					if(i-1>=0){
						if( colors[i][j]!=colors[i-1][j]){
							if( largest<c[colors[i][j]]+c[colors[i-1][j]]){
								largest=c[colors[i][j]]+c[colors[i-1][j]];
								walli = i;
								wallj = j;
								dir = 'N';
							}
						}
					}

					if(j+1<m){
						if( colors[i][j]!=colors[i][j+1]){
							if(largest<c[colors[i][j]]+c[colors[i][j+1]]){
								largest = c[colors[i][j]]+c[colors[i][j+1]];
								walli = i;
								wallj = j;
								dir = 'E';
							}
						}
					}

				}

				out<<largest<<endl;
				out<<walli+1<<' '<<wallj+1<<' '<<dir<<endl;

}

void color(int i,int j,int clr)
{
	if(colors[i][j]!=-1)
		return;

	colors[i][j] = clr; 
	c[clr]++;

	if((data[i][j]&S)==0&&(i+1<n)){
		color(i+1,j,clr); 
	}

	if((data[i][j]&E)==0&&(j+1<m)){
		color(i,j+1,clr);
	}

	if((data[i][j]&W)==0&&(j-1>=0)){
		color(i,j-1,clr);
	}

	if((data[i][j]&N)==0&&(i-1>=0)){
		color(i-1,j,clr);
	}
}

int main(int argc,char *argv[])
{
	solve(); 
	return 0;
}
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//const int WEST_DIRECTION  = 0x00000001;
//const int NORTH_DIRECTION = 0x00000002;
//const int EAST_DIRECTION  = 0x00000004;
//const int SOUTH_DIRECTION = 0x00000008;
//
//const int MAX_N = 50;
//int Room[MAX_N][MAX_N];
//int RoomStatus[MAX_N][MAX_N];
//int AdjMatrix[MAX_N][MAX_N];
//
//int M=0, N=0;
//int room_num =0;
//int RoomSize[MAX_N];
//
//void floodFill( int x, int y, int room_no ){
//	if( RoomStatus[x][y] != 0 ) return;
//	RoomStatus[x][y] = room_no;
//	RoomSize[room_no]++;
//	if( x > 0 ){//not out of bound
//		if( !(Room[x][y] & NORTH_DIRECTION) ) floodFill( x-1, y , room_no);
//		else{// there is a wall north
//			if( RoomStatus[x-1][y] != 0 && RoomStatus[x-1][y] != room_no ) {
//				AdjMatrix[room_no][ RoomStatus[x-1][y] ] =1;
//				AdjMatrix[RoomStatus[x-1][y] ][room_no ] =1;
//			}
//		}
//	}
//
//	if( x < M-1 ){
//		if( !(Room[x][y] & SOUTH_DIRECTION) ) floodFill( x+1, y , room_no );
//		else{// there is a wall north
//			if( RoomStatus[x+1][y] != 0 && RoomStatus[x+1][y] != room_no  ){
//				AdjMatrix[room_no][ RoomStatus[x+1][y] ] =1;
//				AdjMatrix[RoomStatus[x+1][y]][ room_no ] =1;
//			}
//		}
//	}
//
//	if( y > 0 ){//not out of bound
//		if( !(Room[x][y] & WEST_DIRECTION) ) floodFill( x, y-1 , room_no);
//		else{// there is a wall north
//			if( RoomStatus[x][y-1] != 0 && RoomStatus[x][y-1] != room_no ){
//				AdjMatrix[room_no][ RoomStatus[x][y-1] ] =1;
//				AdjMatrix[RoomStatus[x][y-1]][ room_no ] =1;
//			}
//		}
//	}
//
//	if( y < N-1 ){
//		if( !(Room[x][y] & EAST_DIRECTION) ) floodFill( x, y+1 , room_no);
//		else{// there is a wall north
//			if( RoomStatus[x][y+1] != 0 && RoomStatus[x][y+1] != room_no  ){
//				AdjMatrix[room_no][ RoomStatus[x][y+1] ] =1;
//				AdjMatrix[RoomStatus[x][y+1]][ room_no ] =1;
//			}
//		}
//	}
//}
//
//void debug(){
//	cout << "AdjMatrix "<< endl;
//	for ( int i=1; i<room_num+1; i++ ){
//		for( int j=1; j<room_num+1; j++){
//			cout << AdjMatrix[i][j]<<" ";
//		}
//		cout << endl;
//	}
//
//	cout << "RoomStatus " << endl;
//	for( int i=0; i<M; i++ ){
//		for( int j=0; j<N; j++ ){
//			cout << RoomStatus[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void color_walls(){
//	for( int i=0; i<M; i++ ){
//		for( int j=0; j<N; j++ ){
//			if( RoomStatus[i][j] == 0 ) floodFill( i,j,++room_num);
//		}
//	}
//}
//
//
//
//
//
//int main() {
//    ofstream fout ("castle.out");
//    ifstream fin  ("castle.in");
//
//	fin >> N >> M;
//	for( int i=0; i<M; i++ ){
//		for( int j=0; j<N; j++ ){
//			fin >> Room[i][j];
//		}
//	}
//
//	color_walls();
//	fout << room_num << endl;
//
//	int *pBiggestRoom = max_element( RoomSize,RoomSize+room_num+1 );
//	fout << *pBiggestRoom << endl;
//	int pBiggestRoomNO = pBiggestRoom - RoomSize;
//	int secondBiggestRoomSize = -1;
//	int secondBiggestRoomNo = 0;
//
//	int merged = *pBiggestRoom;
//
//	//debug();
//
//	//for( int i=1; i<room_num+1; i++ ) {
//	//	if( AdjMatrix[i][pBiggestRoomNO] == 1 ){
//	//		if( RoomSize[i] > secondBiggestRoomSize ) {
//	//			secondBiggestRoomSize = RoomSize[i];//roomsize index from 1
//	//			secondBiggestRoomNo = i;//index
//	//		}
//	//	}
//	//}
//
//	for( int i=1; i<room_num+1; i++ ){
//		for( int j=1; j<i; j++ ){
//			if( AdjMatrix[i][j] == 1 ){
//				if( RoomSize[i] + RoomSize[j] > merged ){
//					merged = RoomSize[i] + RoomSize[j];
//					pBiggestRoomNO = i;
//					secondBiggestRoomNo = j;
//				}
//			}
//		}
//	}
//
//	//int merged = *pBiggestRoom + secondBiggestRoomSize;
//	fout << merged << endl;
//
//
//	bool found = false;
//	for( int i=M-1; i>=0; i--){
//		
//		for( int j=N-1; j>=0; j--){
//			if( RoomStatus[i][j] != pBiggestRoomNO && RoomStatus[i][j] != secondBiggestRoomNo ) continue;
//			if( RoomStatus[i][j-1] != pBiggestRoomNO && RoomStatus[i][j-1] != secondBiggestRoomNo ) continue;
//			if( RoomStatus[i][j-1] == RoomStatus[i][j] ) continue;
//			if( RoomSize[ RoomStatus[i][j] ] + RoomSize[ RoomStatus[i][j-1] ] == merged){
//				fout << i+1 << " " << j << " " << "E" << endl;
//				found = true;
//				break;
//			}
//		}
//		if( found ) break;
//
//		for( int j=0; j<=N-1; j++){
//			if( RoomStatus[i][j] != pBiggestRoomNO && RoomStatus[i][j] != secondBiggestRoomNo ) continue;
//			if( RoomStatus[i-1][j] != pBiggestRoomNO && RoomStatus[i-1][j] != secondBiggestRoomNo ) continue;
//			if( RoomSize[ RoomStatus[i][j] ] + RoomSize[ RoomStatus[i-1][j] ] == merged){
//				fout << i+1 << " " << j+1 << " " << "N" << endl;
//				found = true;
//				break;
//			}
//		}
//		if( found ) break;
//
//	}
//	
//
//
//    return 0;
//}

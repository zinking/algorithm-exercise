/*
ID: zinking1
PROG: clocks
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;
const int with[10][5]={{},{1,2,4,5},{1,2,3},{2,3,5,6},{1,4,7},{2,4,5,6,8},{3,6,9},{4,5,7,8},{7,8,9},{5,6,8,9}};
int t[10],ans_min=30,ans[30],way[30]={1},use[10];
void dfs(int);
bool check();
void work(int);
int main() {
	ifstream fin ("clocks.in");
	ofstream fout ("clocks.out");
	for (int i=1;i<=9;i++) {
		fin >> t[i];
		t[i]%=12;
	}
	dfs(1);
	for (int i=1;i<ans_min;i++) fout << ans[i] << ' ';
	fout << ans[ans_min] << endl;
	fin.close();
	fout.close();
	return 0;
}
void dfs(int cur) {
	if (cur-1>=ans_min) return;
	if (check()) {
		ans_min=cur-1;
		for (int i=1;i<cur;i++) ans[i]=way[i];
		return;
	}
	for (int i=way[cur-1];i<=9;i++) {
		if (use[i]>=3) continue;
		work(i);
		use[i]++;
		way[cur]=i;
		dfs(cur+1);
		for (int j=1;j<=3;j++) work(i);
		use[i]--;
	}
}
bool check() {
	for (int i=1;i<=9;i++) if (t[i]!=0) return false;
	return true;
}
void work(int k) {
	for (int i=0;i<=4 && with[k][i]!=0;i++) t[with[k][i]]=(t[with[k][i]]+3)%12;
}
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class gridstate;
//typedef vector<int> SEQUENCE;
//typedef SEQUENCE::iterator SEQITER;
//typedef vector<SEQUENCE> SEQHOLDER;
//typedef SEQHOLDER::iterator SQHOLDERITR;
//typedef vector<gridstate> StateStack;
//
//class gridstate{
//	
//	int data[9];
//public:
//	gridstate(){}
//	void initialize( ifstream& fin ){
//		int number = 0;
//		for( int i=0; i<9; i++ ){
//			fin >> number;
//			data[i] = number % 12;
//		}
//	}
//
//	bool reachEnd(){
//		for( int i=0; i<9; i++ )
//			if( data[i] != 0 ) return false;
//		return true;
//	}
//
//	void MoveToNextState( int i, gridstate& out ){
//		const int OPERATION[10][5]={
//			{},{0,1,3,4,-1},{0,1,2,-1,-1},{1,2,4,5,-1},
//			{0,3,6,-1,-1},{1,3,4,5,7},{2,5,8,-1,-1},
//			{3,4,6,7,-1},{6,7,8,-1,-1},{4,5,7,8,-1}
//		};
//
//		for( int i=0; i<9; i++ ){
//			out.data[i] = this->data[i];
//		}
//
//		 for (int k=0;k<=4 && OPERATION[i][k]!=-1;k++) 
//			 out.data[OPERATION[i][k]] = ( this->data[ OPERATION[i][k] ]+3)%12;		
//
//	}
//};
//
//bool sequence_compare( const SEQUENCE& s1, const SEQUENCE& s2 ){
//	if( s1.size() < s2.size() ) return true;
//	else if( s1.size() == s2.size() ){
//		return s1[0] < s2[0];
//	}
//	return false;
//}
//
//class solver{
//	gridstate start;
//	StateStack stateholder;
//	//SEQHOLDER   seqholder;
//	SEQUENCE seq_result;
//	int op_count[10];
//	int depth_control;
//	bool found;
//public:
//	solver( gridstate& s):start(s){}
//
//	void clear_ops(){
//		for( int i=0;i<10;i++) op_count[i] = 0;
//	}
//	void solve(){
//		SEQUENCE s;
//		found = false;
//		
//		for(  depth_control = 1; depth_control<28; depth_control++ ){
//			clear_ops();
//			DFS_Solve( start ,s );
//		}
//		
//	}
//	void DFS_Solve( gridstate& current_gridstate, SEQUENCE& s ){
//		if( found ) return;
//		if( current_gridstate.reachEnd() ) {
//			//seqholder.push_back( s );
//			seq_result = s;
//			found = true;
//			return;
//		}
//
//		if( s.size() >= depth_control ) return;
//		int i = ( s.size()==0 ? 1:s.back() );
//
//		for (  ; i<=9; i++ ){
//			if ( op_count[i]>=3 ) continue;
//			gridstate next_gridstate;
//			current_gridstate.MoveToNextState( i , next_gridstate ); 
//			SEQUENCE  ns = s;
//			
//
//			ns.push_back( i );
//
//			op_count[i]++;
//			DFS_Solve( next_gridstate, ns );
//			op_count[i]--;
//		}
//
//	}
//	void output(ofstream& fout ){
//
//		for( int i=0; i<seq_result.size()-1; i++ ){
//			fout << seq_result[i] << " ";
//		}
//		fout << seq_result.back();
//		fout << endl;
//
//	}
//
//};
//
//int main() {
//    ofstream fout ("clocks.out");
//    ifstream fin  ("clocks.in");
//	gridstate start;
//	start.initialize( fin );
//	solver s(start);
//	s.solve();
//	s.output( fout );
//
//    return 0;
//}

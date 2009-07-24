/*
ID: zinking1
PROG: ariprog
LANG: C++
*/


#include <fstream>
using namespace std;
struct Ans {
	int a,b;
};
int cmp(const void*,const void*);
int cmp2(const void*,const void*);
int main() {
	ifstream fin ("ariprog.in");
	ofstream fout ("ariprog.out");
	int n,m,num[31627],n_num=0,ans_num=0;
	bool flag[125001];
	Ans ans[10001];
	fin >> n >> m;
	for (int i=0;i<=m;i++) for (int j=i;j<=m;j++) if (!flag[i*i+j*j]) {
		flag[i*i+j*j]=true;
		num[++n_num]=i*i+j*j;
	}
	qsort(&num[1],n_num,sizeof(num[1]),cmp);
	for (int i=1;i<=n_num-n+1;i++) for (int j=i+1;j<=n_num-n+2;j++) {
		int a=num[i],b=num[j]-num[i];
		if (b==0) continue;
		if (a+(n-1)*b>m*m*2) break;
		bool can=true;
		for (int k=2;k<n;k++) if (!flag[a+k*b]) {
			can=false;
			break;
		}
		if (can) {
			ans[++ans_num].a=a;
			ans[ans_num].b=b;
		}
	}
	qsort(&ans[1],ans_num,sizeof(ans[1]),cmp2);
	for (int i=1;i<=ans_num;i++) fout << ans[i].a << ' ' << ans[i].b << endl;
	if (ans_num==0) fout << "NONE" << endl;
	fin.close();
	fout.close();
	return 0;
}
int cmp(const void* a,const void* b) {
	return *(int*)a-*(int*)b;
}
int cmp2(const void* a,const void* b) {
	Ans x=*(Ans*)a,y=*(Ans*)b;
	return x.b==y.b?x.a-y.a:x.b-y.b;
}
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <utility>
//#include <map>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef map<int,int> LOOKUP;
//typedef pair<int,int> ArithmicProgression;
//typedef vector<ArithmicProgression> Sequences;
//typedef vector<int> NumberVec;
//
//LOOKUP NumberDict;
//Sequences seq_list;
//NumberVec nv;
//
//bool comp_ap( const ArithmicProgression& l, const ArithmicProgression& r){
//	if( l.second < r.second ) return true;
//	else if ( l.second == r.second ) return l.first < r.first;
//	
//	return false;
//}
//
//int main() {
//    ofstream fout ("ariprog.out");
//    ifstream fin  ("ariprog.in");
//
//	int sequence_length = 0, upperbound = 0;
//	fin >> sequence_length >> upperbound;
//
//	for( int i=0; i <= upperbound; i++ ){
//		for( int j=0; j <= upperbound; j++ ){
//			int number = i*i+j*j;
//			NumberDict[number] = 1;
//			//nv.push_back( number );
//		}
//	}
//
//	LOOKUP::iterator litr;
//	for( litr = NumberDict.begin(); litr != NumberDict.end(); litr++ ){
//		nv.push_back( (*litr).first );
//	}
//
//
//	int max_number = upperbound*upperbound*2;
//	sort( nv.begin(), nv.end() );
//	
//	int a=nv[0], d=nv[1], nv_len = nv.size();
//	for(  int i=0; i<=nv_len-sequence_length+1; i++ ){//if select last sequene length, sequence length won't satisfy
//		
//		//int max_sequnence_number = a + (sequence_length-1)*d;
//		//if( max_sequnence_number > max_number )break;
//
//		for( int j=i+1; j<=nv_len-sequence_length+2; j++ ){
//			a = nv[i];
//			d = nv[j] - nv[i];
//			if( d==0 ) break;
//			int max_sequnence_number = a + (sequence_length-1)*d;
//			if( max_sequnence_number > max_number )break;
//
//			bool is_valid_seq = true;
//			for( int len=3; len <= sequence_length; len++ ){
//				// a , a+d must reside in the dictionary
//				int sequence_number = a + (len-1)*d;
//				if( NumberDict[sequence_number] != 1 ) {
//					is_valid_seq = false;
//					break;
//				}
//			}
//
//			if ( is_valid_seq ){
//				ArithmicProgression ap( a,d);
//				seq_list.push_back( ap );
//			}
//
//		}
//
//
//		
//	}
//
//	if( seq_list.size() == 0 ){
//		fout << "NONE" << endl;
//	}
//	else{
//		sort( seq_list.begin(),seq_list.end(),comp_ap);
//		for( int i=0; i<seq_list.size(); i++ ){
//			fout << seq_list[i].first << " " << seq_list[i].second << endl;
//		}
//	}
//	
//
//    return 0;
//}

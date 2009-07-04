/*
ID: zinking1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	int rnumber;
	int bnumber;
	node():rnumber(0),bnumber(0){}
};

node left2right[1000];
node right2left[1000];


int main() {
    ofstream fout ("beads.out");
    ifstream fin  ("beads.in");

	int n = 0, maxbead = 0, i=0;
	string beadsequence;
	fin >> n;
	fin >> beadsequence;
	beadsequence += beadsequence; // repeat to cycle

	//count from left to right
	for( i=1; i < 2*n ; i++ ){
		char currentchar = beadsequence.at(i-1);
		switch( currentchar ){
			case 'r':
				left2right[i].rnumber = left2right[i-1].rnumber + 1;
				left2right[i].bnumber = 0;
				break;
			case 'b':
				left2right[i].bnumber = left2right[i-1].bnumber + 1;
				left2right[i].rnumber = 0;
				break;
			case 'w':
				left2right[i].bnumber = left2right[i-1].bnumber + 1;
				left2right[i].rnumber = left2right[i-1].rnumber + 1;
				break;

		}
	}

	//count from right to left
	for( i=2*n - 1; i > - 1 ; i-- ){
		char currentchar = beadsequence.at(i);
		switch( currentchar ){
			case 'r':
				right2left[i].rnumber = right2left[i+1].rnumber + 1;
				right2left[i].bnumber = 0;
				break;
			case 'b':
				right2left[i].bnumber = right2left[i+1].bnumber + 1;
				right2left[i].rnumber = 0;
				break;
			case 'w':
				right2left[i].bnumber = right2left[i+1].bnumber + 1;
				right2left[i].rnumber = right2left[i+1].rnumber + 1;
				break;

		}
	}

	int bead_number = 0;
	for( i=0; i < 2*n ; i++ ){
		bead_number = max( left2right[i].bnumber , left2right[i].rnumber ) 
			+ max( right2left[i].bnumber, right2left[i].rnumber );
		maxbead = max( maxbead, bead_number );
	}
	maxbead = min( n, maxbead );

	fout << maxbead << endl;
	
    return 0;
}



// * trying to solve the question with complex Searching * //

/*struct node{
char color;
int  beadnumber;
node( char c, int n ):color(c),beadnumber(n){}
};

typedef vector<node>  VNODE;
VNODE vbead;*/
//int i = 0,num = 0;
//char last_color = beadlist.at(0) ,curr_color;
//for ( i=0; i < beadlist.length(); i++){
//	curr_color = beadlist.at(i);
//	if( curr_color != last_color ){
//		node bead( last_color, num );
//		vbead.push_back( bead );
//		num = 0;
//	}
//	num++;
//	last_color = curr_color;
//}
//if ( num != 0 ) vbead.push_back( node(last_color,num ));

//int len = vbead.size();

//int index = 0, visit_index = 0;
//int	beadnumber=0, cn=0, maxbead = 0;
//
//last_color = vbead[0].color;

//while( true ){
//	/*if ( len == 1 ) {
//		maxbead = vbead[0].beadnumber;
//		break;
//	}*/
//	visit_index = index;
//	while( true ){
//		if ( cn > 1 ){
//			cn = 0;
//			break;
//			
//		}
//		if ( visit_index == len ) {
//			visit_index = 0;
//			if( cn == 0 ) break;
//		}
//		
//		curr_color = vbead[visit_index].color;
//		
//		if ( curr_color != 'w' && curr_color != last_color ) {
//			cn++;
//			last_color = vbead[visit_index].color;				
//		}

//		if ( cn <= 1 ) beadnumber+= vbead[visit_index].beadnumber;
//	
//		if( visit_index < len ) {
//			visit_index++;
//		} 
//		else{
//			visit_index = 0;
//			
//		}
//	}

//	maxbead < beadnumber ? maxbead = beadnumber: NULL;
//	beadnumber = 0;

//	if ( index < len ) index ++;
//	else break;
//}
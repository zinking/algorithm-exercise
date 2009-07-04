/*
ID: zinking1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> VINT;

class StallBlcok{//stalls blocked with only one wood
public:
	VINT stalls;
	StallBlcok(){}
	StallBlcok( int element ){
		stalls.push_back( element );
	}

	int getDistanceWithNextBlock( StallBlcok& next ){
		return next.stalls.front() - stalls.back();
	}

	int getlength(){
		return stalls.back() - stalls.front() + 1;
	}

};

typedef vector<StallBlcok> VBlocks;


VINT sequence;
VBlocks vb;



int main() {
    ofstream fout ("barn1.out");
    ifstream fin  ("barn1.in");

	int max_wood_nubmer = 0, total_stalls = 0, occupied_stalls = 0;
	fin >> max_wood_nubmer >> total_stalls >> occupied_stalls;
	int stall_id = 0;
	for( int i=0; i<occupied_stalls; i++ ){
		fin >> stall_id;
		sequence.push_back( stall_id );
	}
	sort( sequence.begin(), sequence.end() );
	
	for( int i=0; i<occupied_stalls; i++ ){
		vb.push_back( StallBlcok(sequence[i]) );
	}

	int min_distance_between_blocks = total_stalls, min_id = 0;
	while ( vb.size() > max_wood_nubmer ){
		min_distance_between_blocks = total_stalls;
		for( int i=0; i<vb.size()-1; i++ ){
			int distance = vb[i].getDistanceWithNextBlock( vb[i+1] );
			if( distance < min_distance_between_blocks ){
				min_distance_between_blocks = distance;
				min_id = i;
			}
		}
		/* no need for merge operation
		merge( vb[min_id].stalls.begin(),vb[min_id].stalls.end(),
			   vb[min_id+1].stalls.begin(),vb[min_id+1].stalls.end(),
			   vb[min_id].stalls.begin() );
			   */
		//copy(vb[min_id+1].stalls.begin(),vb[min_id+1].stalls.end(), vb[min_id].stalls.begin() + vb[min_id].stalls.size() );
		vb[min_id].stalls.insert( vb[min_id].stalls.end(), vb[min_id+1].stalls.begin(),vb[min_id+1].stalls.end() );
		vb.erase( vb.begin() + min_id + 1);
	}

	int total_blocked = 0;
	for( int i=0; i<vb.size(); i++ ){
		total_blocked += vb[i].getlength();
	}

	fout << total_blocked << endl;


    return 0;
}

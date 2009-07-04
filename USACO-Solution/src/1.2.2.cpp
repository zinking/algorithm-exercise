/*
ID: zinking1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class segment{

public:
	segment():start(0),end(0){}
	segment( int s, int e ){
		if ( s > e ) swap( s, e );
		start = s; 
		end	= e;
	}
	/*segment( const segment& r ):start( r.start ),end( r.end){}

	segment& operator = ( const segment& r ){
		this->start = r.start;
		this->end = r.end;
		return *this;
	}*/

	bool intersect( segment& r){
		if ( start < r.start ){
			return end >= r.start ;
		}
		else{
			return start <= r.end;
		}
	}

	int getSegmentLength(){
		return end - start ;
	}


	int start;
	int end;
};

 bool segment_palce_comparator( segment& s1, segment& s2 ){
	return s1.start > s2.start ;
}
 bool segment_length_comparator( segment& s1, segment& s2 ){
	return s1.getSegmentLength() < s2.getSegmentLength();
}


typedef vector<segment> VSegCon;
VSegCon segments;
VSegCon csegments;

void bubble_sort( ){
	bool swaped;
	int n = segments.size();
	do 
	{
		swaped = false;
		for ( int j = 0; j < n-1 ; j++ ){
			if(  segment_palce_comparator(segments[j],segments[j+1] ) ){
				//just don't work
				swap( segments[j], segments[j+1] );
				/*segment c(segments[j+1] );
				segments[j+1] = segments[j];
				segments[j] = c;*/
				swaped = true;
			}
		}
		n--;

	} while ( swaped );
}

void UniteAllSegments( ){
	//this sort won't work on judge
	//sort( segments.begin(), segments.end(), segment_palce_comparator);
	bubble_sort();
	int start = 0, end = 0;
	for ( int i=0; i < segments.size()-1; i++ ){
		if( segments[i].intersect( segments[i+1]) ){
			start = min( segments[i].start, segments[i+1].start );
			end = max( segments[i].end, segments[i+1].end );
			segment s ( start ,end );
			segments.erase( segments.begin() + i );
			segments.erase( segments.begin() + i );//notice the iterator 
			segments.insert(segments.begin() + i, s );
			i--;
		}
	}
}

void CompensateSegments(){
	for ( int i=0; i < segments.size()-1; i++ ){
		segment s ( segments[i].end , segments[i+1].start );
		csegments.push_back( s );		
	}

}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

	int n = 0, s = 0, e = 0;
	fin >> n ;
	for ( int i=0; i < n ; i++){
		fin >> s >> e;
		segments.push_back( segment(s,e) );
	}

	int max_duration = 0, min_duration = 0;
	UniteAllSegments();
	CompensateSegments();
	max_duration = max_element( segments.begin(), segments.end(), segment_length_comparator )->getSegmentLength();

	if ( csegments.size() == 0 ){
		min_duration = 0;
	}
	else min_duration = max_element( csegments.begin(), csegments.end(), segment_length_comparator )->getSegmentLength();

	fout << max_duration << " " <<  min_duration << endl;


    return 0;
}

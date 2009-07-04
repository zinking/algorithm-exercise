/*
ID: zinking1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
inline int getWeekDay( int year, int month ){
	int day = 13;
	if( 1 == month )  {
		month = 13;
		year --;
	}
	if( 2 == month )  {
		month = 14;
		year --;
	}
	//formula kilam
	//January and Febrary is treated as 13th and 14th month of last year
	return( day + 2*month + 3*(month+1)/5 + year + year/4 -year/100 + year/400 ) % 7 ;

	//taylor's formula
	//w=[c/4]-2c+y+[y/4]+[26(m+1)/10]+d-1 
	// 	int c = year / 100, y = year % 100;
	// 	if( 1 == month )  month = 13; ....
	// 	if( 2 == month )  month = 14; ....
	//January and Febrary is treated as 13th and 14th month of last year
	// 	int w = ( c/4 ) - 2*c + y + ( y/4 ) + ( 26*(month+1)/10 ) + day - 1;
	// 	w = ( w>=0 ? w%7 : 7+w%7 );

}


int main() {
    ofstream fout ("friday.out");
    ifstream fin  ("friday.in");

	int N = 0, year = 0, month=0, day = 0 ;
	int WeekDay[8] = {0,0,0,0,0,0,0,0};
	fin >> N;

	for ( year = 1900; year < 1900 + N; year++ ){
		for ( month = 1; month < 13; month++ ){
			WeekDay[ getWeekDay(year,month ) ] ++;
		}
	}
	fout << WeekDay[5] << " " << WeekDay[6] ;
	for ( year = 0; year < 5; year++ ){
		fout<< " " << WeekDay[year] ;
	}
	fout << endl;
	
    
    return 0;
}

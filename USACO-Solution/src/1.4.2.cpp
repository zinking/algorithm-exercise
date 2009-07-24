/*
ID: zinking1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ofstream fout ("packrec.out");
ifstream fin  ("packrec.in");

int max(int a, int b, int c){
     return max(max(a, b), c);
}

int max(int a, int b, int c, int d){
	return max(max(a, b, c), d);
}

struct Rect{
	int w;
	int h;
	Rect():w(0),h(0){}
	Rect(int width, int height):w(width),h(height){}


	void Tidy(){ 
		if( w > h ) swap( w, h );
	}
	int getArea(){ 
		return w*h; 
	}
	void fileout(){ 
		fout << w << " " << h << endl;
	}
};

Rect rect[4];
int smallestRectArea = 65535;
typedef vector<Rect> VRECT;
VRECT small_rects;
VRECT::iterator vit;


void updateSmallestRect( int w, int h){
	Rect r(w,h);
	if( r.getArea() < smallestRectArea ){
		small_rects.clear();
		small_rects.push_back( r );
		smallestRectArea = r.getArea();
	}
	else if( r.getArea() == smallestRectArea ){
		small_rects.push_back( r );
	}

}


void calculateArea(int x[], int i){
    int h0 = rect[x[0]].h; int w0 = rect[x[0]].w;
    int h1 = rect[x[1]].h; int w1 = rect[x[1]].w;
    int h2 = rect[x[2]].h; int w2 = rect[x[2]].w;
    int h3 = rect[x[3]].h; int w3 = rect[x[3]].w;
    if ((i & 1) == 1) swap(h0, w0);
    if ((i & 2) == 2) swap(h1, w1);
    if ((i & 4) == 4) swap(h2, w2);
    if ((i & 8) == 8) swap(h3, w3);//i bit wise operation to get All combination of transposes

    int tot_w, tot_h;

    //1
    tot_h = max(h0, h1, h2, h3);
    tot_w = w0 + w1 + w2 + w3;
    updateSmallestRect( tot_w, tot_h );
    //2
    tot_h = max(h0, h1, h2) + h3;
    tot_w = max(w0 + w1 + w2, w3);
    updateSmallestRect( tot_w, tot_h );
    //3
    tot_h = max(max(h0, h1) + h3, h2);
    tot_w = max(w0 + w1, w3) + w2;
    updateSmallestRect( tot_w, tot_h );
    //4
    tot_h = max(h0 + h1, h2, h3);
    tot_w = max(w0, w1) + w2 + w3;
    updateSmallestRect( tot_w, tot_h );
    //5
    tot_h = max(h0 + h1, h2 + h3);
    tot_w = max(w0 + w3, w1 + w2);
    if (h0 + h2 > tot_h && w0 + w2 > tot_w) return;
    if (h1 + h3 > tot_h && w1 + w3 > tot_w) return;
    updateSmallestRect( tot_w, tot_h );
}


void getPermutation(int x[], int p){
    if (p >= 4)
    {
        for (int i = 0; i <= 15; i++)
            calculateArea(x, i);
        return;
    }
    for (int i = p; i < 4; i++)
    {
        swap(x[i], x[p]);
        getPermutation(x, p + 1);
    }
}

bool compare_rect( const Rect& r1, const Rect& r2){
	return r1.w < r2.w;
}

bool rect_equal( const Rect& r1, const Rect& r2){
	return ( r1.w == r2.w ) && ( r1.h == r2.h );
}


int main() {

	for (int i = 0; i < 4; i++)
		fin >> rect[i].w >> rect[i].h;
	int x[4] = {0,1,2,3};
	getPermutation(x,0);//permuatate all rects;

	for( int i=0; i<small_rects.size(); i++ ) small_rects[i].Tidy();
	
	sort( small_rects.begin(),small_rects.end(), compare_rect );

	vit = unique( small_rects.begin(),small_rects.end(), rect_equal);
	small_rects.resize( vit - small_rects.begin() );
	fout << smallestRectArea << endl;
	for( int i=0; i<small_rects.size(); i++ ) small_rects[i].fileout();

    return 0;

}

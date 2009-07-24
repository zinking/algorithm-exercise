/*
ID: zinking1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


struct frac {
	int e,d;
};
bool check(int,int);
int cmp(const void*,const void*);
int main() {
	ifstream fin ("frac1.in");
	ofstream fout ("frac1.out");
	int n,ans_num=0;
	frac ans[25600];
	fin >> n;
	for (int i=1;i<=n;i++) for (int j=1;j<i;j++) if (check(j,i)) {
		ans[++ans_num].e=j;
		ans[ans_num].d=i;
	}
	qsort(&ans[1],ans_num,sizeof(ans[1]),cmp);
	fout << "0/1" << endl;
	for (int i=1;i<=ans_num;i++) fout << ans[i].e << '/' << ans[i].d << endl;
	fout << "1/1" << endl;
	fin.close();
	fout.close();
	return 0;
}
bool check(int a,int b) {
	int upperbound = (int)sqrt(  static_cast<float>(a) ) + 1;
	for (int i=2; i<=a; i++) if (a%i==0 && b%i==0) return false;
	return true;
}
int cmp(const void* a,const void* b) {
	frac x=*(frac*)a,y=*(frac*)b;
	return double(x.e)/x.d>double(y.e)/y.d?1:-1;
}

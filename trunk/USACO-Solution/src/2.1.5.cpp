/*
ID: zinking1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sort3.in");
ofstream fout("sort3.out");

#ifdef _NDEBUG
#define out cout
#define in cin
#else
#define out fout
#define in fin
#endif
  
// sum[i]：i的最终位置为sum[i-1]->sum[i]之间
int sum[4];
// cnt[i][j] i位置上j的数目
int cnt[4][4]; 
//存储原始输入数据
int data[1000];

//排好序后，第i个位置应该是什么数
int get_num(int i)
{
	if(i<=sum[1]) return 1;
	else if(i<=sum[2]) return 2;
	else return 3;
}

void solve()
{
	int n;
	in>>n;

	int tmp;

	for(int i=0;i<n;++i){
		in>>data[i];
		sum[ data[i] ] ++;
	}

	sum[2]+=sum[1];
	sum[3]+=sum[2];

	for(int i=0;i<n;++i){
		cnt[get_num(i+1)][data[i]]++;
	}

	int res = 0;

	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(i==j) continue;
			tmp = min(cnt[i][j],cnt[j][i]);
			cnt[i][j]-=tmp;
			cnt[j][i]-=tmp;
			res+=tmp;
		}
	}

	res+=min(cnt[2][3],min(cnt[3][1],cnt[1][2]))*2;
	res+=min(cnt[2][1],min(cnt[3][2],cnt[1][3]))*2;

	out<<res<<endl;
}

int main(int argc,char *argv[])
{
	solve(); 
	return 0;
}
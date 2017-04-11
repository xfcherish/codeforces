#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn = (1000)+10;
int n,a[maxn];

bool judge(int m) {
	int t = m/8;
	int r = m%8;
	vector<int> v;
	for(int i = 1; i <= 8; i++) v.push_back(i);
	do{
		
	}next_permutation(v.begin(),v.end());
}

int main()
{
	int low,high,mid;
	cin >> n;
	for(int i = 1; i <= n; i++)  scanf("%d",&a[i]);
	low = 1;
	high = n;
	while(low < high) {
		mid = (low + high)/2;
		if(judge(mid) == false) high = mid;
		else  low = mid+1;
	}
	low--;
	cout << low << endl;
	return 0;
}
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

const int maxn = (1e6)+10;
char s[maxn];
int nxtD[maxn],preU[maxn],n;
int cntD[maxn],cntU[maxn];
LL ans[maxn];
LL sd[maxn],su[maxn];


int main()
{
	scanf("%d",&n);
	scanf("%s",&s[1]);
	int last = -1;
	for(int i = n; i >= 1; i--) {
		nxtD[i] = last;
		if(s[i] == 'D') last = i;
	}
	last = -1;
	for(int i = 1; i <= n; i++) {
		preU[i] =last;
		if(s[i] == 'U') last = i;
	}
	int U,D;
	U =  D = 0;
	for(int i = 1; i <= n; i++) {
		cntU[i] = U;
		if(s[i] == 'U') U++;
	}
	for(int i = n; i >= 1; i--) {
		cntD[i] = D;
		if(s[i] == 'D') D++;
	}
	sd[0] = su[0] = 0;
	int countd,countu;
	countu = countd = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'U') {
			su[countu+1] = su[countu] + i;
			countu++;
		}
		else if(s[i] == 'D') {
			sd[countd+1] = sd[countd] + i;
			countd++;
		}
	}
	cout << "D = " << D << endl;
	cout << "U = " << U << endl;
	for(int i = 1; i <= n; i++) {
		cout << "cntU[" << i << "]=" << cntU[i] << endl;
		cout << "cntD[" << i << "]=" << cntD[i] << endl;
		if(cntU[i] > cntD[i]) {
			ans[i] = (sd[D]-sd[D-cntD[i]]-1LL*cntD[i]*i)*2;
			cout << "ans[" << i << "]=" << ans[i] << endl;
			ans[i] += (1LL*(cntD[i]+1)*i - (su[cntU[i]]-su[cntU[i]-cntD[i]-1]))*2;
			cout << "ans[" << i << "]=" << ans[i] << endl;
			ans[i] += (n+1-i);
			cout << "ans[" << i << "]=" << ans[i] << endl;
		}
		else if(cntU[i] < cntD[i]) {
			ans[i] = (sd[D-cntD[i]+cntU[i]+1]-sd[D-cntD[i]]-1LL*(cntU[i]+1)*i)*2;
			cout << "ans[" << i << "]=" << ans[i] << endl;
			ans[i] += (1LL*cntU[i]*i - (su[cntU[i]]))*2;
			cout << "ans[" << i << "]=" << ans[i] << endl;
			ans[i] += i;
			cout << "ans[" << i << "]=" << ans[i] << endl;
		}
		else {
			ans[i] = (sd[D]-sd[D-cntD[i]]-1LL*cntD[i]*i)*2;
			ans[i] += (1LL*cntU[i]*i - (su[cntU[i]]))*2;
			if(s[i] == 'U') ans[i] += (n+1-i);
			if(s[i] == 'D') ans[i] += (i);
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
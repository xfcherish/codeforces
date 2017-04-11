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

typedef long long ll;
typedef pair<int,int> PII;

const int maxn = (2e5)+10;


ll mypow(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%m;
    ll temp=mypow(a,b/2,m);
    temp*=temp;
    temp%=m;
    if(b&1)
        temp*=a;
    temp%=m;
    return temp;
}
bool Miller_Rabbin(ll x)
{
    if(x==2)
        return true;      
    for(int i=1;i<=50;++i){
        ll a=rand()%(x-2)+2;
        if(mypow(a,x-1,x)!=1)
            return false;
    }
    return true;
}


int main()
{
	int n;
	cin >> n;
	if(Miller_Rabbin(n)) {
		cout << 1 << endl;
	}
	else {
		if(n % 2 == 0) cout << 2 << endl;
		else {
			if(Miller_Rabbin(n-2)) cout << 2 << endl;
			else cout << 3 << endl;
		}
	}
	return 0;
}



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

const int maxn = (2e5)+10;
LL a[maxn];
int n,k,x;
struct one {
    int pos;
    LL val;
    one(int _pos, LL _val): pos(_pos),val(_val) {}
    /* data */
};
 struct cmp{
    bool operator() (const one & s1, const one & s2) {
        return fabs(s1.val) > fabs(s2.val);
    }
};
priority_queue<one, vector<one>, cmp> que;

int main()
{
    int i;
    int tag = 1;  
    cin >> n >> k >> x;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        que.push(one(i,a[i]));
        if(a[i] < 0) tag = 1-tag;
    }
    while(k--) {
        one u = que.top();
        que.pop();
        if(tag == 1) {
            if(u.val >= 0) { 
                u.val -= x;
                if(u.val < 0) 
                    tag = 1-tag;
            }
            else {
                u.val += x;
                if(u.val >= 0) 
                    tag = 1-tag;
            }
        }
        else {
            if(u.val < 0) u.val -= x;
            else u.val += x;
        }
        a[u.pos] = u.val;
        que.push(u);
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
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

const int maxn = (1e5)+10;

vector<int> x,y;
int n;

void print(int i1, int i2, int i3, int i4) {
	cout << "? " << i1 << " " << i2 << " " << i3 << " " << i4;
	cout << flush << endl;
}

int low_s(bool tag, bool tag2,  int value, int low, int high) {
    int mid,res;
    while(low < high) {
        mid = low + (high-low)/2;
        if(tag == 0 )  {
            if(tag2 == 0) print(1,1,mid,n);
            else print(mid,1,n,n);
        }
        else {
            if(tag2 == 0) print(1,1,n,mid);
            else print(1,mid,n,n);
        }
        cin >> res;
        if(res >= value) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main()
{
	cin >> n;
    int low = low_s(0,1,2,1,n);
    x.push_back(low);

    low = low_s(0,0,1,x[0],n);
    x.push_back(low);

    low = low_s(0,1,1,1,n);
    x.push_back(low);

    low = low_s(0,0,1,x[2],n);
    x.push_back(low);


    low = low_s(1,1,2,1,n);
    y.push_back(low);

    low = low_s(1,0,1,y[0],n);
    y.push_back(low);

    low = low_s(1,1,1,1,n);
    y.push_back(low);

    low = low_s(1,0,1,y[2],n);
    y.push_back(low);

    int res1,res2;
    print(x[0],y[0],x[1],y[1]);
    cin >> res1;
    print(x[2],y[2],x[3],y[3]);
    cin >> res2;
    if(res1 == 1 && res2 == 1) 
        printf("! %d %d %d %d %d %d %d %d\n",x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
	else 
        printf("! %d %d %d %d %d %d %d %d\n",x[0],y[2],x[1],y[3],x[2],y[0],x[3],y[1]);
    return 0;
}






#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

# define pb push_back
# define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;

const int maxn =  105;

typedef double db;

struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator+(P p) { return P(x + p.x, y + p.y); }
    P operator-(P p) { return P(x - p.x, y - p.y); }
    P operator*(db d) { return P(x * d, y * d); }
    P operator/(db d) { return P(x / d, y / d); }
    db dot(P p) { return x * p.x + y * p.y; }
    db det(P p) { return x * p.y - y * p.x; }
    db distTo(P p) { return (*this-p).abs(); }
    db alpha() { return atan2(y, x); }
    void read() { cin>>x>>y; }
    db abs() { return sqrt(abs2());}
    db abs2() { return x * x + y * y; }
    P rot90() { return P(-y,x);}
    P unit() { return *this/abs(); }
};
  
P proj(P p1, P p2, P q) {
    P dir = p2 - p1;
    return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}
 
int n;
vector<P> points;

int main()
{
	cin >> n;  points.resize(n);
	for(int i = 0; i < n; i++)
		points[i].read();	
	double ans = (1e100);
	for(int i = 0; i < n; i++) {
		P p1 = points[i];
		P p2 = points[(i+1)%n];
		P p3 = points[(i+2)%n];
		P q = proj(p1,p3,p2);
		ans = min(ans, 0.5*p2.distTo(q));
	}
	printf("%.10lf\n",ans);
	return 0;
}
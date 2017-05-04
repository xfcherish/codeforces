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
typedef pair<int,int> pii;

const int maxn = (2e5)+10;
const double eps = (1e-8);
const double inf = (1e20);

int cmp(double x) {
	if(fabs(x) < eps) return 0;
	if(x > 0) return 1;
	return -1;
}

struct point {
	double x,y;
	point() {}
	point(double a, double b): x(a),y(b) {}
	friend point operator - (const point & a, const point & b) {
		return point(a.x - b.x , a.y - b.y);
	}
	friend point operator * (const point & a, const double & b) {
		return point(a.x * b, a.y * b);
	}
	friend point operator / (const point & a, const double & b) {
		return point(a.x/b , a.y/b);
	}
};

double det(const point & a, const point & b) {
	return a.x * b.y - a.y * b.x;
}
double dot(const point & a, const point & b) {
	return a.x * b.x + a.y*b.y;
}

struct line {
	point a,b;
	line() {}
	line(point x, point y): a(x),b(y) {}
	/* data */
};

bool parallel(line a, line b) {
	return !cmp(det(a.a-a.b, b.a-b.b));
}

bool line_make_point(line a, line b, point & res) {
	if(parallel(a,b)) return false;
	double s1 = det(a.a - b.a , b.b - b.a);
	double s2 = det(a.b - b.a , b.b - b.a);
	res = (a.b*s1 - a.a*s2)/(s1-s2);
	return true;
}

bool PointOnSegment(point p, point s, point t) {
	return cmp(det(p-s,t-s)) == 0 && cmp(dot(p-s,p-t)) <= 0;
}

vector<double> t[maxn];
double tmax[maxn],tmin[maxn];

int main()
{
	// freopen("input.txt","r",stdin);
	int n; 
	line rec[4];
	point res;
	cin >> n;
	double x1,y1,x2,y2,rx,ry,vx,vy;
	cin >> x1 >> y1 >> x2 >> y2;
	rec[0] = line(point(x1,y1), point(x1,y2));
	rec[1] = line(point(x1,y2), point(x2,y2));
	rec[2] = line(point(x2,y1), point(x2,y2));
	rec[3] = line(point(x1,y1), point(x2,y1));
	for(int i = 0; i < n; i++) {
		cin >> rx >> ry >> vx >> vy;
		line cur = line(point(rx,ry), point(rx+vx, ry+vy));
		for(int j = 0; j < 4; j++) {
			bool tag = line_make_point(cur, rec[j], res);
			if(tag) {
				if(PointOnSegment(res,rec[j].a, rec[j].b)) {
					// cout << "here" << endl;
					// cout << " i = " << i << " j = " << j <<  endl;
					// cout << "res.x = " << res.x << " res.y = " << res.y << endl;
					double tmp = (res.x - rx)*1.0/vx;
					// cout << "tmp = " << tmp << endl;
					t[i].push_back(tmp);
				}
			}
		}
	}
	// for(int i = 0; i < n; i++) {
	// 	cout << "point  " << i << " : ";
	// 	for(int j = 0; j < t[i].size(); j++) {
	// 		cout << t[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int i = 0; i < n; i++) {
		if(t[i].size() == 0) {
			cout << -1 << endl;
			return 0;
		}
		sort(t[i].begin(),t[i].end());
		if(t[i][0] < -1) {
			cout << -1 << endl;
			return 0;
		}
		tmax[i] = t[i][t[i].size()-1];
		tmin[i] = t[i][0];
	}
	double ct1,ct2;
	ct1 = tmin[0];
	ct2 = tmax[0];
	for(int i = 1; i < n; i++) {
		if(ct2 < tmin[i] || ct1 > tmax[i]) {
			cout << -1 << endl;
			return 0;
		}
		else {
			ct1 = max(ct1, tmin[i]);
			ct2 = min(ct2, tmax[i]);
		}
	}
	printf("%.8lf\n",ct1);
	return 0;
}
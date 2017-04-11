#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxn = (1e5)+10;

struct node {
	char c;
	int x,y;
	/* data */
};
node nxt[10];

bool judge() {
	for(int i = 1; i <= 8; i++) {
		//cout << "i = " << i << " nxt = " << nxt[i].c << endl;
		if(nxt[i].c == 'Q') return false;
		if(i % 2 == 1) {
			if(nxt[i].c == 'B') return false;
		}
		else {
			if(nxt[i].c == 'R') return false;
		}
	}
	return true;
}

int main()
{
	//freopen("input.txt","r",stdin);
	char c;
	int xx,yy,x0,y0,n;
	cin >> n >> x0 >> y0;
	for(int i = 1; i <= 8; i++) {
		nxt[i].c = 'n';
	}
	for(int i = 1; i <= n; i++) {
		scanf("\n");
		scanf("%c %d %d", &c, &xx, &yy);
		//cout << "c = " << c << " xx = " << xx << " yy = " << yy << endl;
		if(x0 == xx) {
			if(yy > y0) {
				if(nxt[2].c == 'n') {
					nxt[2].c = c;
					nxt[2].x = xx;
					nxt[2].y = yy;
				}
				else if(nxt[2].y > yy ){
					nxt[2].c = c;
					nxt[2].y = yy;
				}
			}
			if(yy < y0) {
				if(nxt[6].c == 'n') {
					nxt[6].c = c;
					nxt[6].x = xx;
					nxt[6].y = yy;
				}
				else if(nxt[6].y < yy ){
					nxt[6].c = c;
					nxt[6].y = yy;
				}
			}
		}
		else if(y0 == yy) {
			if(xx > x0) {
				if(nxt[4].c == 'n') {
					nxt[4].c = c;
					nxt[4].x = xx;
					nxt[4].y = yy;
				}
				else if(nxt[4].x > xx){
					nxt[4].c = c;
					nxt[4].x = xx;
				}
			}
			if(xx < x0) {
				if(nxt[2].c == 'n') {
					nxt[2].c = c;
					nxt[2].x = xx;
					nxt[2].y = yy;
				}
				else if(nxt[2].x < xx){
					nxt[2].c = c;
					nxt[2].x = xx;
				}
			}
		}
		else if((x0-y0) == (xx-yy)) {
			if(xx > x0) {
				if(nxt[3].c == 'n' || nxt[3].x > xx) {
					nxt[3].c = c;
					nxt[3].x = xx;
					nxt[3].y = yy;
				}
			}
			if(xx < x0) {
				if(nxt[7].c == 'n' || nxt[7].x < xx) {
					nxt[7].c = c;
					nxt[7].x = xx;
					nxt[7].y = yy;
				}
			}
		}
		else if((x0+y0) == (xx+yy)) {
			if(xx > x0) {
				if(nxt[5].c == 'n' || nxt[5].x > xx) {
					nxt[5].c = c;
					nxt[5].x = xx;
					nxt[5].y = yy;
				}
			}
			if(xx < x0) {
				if(nxt[1].c == 'n' || nxt[1].x < xx) {
					nxt[1].c = c;
					nxt[1].x = xx;
					nxt[1].y = yy;
				}
			}
		}
	}
	//cout << "hehe" << endl;
	if(judge() == true) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}


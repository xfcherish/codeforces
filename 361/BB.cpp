#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 200010;
const int inf = 200010;
int a[maxn],dist[maxn];
int n;

struct node {
	int pos;
	int dist;
	/* data */
};

void bfs() {
	int cur,next;
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		next = cur - 1;
		if(next > 0 && next <= n && dist[next] > dist[cur]+1) {
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
		next = cur + 1;
		if(next > 0 && next <= n && dist[next] > dist[cur]+1) {
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
		next = a[cur];
		if(next > 0 && next <= n && dist[next] > dist[cur]+1) {
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}	
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);	
		dist[i] = inf;
	}
	bfs();
	for(int i = 1; i <= n; i++) {
		printf("%d ",dist[i]);
	}
	cout << endl;
	return 0;
}
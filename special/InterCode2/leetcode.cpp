#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define pb push_back


int vis1[155][155],vis2[155][155];
vector<vector<int> > a;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n;
bool judge(int x, int y) {
   // cout << " m = " << m << " n = " << n << endl;
    if(x >= 0 && x < m && y >= 0 && y < n) return true;
    return false;
}

void dfs1(int i, int j) {
    vis1[i][j] = 1;
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(judge(x,y) && a[i][j] <= a[x][y]) 
            if(vis1[x][y] == 0)
                dfs1(x,y); 
    }
}
void dfs2(int i, int j) {
    vis2[i][j] = 1;
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(judge(x,y) && a[i][j] <= a[x][y]) 
            if(vis2[x][y] == 0)
                dfs2(x,y); 
    }
}

vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    vector<pair<int,int> > ans;
    a = matrix;
    m = matrix.size();
    if(m == 0) return ans;
    n = matrix[0].size();
    if(n == 0) return ans;
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    for(int i = 0 ; i < m; i++) {
        // vis1[i][0] = 1;
        // vis2[i][n-1] = 1;
        dfs1(i,0);
        dfs2(i,n-1);
    }
    for(int i = 0; i < n; i++) {
        // vis1[0][i] = 1;
        // vis2[m-1][i] = 1;
        dfs1(0,i);
        dfs2(m-1,i);
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // cout << "1 --- [" << i << "][" << j << "]=" << vis1[i][j] << endl;
            // cout << "2 --- [" << i << "][" << j << "]=" << vis2[i][j] << endl;
            if((vis1[i][j] == 1) && (vis2[i][j] == 1)) {
                ans.push_back(make_pair(i,j));
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int> > matrix;
    vector<int> v;
    v.clear();
    v.pb(1); v.pb(2);  v.pb(2);  v.pb(3);  v.pb(5); 
    matrix.push_back(v);
    v.clear();
    v.pb(3); v.pb(2);  v.pb(3);  v.pb(4);  v.pb(4); 
    matrix.push_back(v);
    v.clear();
    v.pb(2); v.pb(4);  v.pb(5);  v.pb(3);  v.pb(1); 
    matrix.push_back(v);
    v.clear();
    v.pb(6); v.pb(7);  v.pb(1);  v.pb(4);  v.pb(5); 
    matrix.push_back(v);
    v.clear();
    v.pb(5); v.pb(1);  v.pb(1);  v.pb(2);  v.pb(4); 
    matrix.push_back(v);
    vector<pair<int, int> > ans  = pacificAtlantic(matrix);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}

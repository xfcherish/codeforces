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
bool vis[155][155];
vector<vector<int> > a;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n;
bool judge(int x, int y) {
   // cout << " m = " << m << " n = " << n << endl;
    if(x >= 0 && x < m && y >= 0 && y < n) return true;
    return false;
}
bool dfs1(int i, int j) {
   // cout << "i = " << i << " j = " << j << endl;
    vis[i][j] = 1;
    if(vis1[i][j] != -1) return vis1[i][j];
    bool tag = 0;
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(judge(x,y)) {
           // if(vis[x][y] == 0) dfs1(x,y);
            if(a[i][j] >= a[x][y]) {
                if(vis[x][y] == 0) dfs1(x,y);
                if(i == 1 && j == 4) {
                    cout << "x = " << x << " y = " << y << endl;
                    cout << "vis[x][y] = " << vis[x][y] << endl;
                    cout << "vis1[x][y] = " << vis1[x][y] << endl;
                }
              //  if(vis[x][y] == 0) dfs1(x,y);
                if(vis1[x][y] == 1) tag = 1;
            }
        }
    }
    vis1[i][j] = tag;
  //  if(i == 1 && j == 3) cout << "vis1[1][3] = " << vis1[i][j] << endl;
    return tag;
}

bool dfs2(int i, int j) {
    vis[i][j] = 1; 
    if(vis2[i][j] != -1) return vis2[i][j];
    bool tag = false;
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(judge(x,y)) {
             if(a[i][j] >= a[x][y]) {
                if(vis[x][y] == 0) dfs2(x,y);
               // if(vis[x][y] == 0) dfs2(x,y);
                if(vis2[x][y] == 1) tag = 1;
            }
        }
    }
    vis2[i][j] = tag;
    return tag;
}
vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    vector<pair<int,int> > ans;
    a = matrix;
    m = matrix.size();
    if(m == 0) return ans;
    n = matrix[0].size();
    if(n == 0) return ans;
    memset(vis1, -1, sizeof(vis1));
    memset(vis2, -1, sizeof(vis2));
    for(int i = 0 ; i < m; i++) {
        vis1[i][0] = 1;
        vis2[i][n-1] = 1;
    }
    for(int i = 0; i < n; i++) {
        vis1[0][i] = 1;
        vis2[m-1][i] = 1;
    }
    memset(vis, 0 , sizeof(vis));
    for(int i = 0 ; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dfs1(i,j);
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i = 0 ; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dfs2(i,j);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "1 --- [" << i << "][" << j << "]=" << vis1[i][j] << endl;
            cout << "2 --- [" << i << "][" << j << "]=" << vis2[i][j] << endl;
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

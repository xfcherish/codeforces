#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

map<pair<LL,LL>,LL> m;

vector<LL> get_root(LL u) {
	vector<LL> res;
	while( u != 1) {
		// cout << "u = " << u << endl;
		res.push_back(u);
		u /= 2;
	}
	res.push_back(1LL);
	reverse(res.begin(), res.end());
	// cout << " u = " << u << endl;
	// for(int i = 0; i < res.size(); i++)
	// 	cout << res[i] << " ";
	// cout << endl;
	return res;
}

vector<LL> merge_path(vector<LL> path1, vector<LL> path2) {
	vector<LL> res;
	LL gca;
	for(int i = 0, j = 0; i < path1.size() && j < path2.size();) {
		if(path1[i] == path2[j]) {
			gca = path1[i];
			i++;
			j++;
		}
		else break;
	}
	// cout << "gca = " << gca << endl;
	for(int i = path1.size()-1; i >= 0; i--) {
		res.push_back(path1[i]);
		if(path1[i] == gca) 
			break;
	}
	bool start = false;
	for(int i = 0 ; i < path2.size(); i++) {
		if(start) res.push_back(path2[i]);
		if(path2[i] == gca) {
			start = true;
		} 
	}
	// cout << "common_path :" << endl; 
	// for(int i = 0; i < res.size(); i++)
	//  	cout << res[i] << " ";
	// cout << endl;
	return res;
}

int main()
{	
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	LL q,u,v,w;
	int type;
	cin >> q;
	while(q--) {
		cin >> type;
		if(type == 1) { 
			cin >> u >> v >> w;
			vector<LL> path1,path2,common_path;
			path1 = get_root(u);
			path2 = get_root(v);
			common_path = merge_path(path1,path2);
			for(int i = 0; i+1 < common_path.size(); i++) {
				LL tmp_a = common_path[i];
				LL tmp_b = common_path[i+1];
				m[pair<LL,LL> (tmp_a,tmp_b)] += w;
				m[pair<LL,LL> (tmp_b,tmp_a)] += w;
			}
			// cout << "tpye = 1" << endl;
			// cout << " u = " << u << " v = " << v << endl;
			// cout << "path 1 :" << endl; 
			// for(int i = 0 ; i < path1.size(); i++) {
			// 	cout << path1[i] << " ";
			// }
			// cout << endl;
			// cout << "path 2 :" << endl; 
			// for(int i = 0 ; i < path2.size(); i++) {
			// 	cout << path2[i] << " ";
			// }
			// cout << endl;
			// cout << "common_path :" << endl; 
			// for(int i = 0; i < common_path.size(); i++) {
			// 	cout << common_path[i] << " ";
			// } 
			// cout << endl << endl << endl;
		}
		else if(type == 2) {
			cin >> u >> v;
			vector<LL> path1,path2,common_path;
			path1 = get_root(u);
			path2 = get_root(v);
			common_path = merge_path(path1,path2);
			LL ans = 0;
			for(int i = 0; i+1 < common_path.size(); i++) {
				LL tmp_a = common_path[i];
				LL tmp_b = common_path[i+1];
				// cout << "m[" << tmp_a << "," << tmp_b << "]="
					// << m[pair<LL,LL> (tmp_a,tmp_b)] << endl;
				ans += m[pair<LL,LL> (tmp_a,tmp_b)];
			}
			// cout << "tpye = 2" << endl;
			// cout << " u = " << u << " v = " << v << endl;
			// cout << "path 1 :" << endl; 
			// for(int i = 0 ; i < path1.size(); i++) {
			// 	cout << path1[i] << " ";
			// }
			// cout << endl;
			// cout << "path 2 :" << endl; 
			// for(int i = 0 ; i < path2.size(); i++) {
			// 	cout << path2[i] << " ";
			// }
			// cout << endl;
			// cout << "common_path :" << endl; 
			// for(int i = 0; i < common_path.size(); i++) {
			// 	cout << common_path[i] << " ";
			// } 
			// cout << endl;
			// cout << "ans = " << ans << endl;
			// cout << endl << endl << endl;
			
			cout << ans << endl;
		}
	}
	return 0;
} 
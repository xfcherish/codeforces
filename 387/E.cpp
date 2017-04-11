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

const int maxn = (1e6)+10;

vector<string> ans[maxn];
vector<string> v;
int cur,res,n;

vector<string> split(string s){
	vector<string> result;
	int n = s.length();
	for(int i = 0; i < n;  ) {
		string str;
		while(s[i] != ',' && i < n) {
			str += s[i];
			i++;
		}
		result.push_back(str);
		i++;
	}
	return result;
}

int str2num(string str) {
	int num = 0;
	for(int i = 0; i < str.length(); i++) {
		num *= 10;
		num += (str[i] - '0');
	}
	return num;
}

void dfs(int dep) {
	if(cur >= n ) return;
	string word = v[cur];
	if(word.size() == 0) {
		cur = n + 1;
		return;
	}
	int num = str2num(v[cur+1]);
	ans[dep].push_back(word);
	res = max(res,dep);
	cur += 2;
//	cout << "word = " << word << " dep = " << dep << endl;
	for(int i = 0 ; i < num; i++) 
		dfs(dep+1);
}

int main()
{
	// freopen("input.txt","r",stdin);
	int num,dep,cnt;
	string s;
	cin >> s;
	v = split(s);
	n = v.size();
	cur = 0;
	res = 0;
	while(1) {
		if(cur >= n) break;
		dfs(1);
	}
	cout << res << endl;
	for(int i = 1; i <= res; i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
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

int n,k;
map<string,vector<int> > m;
vector<int> num1,num2;

int main()
{
	// freopen("input.txt","r",stdin);
	string s,s2,s3;
	int b;
	cin >> n >> k;
	for(int i = 0 ; i < n; i++) {
		cin >> s >> b;
		m[s].push_back(b);
	}	
	map<string,vector<int> >::iterator it;
	long long ans = 0;
	int max_val = 0;
	for(it = m.begin(); it != m.end(); it++) {
		s2 = it->first;
		vector<int> v = it->second;
		s3 = s2;
		reverse(s3.begin(), s3.end());
		if(s2 == s3) {
			sort(v.begin(), v.end(), greater<int>());
			int tmp1 = 0;
			int tmp2 = 0;
			int len = v.size();
			if(len == 0) continue;
			for(int i = 0; i+1 < len; i+=2) {
				if(v[i]+v[i+1] > 0) {
					tmp1 += (v[i]+v[i+1]);
				}
			}
			tmp2 += v[0];
			for(int i = 1; i+1 < len; i+=2) {
				if(v[i]+v[i+1] > 0) tmp2 += (v[i]+v[i+1]);
			}
			num1.push_back(tmp1);
			num2.push_back(tmp2);
		}
		else {
			map<string,vector<int> >::iterator it2 = m.find(s3);
			vector<int> v2 = it2->second;
			if(v2.size() != 0) {
				sort(v.begin(), v.end(), greater<int>());
				sort(v2.begin(), v2.end(), greater<int>());
				int len1 = v.size();
				int len2 = v2.size();
				// cout << "len1 = " << len1 << " len2 = " << len2 << endl;
				for(int i = 0, j = 0; i < len1 && j < len2; i++,j++) {
					// cout << "v[" << i << "]=" << v[i] << endl;
					// cout << "v2[" << j << "]=" << v2[j] << endl;
					if(v[i] + v2[j] > 0) {
						ans += (v[i]+v2[j]);
					}
					else break;
				}
				it->second.clear();
				it2->second.clear();
			}
		}
		// cout << "s2 = " << s2 << endl;
		// cout << "s3 = " << s3 << endl;
		// cout << "ans = " << ans << endl;
	}
	long long sum = 0;
	int max_single = 0;
	for(int i = 0; i < num1.size(); i++) sum += num1[i];
	for(int i = 0; i < num2.size(); i++) {
		max_single = max(max_single, num2[i] - num1[i]);
	}
	cout << ans+sum+max_single << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

pair<int,int> PII;

int n,ans,total;
string s;
int all[52];

int tran(char c) {
	if(c <= 'Z' && c >= 'A')
		return (c-'A'+26);
	if(c <= 'z' && c >= 'a')
		return (c-'a');
	return -1;
}

bool judge(int len) {
	int elements[52];
	memset(elements, 0, sizeof(elements));
	for(int i = 0; i < len; i++) 
		elements[tran(s[i])]++;
	int tmp_total = 0;
	for(int j = 0; j < 52; j++) {
		if(elements[j] > 0) tmp_total++;
	}
	if(tmp_total == total) return true;
	for(int i = 1; i + len - 1 < n; i++) {
		elements[tran(s[i-1])]--;
		elements[tran(s[i+len-1])]++; 
		int tmp = 0;
		for(int j = 0; j < 52; j++) {
			if(elements[j] > 0) tmp++;
		}
		if(tmp == total) 
			return true; 
	}
	return false;
}

int main()
{
	cin >> n >> s;
	total = 0;
	for(int i = 0; i < s.length(); i++) {
		all[tran(s[i])]++;
	}
	for(int i = 0; i < 52; i++)
		if(all[i] > 0) total++;
	int low = 1;
	int high = n;
	int mid;
	while(low < high) {
		// cout << "low = " << low << endl;
		// cout << "high = " << high << endl;
		mid = (low + high)/2;
		// cout << "mid = " << mid << endl;
		// cout << "judge(" << mid << ")=" << judge(mid) << endl;
		if(judge(mid) == false) 
			low = mid+1;
		else high = mid;
	}
	cout << low << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
string s,t;
int len_s,len_t, ans;
vector<PII> answers;
int dp[2200];

vector<int> find_substring(string pattern, string text) {
    int n = pattern.size();
    vector<int> next(n+1,0);
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0) {
            j = next[j];
            if(pattern[j] == pattern[i]) {
                next[i+1] = j+1;
                break;
            }
        }
    }
    vector<int> positions;
    int m = text.size();
    for(int i = 0, j = 0; i < m; i++) {
        if(j < n && text[i] == pattern[j]) {
            j++;
        } else {
            while(j > 0) {
                j = next[j];
                if(text[i] == pattern[j]) {
                    j++;
                    break;
                }
            }
        }
        if(j == n) {
            positions.push_back(i-n+1);
        }
    }
    return positions;
}

void DP(int pos, vector<PII> cur) {
    if(cur.size() > ans) return;
    if(pos >= len_t) {
        if(ans > cur.size()) {
            ans = cur.size();
            answers = cur;
        }
        return;
    }
    for(int i = len_t - 1; i >= pos; i--) {
        string pattern = t.substr(pos,i-pos+1);
        vector<int> positions = find_substring(pattern,s);
        if(positions.size() > 0) {
            int loc = positions[0];
            vector<PII> nxt = cur;
            nxt.push_back(make_pair(loc,loc+pattern.size()-1));
            DP(pos+pattern.size(), nxt);
            continue;
        }
        string pattern2 = pattern;
        reverse(pattern2.begin(), pattern2.end());
        vector<int> positions2 = find_substring(pattern2,s);
        if(positions2.size() > 0) {
            int loc = positions2[0];
            vector<PII> nxt = cur;
            nxt.push_back(make_pair(loc+pattern.size()-1,loc));
            DP(pos+pattern.size(), nxt);
            continue;
        }
    }

}

int main()
{
	cin >> s >> t;
    len_s = s.length();
    len_t = t.length();
    vector<PII> results; 
    ans = 2200;
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < len_t; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] != -1) {
                 string pattern = t.substr(j,i-j+1);
                 vector<int> positions = find_substring(pattern,s);
                 if(positions.size() > 0) {
                    int loc = positions[0];
                    vector<PII> nxt = cur;
                    nxt.push_back(make_pair(loc,loc+pattern.size()-1));
                    DP(pos+pattern.size(), nxt);
                    continue;
                }
                   string pattern2 = pattern;
                   reverse(pattern2.begin(), pattern2.end());
                   vector<int> positions2 = find_substring(pattern2,s);
                   if(positions2.size() > 0) {
                       int loc = positions2[0];
                       vector<PII> nxt = cur;
                       nxt.push_back(make_pair(loc+pattern.size()-1,loc));
                       DP(pos+pattern.size(), nxt);
                       continue;
        }
            }
        }
    }
    if(ans == 2200) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    for(int i = 0; i < answers.size(); i++) 
        cout << 1+answers[i].first << " " << 1+answers[i].second << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char c[1000][1000];
int k;
void solve(int n) 
{
	if(n == k+1) return;
	int now_cnt = (1<<n);
	int pre_cnt = now_cnt/2;
    for(int i = 1; i <= pre_cnt; i++) {
    	for(int j = pre_cnt+1; j <= now_cnt; j++) {
    		c[i][j] = c[i][j-pre_cnt];
    	}
    }
    for(int i = pre_cnt+1; i <= now_cnt; i++) {
    	for(int j = 1; j <= pre_cnt; j++) {
    		c[i][j] = c[i-pre_cnt][j];
    	}
    	for(int j = pre_cnt+1; j <= now_cnt; j++) {
    		if(c[i][j-pre_cnt] == '+')
    			c[i][j] = '*';
    		if(c[i][j-pre_cnt] == '*')
    			c[i][j] = '+';
    	}
    }
    solve(n+1);
    return;
}

int main()
{
	c[1][1] = '+';
	cin >> k;
	solve(1);
	for(int i = 1; i <= (1<<k); i++) {
		for(int j = 1; j <= (1<<k); j++) {
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
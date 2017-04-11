#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
int a[600][600];
using namespace std;

int main()
{
    int n, m, i, j, cnt =0, a1, a2, b1, b2, flag = 0;
    scanf("%d%d\n", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            char c = getchar();
            if(c == '.')a[i][j] = 1;
            if(c == 'X'){
                a[i][j] = 2;
                cnt++;
            }
        }
        getchar();
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(a[i][j] == 2){
                for(a1 = j; a[i][a1] == 2; a1++);
                for(a2 = i; a[a2][j] == 2; a2++);
                for(b1 = i; b1 < a2; b1++){
                    for(b2 = j; b2 < a1; b2++){
                        if(a[b1][b2] == 2)cnt--;
                    }
                }
                flag = 1;
                break;
            }
        }
        if(flag)break;
    }
    if(cnt == 0)printf("YES\n");
    else printf("NO\n");
    return 0;
}






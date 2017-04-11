#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define maxn 1000000002
int x[15];
int y[15];
char type0, type1, type2, type3, type4, type5, type6, type7;

int main()
{
    int x1, y1, x0, y0;
    int i, n;
    char Type;
    y[0] = maxn;
    y[1] = -maxn;
    x[2] = -maxn;
    x[3] = maxn;
    x[4] = -maxn;
    y[4] = maxn;
    x[5] = maxn;
    y[5] = -maxn;
    x[6] = maxn;
    y[6] = maxn;
    x[7] = -maxn;
    y[7] = -maxn;
    char c;
    scanf("%d", &n);
    scanf("%d%d\n", &x0, &y0);
    for(i = 0; i < n; i++){
        getchar();
        scanf("%c %d %d", &Type, &x1, &y1);
        if(x1 == x0){
            if(y1 > y0 && y1 < y[0]){
                x[0] = x1;
                y[0] = y1;
                type0 = Type;
            }
            if(y1 < y0 && y1 > y[1]){
                x[1] = x1;
                y[1] = y1;
                type1 = Type;
            }
        }
        if(y1 == y0){
            if(x1 < x0 && x1 > x[2]){
                x[2] = x1;
                y[2] = y1;
                type2 = Type;
            }
            if(x1 > x0 && x1 < x[3]){
                x[3] = x1;
                y[3] = y1;
                type3 = Type;
            }
        }
        if((x1 - x0) == (y1 - y0) || (x1 - x0) == (y0 - y1)){
            if(x1 < x0 && y1 > y0 && x1 > x[4] && y1 < y[4]){
                x[4] = x1;
                y[4] = y1;
                type4 = Type;
            }
            if(x1 > x0 && y1 < y0 && x1 < x[5] && y1 > y[5]){
                x[5] = x1;
                y[5] = y1;
                type5 = Type;
            }
            if(x1 > x0 && y1 > x0 && x1 < x[6] && y1 < y[6]){
                x[6] = x1;
                y[6] = y1;
                type6 = Type;
            }
            if(x1 < x0 && y1 < x0 && x1 > x[7] && y1 > y[7]){
                x[7] = x1;
                y[7] = y1;
                type7 = Type;
            }
        }
    }
    if(type0 == 'R' || type1 == 'R' || type2 == 'R' || type3 == 'R' || type4 == 'B' || type5 == 'B' || type6 == 'B' || type7 == 'B' || type0 == 'Q' || type1 == 'Q' || type2 == 'Q' || type3 == 'Q' || type4 == 'Q' || type5 == 'Q' || type6 == 'Q' || type7 == 'Q')
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
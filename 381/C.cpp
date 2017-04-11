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

const int MAXN = (1e5)+10;
const int INF = (1e9)+10;

int n,m;
struct one {
	int l,r;
	int d;
	/* data */
};
one q[MAXN];
int A[MAXN];  
//int max;  
//int min;  
  
struct node  
{  
    int left;  
    int right;  
    int max;           //维护最大值  
    int sum;          //维护区间和  
    int min;           //维护最小值  
}Tree[MAXN<<2];  
  
  
void maintain(int root)         //向上调整  
{  
    int LC = root<<1;  
    int RC = (root<<1)+1;  
    Tree[root].sum = Tree[LC].sum + Tree[RC].sum;  
    Tree[root].max = max(Tree[LC].max,Tree[RC].max);  
    Tree[root].min = min(Tree[LC].min,Tree[RC].min);  
}  
  
void Build(int root,int start,int end)                     //构建线段树  
{  
    Tree[root].left = start;  
    Tree[root].right = end;  
    if(start == end)  
    {  
        Tree[root].sum = A[start];  
        Tree[root].max = A[start];  
        Tree[root].min = A[start];  
        return;  
    }  
    int mid = (start + end)>>1;  
    Build(root<<1,start,mid);  
    Build((root<<1)+1,mid+1,end);  
    maintain(root);  
}  
  
void update(int root,int pos,int value)                     //更新点的值  
{  
    if(Tree[root].left == Tree[root].right && Tree[root].left == pos)  
    {  
        Tree[root].sum = value;  
        Tree[root].max = value;  
        Tree[root].min = value;  
        return;  
    }  
    int mid = (Tree[root].left + Tree[root].right)>>1;  
    if(pos <= mid)  
        update(root<<1,pos,value);  
    else  
        update((root<<1)+1,pos,value);  
    maintain(root);  
}  
  
int Query(int root,int start,int end)                         //查询区间和  
{  
    if(start == Tree[root].left && Tree[root].right == end)  
    {  
        return Tree[root].sum;  
    }  
    int mid = (Tree[root].left + Tree[root].right)>>1;  
    int ret = 0;  
    if(end <= mid)  
        ret += Query(root<<1,start,end);  
    else if(start >= mid+1)  
        ret += Query((root<<1)+1,start,end);  
    else  
    {  
        ret += Query(root<<1,start,mid);  
        ret += Query((root<<1)+1,mid+1,end);  
    }  
    return ret;  
}  
  
int RminQ(int root,int start,int end)              //查询区间最小值  
{  
    if(start == Tree[root].left && Tree[root].right == end)  
    {  
        return Tree[root].min;  
    }  
    int mid = (Tree[root].left + Tree[root].right)>>1;  
    int ret = INF;  
    if(end <= mid)  
        ret = min(ret,RminQ(root<<1,start,end));  
    else if(start >= mid+1)  
        ret = min(ret,RminQ((root<<1)+1,start,end));  
    else  
    {  
        int a = RminQ(root<<1,start,mid);  
        int b = RminQ((root<<1)+1,mid+1,end);  
        ret = min(a,b);  
    }  
    return ret;  
}  
  
int RmaxQ(int root,int start,int end)                 //查询区间最大值  
{  
    if(start == Tree[root].left && Tree[root].right == end)  
    {  
        return Tree[root].max;  
    }  
    int mid = (Tree[root].left + Tree[root].right)>>1;  
    int ret = -INF;    //modify this  
    if(end <= mid)  
        ret = max(ret,RmaxQ(root<<1,start,end));  
    else if(start >= mid+1)  
        ret = max(ret,RmaxQ((root<<1)+1,start,end));  
    else  
    {  
        int a = RmaxQ(root<<1,start,mid);  
        int b = RmaxQ((root<<1)+1,mid+1,end);  
        ret = max(a,b);  
    }  
    return ret;  
}  

bool cmp(const one & s1,  const one & s2) {
	return s1.d < s2.d;
}

int main()
{
	int l,r;
	cin >> n >> m;
	memset(A, -1, sizeof(A));
	Build(1,1,n);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d",&q[i].l, &q[i].r);
		q[i].d = (q[i].r - q[i].l);
	}
	sort(q+1,q+1+m,cmp);
	int ans = INF;
	for(int i = 1; i <= m; i++) {
		l = q[i].l;
		r = q[i].r;
		// cout << "l = " << l << " r = " << r << endl;
		int min_val = RminQ(1,l,r);
		int max_val = RmaxQ(1,l,r);
		// int sum = Query(1,l,r);
		// cout << "sum = " << sum << endl;
		// cout << "min_val = " << min_val << endl; 
		if(RminQ(1,l,r) != -1) {
			ans = min(ans, max_val + 1);
			continue;
		}
		else {
			// cout << "max_val = " << max_val << endl; 
			for(int j = l; j <= r; j++) {
				if(A[j] == -1) {
					A[j] = (++max_val);
					update(1,j,A[j]);
					// cout << "update" << endl;
				}
			}
			ans = min(ans, max_val+1);
		}
	}
	cout << ans << endl;
	for(int i = 1 ; i <= n; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}






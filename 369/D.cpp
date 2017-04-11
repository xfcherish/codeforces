#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = (1e5)+10;
const int mod = (1e9) + 10;

int a[maxn],n;
int cnt[maxn];
vector<int> adj[maxn];
vector<int> circuit;

long long pow_mod(long long a, long long i, long long n) {
	if(i == 0) return 1%n;
	long long temp = pow_mod(a, i>>1 , n);
	temp = temp * temp % n;
	if(i&1) temp = temp * a % n;
	return temp;
}

void find_circuit(int start) {
    if(adj[start].size() == 0 ) 
        circuit.push_back(start);
    else {
        while(adj[start].size()!=0) {
            sort(adj[start].begin(), adj[start].end());
            int tmp = adj[start][0];
            for(vector<int>::iterator it = adj[start].begin(); it != adj[start].end(); it++ ) {
                if((*it) == tmp) {
                     adj[start].erase(it);
                     break;
                 }
            }
            for(vector<int>::iterator it = adj[tmp].begin(); it != adj[tmp].end(); it++ ) {
                if((*it) == start) {
                    adj[tmp].erase(it);
                    break;
                }
            }
            find_circuit(tmp);
        }
        circuit.push_back(start);
    }
}
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		adj[i].push_back(a[i]);
		adj[a[i]].push_back(i);
	}	
	find_circuit(1);
	// cout << "circuit" << endl;
	// for(int i = 0 ; i < circuit.size(); i++) {
	// 	cout << circuit[i] << endl;
	// }
	memset(cnt,0,sizeof(cnt));
	for(int i = 0; i < circuit.size(); i++) {
		cnt[circuit[i]]++;
	}
	int mark = -1;
	for(int i = 1; i <= n; i++) {
		if(cnt[i] == 2) {
			mark = i;
		}
	}
	int num_circuit = 0;
	// cout << "mark = " << mark << endl;
	if(mark == -1)
		num_circuit = 0;
	else {
		int pos1 = -1;
		int pos2 = -1;
		for(int i = 0; i < circuit.size(); i++) {
			if(mark == circuit[i]) {
				if(pos1 == -1)
					pos1 = i;
				else if(pos2 == -1)
					pos2 = i;
			}
		}
		num_circuit = pos2 - pos1;
	}
	// cout << "num_circuit = " << num_circuit << endl;
	long long ans = (pow_mod(2, num_circuit , mod) - 2 + mod) % mod;
	ans = ( ans * pow_mod(2, n - num_circuit, mod)) % mod;
 	cout << ans << endl;
	return 0;
}
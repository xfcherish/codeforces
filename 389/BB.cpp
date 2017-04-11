#include <iostream>

#include <string>


using namespace std;
string a,b;
int c[30];

int main()
{
    cin >> a;
    cin >> b;
    int i, n = a.length();
    for(i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(c[b[i] - 'a'] != 0 && c[b[i] - 'a'] != a[i] - 'a'){
                cout << -1 << endl;
                return 0;
            }
            if(c[a[i] - 'a'] != 0 && c[a[i] - 'a'] != b[i] - 'a'){
                cout << -1 << endl;
                return 0;
            }
            c[a[i] - 'a'] = b[i] - 'a';
            c[b[i] - 'a'] = a[i] - 'a';
            if(c[b[i] - 'a'] != 0 && c[b[i] - 'a'] != a[i] - 'a'){
                cout << -1 << endl;
                return 0;
            }
            if(c[a[i] - 'a'] != 0 && c[a[i] - 'a'] != b[i] - 'a'){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    int ans = 0;
    for(i = 0; i < 26; i++){
        if(c[i] != 0)ans++;
    }
    if(ans % 2 != 0) ans = ans/2 + 1;
    else ans = ans/2;
    cout << ans << endl;
    for(i = 0; i < 26; i++){
        if(c[i] != 0){
            char c1 = c[i]+'a';
            char c2 = c[c[i]]+'a';
            cout << c1 << " " << c2 << endl;
            c[c[i]] = 0;
            c[i] = 0;
        }
    }
    return 0;
}
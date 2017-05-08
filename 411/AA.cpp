#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int main (){
	int l, r;
	cin >> l >> r;

	vector <int> count(7, 0);
	int max = -1;
	int max_ind = 0;

	//does not work with solo prime numbers
	if (l == r)
		cout << l << endl;
	else if(r - l > 10){
		cout << 2 << endl;
	}

	else{
		for(int i=l; i<=r; i++){
			//cout << i << endl;
			int temp = i;
			if(temp%2==0){
				count[2]++;
				//cout << "got 2" << endl;
				if(max<count[2]){
					max = count[2];
					max_ind = 2;
				}
			}

			else{
				for(int j=3; j<=temp && j<=7; j+=2){
					if(temp%j==0){
						//cout << "got "<<j<< endl;
						count[j]++;
						if(max<count[j]){
							max = count[j];
							max_ind = j;
						}
						break;
					}
				}
			}
		}

		cout << max_ind << endl;
	}
	return 0;
}
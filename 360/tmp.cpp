#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> nums , int target) {
	int low,mid,high;
	low = 0;
	high = nums.size()-1;
	mid = (low+high)/2;
	while(low <= high) {
		if(nums[mid] == target) 
			break;
		else if(nums[mid] > target) 
			high = mid - 1;
		else if(nums[mid] < target)
			low = mid + 1;
		mid = (low+high)/2;
	}
	if(nums[mid] == target) return mid;
	else return -1;
}



int main()
{
	vector<int> v ;
	for(int i = 1; i <= 10; i+=1)
		v.push_back(i);
	int target = 1 ;
	cout << binary_search(v,target) << endl;
	return 0;
}
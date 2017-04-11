#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> nums , int target) {
	int low,mid,high;
	low = 0;
	high = nums.size()-1;
	while(low <= high) {
		mid = (low+high)/2;
		if(nums[mid] == target) 
			return mid;
		else if(nums[mid] > target) 
			high = mid - 1;
		else if(nums[mid] < target)
			low = mid + 1;
	}
	return -1;
}

int find_lower(const vector<int> &nums, int target)
{
    if(nums.size() < 1) return -1;
    int low = 0;
    int high = nums.size() -1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(nums[mid] >= target)
            high = mid - 1;
        else
            low = mid +1;
    }
    if(nums[low] == target)
        return low;
    else
        return -1;
}

int find_upper(const vector<int> &nums, int target)
{
    if(nums.size() < 1) return -1;
    int low = 0;
    int high = nums.size() -1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(nums[mid] <= target)
        	low = mid + 1;
        else
            high = mid - 1;
    }
    if(nums[high] == target)
        return high+1;
    else
        return -1;
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
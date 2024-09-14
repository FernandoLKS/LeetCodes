#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> Hash;

        for(int i = 0; i < nums.size(); i++){
            if(Hash.find(target - nums[i]) == Hash.end())
                Hash[nums[i]] = i;
            else                
                return {Hash[target - nums[i]], i};
        }
        return {-1, -1};
    }
};

int main(){
    Solution Solution;

    vector<int> nums = {2,7,11,15};
    int target = 9;
 
    vector<int> Result = Solution.twoSum(nums, target);
    cout << Result[0] << ',' << Result[1] << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // initial sum & left sum variable
        unsigned int sum {};
        int leftSum {};

        // sum nums vector element
        for (const auto& i : nums) {
            sum += i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // compare left sum and right sum
            if (leftSum == sum - leftSum - nums[i]) {
                // if equal, return pivot index
                return i;
            }
            // add left sum
            leftSum += nums[i];
        }
        
        // failed return
        return -1;
    }
};

int main() {
    Solution s;
    std::vector<int> nums {0,1,2,3,4,5,0};
    s.pivotIndex(nums);

    return 0;
}
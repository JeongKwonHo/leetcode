#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r {};
        int l {};
        int subArraySum {};
        int minSize = std::numeric_limits<int>::max();
        while(r < nums.size()) { 
            subArraySum += nums[r++];
            while(target <= subArraySum) {
                  minSize = std::min(minSize, r - l);
                subArraySum -= nums[l++];
            }
        }

        if (minSize == std::numeric_limits<int>::max()) {
            return 0;
        }
        return minSize;        
    }
};

int main() {
    Solution s;
    std::vector<int> nums {1,1,1,1,1,1,1,1};
    std::vector<int> nums2 {2,3,1,2,4,3};
    std::vector<int> nums3 {1,4,4};
    std::cout << s.minSubArrayLen(11, nums) << std::endl;
    std::cout << s.minSubArrayLen(7, nums2) << std::endl;
    std::cout << s.minSubArrayLen(4, nums3) << std::endl;
    return 0;
}
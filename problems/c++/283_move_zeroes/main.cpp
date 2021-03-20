#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int wIdx = 0;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] != 0) {
                std::swap(nums[wIdx], nums[idx]);
                wIdx++;
            }
        } 
    }

    void print(std::vector<int>& nums) {
        for (const auto& iter : nums) {
            std::cout << iter << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Solution s;
    std::vector<int> nums {0,1,2,3,4,5,0};
    s.moveZeroes(nums);
    s.print(nums);

    return 0;
}
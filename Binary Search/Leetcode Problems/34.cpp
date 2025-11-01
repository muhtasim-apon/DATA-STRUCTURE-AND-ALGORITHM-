//find first and last position of element in sorted array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>idx;
        int low = 0, high = nums.size() - 1, ans1 = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans1 = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int low1 = 0, high1 = nums.size() - 1, ans2 = -1;
        while (low1 <= high1) {
            int mid = low1 + (high1 - low1) / 2;
            if (nums[mid] == target) {
                ans2 = mid;
                low1 = mid + 1;
            } else if (nums[mid] < target) {
                low1 = mid + 1;
            } else {
                high1 = mid - 1;
            }
    }
    idx.push_back(ans1);
    idx.push_back(ans2);
    return idx;
    }
};

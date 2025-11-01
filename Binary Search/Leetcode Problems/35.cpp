//implementing lower bound funtion
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int index=-1;
        if(target>nums[nums.size()-1])return nums.size();
        if(target<nums[0])return 0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                index=mid;
                return index;
            }
            else if(nums[mid]>target)
            {
                 index=mid;
                high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        }
        return index;
    }
};
//implementing upper bound function
class Solution {
    public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int index=-1;
        if(target>=nums[nums.size()-1])return nums.size();
        if(target<nums[0])return 0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                index=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                 index=mid;
                high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        }
        return index;
    }
    
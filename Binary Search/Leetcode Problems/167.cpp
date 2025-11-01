//two sum -input array is sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>idx;
        // int binarysearch(int low,int high,int val)
        // {
        //     while(low<=high)
        //     {
        //         int mid=(low+high)/2;
        //         if(numbers[mid]==val)return mid;
        //         if(numbers[mid]>val)high=mid-1;
        //         else low=mid+1;
        //     }
        //     return -1;
        // }
        for(int i=0;i<numbers.size()-1;i++)
        {
            int val=target-numbers[i];
            if(binary_search(numbers.begin()+i+1,numbers.end(),val))
            {
                int get=lower_bound(numbers.begin()+i+1,numbers.end(),val)-numbers.begin();
                idx.push_back(i+1);
                idx.push_back(get+1);
                break;
            }
        }
        return idx;
    }
};
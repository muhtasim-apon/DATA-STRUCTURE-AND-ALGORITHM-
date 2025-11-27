#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target in a rotated sorted array
int searchRotated(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if mid is the target
        if (nums[mid] == target)
            return mid;

        // Check if left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1; // target lies in left half
            else
                low = mid + 1;  // target lies in right half
        }
        // Otherwise, right half is sorted
        else {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;  // target lies in right half
            else
                high = mid - 1; // target lies in left half
        }
    }

    return -1; // Target not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of the rotated sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target element to search: ";
    cin >> target;

    int result = searchRotated(nums, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}

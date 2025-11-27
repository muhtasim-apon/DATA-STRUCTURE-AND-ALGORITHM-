#include <bits/stdc++.h>
using namespace std;

// Find leftmost occurrence of x in [l, r]
int leftmost(int arr[], int x, int l, int r) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            ans = mid;
            r = mid - 1;
        } else if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

// Find rightmost occurrence of x in [l, r]
int rightmost(int arr[], int x, int l, int r) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            ans = mid;
            l = mid + 1;
        } else if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

int lowerbound(int arr[], int target,int l,int r) {
        int low=0,high=r;
        int index=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==target)
            {
                index=mid;
                return index;
            }
            else if(arr[mid]>target)
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

// Find smallest index j in [l, r] with arr[j] > x
int findUpper(int arr[], int x, int l, int r) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] > x) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int q;
    cin >> q;
    while (q--) {
        int x, L, R;
        cin >> x >> L >> R;

        int left = leftmost(arr, x, L, R);
        int right = rightmost(arr, x, L, R);

        if (left != -1 && right != -1) {
            // Case 1: x exists in subarray
            cout << left << " " << right << "\n";
        } else {
            // x does not exist in subarray
            int lower = findLower(arr, x, L, R);
            int upper = findUpper(arr, x, L, R);

            // Case 3: all values greater than x
            if (lower == -1 && upper != -1) {
                cout << -1 << " " << upper << "\n";
            }
            // Case 4: all values smaller than x
            else if (upper == -1 && lower != -1) {
                cout << lower << " " << -1 << "\n";
            }
            // Case 2: x in between some elements
            else {
                cout << lower << " " << upper << "\n";
            }
        }
    }
}

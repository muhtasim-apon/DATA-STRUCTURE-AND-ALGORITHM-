#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void heapify(int i)
{
    int highest = i;
    int l = left(i);
    int r = right(i);

    if (l < arr.size() && arr[l] > arr[highest])
        highest = l;

    if (r < arr.size() && arr[r] > arr[highest])
        highest = r;

    if (highest != i)
    {
        swap(arr[i], arr[highest]);
        heapify(highest);
    }
}

void up(int i)
{
    while (i > 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void insert(int key)
{
    arr.push_back(key);
    up(arr.size() - 1);
}

int extract()
{
    int root = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    heapify(0);
    return root;
}

// void build(vector<int> &arr)
// {

//     for (int i = arr.size() / 2 - 1; i >= 0; i--)
//         heapify(i);
// }

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        insert(x);
        arr[0] -= k;
        heapify(0);
    }
    vector<int> ans;
    while (!arr.empty())
    {
        ans.push_back(extract());
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size() - 1; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("%d", ans.back());
    printf("\n");
}
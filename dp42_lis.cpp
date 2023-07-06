#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);
    sort(arr, arr + n);
    for (int i = 0; i <= n - 1; i++)
    {

        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= n - 1; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}
int lcs(int arr[], int n)
{
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);
    sort(arr, arr + n);
    for (int i = 0; i <= +n - 1; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }
    int ans = -1;
    int last = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            last = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[last]);
    while (hash[last] != last)
    {
        last = hash[last];
        temp.push_back(arr[last]);
    }
    reverse(temp.begin(), temp.end());

    cout << "the sequence is" << endl;
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;

    return ans;
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The length of the longest increasing subsequence is "
         << lcs(arr, n);

    return 0;
}

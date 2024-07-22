int trap(vector<int> &arr)
{
    int maxValIndex = 0, n = arr.size(),leftMax = 0, rightMax = 0, ans = 0;
    // calculate maxVal Index
    for (int i = 1; i < n; i++)
        if (arr[maxValIndex] < arr[i]) maxValIndex = i;
    // calculte left part
    for (int i = 0; i < maxValIndex; i++)
        if (leftMax > arr[i]) ans += leftMax - arr[i];
        else leftMax = arr[i];

    // calculate right part
    for (int i = n - 1; i > maxValIndex; i--)
        if (rightMax > arr[i])ans += rightMax - arr[i];
    else rightMax = arr[i];

    return ans;
}
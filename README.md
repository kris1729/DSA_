# DSA_
Two_Pointer_And_PrifixSum
---
# Segregate 0 and 1

![](./ouestion_img/segregate_0s_1s.png)

### mathod 1 - Sorting

- by using bubble / insertion / selection time O(N^2)
- by using sorting function it take O(nlogn)

```cpp
sort(arr.begin(),arr.end());
```

### Method 2 - count 0 and count 1

```cpp
int cnt0 = 0;
int cnt1 = 0;
for(int i =0;i<n;i++){
    if(arr[i]==0)cnt0++;
    else cnt1++;
}
for(int i =0;i<cnt0;i++)
arr[i]=0;
for(int i = cnt0;i<n;i++)
arr[i]=1;
```

- Time Complexity O(n)

### Method 3 - Using Two Pointer

- take st and end pointer if st point is 0 then it move and end
  point 1 then it move towords the st when the point reverse value then <b>swap</b> them

```cpp
int st = 0,end=n-1;
while(st<end){
    if(arr[st]==0)st++;
    else{
        if(arr[end]==1){
            swap(arr[st],arr[end]);
            st++;
            end--;
     }
        else
        end--;
       }
}
```

---

# Two Sum II - Input Array Is Sorted

![](./ouestion_img/Two%20Sum%20II%20-%20Array%20Is%20Sorted%20.png)
### Method 1 - Broute force App.
- time complexity O(n^2)
```cpp
vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] + arr[j] == target)return {i+1,j+1};
        return {};          
}
```
### method 2 - using binary search
- because of sorting nature array we take one by one element arr[i] and search all remaing <b>target - arr[i]
- O(n*long(n))
```cpp
vector<int> twoSum(vector<int>& arr, int target) {

 int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            // binary search
            int st = i + 1, end = n - 1, key = target - arr[i];
            while (st <= end) {
                int mid = (st + end) / 2;
                if (arr[mid] == key)
                    return {i + 1, mid + 1};
                else if (arr[mid] > key)
                    end = mid - 1;
                else
                    st = mid + 1;
            }
        }
        return {};
}
```

### method 3 - Two pointer
- when we move starting point to right then value increses and when we move end point to left then value will decreases
- ## can be apply only sorted array
O(n)  time complxity

```cpp
 vector<int> twoSum(vector<int>& arr, int target) {

        int st = 0, end = arr.size() - 1;
        while (st < end) {
            int key = arr[st] + arr[end];
            if (key == target)
                return {st + 1, end + 1};
            else if (key < target)
                st++;
            else
                end--;
        }
        return {};

    }
```
----
# Pair with Given Difference
![](./ouestion_img/Find%20Pair%20Given%20Difference.png)

### Method -1  Broute force approch
```cpp
int findPair(int n, int x, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[j] - arr[i] == x)
                return 1;
    return -1;
}
```
### Method-2 Binary Search approch
```cpp
int findPair(int n, int x, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {  
        int st = i + 1, end = n - 1, mid;
        int key = x + arr[i];
        while (st <= end)
        {
            mid = (st + end) / 2;
            if (arr[mid] == key)return 1;
            else if (arr[mid] > key) end = mid - 1;
            else st = mid + 1;       
        }
    }
    return -1;
}

```
### method-3 two pointer
- put st and end at that point , where they move one side then the value change (inc&dec) for each one 
- after sorting..
- we put st at 0 and end at 1 and take diff , if diff is less than actual diff than we move the end at right side , and if diff is greater than actual diff than we move st in right side;

```cpp
int findPair(int n, int x, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int st = 0, end = 1;
    while (end < n)
    {
        int key = arr[end] - arr[st];
        if (key == x)return 1;
        else if (key < x)end++;
        else st++;
        // important step
        if (st == end) end++;
    }
    return -1;
}
```
> both side st and end give same type of effect the both st and end will be one side or both in st or both in end.


> # Prifix And Suffix Sum

# Divide array in 2 subarray with equal sum

### Method-1 , broute force approch
Time complexity will be O(n^2)
```cpp
for(int i =0;i<n-1;i++){
    int sum1 =0,sum2 = 0;
    for(int j =0;j<=i; j++)
    sum1+= arr[j];
    for(int j =n;j>i;j--)
    sum2+=arr[j];
    if(sum1==sum2)return 1;
}
return 0;
```
### Method-2 , using Prifix sum
using prifix sum compair total sum-prifixsum
```cpp
int totalSum = 0;
for (int i = 0; i < n; i++)totalSum += arr[i];
int prifixSum = 0;
for (int i = 0; i < n - 1; i++)
{
    prifixSum += arr[i];
    if (2 * prifixSum == totalSum) return 1;
}
return 0;
```
#  Maximum Subarray
![](./ouestion_img/Maximixe%20the%20sum%20of%20subArray.png)
### method -1
find all the subarray sum and return the max sum.
```cpp
int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
```
### method -2 , using prifix sum
*let array is 5 size and when PrifixSum start at*

**index-0** 
- {0} , {0,1} , {0,1,2} , {0,1,2,3} , {0,1,2,3,4},

**index-1** 
- {1} , {1,2} , {1,2,3} , {1,2,3,4},

**index-2** 
- {2} , {2,3} , {2,3,4},

**index-3** 
- {3} , {3,4},

**index-4** 
- {4},

> this is all sumArray and their sum in form of prifix sum and take max
```cpp
 int maxSum =INT_MIN;
        for(int i =0;i<nums.size();i++){
            int sum =0;
            for(int j =i;j<nums.size();j++){
                sum += nums[j];
            maxSum = max(maxSum,sum);}
        }
 return maxSum;
```
### Method-3, Kadane's Algorithm IMPORTANT
> find PriFixSum and when prifix sum is **NEGATIVE** then make it **ZERO**.
```cpp
int maxSum = nums[0],prifixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
             if (prifixSum < 0)
                prifixSum = 0;
            prifixSum += nums[i];
            maxSum = max(maxSum, prifixSum);}
            
return maxSum;
```
*why*  because -ve prifix always dec the continous sum.
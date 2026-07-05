## M1-Brute Force Method

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1;j<nums.size(); j++){
                if(nums[j]==target-nums[i]) return {i,j};
            }
        }
        return {};
    }
};
```
### Complexities
Time complexity: O(n^2).
For each element, we try to find its complement by looping through the rest of the array which takes O(n) time. Therefore, the time complexity is O(n^2).

Space complexity: O(1).
The space required does not depend on the size of the input array, so only constant space is used.


## M2-Optimised Solution

```cpp
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < nums.size(); ++i) {
      if (const auto it = numToIndex.find(target - nums[i]);
          it != numToIndex.cend())
        return {it->second, i};
      numToIndex[nums[i]] = i;
    }

    throw;
  }
};
```

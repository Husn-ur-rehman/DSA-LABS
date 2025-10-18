#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;     
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) { 

            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

        
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

        
            dq.push_back(i);

        
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);

        }
        return result;
    }    
};

int main() {
    vector<int> nums = {7, 3, 5, 8, 9, 2, 7, 10};
    int k = 3;
    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(nums, k);

    for (int x : ans)
        cout << x << " ";
}

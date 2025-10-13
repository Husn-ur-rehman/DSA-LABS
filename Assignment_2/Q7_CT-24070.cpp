#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int largestArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight;
            if (i == n)
                currHeight = 0;
            else
                currHeight = heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int topIndex = st.top();
                st.pop();

                int height = heights[topIndex];
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                int area = height * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        return maxArea;
    }

};

int main() {
    vector<int> heights = {5, 4, 1, 3, 9, 4};
    Solution obj;
    cout <<obj.largestArea(heights);
    return 0;
}

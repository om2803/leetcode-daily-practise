class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
int n = nums.size();
    vector<int> res;

    // Handle the base case where k is greater than the array size
    if (k > n) {
        return res;
    }

    // Use a deque to maintain a monotonically decreasing order of elements within the window
    deque<int> dq;

    // Initialize the first window
    for (int i = 0; i < k; ++i) {
        // Push elements in descending order to maintain the max at the front
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    res.push_back(nums[dq.front()]); // Add the max element of the first window

    // Slide the window
    for (int i = k; i < n; ++i) {
        // Remove elements from the front of the deque if they are no longer in the window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Push elements in descending order again
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        res.push_back(nums[dq.front()]); // Add the max element of the current window
    }

    return res;
    }
};
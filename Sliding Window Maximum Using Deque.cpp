#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq; // Store indices of elements
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove indices of all elements from the back of the deque
        // that are less than the current element (they are useless)
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Add the current element at the back of the deque
        dq.push_back(i);

        // The element at the front of the deque is the largest in the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the window size: ";
    cin >> k;

    vector<int> result = slidingWindowMaximum(nums, k);

    cout << "The maximums in each sliding window are:\n";
    for (int maxVal : result) {
        cout << maxVal << " ";
    }
    cout << endl;

    return 0;
}

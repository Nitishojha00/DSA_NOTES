#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> mountains;  // {height, index}
    for (int i = 1; i <= n; ++i) {
        int h;
        cin >> h;
        mountains.emplace_back(h, i);
    }

    // Sort mountains from tallest to shortest
    sort(mountains.begin(), mountains.end(), greater<>());

    vector<int> dp(n + 1, 0);  // dp[i] = max sequence ending at mountain i
    set<int, greater<>> leftSet;   // stores indices of taller mountains (left to right)
    set<int> rightSet;             // stores indices of taller mountains (right to left)
    vector<int> currentHeightIndices;

    int lastHeight = -1;

    for (auto [height, index] : mountains) {
        // New height group, push last group indices into sets
        if (height != lastHeight) {
            for (int idx : currentHeightIndices) {
                leftSet.insert(idx);
                rightSet.insert(idx);
            }
            currentHeightIndices.clear();
        }

        // Find nearest taller to the left and right
        auto leftIt = leftSet.lower_bound(index);
        auto rightIt = rightSet.lower_bound(index);

        int left = (leftIt == leftSet.end()) ? 0 : *leftIt;
        int right = (rightIt == rightSet.end()) ? 0 : *rightIt;

        dp[index] = max(dp[left], dp[right]) + 1;

        currentHeightIndices.push_back(index);
        lastHeight = height;
    }

    // Find the best DP value
    int best = *max_element(dp.begin(), dp.end());
    cout << best << '\n';

    return 0;
}

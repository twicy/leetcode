#include <bits/stdc++.h>
using namespace std;

void complete_knapsack_v2(vector<int> &weight, vector<int> &value, int capacity) {
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < weight.size(); i++) {
        for (int j = 0; j <= capacity; j++) {
            if (j - weight[i] >= 0)
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << "Complete Knapsack value(v2): " << dp[capacity] << "\n";
}


void complete_knapsack_v1(vector<int> &weight, vector<int> &value, int capacity) {
    vector<vector<int>> dp(weight.size(), vector<int>(capacity + 1, 0));

    for (int i = weight[0]; i < dp[0].size(); i++) {
        dp[0][i] = dp[0][i - weight[0]] + value[0];
    }

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
            }
        }
    }

    cout << "Complete Knapsack value(v1): " << dp[weight.size() - 1][capacity] << "\n";
}

void zero_one_knapsack_v2(vector<int> &weight, vector<int> &value, int capacity) {
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < weight.size(); i++) {
        for (int j = capacity; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << "0-1 Knapsack value(v2): " << dp[capacity] << "\n";
}


void zero_one_knapsack_v1(vector<int> &weight, vector<int> &value, int capacity) {
    vector<vector<int>> dp(weight.size(), vector<int>(capacity + 1, 0));

    // ith row means selecting this item
    for (int i = weight[0]; i < dp[0].size(); i++) {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << "0-1 Knapsack value(v1): " << dp[weight.size() - 1][capacity] << "\n";
}

int main () {
    int n, capacity;
    cin >> n >> capacity;

    cout << "capacity: " << capacity << "\n";
    vector<int> weight(n, 0);
    vector<int> value(n, 0);

    for(int i = 0; i < n; ++i) {
        cin >> weight[i];
        cout << weight[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n; ++i) {
        cin >> value[i];
        cout << value[i] << " ";
    }
    cout << "\n";

    zero_one_knapsack_v1(weight, value, capacity);
    zero_one_knapsack_v2(weight, value, capacity);
    complete_knapsack_v1(weight, value, capacity);
    complete_knapsack_v2(weight, value, capacity);
    return 0;
}
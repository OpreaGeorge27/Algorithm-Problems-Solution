#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
  void solve() {
    read_input();
    print_output(get_result());
  }

 private:
  vector<double> prices;
  int n, k;

  void read_input() {
    ifstream inputFile("oferta.in");
    inputFile >> n;
    inputFile >> k;
    prices.resize(n);
    for (int i = 0; i < n; i++) {
      inputFile >> prices[i];
    }
    inputFile.close();
  }

  double get_result() {
    vector<double> dp(n + 1);
    dp[0] = 0;
    dp[1] = prices[0];
    if (n >= 2) {
      dp[2] = prices[0] + prices[1] - min(prices[0], prices[1]) / 2;
    }

    for (int i = 2; i < n; i++) {
      dp[i + 1] = min({dp[i - 2] + prices[i] + prices[i - 1] + prices[i - 2] -
                           min({prices[i], prices[i - 1], prices[i - 2]}),
                       dp[i - 1] + prices[i] + prices[i - 1] -
                           min(prices[i], prices[i - 1]) / 2,
                       dp[i] + prices[i]});
    }
    return dp[n];
  }

  void print_output(double result) {
    ofstream outputFile("oferta.out");
    outputFile << fixed << setprecision(1) << result << "\n";
    outputFile.close();
  }
};

int main() {
  auto *task = new (nothrow) Task();
  if (!task) {
    cerr << "new failed: WTF are you doing? Throw your PC!\n";
    return -1;
  }
  task->solve();
  delete task;
  return 0;
}

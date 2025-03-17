#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
  void solve() {
    read_input();
    print_output(get_result());
  }

 private:
  int n;
  vector<int> P, C;

  void read_input() {
    ifstream fin("servere.in");
    fin >> n;
    P.resize(n);
    C.resize(n);
    for (int i = 0; i < n; i++) {
      fin >> P[i];
    }
    for (int i = 0; i < n; i++) {
      fin >> C[i];
    }
    fin.close();
  }

  double get_result() {
    int minC = *min_element(C.begin(), C.end());
    int maxC = *max_element(C.begin(), C.end());
    double l = minC, r = maxC;
    double best_min_power = numeric_limits<double>::lowest();

    while (r - l > 1e-4) {
      double mid1 = l + (r - l) / 3;
      double mid2 = r - (r - l) / 3;
      double power1 = calculate_min_power(mid1);
      double power2 = calculate_min_power(mid2);

      best_min_power = max({best_min_power, power1, power2});

      if (power1 > power2) {
        r = mid2;
      } else {
        l = mid1;
      }
    }

    return best_min_power;
  }

  double calculate_min_power(double current) {
    double min_power = numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
      double adjusted_power = P[i] - abs(current - C[i]);
      min_power = min(min_power, adjusted_power);
    }
    return min_power;
  }

  void print_output(double result) {
    ofstream fout("servere.out");
    fout << fixed << setprecision(1) << result << "\n";
    fout.close();
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

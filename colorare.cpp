#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Task {
 public:
  void solve() {
    read_input();
    unsigned long long result = get_result();
    print_output(result);
  }

 private:
  unsigned long long k;
  vector<pair<unsigned long long, char>> data;

  void read_input() {
    ifstream fin("colorare.in");
    fin >> k;
    data.resize(k);
    for (unsigned long long i = 0; i < k; ++i) {
      fin >> data[i].first >> data[i].second;
    }
    fin.close();
  }

  unsigned long long get_result() {
    unsigned long long n = 0;
    unsigned long long x = data[0].first;
    char T = data[0].second;

    if (T == 'H') {
      n = 6 * my_pow(3, x - 1);
    } else {
      n = 3 * my_pow(2, x - 1);
    }

    for (unsigned long long i = 1; i < k; i++) {
      char TPrev = data[i - 1].second;
      T = data[i].second;
      x = data[i].first;

      if (T == 'H' && TPrev == 'V') {
        n = (n * 2 * my_pow(3, x - 1)) % MOD;
      } else if (T == 'V' && TPrev == 'H') {
        n = (n * my_pow(2, x - 1)) % MOD;
      } else if (T == 'H' && TPrev == 'H') {
        n = (n * my_pow(3, x)) % MOD;
      } else if (T == 'V' && TPrev == 'V') {
        n = (n * my_pow(2, x)) % MOD;
      }
    }

    return n;
  }

  unsigned long int my_pow(unsigned long int base, unsigned long int exponent) {
    unsigned long int result = 1;
    while (exponent > 0) {
      if (exponent % 2 == 1) {
        result = (result * base) % MOD;
      }
      base = (base * base) % MOD;
      exponent /= 2;
    }
    return result;
  }

  void print_output(unsigned long long result) {
    ofstream fout("colorare.out");
    fout << result;
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

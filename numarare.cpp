#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
#define MOD 1000000007

class Task {
 public:
  void solve() {
    read_input();
    print_output(get_result());
  }

 private:
  int n, m;
  vector<set<int>> adjg1;
  vector<int> v[NMAX];
  vector<int> in_degree;

  void read_input() {
    ifstream fin("numarare.in");
    fin >> n >> m;
    adjg1.resize(n + 1);
    in_degree.resize(n + 1);
    for (int i = 1, x, y; i <= m; ++i) {
      fin >> x >> y;
      adjg1[x].insert(y);
    }
    for (int i = 1, x, y; i <= m; ++i) {
      fin >> x >> y;
      if (adjg1[x].find(y) == adjg1[x].end())
        continue;
      v[x].push_back(y);
      in_degree[y]++;
    }
    fin.close();
  }

  int get_result() {
    vector<int> sorted_nodes = topological_sort();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = sorted_nodes.size() - 1; i >= 0; --i) {
      for (int neighbor : v[sorted_nodes[i]]) {
        dp[sorted_nodes[i]] = (dp[sorted_nodes[i]] + dp[neighbor]) % MOD;
      }
    }
    return dp[1];
  }

  vector<int> topological_sort() {
    vector<int> result;
    vector<int> in_degree_local = in_degree;
    queue<int> zero_in_degree_nodes;

    for (int i = 1; i <= n; ++i) {
      if (in_degree_local[i] == 0) {
        zero_in_degree_nodes.push(i);
      }
    }

    while (!zero_in_degree_nodes.empty()) {
      int current = zero_in_degree_nodes.front();
      zero_in_degree_nodes.pop();
      result.push_back(current);

      for (int neighbor : v[current]) {
        in_degree_local[neighbor]--;
        if (in_degree_local[neighbor] == 0) {
          zero_in_degree_nodes.push(neighbor);
        }
      }
    }

    return result;
  }

  void print_output(int result) {
    ofstream fout("numarare.out");
    fout << result << '\n';
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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Task {
 public:
  void solve() {
    read_input();
    print_output(get_result());
  }

 private:
  unordered_map<string, vector<string>> adj;
  unordered_map<string, int> dp;
  string start, end;

  void read_input() {
    ifstream fin("trenuri.in");
    fin >> start >> end;
    int m;
    fin >> m;
    for (int i = 0; i < m; ++i) {
      string x, y;
      fin >> x >> y;
      adj[x].push_back(y);
    }
    fin.close();
  }

  int get_result() { return dfs(start); }

  int dfs(const string &node) {
    if (node == end) {
      return 1;  // daca suntem la destinatie, am gasit un drum l=1
    }
    if (dp.find(node) != dp.end()) {
      return dp[node];  // folosim rezultatul memorat
    }

    int max_length = 0;
    for (const auto &neighbor : adj[node]) {
      max_length = max(max_length, dfs(neighbor));
    }

    dp[node] = max_length + 1;  // actualizam drumul maxim pentru acest nod
    return dp[node];
  }

  void print_output(int result) {
    ofstream fout("trenuri.out");
    fout << result << endl;
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

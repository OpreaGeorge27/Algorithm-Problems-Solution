#include <bits/stdc++.h>
#include "shortest_path.h"
using namespace std;

class Task {
 public:
  void solve() {
    read_input();
    print_output(compute());
  }

 private:
  int n, m;
  int x, y, z;
  vector<pair<int, int>> adj[NMAX];
  vector<pair<int, int>> adjT[NMAX];  // graf transpus
  vector<Edge> edges;

  void read_input() {
    ifstream fin("drumuri.in");
    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
      int a, b, c;
      fin >> a >> b >> c;
      adj[a].emplace_back(b, c);
      adjT[b].emplace_back(a, c);  // adaugam muchia transpusa
      edges.emplace_back(a, b, c);
    }

    fin >> x >> y >> z;
    fin.close();
  }

  double compute() {
    // calculam drumurile minime de la x și y la toate nodurile folosind
    // Dijkstra
    DijkstraResult dist_x = dijkstra(x, n, adj);
    DijkstraResult dist_y = dijkstra(y, n, adj);
    DijkstraResult dist_z = dijkstra(
        z, n,
        adjT);  // Drumuri minime de la z la toate nodurile în graful transpus

    double min_cost = INF;

    for (int node = 1; node <= n; ++node) {
      if (dist_x.d[node] == INF || dist_y.d[node] == INF ||
          dist_z.d[node] == INF) {
        continue;
      }
      if (dist_x.d[node] + dist_z.d[node] + dist_y.d[node] < min_cost) {
        min_cost = dist_x.d[node] + dist_z.d[node] + dist_y.d[node];
      }
    }

    return min_cost;
  }

  void print_output(double result) {
    FILE *fout = fopen("drumuri.out", "w");
    fprintf(fout, "%.6f\n", result);
    fclose(fout);
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

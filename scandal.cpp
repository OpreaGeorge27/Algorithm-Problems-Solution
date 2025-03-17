#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
  void solve() {
    read_input();
    vector<vector<int>> scc = find_scc();
    print_output(scc);
  }

 private:
  int nrPrieteni, nrRelatii;
  vector<vector<int>> restrictii, restrictiiTranspus;

  void read_input() {
    ifstream input("scandal.in");
    input >> nrPrieteni >> nrRelatii;

    restrictii.resize(2 * nrPrieteni + 1);
    restrictiiTranspus.resize(2 * nrPrieteni + 1);

    for (int i = 0; i < nrRelatii; i++) {
      int prietenS, prietenD, relatie;
      input >> prietenS >> prietenD >> relatie;
      add_restriction(prietenS, prietenD, relatie);
    }

    input.close();
  }

  void add_restriction(int prietenS, int prietenD, int relatie) {
    switch (relatie) {
    case 0:
      restrictii[prietenS + nrPrieteni].push_back(prietenD);
      restrictii[prietenD + nrPrieteni].push_back(prietenS);
      restrictiiTranspus[prietenD].push_back(prietenS + nrPrieteni);
      restrictiiTranspus[prietenS].push_back(prietenD + nrPrieteni);
      break;
    case 1:
      restrictii[prietenS + nrPrieteni].push_back(prietenD + nrPrieteni);
      restrictii[prietenD].push_back(prietenS);
      restrictiiTranspus[prietenD + nrPrieteni].push_back(prietenS +
                                                          nrPrieteni);
      restrictiiTranspus[prietenS].push_back(prietenD);
      break;
    case 2:
      restrictii[prietenD + nrPrieteni].push_back(prietenS + nrPrieteni);
      restrictii[prietenS].push_back(prietenD);
      restrictiiTranspus[prietenS + nrPrieteni].push_back(prietenD +
                                                          nrPrieteni);
      restrictiiTranspus[prietenD].push_back(prietenS);
      break;
    case 3:
      restrictii[prietenS].push_back(prietenD + nrPrieteni);
      restrictii[prietenD].push_back(prietenS + nrPrieteni);
      restrictiiTranspus[prietenD + nrPrieteni].push_back(prietenS);
      restrictiiTranspus[prietenS + nrPrieteni].push_back(prietenD);
      break;
    }
  }

  void dfs(int nod, vector<int> &vizitat, stack<int> &sortat_finalizat) {
    stack<int> s;
    s.push(nod);

    while (!s.empty()) {
      int v = s.top();
      s.pop();

      if (!vizitat[v]) {
        vizitat[v] = 1;
        sortat_finalizat.push(v);
        for (int vecin : restrictii[v]) {
          if (!vizitat[vecin]) {
            s.push(vecin);
          }
        }
      }
    }
  }

  void dfsTranspus(int nod, vector<int> &vizitat, vector<int> &componenta) {
    stack<int> s;
    s.push(nod);

    while (!s.empty()) {
      int v = s.top();
      s.pop();

      if (vizitat[v]) {
        vizitat[v] = 0;
        componenta.push_back(v);
        for (int vecin : restrictiiTranspus[v]) {
          if (vizitat[vecin]) {
            s.push(vecin);
          }
        }
      }
    }
  }

  // Kosaraju (componenete tare conexe)
  vector<vector<int>> find_scc() {
    vector<vector<int>> componente;
    vector<int> vizitat(2 * nrPrieteni + 1, 0);
    stack<int> sortat_finalizat;

    for (int nod = 1; nod <= 2 * nrPrieteni; nod++) {
      if (!vizitat[nod]) {
        dfs(nod, vizitat, sortat_finalizat);
      }
    }

    while (!sortat_finalizat.empty()) {
      int nod = sortat_finalizat.top();
      sortat_finalizat.pop();

      if (vizitat[nod]) {
        vector<int> componenta;
        dfsTranspus(nod, vizitat, componenta);
        componente.push_back(componenta);
      }
    }

    return componente;
  }

  void print_output(const vector<vector<int>> &componente) {
    ofstream output("scandal.out");

    bool gresit = false;
    set<int> nodSet;
    for (const auto &componenta : componente) {
      nodSet.clear();
      for (int nod : componenta) {
        nodSet.insert(nod);
      }

      for (int nod : componenta) {
        if ((nod > nrPrieteni &&
             nodSet.find(nod - nrPrieteni) != nodSet.end()) ||
            (nod <= nrPrieteni &&
             nodSet.find(nod + nrPrieteni) != nodSet.end())) {
          gresit = true;
          break;
        }
      }
      if (gresit)
        break;
    }

    if (gresit) {
      output << -1 << endl;
    } else {
      int nrInvitati = 0;
      vector<int> invitati;
      vector<int> componentaNod(2 * nrPrieteni + 1, -1);

      for (int idxComponenta = 0; idxComponenta < componente.size();
           idxComponenta++) {
        for (int nod : componente[idxComponenta]) {
          componentaNod[nod] = idxComponenta;
        }
      }

      for (int i = 1; i <= nrPrieteni; i++) {
        if (componentaNod[i] != -1 &&
            componentaNod[i] > componentaNod[i + nrPrieteni]) {
          // se verifica daca i trebuie invitat si daca i nu trebuie invitat
          invitati.push_back(i);
          nrInvitati++;
        }
      }

      output << nrInvitati << endl;
      for (int invitat : invitati) {
        output << invitat << endl;
      }
    }

    output.close();
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

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
  vector<string> cuvinte;
  vector<int> frecventa_total = vector<int>(26, 0);
  vector<vector<int>> frecventa_cuvinte;

  void read_input() {
    ifstream fin("criptat.in");
    fin >> n;
    frecventa_cuvinte = vector<vector<int>>(n, vector<int>(26, 0));
    cuvinte.resize(n);
    fin.ignore();
    for (int i = 0; i < n; i++) {
      string cuvant;
      char ch;
      while (fin.get(ch) && ch != '\n') {
        frecventa_total[ch - 'a']++;
        frecventa_cuvinte[i][ch - 'a']++;
        cuvant.push_back(ch);
      }
      cuvinte[i] = cuvant;
    }
  }

  int get_result() {
    ofstream fout("criptat.out");
    string ret = "";

    while (*max_element(frecventa_total.begin(), frecventa_total.end())) {
      int max_frec_index =
          max_element(frecventa_total.begin(), frecventa_total.end()) -
          frecventa_total.begin();

      vector<pair<int, string>> sorted_words;
      for (int i = 0; i < n; i++) {
        int dominant_count = frecventa_cuvinte[i][max_frec_index];
        sorted_words.push_back({dominant_count, cuvinte[i]});
      }

      sort(sorted_words.begin(), sorted_words.end(),
           [](const pair<int, string> &a, const pair<int, string> &b) {
             return a.first * b.second.size() > b.first * a.second.size();
           });

      string password = "";
      unsigned long int dominant_count = 0;
      for (pair pair : sorted_words) {
        password += pair.second;
        dominant_count += pair.first;
        if (dominant_count <= (password.length() / 2)) {
          password = password.substr(0, password.size() - pair.second.size());
          dominant_count -= pair.first;
        }
      }

      if (ret.size() == 0) {
        ret = password;
      } else if (password.size() > ret.size()) {
        ret = password;
      }

      frecventa_total[max_frec_index] = 0;
    }

    return ret.length();
  }

  double get_score(int index, char ch) {
    return frecventa_cuvinte[index][ch - 'a'] / cuvinte[index].size();
  }

  void print_output(unsigned long int result) {
    ofstream fout("criptat.out");
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

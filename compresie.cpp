#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
  void solve() {
    read_input();
    get_result();
    print_output();
  }

 private:
  unsigned long long lenA, lenB, n = 0;
  vector<unsigned long long> A, B;

  void read_input() {
    ifstream fin("compresie.in");
    fin >> lenA;
    A.resize(lenA);
    for (unsigned long long i = 0; i < lenA; i++) {
      fin >> A[i];
    }
    fin >> lenB;
    B.resize(lenB);
    for (unsigned long long i = 0; i < lenB; i++) {
      fin >> B[i];
    }
    fin.close();
  }

  double get_result() {
    unsigned long long idx = 0;

    while (lenA && lenB) {
      if (A[idx] == B[idx]) {
        idx++;
        lenA--;
        lenB--;
        continue;
      }
      if (A[idx] < B[idx]) {
        merge_like_crazy(A, idx, B[idx], lenA);
        continue;
      }
      merge_like_crazy(B, idx, A[idx], lenB);
    }

    return 0;
  }

  unsigned long long merge_like_crazy(vector<unsigned long long> &arr,
                                      unsigned long long idx,
                                      unsigned long long target,
                                      unsigned long long &len) {
    unsigned long long offset = 1;
    while (idx + offset < arr.size() && arr[idx] < target) {
      arr[idx] += arr[idx + offset];
      offset++;
    }
    if (arr[idx] >= target) {
      arr.erase(arr.begin() + idx + 1, arr.begin() + idx + offset);
      len -= offset - 1;
      return offset;
    }
    return 0;
  }

  void print_output() {
    ofstream fout("compresie.out");
    if (lenA == 0 && lenB == 0 && A == B) {
      fout << A.size() << "\n";
    } else {
      fout << -1 << "\n";
    }
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

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>
#include <string>
#include <iostream>
 
using namespace std;
 
template<typename T>
vector<int> get_pi(const T &a) {
  int n = a.size();
  vector<int> pi(n);
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && a[i] != a[j]) j = pi[j - 1];
    j += ((a[i] == a[j]) ? 1 : 0);
    pi[i] = j;
  }
  return pi;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string ans;
  for (int wi = 0; wi < n; wi++) {
    string word;
    cin >> word;
    int alen = ans.length();
    int wlen = word.length();
    int s = max(0, alen - wlen);
    auto p = get_pi(word);
 
    int match_len = 0;
    for (int i = s; i < alen; i++) {
      while (match_len > 0 && ans[i] != word[match_len]) match_len = p[match_len - 1];
      if (ans[i] == word[match_len]) match_len++;
    }
    ans += word.substr(match_len);
  }
  cout << ans << "\n";
  return 0;
}

#include <cstdio>
#include <string>
using namespace std;

int toDecimal(const string &nb, const string &dg);
string fromDecimal(int n, const string &dg);

int main() {
  int t, T;
  char nb[108], s1[108], s2[108];
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    scanf("%s %s %s", nb, s1, s2);
    printf("Case #%d: %s\n", t, fromDecimal(toDecimal(nb, s1), s2).c_str());
  }
  return 0;
}

int toDecimal(const string &nb, const string &dg) {
  int i, A=0, b=dg.length();
  for (i=0; i<nb.length(); i++)
    (A*=b)+=dg.find(nb[i]);
  return A;
}

string fromDecimal(int n, const string &dg) {
  int b=dg.length();
  string A;
  while (n!=0) {
    A.push_back(dg[n%b]);
    n/=b;
  }
  return string(A.rbegin(), A.rend());
}

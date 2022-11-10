/**
 * n = V+1
 * s = E+1
 * k = m+1
 */

#include <iostream>

using std::cin;
using std::cout;
using std::cerr;

int n, s, k;
int v, e, m;

void readRollbesattningsProblem() {
  cin >> n >> s >> k;

  for (int i = 0; i < n; i++) {
    int numPossibleActors;
    cin >> numPossibleActors;
    for (int j = 0; j < numPossibleActors; j++) {
      int p;
      cin >> p;
    }
  }

  for (int i = 0; i < s; i++) {
    int numRolesInScene;
    cin >> numRolesInScene;
    for (int j = 0; j < numRolesInScene; j++) {
      int r;
      cin >> r;
    }
  }

  // Var noggrann med att flusha utdata när flödesgrafen skrivits ut!
  cout.flush();
}

void readGraphColouringProblem() {
  cin >> v >> e >> m;
  n = v+1;
  s = e+1;
  k = m+1;
  cout << n << "\n" << s << "\n" << k << "\n";

  for (int i = 0; i < n; i++) {
    //  p1, p2, … pk
    cout << k << " ";
    for (int j = 0; j < k; j++) {
      cout << j+1 << " ";
    }
    cout "\n";
  }

  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;

    cout << 2 << " " << a << " " << b; 
  }



  // Var noggrann med att flusha utdata när flödesgrafen skrivits ut!
  cout.flush();
}


int main(void) {
  // Två trick för att göra cin/cout lite snabbare.
  // Se http://kattis.csc.kth.se/doc/iostreamio
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  readRollbesattningsProblem();

  readGraphColouringProblem();

  return 0;
}

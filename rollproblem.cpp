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

int* allEdges;
int* allVertecies;

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

int readGraphColouringProblem() {
  // Antagande
  // e > 0
  // v > 0

  cin >> v >> e >> m;
  n = v+1;
  s = e+1;
  k = m+1;

  if (e < 1) {
    // e == 0  =>  Grafen gar att farga.
    return 0;
  }

  allVertecies = new int[n+1];
  allEdges = new int[e*2];
  int allEdgesPointer = 0;

  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    allVertecies[a] = 1;
    allVertecies[b] = 1;

    // Spara kanten.
    allEdges[allEdgesPointer] = a;
    allEdgesPointer++;
    allEdges[allEdgesPointer] = b;
    allEdgesPointer++;
  }
  // Räkna med divornas kant. (Gadget.)
  allVertecies[n] = 1;
  allVertecies[1] = 1;

  // Hantera isolerade horn. (Gadget.)
  for (int i = 1; i < n+1; i++) {
    if (allVertecies[i] == 0) {
      // Raknar isolerat horn.
      s++;
    }
  }

  return 1;
}

void printRollbesattningsProblem() {
  cout << n << "\n" << s << "\n" << k << "\n";

  for (int i = 0; i < n; i++) {
    //  p1, p2, … pk
    cout << k << " ";
    for (int j = 0; j < k; j++) {
      cout << j+1 << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < e*2; i += 2) {
    cout << 2 << " " << allEdges[i] << " " << allEdges[i+1] << "\n";
  }
  // Divornas kant. (Gadget.)
  cout << 2 << " " << n << " " << 1 << "\n";

  // Hantera isolerade horn. (Gadget.)
  for (int i = 1; i < n+1; i++) {
    if (allVertecies[i] == 0) {
      // Isolerat horn!
      cout << 2 << " " << i << " " << n << "\n";
    }
  }

  cout.flush();
}

void printJaInstance() {
  //Smalest yes instance of Rollbesattnings Problem.
  cout << 3 << "\n" << 2 << "\n" << 3 << "\n";
  cout << 1 << " " << 1 << "\n";
  cout << 1 << " " << 2 << "\n";
  cout << 1 << " " << 3 << "\n";
  cout << 2 << " " << 1 << " " << 3 << "\n";
  cout << 2 << " " << 2 << " " << 3 << "\n";
  
  cout.flush();
}


int main(void) {
  // Två trick för att göra cin/cout lite snabbare.
  // Se http://kattis.csc.kth.se/doc/iostreamio
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  //readRollbesattningsProblem();

  int check = readGraphColouringProblem();

  if (check) {
    printRollbesattningsProblem();
  } else {
    printJaInstance();
  }

  return 0;
}

//20191128 Jian Park
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  double a;
  
  cin >> a; // input real numbe a
  cout << fixed << setprecision(6) << sqrt(a) << endl; // output square root of number a
  return 0;
}
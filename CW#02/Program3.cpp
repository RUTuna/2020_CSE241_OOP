//20191128 Jian Park
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0)); // set seed is time(0)
  for(int i=0;i<3;i++){ // output three times
  cout << fixed << setprecision(6) << rand()/(float)RAND_MAX << ' '; // to make 0~1, division by RAND_MAX
  }
  return 0;
}
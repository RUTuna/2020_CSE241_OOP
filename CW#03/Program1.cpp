//20191128 Jian Park
#include <iostream>
using namespace std;

int main() {
  int a, b, sum=0;
  
  cin >> a >> b; // input two numbers a and b
  for(int i=a; i<=b; i++){ // when i is b from a
    sum=sum+i; // add i to sum
  }
  cout << sum << endl; // output sum
  return 0;
}
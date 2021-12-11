//20191128 Jian Park
#include <iostream>
using namespace std;

int main() {
  int a, i=2, result = 1; // a is input value, result is output value
  
  cin >> a ; // input number that to know prime number
  if (a==1)result = 0; // 1 is not prime number
  else {
    while(i < a) {
      if(a%i==0) {
        result = 0; // if the remainder divided by i is 0, it is not prime number
        break;
      } else {
        i++;
      }
    }
  }
  cout << result << endl;
  return 0;
}
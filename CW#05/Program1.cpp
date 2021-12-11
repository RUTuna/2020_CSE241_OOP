//20191128 Jian Park
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string myIntegerToBinary(int n){ // it is a function that converts n to binary number string and return it
  string bi; //string that save binary number
  int i=0;
  char c; // c is 
  
  while(n!=0){ //repeat until n becomes 0
    i=n%2; //i is the remainder of n divided by 2
    c=i+'0'; //change i to char and put it in c
    bi=c+bi; //add c to bi that is strinf
    n/=2; //n is the quotient of n divided by 2.
  }
  
  return bi; //returen bi
}

int main() {
  ifstream inFile; 
  ofstream outFile; //set file open mode
  inFile.open("Program1Input.txt"); //open input file
  outFile.open("Program1Output.txt"); //open output file
  int n;
  
  inFile >> n; //input n
  outFile << myIntegerToBinary(n); //output myIntegerToBinary(n)

  inFile.close(); //close input file
  outFile.close(); //close output file
  return 0;
}

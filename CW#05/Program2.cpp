//20191128 Jian Park
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int myFibonacci(int n){
  if(n==0) return 0; //if n is 0, return 0
  else if(n==1) return 1; //if n is 1, return 1
  else return myFibonacci(n-1)+myFibonacci(n-2); //another case return the sum of the (n ? 1)-th and (n ? 2)-th numbers
}

int main() {
  ifstream inFile;
  ofstream outFile; //set file open mode
  inFile.open("Program2Input.txt"); //open input file
  outFile.open("Program2Output.txt"); //open output file
  int n;
  
  inFile >> n; //input n
  outFile << myFibonacci(n); //output myFibonacci(n)
  
  inFile.close(); //close input file
  outFile.close(); //close output file
  return 0;
}

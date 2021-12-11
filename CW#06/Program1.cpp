//20191128 Jian Park
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

double mySwap(double *A, double *B){
  double tmp=*A;
  *A=*B;
  *B=tmp;
}

void Sort (double Data[], int n){
  int i,j;
  for(i=0; i<n; i++){
    for(j=0; j<n-1-i; j++){
      if(Data[j]>Data[j+1]) mySwap(&Data[j], &Data[j+1]);
    }
  }
}

int main() {
  ifstream inFile; 
  ofstream outFile; //set file open mode
  inFile.open("Program1Input.txt"); //open input file
  outFile.open("Program1Output20191128.txt"); //open output file
  
  int n=0, i=0, j;
  bool number = true; //dafault is true
  double Data[51];
  string data_string;
  long place;
  
  if(inFile.fail()){ //if can't find input file
    outFile << "Error#0";
  }else {
    place = inFile.tellg();
    while(inFile >> data_string){ //input string type
      inFile.seekg(place,ios::beg); 
      inFile >> Data[i]; //input double type
      if(!Data[i] && data_string != "0"){ // check input is number
        number = false; //if input is not number, 'number' is false
        break;
      }
      n++; i++; //n is number of input
      place = inFile.tellg();
    }
    if(!number){
      outFile << "Error#1"; //input is not number, output 'Error#1'
    } else {
      Sort(Data, n); //sorting Data
      for(i=0; i<n; i++){
        outFile << setprecision(10) << Data[i] << ' '; //output sorting result
      }
    }
  }
  
  inFile.close(); //close input file
  outFile.close(); //close output file
  return 0;
}

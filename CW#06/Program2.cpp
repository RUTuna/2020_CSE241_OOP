//20191128 Jian Park
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  ifstream inFileA, inFileB; 
  ofstream outFile; //set file open mode
  inFileA.open("Program2InputA.txt");
  inFileB.open("Program2InputB.txt"); //open input file
  outFile.open("Program2Output20191128.txt"); //open output file
  
  double A[11][11], B[11][11], C[11][11]={0};
  double r;
  bool number = true; // dafault is true
  int ax,ay,bx,by;
  int num;
  int i,j,k;
  
  if(inFileA.fail() || inFileB.fail()){ //if can't find input file A or B
    outFile << "Error#0";
  } else {
    inFileA >> ax >> ay;
    num=0;
    for(i=0; i<ax; i++){
      for(j=0; j<ay; j++){
        if(inFileA >> A[i][j]) num++; //count number of input
      }
    }
    if(num != ax*ay) number = false; //if num is not ax*ay that mean some input is not number

    inFileB >> bx >> by;
    if(ay!=bx){
      outFile << "Error#2";
    } else {
      num=0;
      for(i=0; i<bx; i++){
        for(j=0; j<by; j++){
          if(inFileB >> B[i][j]) num++;
        }
      }
      if(num != bx*by) number = false;
      
      if(!number){
        outFile << "Error#1";
      } else{
        for (k=0; k<ay; k++) { //calculat matrix multiplication
          for (i=0; i<ax; i++) {
            r = A[i][k];
            for (j=0; j<by; j++)
              C[i][j] += r * B[k][j];    
          }
        }
        
        outFile << ax << ' ' << by << endl;
        for(i=0; i<ax; i++){
          for(j=0; j<by; j++){
            outFile << fixed << setprecision(6) << C[i][j] << ' ';
          }
          outFile << "\n";
        }
      }

    }
  }

  inFileA.close();
  inFileB.close(); //close input file
  outFile.close(); //close output file
  return 0;
}
//20191128 Jian Park
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double mySwap(double *A, double *B){
  double tmp=*A;
  *A=*B;
  *B=tmp;
}

int main(){
  ifstream inFile; 
  ofstream outFile; //set file open mode
  inFile.open("Program3Input.txt"); //open input file
  outFile.open("Program3Output.txt"); //open output file

  int M, N;
  int i, j, k;
  double a[10][10]={0}, d;

  inFile >> M >> N;

  for (i=1; i<=N; i++)
    for (j=1; j<=N; j++)
      inFile >> a[i][j];
 
  for (i=1; i<=N; i++)
    for (j=1; j<=2*N; j++) 
      if (j == (i+N)) a[i][j] = 1;


  for (i=N; i>1; i--)
    if (a[i-1][1] < a[i][1])
      for (j=1; j<=N*2; j++) mySwap(&a[i][j], &a[i-1][j]);

 
  for (i=1; i<=N; i++){
    for (j=1; j<=N*2; j++){
      if (j != i){
        d = a[j][i]/a[i][i];
        for (k=1; k<=N*2; k++){
          a[j][k] -= a[i][k]*d;
        }
      }
    }
  }
    
  for (i=1; i<=N; i++){
    d=a[i][i];
    for (j=1; j<= N*2; j++) a[i][j] = a[i][j]/d;
  }
 
  for (i=1; i<=N; i++){
    for (j=N+1; j<=N*2; j++) cout << a[i][j] << " ";
    cout << fixed << setprecision(6) << endl;
  }

  inFile.close(); //close input file
  outFile.close(); //close output file
  return 0;
}
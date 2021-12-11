//20191128 Jian Park
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
  ifstream inFile;
  ofstream outFile; //set file open mode
  inFile.open("Input.txt"); //open input file
  outFile.open("Output.txt"); //open output file
  int C, T, S, count=0; //count is number of score that it is lower then average
  double avg=0; //avg is average
  long place;
  
  inFile >> C; //read C
  
  for(int i=0; i<C; i++){
    avg=0; count=0; //reset average and count
    inFile >> T; //read T
    place = inFile.tellg(); //set position
  
    for(int j=0; j<T; j++){
      inFile >> S; //read S
      avg+=S;
    }
    avg = avg/T; //calculate average
    inFile.seekg(place,ios::beg); //move point to before score for each class
    for(int j=0; j<T; j++){
      inFile >> S;
      if(S < avg) count++; //count score that it is lower then average
    }
    outFile << '#' << i+1 << ' ' << fixed << setprecision(6) << double(count)/double(T)*100 << '%' << endl; //write output file
    
  }
  
  inFile.close(); //close input file
  outFile.close(); //close output file
  return 0;
}

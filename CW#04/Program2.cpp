//20191128 Jian Park
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream file; //set file open mode
  file.open("Paragraph.txt"); //open input file
  string search, word;
  int count=0, len1, len2; //count is number of find word
  
  cin >> search; //input word that to know
  len1 = search.length(); //len1 is number of search
  for(int i=0; i<len1; i++){
    search[i] = tolower(search[i]); //search changes to lowercase
  }
  while(file >> word) { //read in words until no more words
    len2 = word.length();
    for(int j=0; j<len2; j++){
      word[j] = tolower(word[j]); //word changes to lowercase
    }
    if(search == word) count++; //when search and word is same, add 1 to count
  }
  cout << count << endl; //output count
  file.close(); //close file
  return 0;
}

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Uses two arguments:
 * arg1 - input file
 * arg2 - output file
 */

int main(int argc, char * argv[]){


   if(argc != 3){
	  cout << "This program requires a text file argument and an output file"
		 << endl;
	  return 0;
   }

   /* Empty file edge case */
   ifstream efile;
   efile.open(argv[1], ios::ate);
   if(efile.tellg() == 0){
	  ofstream outfile;
	  outfile.open(argv[2], ios::trunc);
	  outfile.close();
	  efile.close();
	  return 0;
   }

   // Open input file for reading 
   ifstream file;
   file.open(argv[1], ios::binary);
   string word;
   int nextByte = 0;

   // Opening out file for writing
   ofstream outfile;
   outfile.open(argv[2]);


   // Perform necessary operations for words
   while(file >> word){
	  outfile << word << endl;
   }


   outfile.close();
   file.close();

   return 0;
}

/* 
* Function ideas:
* 
*  - Function to place every word in an unordered_map to keep track of word
*  frequencies
* 
*  - Function to separate all sentences of a file and place them in a set
*
*/

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


//   if(argc != 3){
//	  cout << "This program requires a text file argument and an output file"
//		 << endl;
//	  return 0;
//   }

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

   if(argv[3] != NULL){
	  ifstream file;
	  file.open(argv[1], ios::binary);

	  ofstream testout;
	  testout.open(argv[3]);
	  
	  unsigned int character;

	  while( (character = file.get()) != EOF ){
		 if( (unsigned char)character == 'a' ){
			continue;
		 }
		 testout << (unsigned char)character;
	  }
   }

   return 0;
}

/* 
* Function ideas:
* 
*  - Function to place every word in an unordered_map to keep track of word
*  frequencies
* 
*  - Function to separate all sentences of a file and place them in a set
*	  - How to separate sentences? have cases when we encounter a character
*	  not within ASCII value range 33-127.
*	  - Have cases when we encounter sentence ending punctuation, like '.',
*	  '!', '?', ')' (perhaps if we've read a '(' beforehand), same for ']',
*	  bookend 'newlines'?
*	  - Periods followed by an uppercase character or number. IGNORE numbers
*	  immediately after a decimal point. Capital letters after a period
*	  signify start of new sentences. But also need to account for factorial
*	  numbers. (4!). Should functions work based on the fact that perfect
*	  sentences may not be able to be extracted?
*
*/

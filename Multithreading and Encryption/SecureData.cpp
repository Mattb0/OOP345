// Workshop 10 - Multi-Threading
 // SecureData.cpp
 #include <iostream>
 #include <fstream>
 #include <string>
 #include "SecureData.h"
#include <functional>
#include <thread>
 namespace w10 {

     void converter(char* t, char key, int n, const Cryptor& c) {
         for (int i = 0; i < n; i++)
             t[i] = c(t[i], key);
     }

     SecureData::SecureData(const char* file, char key) {
         // open text file
         std::fstream input(file, std::ios::in);
         if (!input)
             throw std::string("\n***Failed to open file ") +
             std::string(file) + std::string(" ***\n");

         // copy from file into memory
         nbytes = 0;
         input >> std::noskipws;

         while (input.good()) {
             char c;
             input >> c;
             nbytes++;
         }

         nbytes--;
         input.clear();
         input.seekg(0, std::ios::beg);
         text  = new char[nbytes + 1];

         int i = 0;
         while (input.good())
             input >> text[i++];
         text[--i] = '\0';
         std::cout << "\n" << nbytes << " bytes copied from text "
          << file << " into memory (null byte added)\n";
         encoded = false;

         // encode using key
         code(key);
         std::cout << "Data encrypted in memory\n";
     }

     SecureData::~SecureData() {
         delete [] text;
     }

     void SecureData::display(std::ostream& os) const {
         if (text && !encoded)
             os << text << std::endl;
         else if (encoded)
             throw std::string("\n***Data is encoded***\n");
         else
             throw std::string("\n***No data stored***\n");
     }

     void SecureData::code(char key) {
		const int threads = 4; // assuming
		 // -- http://en.cppreference.com/w/cpp/thread/thread --
		 std::thread t[threads];
			
		// Use std::bind from the functional library to bind the converter
		 for (int i = 1; i < threads; ++i)
		 {
			 t[i] = std::thread(converter, text, key, nbytes, Cryptor() );

		 }

         converter(text, key, nbytes, Cryptor());
         encoded = !encoded;
     }

     void SecureData::backup(const char* fileName) {
         if (!text)
             throw std::string("\n***No data stored***\n");
         else if (!encoded)
             throw std::string("\n***Data is not encoded***\n");
         else {
			 std::fstream file(fileName);  // open binary file
			 if (file.is_open() == false)
			 {
				 std::cerr << "Error. Cannot Open File";
				 std::cin.ignore();
			 }
         }
     }

	 void SecureData::restore(const char* fileName, char key) {
		 std::fstream file(fileName);  // open binary file
		 if (file.is_open() == false)
		 {
			 std::cerr << "Error. Cannot Open File";
			 std::cin.ignore();
		 }  
		 // Refenced: http://www.cplusplus.com/reference/istream/istream/tellg/

		 file.seekg(0, file.end);
		 int size = file.tellg();
		 nbytes = size;
		 text = new char[nbytes + 1];
       	 
		 // Reading the binary file
		 for (int i = 0; file.good(); i++)
		 {
			 file >> text[i];
		 }

         std::cout << "\n" << nbytes + 1 << " bytes copied from binary file " << " into memory (null byte included)\n";
         encoded = true;
         // decoding using a key
         code(key);
         std::cout << "Data decrypted in memory\n\n";
     }

     std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
         sd.display(os);
         return os;
     }
 }
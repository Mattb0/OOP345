 #include <iostream>
 #include "Stations.h"

 int main(int argc, char* argv[]) {  
     std::cout << "\nCommand Line : ";

     for (int i = 0; i < argc; i++) 
     {
         std::cout << argv[i] << ' ';
     }

     std::cout << std::endl;
     if (argc != 2) {
         std::cerr << "\nIncorrect number of arguments\n";
		// system("PAUSE"); // disable debug
     	return 1;
     }
     w2::Stations stations(argv[1]);  // namespace
     stations.update();  // call update 
     stations.restock(); // call restock
     stations.report();  // call report
	// system("PAUSE");  // disable debug
     return 0;
 }
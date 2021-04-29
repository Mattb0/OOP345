	Stations processes information about the monthly passes stored at a set of
	monitored Subway stations.  

	The Stations constructor receives the name of a file in the form of a C-style, 
	null-terminated string. 

	The file contains all of the data for the monitored stations (see below). 
	The first record holds the number of stations and the delimiter character for name input. 

	Each subsequent record holds the name of a station followed by the delimiter, 
	the number of students passes and the number of adult passes.  

	Upon instantiation, a Stations object opens the file,  allocates memory for the 
	monitored stations and copies the data from the file to each Station object.

	Upon destruction,  a Stations object copies the updated data from memory to the same file, 
	overwriting the previous records.
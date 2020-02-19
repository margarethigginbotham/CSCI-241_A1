/***********************************************************
CSCI 241 - Assignment 1 - Fall 2017

Progammer: Margaret Higginbotham
Z-ID: z1793581
Section: 3
TA: Bhavana Mallineni
Date Due: September 14, 2017

Purpose: The assignment is an exercise in writing, compiling, and
         executing a C++ program on the departmental UNIX system.
	 It also covers the basics of object-oriented programming
	 and the manipulation of C and C++ strings.
************************************************************/

#include <iostream>	//Libraries used
#include <cstring>
#include <fstream>
#include <string>

using std::cout;	//Using declarations
using std::endl;
using std::ifstream;
using std::string;
using std::strcpy;
using std::strlen;

#define ARRAY_SIZE 40	//Maximum number of records

class Provider{

  private:
			//Data members for all of the provider's information
    char number[7];
    char specialty[41];
    char name[41];
    char firstAddress[41];
    char secondAddress[31];
    char city[21];
    char state[3];
    char zipCode[6];
    char phoneNumber[15];

  public:

    Provider();		/*Constructor function
			  Set method prototypes for all the the provider's information*/
    void setNumber(const char*);
    void setSpecialty(const char*);
    void setName(const char*);
    void setFirstaddress(const char*);
    void setSecondaddress(const char*);
    void setCity(const char*);
    void setState(const char*);
    void setZipcode(const char*);
    void setPhonenumber(const char*);
    void print();
};

int information(Provider[]);	/*Function protoype for a function that reads
				  through the provider's information*/
Provider::Provider(){}		//Default constructor method

//Class methods
/***************************************************************
Provider::setNumber
Use: sets the number from the original array to be the provider's
     number
Parameters: 1. char*- the numbers from the original list
Returns: nothing
***************************************************************/
void Provider::setNumber(const char* newNumber){
  strcpy(number, newNumber);
}

/***************************************************************
Provider::setSpecialty
Use: sets the specialty from the original array to be the provider's
     specialty
Parameters: 1. char*- the specialty  from the original list
Returns: nothing
***************************************************************/
void Provider::setSpecialty(const char* newSpecialty){
  strcpy(specialty, newSpecialty);
}

/***************************************************************
Provider::setName
Use: sets the name from the original array to be the provider's
     name
Parameters: 1. char*- the name from the original list
Returns: nothing
***************************************************************/
void Provider::setName(const char* newName){
  strcpy(name, newName);
}

/***************************************************************
Provider::setFirstaddress
Use: sets the first address from the original array to be the
     provider's first address
Parameters: 1. char*- the first address from the original list
Returns: nothing
***************************************************************/
void Provider::setFirstaddress(const char* newFirstaddress){
  strcpy(firstAddress, newFirstaddress);
}

/***************************************************************
Provider::setSecondaddress
Use: sets the second address from the original array to be the
     provider's second address
Parameters: 1. char*- the second address from the original list
Returns: nothing
***************************************************************/
void Provider::setSecondaddress(const char* newSecondaddress){
  strcpy(secondAddress, newSecondaddress);
}

/***************************************************************
Provider::setCity
Use: sets the city from the original array to be the provider's
     city
Parameters: 1. char*- the city from the original list
Returns: nothing
***************************************************************/
void Provider::setCity(const char* newCity){
  strcpy(city, newCity);
}

/***************************************************************
Provider::setState
Use: sets the state from the original array to be the provider's
     state
Parameters: 1. char*- the state from the original list
Returns: nothing
***************************************************************/
void Provider::setState(const char* newState){
  strcpy(state, newState);
}

/***************************************************************
Provider::setZipcode
Use: sets the zip code from the original array to be the provider's
     zip code
Parameters: 1. char*- the zip code from the original list
Returns: nothing
***************************************************************/
void Provider::setZipcode(const char* newZipcode){
  strcpy(zipCode, newZipcode);
}

/***************************************************************
Provider::setPhonenumber
Use: sets the phone number from the original array to be the
     provider's phone number
Parameters: 1. char*- the phone number from the original list
Returns: nothing
***************************************************************/
void Provider::setPhonenumber(const char* newPhonenumber){
  strcpy(phoneNumber, newPhonenumber);
}

/***************************************************************
Provider::print
Use: Prints the information
Parameters: none
Returns: nothing
***************************************************************/
void Provider::print(){
  cout << endl <<  "#" << number <<endl
       << name << endl
       << specialty << endl
       << firstAddress << endl
       << secondAddress << endl
       << city << ", " << state << " " << zipCode << endl
       <<phoneNumber << endl;
}

//Function
/***************************************************************
Provider::information
Use: Sets the numbers from the original array to be the provider's
     number
Parameters: 1. Provider- the list of all the information of the
               providers
Returns: 1. int- keeps track of which lines in the csv document
                 have been read
****************************************************************/
int information(Provider list[]){
  string numberStr,		//Declares the provider's information as C++ string objects
         specialtyStr,
         lastNameStr,
         firstNameStr,
         middleNameStr,
         titleStr,
         firstAddressStr,
         secondAddressStr,
         cityStr,
         stateStr,
         zipCodeStr,
         phoneNumberStr,
         fullNameStr;		//fullName used to decided whether or not a middle name is present

         ifstream inFile;	//Declares the input file variable
	 int line = 0;		//Keeps track of which line that is read

  inFile.open("providers.csv");		//Opens the input file
					//While loop keeps it looping until the end of the document
  while(inFile.good()){		//.good() ensures the input file does not return any errors
    getline(inFile,numberStr,',');	//getline fuctions assign each bit of information to a C++ string object
    getline(inFile,specialtyStr,',');
    getline(inFile,lastNameStr,',');
    getline(inFile,firstNameStr,',');
    getline(inFile,middleNameStr,',');
    getline(inFile,titleStr,',');
    getline(inFile,firstAddressStr,',');
    getline(inFile,secondAddressStr,',');
    getline(inFile,cityStr,',');
    getline(inFile,stateStr,',');
    getline(inFile,zipCodeStr,',');
    getline(inFile,phoneNumberStr);	//No delimiter because that it is the last bit of information
						//First it assigns middleName to a C string
    if(strlen(middleNameStr.c_str()) != 0)	//Then it it is not 0, there is a middle name
      fullNameStr = lastNameStr + ", " + firstNameStr + "," + middleNameStr + "," + titleStr;
						//Else, then there is not a middle name
    else
      fullNameStr = lastNameStr + ", " + firstNameStr + ", " + titleStr;

    list[line].setNumber(numberStr.c_str());            //First converts each C++ string object to C strings
    list[line].setName(fullNameStr.c_str());            //then calls the set method to assign each to their
    list[line].setSpecialty(specialtyStr.c_str());      //corresponding class data member
    list[line].setFirstaddress(firstAddressStr.c_str());
    list[line].setSecondaddress(secondAddressStr.c_str());
    list[line].setCity(cityStr.c_str());
    list[line].setState(stateStr.c_str());
    list[line].setZipcode(zipCodeStr.c_str());
    list[line].setPhonenumber(phoneNumberStr.c_str());

    line++;		//Incrememnts the line number at the end each time
  }

  line--;

  return line;		//Returns the line number
}

/***************************************************************
main
Function: Program reads a file of records into an array of objects
	  and loops through the array to print all fo the objects.
Input: ~t90kjm1/CS241/Data/Fall2017/Assign1/providers.csv
       List of providers and their information in a not pleasing
       format.
Output: ~t90kjm1/CS241/Data/Fall2017/Assign1/assign1
	List of the providers and their information in an easy to
	read format.
****************************************************************/
int main(){
  Provider list[ARRAY_SIZE];		//Creates an array with the maximum amount of possible providers
  ifstream inFile;			//Declares the input file variable

  inFile.open("providers.csv");         //Opens the providers.csv file makes sure it opens correctly

 if(!inFile){
    cout << "Error: Could not open file" << endl;
    exit(1);
  }

  for(int i = 0; i < information(list); i++){		//Loop that prints the information while the providers
    list[i].print();					//list is not at thee end
  }

  inFile.close();				//Closes the providers file at the end

  cout << endl;

  return 0;
}


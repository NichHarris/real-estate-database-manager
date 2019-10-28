# real-estate-database-manager
COEN244 Assignment 3
COEN 244 (Fall 2019) - Assignment 3
Deadline: October 21 by 11:59PM
Type: Group Assignment
Weight: This assignment is worth 4% of your final grade
IMPORTANT:
- You must include the name and student number of both members of a group in
every file. All .h and .cpp files must be submitted in a folder.
- The assignments must be submitted on Moodle. Assignments sent by email
won’t be corrected.
- No late submission policy.
We defined the following classes to manage the database for a real estate agency.
Implement these classes with necessary set and get functions for each class. The
print function for each class outputs all the data members of that class. Write a
driver program that tests all your classes thoroughly and demonstrates
polymorphism.

class Date
{
public:
 Date ( );
 Date(int, int, int);
 void print( );
private:
int month;
int day;
int year;
};

class Person
{
public:
 Person ( );
 Person(string, string, Date);
 ~ Person( );
 virtual void print ( );
private:
string name;
string address;
};

class Client : public Person
{
 public:
 Client ( );
 Client(string, string, string);
 ~ Client( );
 virtual print( );
private:
 string socialinsurancenumber;
};

class RealEstateAgent : public Person
{
 public:
 RealEstateAgent( );
 RealEstateAgent(string, string, Date, int);
 ~ RealEstateAgent( );
 virtual print( );
 private:
 Date employment_date;
 int employee_id;
};

class Property
{
 public:
 Property();
 Property(string, string, Client, RealEstateAgent *, Date);
 ~ Property( );
 virtual print( );
private:
 string street_address;
 string cityname;
 Client * seller; // Initialized to the Client parameter of the constructor function.
 Client * buyer; // Initialized to a null pointer.
 RealEstateAgent * agent;
 Date listingdate;
};

class LandSale: public Property
{
 public:
 LandSale ( );
 LandSale(string, string, Client, RealEstateAgent, Date, double, int);
 ~ LandSale( );
 virtual print( );
 private:
 double area;
 int price;
};

class HouseSale: public Property
{
 public:
 HouseSale ( );
 HouseSale(string, string, Client, RealEstateAgent, Date, int, int, int);
 ~ HouseSale( );
 virtual print( );
 private:
 int year_of_built;
 int no_of_rooms;
 int price;
};

class ApartmentSale : public Property
{
 public:
 ApartmentSale();
 ApartmentSale (string, string, Client, RealEstateAgent, Date, int, int, int, int);
 ~ ApartmentSale( );
 virtual print( );
 private:
 int year_of_built;
 int no_of_rooms;
 int condominium_fee;
 int price;
};

class RealEstateManager
{
 private:
 static const max_number_of_agents = 30;
 static const listingsize = 1000;
 static const archivesize = 2000;

// The followings are array of pointers, all the arrays should be initialized to null values.
RealEstateAgent * agentRecordsArray[max_number_of_agents];
Property * propertyListingArray[listingsize];
Property * archiveRecordsArray[archivesize];
 public:
 RealEstateManager( );
// insertAgent function adds a new agent to the agentRecordsArray
 bool insertAgent(RealEstateAgent *);
// insertProperty function adds a property to the first available location in the
// propertyListingArray
 bool insertProperty(Property *);
// When a property is sold, the buyer will be stored in the Property object and
// the object itself will be transferred from propertyListingArray to the
// archiveRecordsArray and null value will be inserted at its location at the
// propertyListingArray.
 bool propertysold(Property *, Client *);
// findHousesCity function determines all the houses for sale in a given city and
// prints them. String parameter of the function corresponds to a city name. You would
// need to use dynamic_cast to determine the class of the objects stored in the
// propertyListingArray.
void findHousesCity( string);
// findPropertiesAgent function determines all the listings of an agent and prints them.
void findPropertiesAgent(RealEstateAgent *);
};

Key Considerations for the assignment:
! You must enforce encapsulation by keeping all data members private.
! For each class that you create you need to separate the specification of the class from
its implementation by using header files. Make sure that you submit with your answer
both the .h and .cpp files for each class.
! In the implemented member functions the relevant data members should be updated.
! You need to make sure that your classes are well defined using the various concepts
seen in the class including constant member functions, static members, inline
functions, etc.
! Objects should be created dynamically and must be deleted when no longer needed.
There should be an output statement confirming the deletion of an object from the
destructor function.

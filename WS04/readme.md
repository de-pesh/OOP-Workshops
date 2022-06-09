# Workshop #4: Constructors, Destructors, and the *this* object
* Version 1.1<br />
  report signature corrected<br />
  Overview recording uploaded
## Overview session
Click [HERE](https://youtu.be/Q8gyz9sycZo) to view the overview session recording

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:


- Create default and overloaded constructors
- Create destructors
- Initialize class member variables 
- Release member pointers

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your OOP244 class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

Depending on the section you are enrolled in, the submission due day of the week may shift a day or two. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]

### Overall workshop due days
- day 1: Workshop open for preview<br/>
  (If you need to check your program with the submitter, you can use `-feedback` option to test the execution without submission)
- day 2: submission opens for both parts 1 and 2
- day 5: (end of day) Part 1 due
- day 8: (end of day) Part 2 due
- day 9: (end of day) submissions rejected

If at the deadline (end of day 8) the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

# Part 1, The Car Inventory - lab (50%)  
## `Car` Module
Design and implement a class named `Car` that stores the following information for a car entry:
* Type of the car (i.e SUV)
* The brand of the car (i.e Volvo)
* The model of the car (i.e XC90)
* The year of the car (i.e 2021)
* The code for the car inventory (i.e 100)
* The price of the car (i.e 90000)

Each object of the class `Car` can be created in either of the following ways:
* By default set everything to **nullptr** and **0**
* Provide the type, brand, and model of the car
* Provide all the required information

The `Car` provides functionalities to reset the information, add information, print the information, check the validity of the information, and check if two entries are the same. Details of these will be provided below.

## Implementation
Create a class named `Car` and add the following members.

### Private Member Variables

```C++
char* m_type;
char* m_brand;
char* m_model;
int m_year;
int m_code;
double m_price;
```
#### Valid Car member variable values  
```Text
type, not null or empty
brand, not null or empty
model, not null or empty
year >= 1990
code, three digit integer
price > 0
```
### Constructors
```C++
Car();
```
The default constructor will initialize the member variables by calling the `resetInfo()` method (the details of this method will be provided in the **Private Member** section.

--------------------------------------------------------

```C++
Car(const char* type, 
    const char* brand, 
    const char* model, 
    int year, 
    int code, 
    double price);
```
This constructor will dynamically keep the values of the C-string argument in their corresponding attributes and set the rest of the attributes the corresponding argument values if they pass validation. Otherwise it will reset the information (see **void resetInfo()**)<br />

When instantiated using this constructor, if the **year**, **code** or **price** arguments are not provided they will be set to **2022**, **100** and **1**  using default values for the arguments.

--------------------------------------------------------
### Destructor

This destructor should deallocate all they dynamically allocated memory.

--------------------------------------------------------

### Private Member
```C++
void resetInfo();
```
This method resets the values for all member variables by setting type, brand, and model to **nullptr** and setting the year, code, and price to 0.

--------------------------------------------------------
### Public Members
```C++
Car& setInfo(const char* type, 
             const char* brand, 
             const char* model, 
             int year, 
             int code, 
             double price);
```
This method will first deallocate all the allocated memory and then sets the attributes to the corresponding arguments exactly like the 6 argument constructor. <br />
Note: this function does not have any default values for its arguments.<br />
In the end, it will return the reference of the current object.


--------------------------------------------------------
```C++
void printInfo() const;
```
This method prints the values of all the member variables on the screen in following format.<br />
Order:<br />
TYPE,BRAND,MODEL,YEAR,CODE,PRICE<br />
Spacing:
```text
| 10  spaces | 16        spaces | 16        spaces | 9999 |  999 | 999999.99 |
```

--------------------------------------------------------
```C++
bool isValid() const;
```
This method returns whether all member variables have valid values or not based on the criteria stated at the [Private Member Variables](#valid-car-member-variable-values).

--------------------------------------------------------
```C++
bool isSimilarTo(const Car& car) const;
```
This function is to check whether the type, brand, model and year of an object of `Car` are equal to another object of this class. The function will return `true` only if all those values match. 

--------------------------------------------------------
### Global helper functions

Implement a global function in the `sdds` namespace to check whether there are duplicate entries in the entire inventory.
```C++
bool has_similar(const Car car[], const int num_cars)
```
It returns `true` if it finds two `Car` objects that have similar information in the car array. See below for the function implementation logic:
```C++
for (int i = 0; i < num_cars; i++){
  for (int j = i+1; j < num_cars; j++){
    if (car[i] is Simialr to car[j]){
        // match is found
    }
  }
}
```
--------------------------------------------------------

Implement a global function in the `sdds` namespace to check whether there are duplicate entries in the entire inventory.
```C++
bool has_invalid(const Car car[], const int num_cars)
```
It returns `true` if it finds an invalid **Car** in the car array, otherwise it returns false;
--------------------------------------------------------
Implement a global function in the `sdds` namespace to print and array of valid Cars and ignore the invalid Cars:
```C++
void print(const Car car[], const int num_cars);
```
--------------------------------------------------------

### Tester Program
```C++
/* ------------------------------------------------------
Workshop 4 part 1
Filename: main.cpp
Version 1.0
Author: Asad Norouzi
-----------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include "Car.h"
using namespace std;
using namespace sdds;

int main()
{
	const int num_cars = 6;
	Car carInventory[num_cars] = {
		{},
		{"suv", "volvo", "xc90"},
		{"Truck", "Ford", "F 150", 2021, 105, 55000},
		{"Sedan", "BMW", "M550i", 2022, 101, 91000},
		{"Truck", "Tesla", "Cybertruck", 2021, 102, 65000},
		{"Sedan", "BMW", "M550i"}
	};
	
	if (carInventory[2].setInfo("SUV", "Volvo", "XC90", 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo(nullptr, "Volvo", "XC90", 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", nullptr, "XC90", 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", nullptr, 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", "XC90", 1934, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", "XC90", 2019, 1, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (carInventory[1].setInfo("SUV", "Volvo", "XC90", 2019, 109, 0).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}

	cout << setw(60) << "----- Testing printInfo function -----" << endl << endl;
	cout << "| Type       | Brand            | Model            | Year | Code |     Price |" << endl;
	cout << "+------------+------------------+------------------+------+------+-----------+" << endl;
	carInventory[4].printInfo();
	cout << endl << endl;
	cout << setw(60) << "----- Car Inventory Information -----" << endl << endl;
	cout << "| Type       | Brand            | Model            | Year | Code |     Price |" << endl;
	cout << "+------------+------------------+------------------+------+------+-----------+" << endl;
	print(carInventory, num_cars);

	if (has_invalid(carInventory, num_cars)) {
		cout << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
		cout << "*  WARNING: There are invalid data in the inventory!      *" << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
	}
	if (has_similar(carInventory, num_cars)) {
		cout << endl;
		cout << setfill('+') << setw(60) << "+" << endl;
		cout << "+  WARNING: There are similar entries in the inventory!   +" << endl;
		cout << setfill('+') << setw(60) << "+" << endl;
	}
	return 0;
}
```
### Expected Output
```Text
Information was set correctly!
Information was set incorrectly!
Information was set incorrectly!
Information was set incorrectly!
Information was set incorrectly!
Information was set incorrectly!
Information was set incorrectly!
                      ----- Testing printInfo function -----

| Type       | Brand            | Model            | Year | Code |     Price |
+------------+------------------+------------------+------+------+-----------+
| Truck      | Tesla            | Cybertruck       | 2021 |  102 |  65000.00 |


                       ----- Car Inventory Information -----

| Type       | Brand            | Model            | Year | Code |     Price |
+------------+------------------+------------------+------+------+-----------+
| SUV        | Volvo            | XC90             | 2019 |  109 |  80000.00 |
| Sedan      | BMW              | M550i            | 2022 |  101 |  91000.00 |
| Truck      | Tesla            | Cybertruck       | 2021 |  102 |  65000.00 |
| Sedan      | BMW              | M550i            | 2022 |  100 |      1.00 |

************************************************************
*  WARNING: There are invalid data in the inventory!      *
************************************************************

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+  WARNING: There are similar entries in the inventory!   +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


```

### Files to submit:  

```Text
Car.h
Car.cpp
main.cpp
```

### Data Entry

No Data Entry required.

### Submission Process:

Upload your the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# PART 2 - DIY (50%)


Create a module for a fleet of cleaning robots. A robot object displays the details of the robots in the designated areas.

The class name is called `CleanerBot` and should hold the following information for a robot:
* Location (Dynamic Cstring) ==> indicates the robot's current location
* Battery (double) ==> holds the robot's remaining battery percentage
* Brush (int) ==> holds the robot's number of brushes
* Active (YES|NO) ==> indicated whether the robot is active or not

### Public and mandatory functions, constructors, and destructors

#### Constructors
* Default constructor for a robot with no information to set the robot into an empty state
* Constructor with 4 arguments to initialize the robot information in the following order:<br />
location, battery, brush, active

#### Destructor
* The destructor must handle any potential memory leak.

#### Functions
##### Modifiers
* `set`: to set the robot information (same order as the constructor)
* `setLocation`: to set the robot location
* `setActive`: to set the robot active status (true or false)

##### Queries
* `getLocation`: to return the robot location
* `getBattery`: to return the robot remaining battery percentage
* `getBrush`: to return the robot number of brushes
* `isActive`: to return if a robot is active
* `isValid`: to return if the robot information is valid
-----------------------------------
* `display`: to display the information in the following format. (Numbers on top are not printed; they are used as a ruler)
```Text
Name, Location, Weight, Width, Height, Speed, Deployed:
     1            2             3              4  
1234567890123456789012345678901234567890123456789012
| LOCATION   | 99999.9 | 9999999999999999 | NO/YES |
Example:
| Kitchen    |    88.6 |                5 | YES    |
```

#### The Robots Information stand alone report function

~~int report(CleanerBot* bot, const short num_bots);~~<br/>
```C++
//this will not change the outcome but is the correct signature of the report
int report(CleanerBot* bot, short num_bots);
```
This function receives an array of robots and prints a report of their information and a warning message that is displayed if there are robots with less than 30% remaining battery. The warning message displays the number of robots with low battery and also displays a sorted list of robots based on their battery power in descending order.

Note that invalid robots are not displayed in the report. 
  
Function execution sample for an array of 8 robots with two robots with low batteries and two invalid robots.

```Text
         ------ Cleaner Bots Report -----
     ---------------------------------------
| Location   | Battery |  Number of Brushes | Active |
|------------+---------+--------------------+--------|
| library    |    82.5 |                  7 | NO     |
| corridor   |    75.0 |                  3 | YES    |
| pantry     |    23.6 |                 12 | NO     |
| parking    |    30.1 |                  9 | YES    |
| storage    |    57.0 |                  2 | YES    |
| basement   |    29.9 |                  1 | YES    |

|====================================================|
| LOW BATTERY WARNING:                               |
|====================================================|
| Number of robots to be charged: 2                  |
| Sorting robots based on their available power:     |
| Location   | Battery |  Number of Brushes | Active |
|------------+---------+--------------------+--------|
| library    |    82.5 |                  7 | NO     |
| corridor   |    75.0 |                  3 | YES    |
| storage    |    57.0 |                  2 | YES    |
| parking    |    30.1 |                  9 | YES    |
| basement   |    29.9 |                  1 | YES    |
| pantry     |    23.6 |                 12 | NO     |
|====================================================|

> You may add as many additional functions to the robot module as you like to accomplish this task.

### Tester Program
```C++
/* ------------------------------------------------------
Workshop 4 part 2
Module: N/A
Filename: main.cpp
Version 1.0
Author: Asad Norouzi 
-----------------------------------------------------------*/
#include <iostream>
#include "CleanerBot.h"

using namespace std;
using namespace sdds;

int main()
{
	const int num_bots = 8;
	CleanerBot bot[num_bots] = {
		{},
		{"library", 82.5, 7, false},
		{"corridor", 75, 3, true},
		{"pantry", 23.6, 12, false},
		{"parking", 30.1, 9, true},
		{"storage", 57, 2, true},
		{"?", -1, 1, false},
		{"basement", 29.9, 1, true}
	};

	report(bot, num_bots);

	return 0;
}
```

### Expected Output
```Text
         ------ Cleaner Bots Report -----
     ---------------------------------------
| Location   | Battery |  Number of Brushes | Active |
|------------+---------+--------------------+--------|
| library    |    82.5 |                  7 | NO     |
| corridor   |    75.0 |                  3 | YES    |
| pantry     |    23.6 |                 12 | NO     |
| parking    |    30.1 |                  9 | YES    |
| storage    |    57.0 |                  2 | YES    |
| basement   |    29.9 |                  1 | YES    |

|====================================================|
| LOW BATTERY WARNING:                               |
|====================================================|
| Number of robots to be charged: 2                  |
| Sorting robots based on their available power:     |
| Location   | Battery |  Number of Brushes | Active |
|------------+---------+--------------------+--------|
| library    |    82.5 |                  7 | NO     |
| corridor   |    75.0 |                  3 | YES    |
| storage    |    57.0 |                  2 | YES    |
| parking    |    30.1 |                  9 | YES    |
| basement   |    29.9 |                  1 | YES    |
| pantry     |    23.6 |                 12 | NO     |
|====================================================|

```
# Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
CleanerBot.cpp
CleanerBot.h
main.cpp
```

### Data Entry

No data entry required!

## Submission Process:

Upload your the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

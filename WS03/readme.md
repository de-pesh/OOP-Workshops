# Workshop #3: Member Functions and Privacy
* version 1.0

In this workshop, you will use member functions, privacy, safe empty state and formatting of the output to complete your work.
## The Overview session

The overview session Was held on Wed. July 1st at 14:00.

To View the session click here [WS3 Overview](https://youtu.be/E7dzJCWwy3U)
## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities:

- to define a class type
- to privatize data within the class type
- to instantiate an object of class type
- to use member functions to query the state of an object
- to use member functions to change the state of an object
- to use standard library facilities to format data inserted into the output stream
- to describe to your instructor what you have learned in completing this workshop


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

# Part 1 - lab (50%) The Army Class

## the class
Code an Army class that holds the information for an Army. The class must have private data members to include the following information:
a) the nationality of an Army,
b) the number of units in an Army, and
e) the power of an Army.

Declare one C++ constant, namely MAX_NAME_LEN and set it to 50.

Declare three private data members. 
1) Declare an array to hold the nationality of an Army, not exceeding MAX_NAME_LEN characters. 
2) Declare an integer variable for the number of units in an Army. 
3) Declare a double variable for the power of an Army.

Store your class definition in a header file named Army.h and your member function definitions in an implementation file named Army.cpp.

## Public Member functions

Declare and implement the following member functions.

### setEmpty:
```void setEmpty();```

This member function initializes the Army object to a safe empty state. An Army is in an empty state when it has an empty nationality and no units.

### createArmy:
```void createArmy(const char* country, double pow, int troops);```

It uses three input parameters to initialize an Army object. It receives the nationality of an Army, the number of units in an Army and the power of the Army. It validates the data values received and uses these data values to set the respective data members, only if all of them are valid. 
            
All the data values are valid if 
a) the first parameter is not nullptr and the length of the name is greater than zero, 
b) the number of units is greater than zero
c) the power is greater than zero. 

> Note: Only copy the first MAX_NAME_LEN characters from the input parameter to the cString data member that holds the nationality of an Army. (you could use &lt;cstring&gt; strncpy() or your own utility function for this )

If the data values are invalid, the member function initializes the Army object to a safe empty state.

### updateUnits:
```void updateUnits(int troops);```
Update your Army by incrementing the units with the amount of provided troops also the power of the Army will be increased by a value equal to 25% of the newly provided troops.

### checkNationality:
```const char* checkNationality() const;```

This query returns the nationality of an Army.

### checkCapacity: 
```int checkCapacity() const;```

This query returns the number of units in an Army.

### checkPower:
```double checkPower() const;```

This query returns the power of an Army.
   
### isEmpty: 
```bool isEmpty() const;```

This query returns true if the Army object is in a safe empty state; false otherwise.

### isStrongerThan: 
```bool isStrongerThan(const Army& army)const;```

This function returns true if the Army has more power than the incoming Army, and returns false otherwise.
## Global (stand-alone) functions

### battle: 
```void battle( Army& arm1, Army& arm2);```

This function will force both armies to fight. If both armies are valid, the losing Army will lose 50% of their unit count
	   PS: - you might want to use the isStrongerThan function to check which Army will win
		   - you might want to use the updateUnits function to update the losing country. Passed value needs to be casted to an int

### display: 
```void displayDetails(const Army* armies, int size);```

This function sends the information about an Army array to standard output in the following format if the object holds valid data values.

```
Armies reporting to battle:<ENDL>
```

Each Army in the array will be printed in the following format.

```
Nationality: XXXXXXXXXXX, Units Count: XXXX, Power left: X.X<ENDL>
```
Power left has one digit after the decimal point.

## Testing Program
```
/* ------------------------------------------------------
Workshop 3 part 1
Module: N/A
Autor: Mohammad Shamas
Filename: main.cpp
Version 1.0
-------------------------------------------------------*/

#include <iostream>
using namespace std;
#include "Army.h"
using namespace sdds;

int main() {

	Army armies[6]{};

	armies[0].createArmy("Atlantis", 500.5, 1000);
	armies[1].createArmy("", 100.0, 100);
	armies[2].createArmy("Ambrosia", 215.0, 520);
	armies[3].createArmy("United States of Auradon", 220.5, 751);
	armies[4].createArmy("Azmenistan", 250.0, 750);
	armies[5].createArmy(nullptr, 250.5, 750);

	//Test 1
	cout << "----------------------------------------" << endl;
	cout << "1. Testing the validation logic." << endl;
	cout << "(only 4 armies should be valid (0,2,3,4) )" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "armies[" << i << "]: "
			<< (armies[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;
	//Test 2
	cout << "----------------------------------------" << endl;
	cout << "2. Testing the display function." << endl;
	cout << "----------------------------------------" << endl;
	displayDetails(armies, 6);
	cout << "----------------------------------------" << endl << endl;
	// Test 3
	cout << "----------------------------------------" << endl;
	cout << "3. Testing the member functions without the update." << endl;
	cout << "----------------------------------------" << endl;
	Army backup;
	backup.createArmy("Foreigners", 100, 100);
	cout << backup.checkNationality()
		<< ','
		<< backup.checkCapacity()
		<< ','
		<< backup.checkPower() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 4
	cout << "----------------------------------------" << endl;
	cout << "4. Testing the member functions with the update." << endl;
	cout << "----------------------------------------" << endl;
	backup.updateUnits(100);
	cout << backup.checkNationality()
		<< ','
		<< backup.checkCapacity()
		<< ','
		<< backup.checkPower() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 5
	cout << "----------------------------------------" << endl;
	cout << "5. Testing the battle function." << endl;
	cout << "----------------------------------------" << endl;
	battle(armies[0],armies[2]);
	battle(armies[3], armies[4]);
	displayDetails(armies, 6);
	cout << "----------------------------------------" << endl << endl;
	return 0;
}
```

## Sample Output
```
----------------------------------------
1. Testing the validation logic.
(only 4 armies should be valid (0,2,3,4) )
----------------------------------------
armies[0]: valid
armies[1]: not valid
armies[2]: valid
armies[3]: valid
armies[4]: valid
armies[5]: not valid
----------------------------------------

----------------------------------------
2. Testing the display function.
----------------------------------------
Armies reporting to battle:
Nationality: Atlantis, Units Count: 1000, Power left: 500.5
Nationality: Ambrosia, Units Count: 520, Power left: 215.0
Nationality: United States of Auradon, Units Count: 751, Power left: 220.5
Nationality: Azmenistan, Units Count: 750, Power left: 250.0
----------------------------------------

----------------------------------------
3. Testing the member functions without the update.
----------------------------------------
Foreigners,100,100.0
----------------------------------------

----------------------------------------
4. Testing the member functions with the update.
----------------------------------------
Foreigners,200,125.0
----------------------------------------

----------------------------------------
5. Testing the battle function.
----------------------------------------
In battle of Atlantis and Ambrosia, Atlantis is victorious!
In battle of United States of Auradon and Azmenistan, Azmenistan is victorious!
Armies reporting to battle:
Nationality: Atlantis, Units Count: 1000, Power left: 500.5
Nationality: Ambrosia, Units Count: 260, Power left: 150.0
Nationality: United States of Auradon, Units Count: 376, Power left: 126.8
Nationality: Azmenistan, Units Count: 750, Power left: 250.0
----------------------------------------



```
## PART 1 Submission 

### Files to submit:  

```Text
Army.h
Army.cpp
main.cpp
```
### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.




# Part 2 - DIY (50%)
> Except for the mandatory sections of DIY, all the other parts can be changed by students if they find it necessary as long as the program produces an output that exactly matches the required output.

Write a **Bar Chart** program that receives several sample values and creates a bar chart based on the values of the samples received. 

A **BarChart** is a collection of valid **Bar**s that are drawn horizontally on the screen:  

  
```Text
Bar Chart Title
-----------------------------------------------------------------------
First sample title..|=====
Second Sample.......|=============================================
Third Sample........|====================
Fourth..............|=======
Fifth...............|=========================
And Six.............|===============
-----------------------------------------------------------------------
```

A Bar object illustrates a sample that consists of a title and an integer value between 0 and 100.

The **BarChart** is initialized (using init() method) by the title of the survey, the number of the samples (ie. Bars to be drawn) and the fill character to draw the bars.

> Note: The **Title of the chart** and **the Bars** in the **BarChart** are to be held dynamically; Which means a **BarChart** class has a dynamic array of **Bar** class objects.

Each sample is **added** to the chart by the **title** and the **value** of the sample to be represented by a **Bar** in the **BarChart**. 

> Note: The length of the bar will be "the **value** divided by 2", which means, a value of 10 will be displayed by a bar that is 5 characters long or a value of 41 will be displayed by a bar that is 20 characters long and so on...

When displaying the **BarChart**, If the **number of added samples** is not the same as **the number of samples** in the **BarChart**, or if any of the **Bar**s in **BarChart** is invalid, then the Chart will be considered invalid and a proper error message will be displayed. (see main and execution sample below)

Here is a sample of the main program using the **BarChart** Class and its execution result:

```C++
/* ----------------------------------------------------
Workshop 3:
Version: 1.0
Author: Fardad Soleimanloo
Description:
This file tests the BarChart section of your DIY workshop
-----------------------------------------------------*/
#include <iostream>
#include "BarChart.h"
using namespace sdds;
using namespace std;
int main() {
   BarChart bc;
   bc.init("How much students like this lab.", 5, '=');
   bc.add("Best Lab Ever", 2);
   bc.add("Good Lab", 10);
   bc.add("Doable Lab", 63);
   cout << "Premature draw call:"<< endl; 
   bc.draw(); // will not draw; it will print an error instead
   bc.add("Bad Lab", 10);
   bc.add("Worst Lab Ever", 5);
   cout << "Proper draw call after all samples are entered:" << endl;
   bc.draw();
   bc.deallocate();
   return 0;
}

```
Execution sample:
```Text
Premature draw call:
Invalid Chart!
Proper draw call after all samples are entered:
How much students like this lab.
-----------------------------------------------------------------------
Best Lab Ever.......|=
Good Lab............|=====
Doable Lab..........|===============================
Bad Lab.............|=====
Worst Lab Ever......|==
-----------------------------------------------------------------------
```

## Bar Module
### Suggested member variables
- a Cstring to hold a maximum of 20 characters for the title
- a char variable to hold the fill character
- an integer variable to hold the sample value of the Bar

### Suggested public member functions
- a function to set the Bar to the empty state
- a function to set the title, fill character and value of the bar and set the function to an invalid state if the value is not acceptable (less than zero or more than 100)
- a function that returns "if the Bar is valid or not"

### Mandatory public member function
Write a member function called **draw** that does not accept any parameters and can not modify the bar.

This function should draw a bar as follows.<br />
For example, if the **title** of the bar is "**Number of cakes**", the **fill** character is an asterisk (**'*'**) and the value is **51**; the Bar should be drawn exactly like this:  

```Text
Numberof cakes......|*************************<NEWLINE>
```
- Print the title in 20 characters and fill the spaces with dot characters (**'.'**). 
- print a pipe character (**'|'**)
- print the fill character to **the value divided 2** (ie. 51/2 -> 25)

If the value of the Bar is invalid (less than zero or more than 100) this function takes no action.

### barTester program:  
```C++
#include "Bar.h"
using namespace sdds;
int main() {
   Bar b;
   for (int i = 1; i <= 5; i++) {
      b.set("the bar", '=', i*20);
      b.draw();
   }
   b.set("Bad Bar", '=', -200);
   b.draw();
   b.set("Bad Bar", '=', 200);
   b.draw();
   return 0;
}
```
### bar tester output
```Text
the bar.............|==========
the bar.............|====================
the bar.............|==============================
the bar.............|========================================
the bar.............|==================================================
```


## BarChart Module
### Mandatory member variables
- a **character pointer** to hold the dynamically allocated "title of the chart"
- a **Bar pointer** to hold the dynamically allocated array of **Bar**s.

### Suggested member variables
- a **character variable** to hold the fill character
- an **integer variable** to hold the size of the dynamically allocated array of **Bar**s
- an **integer variable** to keep track of the number of added samples to set the **Bar**s.

### Suggested member function
- a function to return if all the **Bar**s are in a valid state or not.

### Mandatory member functions

```C++
    void init(const char* title, int noOfSampels, char fill);
```
Initializes the Chart as explained before.

```C++
    void add(const char* bar_title, int value);
```
Sets the next available **Bar** (in the dynamic Bar array), or does nothing if they are all already set.
```C++
    void draw()const;
```
If The **BarChar** is valid and if all the **Bar**s in the Chart are valid it draws the bar exactly as follows:
- prints the title of the Chart and goes to new line
- prints 71 dashes ('-') and goes to a new line
- prints all the Bars
- prints 71 dashes ('-') and goes to a new line
Otherwise, it will print:  
```Text
Invalid Chart!<NEWLINE>
```

```C++
    void deallocate();
```
Deallocates all the dynamically allocated memory.

> Modify the tester program to test the different circumstances of the application and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)


### Files to submit:  
```Text
main.cpp
Bar.cpp
Bar.h
BarChart.cpp
BarChart.h
```
### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


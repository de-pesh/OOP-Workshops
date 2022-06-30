# Workshop #6: Class with a Resource

In this workshop, you will work with a class that holds dynamic resources as well as static ones. In addition to having regular member functions, this class will also permit copy copied. Copying their data members will involve the use of copy constructors and assignment operators. The class used in this workshop will be the `Basket` class for which we will produce different fruit baskets.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- implement a copy constructor and a copy assignment operator
- to manage a class with dynamic resources
- to use existing objects to create new ones or to assign values to existing objects based on other existing ones
- to implement custom input/output operators
- to describe to your instructor what you have learned in completing this workshop

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

> This workshop is due in the week after the study break, but start working on it now while the concept is fresh in your mind. <br /> :warning: Also note that the due date of milestone 1 of the project in the same week. 

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

# Part 1 - Lab (50%)

The Numbers Module

Your task for this lab is to complete the implementation of the **Numbers** class. This class reads several double values from a file (one number per line) and holds them dynamically in memory. Then the caller application has the option of adding numbers to the collection. This Module can provide information about the numbers and display them on the screen:<br />
- The Module can display the values in ascending order (sort).
- The Module can find the largest value
- The Module can find the smallest value
- The Module can calculate the average of the values in the collection

Also The **Numbers** class has the following capabilities: 
- A **Numbers** object can safely be copied or assigned to another **Numbers** module
- A **Numbers** object can be displayed or streamed into an istream object.
- A **Numbers** object can be read from an istream object.

When the **Numbers** object goes out of the scope the values overwrite the old values in the file, ONLY IF the object is the original object and not a copy.
# The Numbers class
The Numbers class has four attributes:
```C++
    double* m_numbers; // holds the address of the dynamic array of doubles holding the number collection
    char* m_filename;  // holds the name of the file associated with the class (if it is the original object and not a copy)
    bool m_isOriginal; // flags if this object is the original (and not a copy)
    int m_numCount; // holds the number of values in the m_number dynamic array
```

## Constructors, Destructor and Copy Assignment

The **Numbers** class can be instantiated in three different ways:

### One argument constructor (implemented)
Creates an original instance of the Numbers class by receiving the data file name as a constant Cstring
- Sets the object to safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to true.
- Sets the filename of the class (**setFilename()**)
- Sets the number of the double values to be read from the file (sets m_numCount using **numberCount()**)

Now if the number of double values in file is greater than zero it tries to read the values from the file using the **load()** function as follows:

- If m_numCount is greater than zero and load() is successful, the values will be sorted.
- If not successful, it will free the memory pointed by m_numbers and m_filename
- sets the object back the safe empty state and sets the class NOT TO BE original anymore.

### Default constructor  (implemented)
```C++
 Numbers();
```
- Sets the object to safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to false.

### Destructor (implemented)
- Saves the values in the file
- deletes the memory pointed by m_numbers and m_filename

### Copy Constructor (to be implemented)
- Sets the object to safe empty state
- Sets the object NOT to be original
- Assigns the current object to the **Numbers** object that is being copied. (calls the Copy Assignment Operator)


### Copy Assignment Operator (to be implemented)
- deletes the current collection of the double values
- Allocates new memory pointed by m_numbers to the number of the values in the object that is being copied.
- Copies all the double values in the object that is being copied into the newly allocated memory.
- returns the reference of the current object.

## Member Functions and Member operator+= overload 

### isEmpty() (implemented)
returns true if **m_numbers** is null

### setEmpty() (implemented)
sets m_numbers and m_filename to nullptr.
sets m_numCount to zero.

### setFilename() (implemented)
- Receives a constant Cstring for the data file name.
- Frees the memory pointed by m_filename pointer
- Allocates memory to hold the data file name as a Cstring.
- Copies the data file name to the newly allocated memory.

### sort() (implemented)
Sorts the double values in ascending order

### max() (implemented)
Returns the largest double number in the list

### min() (implemented)
Returns the smallest double number in the list

### average()  (implemented)
Returns the average of the double numbers in the list.

### numberCount() (to be implemented)
This function (that is incapable of modifying the currect object), will return the number of lines in the data file (hence returning the number of double values in the file).
- Create an instance of **ifstream** to  open the data file name.
- While the **ifstream** object has not failed keep reading single characters from the file
- Count the number of **newline** characters in an integer variable
- Return the number of counted **newlines** when all characters in the file are scanned.

### load() (to be implemented)
This function returns true if all the double values are read from the data file and stored in a dynamically alocated memory pointed by **m_numbers**, othewise returns false.
- If number of double values in the file is greater than zero (m_numCount > 0)
- Allocate memory to hold the double values in an array pointed by m_numbers.
- Create an instance of ifstream for the data file
- While the ifstream object has not failed, keep reading double values from the file into the elements of m_numbers dynamic array (as you do with cin)<br />
> make sure to add to the index of the loop only if the istream object has not failed in its last reading
- return true if the number of read doubles, is equal to the m_numCount member variable.

### save() (to be implemented)
- If the current object is the original and it is not in safe empty state
- Create an instance of ofstream to overwrite the dat afile
- Write all the elements of the m_numbers array using the ofstream object.
- Write a newline after each double value.

### Operatro += (to be implemented)
Overload the += operator to add a single double value to the list of numbers in the array and then return the reference of the current object.

You need to increase the size of the allocated memory by one (add one double to the array), to be able to do this. 

Here is the sequence of the actions to be taken to resize memory:
- Create a temporary local double pointer and allocate memory with the increased size
- Copy all the current values to the newly allocated memory.
- Update the size of the data to the new size
- Now that all the values are copied to the new memory, delete the original allocated memory
- Set the original data pointer to point to newly allocated memory
- You are done!

[View the Slides](images/memoryResizing.pdf)

Using the above guidelines; in our case, do the following only if the object is not in an empty state:
- Create a temp double pointer and allocate memory to the size: **m_numCount + 1**
- In a loop, copy all the double **m_numbers** elements to the double **temp** number elements (up to m_numCount)
- Add one to m_numCount (to update the number of double values)
- copy the value of the double argument to the last element of the double **temp** array (and therefore add the double value to the list)
- delete m_numbers to get rid of the ariginal allocated memory
- Set **m_numbers** to **temp** pointer; by doing this m_numbers will point to the newly allocated memory.
- sort the numbers so the added number stands at the proper location in the array

Regardless of the object being empty or not return the reference of the current object.

### display function. (to be implemented)
```C++
   ostream& display(ostream& ostr) const
```
- if the object is empty, write: **"Empty list"**.
- if the object is not empty start by writing:  **"========================="** on **ostr** and then go to newline
- if the object is flagged as original, then write the file name otherwise write ```"*** COPY ***"``` and then go to new line
- write all the double numbers seperated by **", "** (A comma and a space) and then go to new line
- write **"-------------------------"** and go to new line
- Write **"Total of " << m_numCount << " number(s)"** and go to new line
- write **"Largest number:  "** and the largest number in the list and go to new line
- write **"Smallest number: "** and the smallest number in the list and go to new line
- write **"Average :        "** and the average of all the numbers inthe list and go to new line
- write **"========================="** and DO NOT GO TO NEWLINE

At the end return the ostr object.

#### Execution sample
A Numbers object that has the double values 34.1, 3, 6, 12.2 and 34.56 in a file called **numbers.txt**<br />
should be displayed as follows:  
```Text
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
```
If a Number object is empty, it will be displayed as follows:
```Text
Empty list
```

## Helper function overlaods (to be implemented)
```C++    
ostream& operator<<(ostream& os, const Numbers& N);
```
Overload the insertion operator to display the Numbers object using istream.
- call the display fucntion of N and return it

```C++
istream& operator>>(istream& istr, Numbers& N);
```
Overload the extraction operator to display the Numbers object using istream.
- read a double value using istr
- add the double value to N using += operator
- return istr;

## the tester program and the execution sample.
The tester program's execution should generate the following output:

```Text
Test 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
Add a number to the list: 1000
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
End Test 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Content of "numbers.txt"
*****************************************************************
3
6
12.2
34.1
34.56
*****************************************************************
Test 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
Empty list
Empty list
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
=========================
*** COPY ***
3, 6, 12.2, 34.1, 34.56, 1000
-------------------------
Total of 6 number(s)
Largest number:  1000
Smallest number: 3
Average :        181.643
=========================
End Test 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2

Content of "numbers.txt"
*****************************************************************
3
6
12.2
34.1
34.56
1000
*****************************************************************
Test 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3

In this test we use your insertion and extraction operators to do
File IO. This makes sure your implementation is done correctly
using the reference of istream and ostream and NOT cin and cout

End Test 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3

Content of "numbers.txt"
*****************************************************************
-5
3
6
12.2
34.1
34.56
222.1
333.2
1000
*****************************************************************

Content of "add.txt"
*****************************************************************
-5
222.1
333.2
*****************************************************************

Content of "output.txt"
*****************************************************************
=========================
numbers.txt
-5, 3, 6, 12.2, 34.1, 34.56, 222.1, 333.2, 1000
-------------------------
Total of 9 number(s)
Largest number:  1000
Smallest number: -5
Average :        182.24
=========================
*****************************************************************

```
## PART 1 Submission (lab)

### Files to submit:  

```Text
Numbers.cpp
Numbers.h
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry
```
1000<ENTER>
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



# DIY (50%) 

## `Basket` Module

Design and code a class named `Basket` that holds information about a fruit basket. Place your class definition in a header file named `Basket.h` and your function definitions in an implementation file named `Basket.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

Add to this module a custom type called `Fruit`:
```cpp
struct Fruit
{
  char m_name[30 + 1]; // the name of the fruit
  double m_qty;        // quantity in kilograms
};
```

### `Basket` Class

Design and code a class named `Basket` that holds information about a fruit basket.


#### `Basket` Private Members

The class should be able to store the following data:

- `m_fruits`: a dynamically allocated array of objects of type `Fruit`. This is the resource that you must manage.
- `m_cnt`: the size of the `m_fruits` array.
- `m_price`: the price of the basket.

You can add any other private members in the class, as required by your design.



#### `Basket` Public Members

- the default constructor
- a custom constructor that receives as parameters an array of objects of type `Fruit`, the size of the array received in the fist parameter, and the price of the basket (in this order); stores the parameters into the attributes if **all** the parameters are valid (the numbers are greater than 0, and the array is not null).
- the copy constructor (you must do a deep-copy for the resource, and a shallow copy for the other attributes)
- the copy assignment operator (you must do a deep-copy for the resource, and a shallow copy for the other attributes; note that the copy constructor and copy assignment operator have almost identical logic -- reuse the code)
- the destructor
- `void setPrice(double price)`: updates the `m_price` attribute to the value received as parameter
- the conversion to `bool` operator: returns `true` if the basket contains any fruits, `false` otherwise.
- an overload of the `+=` operator that receives as a parameter an object of type `Fruit` (by value) and adds it to the attribute `m_fruits` (resize the array-attribute; check previous workshops if you need a refresh on resizing a dynamic array)


#### Friend Helper Functions

- overload the insertion operator (`operator<<`) to insert into the stream (received as the first parameter) the content of an object of type `Basket` (received as the second parameter).

  If the basket doesn't contain any fruit, print the message `The basket is empty!<ENDL>`.

  If the basket contains fruits, print the content in the format:
  ```txt
  Basket Content:<ENDL>
  [FRUIT_1_NAME]: [FRUIT_1_QUANTITY]kg<ENDL>
  [FRUIT_2_NAME]: [FRUIT_2_QUANTITY]kg<ENDL>
  ...
  Price: [BASKET_PRICE]<ENDL>
  ```
  The fruit names should be printed on fields of size 10, aligned to the right; the fruit quantities and basket price should be printed with **two** significant digits.





## Tester Program
```C++
// Workshop 6: Classes with Resources
// Version: 1.0
// Author: Nargis Khan, Cornel Barna
// Description:
// This file tests lab section of your workshop
/////////////////////////////////////////////

#include<iostream>
#include<cstring>
#include"Basket.h"
#include"Basket.h" //intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(40);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(40);
	cout << "" << endl;
	cout.fill(oldFill);
}

int main()
{
	sdds::Fruit fruits[]{
		{"apple",  0.65},
		{"banana", 1.25},
		{"pear",   0.50},
		{"mango",  0.75},
		{"plum",   2.00},
	};

	{
		printHeader("T1: Default Constructor");

		Basket aBasket;
		cout << aBasket;

		// conversion to bool operator
		if (aBasket)
			cout << "Test failed: the basket should be empty!\n";
		else
			cout << "Test succeeded: operator said the basket is empty!\n";

		cout << endl;
	}

	{
		printHeader("T2: Custom Constructor");

		Basket aBasket(fruits, 2, 6.99);
		cout << aBasket;

		// conversion to bool operator
		if (aBasket)
			cout << "Test succeeded: operator said the basket has content!\n";
		else
			cout << "Test failed: the basket should NOT be empty!\n";

		cout << endl;
	}

	{
		printHeader("T3: += operator");

		Basket aBasket;
		aBasket += fruits[2];
		(aBasket += fruits[0]) += fruits[4];
		aBasket.setPrice(12.234);

		cout << aBasket;
		cout << endl;
	}
	
	{
		printHeader("T4: Copy Constructor");

		Basket b1;
		Basket b2(b1);

		cout << "Basket #1 -> " << b1;
		cout << "Basket #2 -> " << b2;

		b1 += fruits[3];
		b1.setPrice(3.50);

		Basket b3(b1);
		cout << "Basket #3 -> " << b3;
		cout << endl;
	}

	{
		printHeader("T5: Copy Assignment");

		Basket b1, b2, b3(fruits, 5, 19.95);

		b1 = b2;
		cout << "Basket #1 -> " << b1;
		cout << "Basket #2 -> " << b2;

		b1 = b3;
		cout << "Basket #1 -> " << b1;

		b3 = b2;
		cout << "Basket #3 -> " << b3;
	}

	return 0;
}

```
## Execution Sample
```text
----------------------------------------
|> T1: Default Constructor
----------------------------------------
The basket is empty!
Test succeeded: operator said the basket is empty!

----------------------------------------
|> T2: Custom Constructor
----------------------------------------
Basket Content:
     apple: 0.65kg
    banana: 1.25kg
Price: 6.99
Test succeeded: operator said the basket has content!

----------------------------------------
|> T3: += operator
----------------------------------------
Basket Content:
      pear: 0.50kg
     apple: 0.65kg
      plum: 2.00kg
Price: 12.23

----------------------------------------
|> T4: Copy Constructor
----------------------------------------
Basket #1 -> The basket is empty!
Basket #2 -> The basket is empty!
Basket #3 -> Basket Content:
     mango: 0.75kg
Price: 3.50

----------------------------------------
|> T5: Copy Assignment
----------------------------------------
Basket #1 -> The basket is empty!
Basket #2 -> The basket is empty!
Basket #1 -> Basket Content:
     apple: 0.65kg
    banana: 1.25kg
      pear: 0.50kg
     mango: 0.75kg
      plum: 2.00kg
Price: 19.95
Basket #3 -> The basket is empty!
```
## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
Basket.cpp
Basker.h
main.cpp
```

### Data Entry

No date entry needed

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

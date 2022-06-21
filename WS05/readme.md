# Workshop #5: Title Lecture topics of the week goes here

* Version 1.0

In this workshop, you will implement different types of operator overload in a partially developed classes.

## Overview Session

The overview session was on Monday June 13th at 1:00 PM;

Click [HERE](https://youtu.be/RmPakgNRP7o) to watch the session.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create binary member operators
- define and create various type conversion operators
- define and create unary operators
- define and create helper binary operator between classes
- define and create helper operators between a primitive type and a class.

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
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

# Part 1 - LAB (50%)

Your task as to implement two modules called __Chapter__ and __Book__. The Book class is using __Chapter__ class in a composition pattern. (i.e. Book has an array of Chapters)

## The Chapter class
Partial code for the .h and .cpp file for the Chapter modules is already provided.
The partial implementation allows creating and initialization of book Chapter objects.
The provided code should be fully included in the submission without any changes.
```C++
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
#define MAX_CHAPTER_TITLE 20
namespace sdds {
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE+1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();
    public:
        Chapter();
        Chapter(const char* title_);
        Chapter(const char* title_, int chapter_num, int n_pages, int n_words);
        std::ostream& display(std::ostream&)const;

    };
}
#endif



```
And
```C++
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}
	Chapter::Chapter() {
		init_chapter();
	}

	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title , title_);
	}
	Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}
}


```

### Add the following to the Chapter class:
- An `int` type cast operator: It will return the number of the pages in the Chapter object.
- A `double` type cast operator: It will return the average number of words per page.
- A `const char*` type cast operator: It will return the title of a chapter object.
- An assignment operator overload: to allow setting a chapter to another chapter object.  
(i.e., right-hand operand is of type const Chapter&).
- A prefix `++` operator overload: It will increase the number of pages for a chapter object by one.  
- A prefix `--` operator overload: It will decrease the number of pages for a chapter object by one.  
- An insertion helper operator overload: to allow printing of a chapter to the output console.
You will need to use the provided display member function to accomplish this operator overload.


## The Book class
Partial code for the .h and .cpp file for the Book modules is already provided.
The partial implementation allows creating and initialization of book objects.
The provided code should be fully included in the submission without any changes.
```C++
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
   const int MAX_NUM_CHAPTERS = 10;
   const int MAX_BOOK_TITEL = 40;
   const int MAX_AUTHOR_NAME = 20;
   class Book
    {
        char m_title[MAX_BOOK_TITEL+1];
        char m_author[MAX_AUTHOR_NAME+1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter* chapter);
    public:
        Book();
        Book(const char* title_);
        Book(const char* title_, const char* author_, double price_);
        void summary(); // Print a book summary
    };
}
#endif

```
and
```C++
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}


}

```
### To be implemented from the Book class:
- A postfix `++` operator overload to increase the number of chapters by one.  
- A private member function called `add_chapter` which receives a pointer to a chapter and adds the chapter to the array of chapters for the book. It returns an integer which is the number of chapters after the new chapter is been added.
Make sure you use the postfix `++` operator you implemented above.
- A public member function called `display` which takes a reference to a ostream object and returns a reference to an ostream object. This function is going to print a book object according to the provided sample output. You are
required to properly use overloads implemented in the __Chapter__ module.
- An `int` type cast operator: It will return the number of chapters of a book object.
- A `bool` type cast operator: It will return true if `title` and `author`, and `num_chapters` are non-empty and __there is at least one chapter with number of pages greater than zero__.  Note that you will need to implement a getter member function on `num_pages` for the chapter class, in order to satisfy the last part of the given condition.
- A `double` type cast operator: It will return the book price.
- A `const char*` type cast operator: It will return title of the book
- A logical not operator overload: return true if any of the conditions mentioned for the bool operator overload are not true.
- A `+=` operator overload: to allow adding a chapter to a book. Make sure you reuse
code through the `add_chapter` member function you implemented above.
- A `-=` operator overload to apply a dollar value discount to the book price.
For example if `mybook` is a __Book__ object with a price tag of $100.50, then this
operation `mybook -= 10.5;` will result in the `mybook` price to be lowed to `$90`.
- An insertion operator overload: to allow printing of a book object to the
output console. Make sure you properly reuse the `display` member function you implemented above.

## Tester Program
```C++
// Workshop 5:
// Version: 1.0
// Author: Aras Azimipanah
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Book.h"
#include "Chapter.h"
using namespace std;
using namespace sdds;

void print_test_section_separator() {
    // For ease of reading tester output
    cout << "---------------------------------------------------------------------" << endl;
}

int main() {
    /*Python Book*/
    Book python = { "Fluent Python", "Luciano Romalho", 38.5 };
    Chapter py_chapter = { "Introduction", 1, 10, 5000 };
    python += py_chapter;

    /*CPP Book*/
    Book cpp("Object Oriented Programming using C++", "Bjarne Stroustrup", 89.56);
    Chapter chapters[] = {
       {"Introduction", 1, 10, 4853},
       {"Language History",2, 23, 12000},
       {"Varibales",3, 30, 16400},
       {"Flow Control",4,  33, 18450}
    };
    for (int i = 0; i < 4; i++) {
        cpp += chapters[i];
        // Test proper implementation of the postfix ++
        cout << "'" << (const char*)(cpp) << "' book now has " << (int)cpp << " chpaters!" << endl;
    }

    Book books[] = {
        //Empty Books
        {},
        {"Java Programming"},
        {"Go Programming", "Alan Donovan", 0},
        {"Java Programming", "Joshua Bloch",35.0 },
        // Non Empty Books
        python,
        cpp
    };

    for (int i = 0; i < 6; i++) {
        if (books[i])
            cout << (const char*)books[i] << " is not empty!"<<endl;
        if(!books[i])
            cout << (const char*)books[i] << " is empty!" << endl;
    }
    print_test_section_separator();

   // Test Insertion operator overloads 
   // This will test both insertion operators for Book and Chapter classes!
   cout << cpp;
   print_test_section_separator();

   // Show cpp and python books summary
   cout << "Orignal prices:" << endl;
   cpp.summary();
   python.summary();
   print_test_section_separator();

   // Books going on sale!
   python -= 7.0;
   cpp -= 8.5;
   cout << "After discount prices:" << endl;
   cpp.summary();
   python.summary();
   print_test_section_separator();

   // Individual typecast tests
   cout << "'" << (const char*)(cpp) << "' book has " << (int)cpp << " chapters." << endl;
   cout << "Final price of '" << (const char*)(cpp) << "' book: $" << (double)cpp << endl;
   cout << "First chpater of '" << (const char*)(cpp) <<
       "' book has " << (int)chapters[0] << " pages and an avarage of " << 
       (double)chapters[0] << " words per page."<< endl;

   
   return 0;
}
```
## output
```text
'Object Oriented Programming using C++' book now has 1 chpaters!
'Object Oriented Programming using C++' book now has 2 chpaters!
'Object Oriented Programming using C++' book now has 3 chpaters!
'Object Oriented Programming using C++' book now has 4 chpaters!
 is empty!
Java Programming is empty!
Go Programming is empty!
Java Programming is empty!
Fluent Python is not empty!
Object Oriented Programming using C++ is not empty!
---------------------------------------------------------------------
Title:'Object Oriented Programming using C++'
Author: 'Bjarne Stroustrup'
| Chapter 1  | Introduction         |
| Chapter 2  | Language History     |
| Chapter 3  | Varibales            |
| Chapter 4  | Flow Control         |
---------------------------------------------------------------------
Orignal prices:
| Object Oriented Programming using C++    | Bjarne Stroustrup    | 4    96   | 89.56  |
| Fluent Python                            | Luciano Romalho      | 1    10   | 38.5   |
---------------------------------------------------------------------
After discount prices:
| Object Oriented Programming using C++    | Bjarne Stroustrup    | 4    96   | 81.06  |
| Fluent Python                            | Luciano Romalho      | 1    10   | 31.5   |
---------------------------------------------------------------------
'Object Oriented Programming using C++' book has 4 chapters.
Final price of 'Object Oriented Programming using C++' book: $81.06
First chpater of 'Object Oriented Programming using C++' book has 10 pages and an avarage of 485.3 words per page.
```

## PART 1 Submission (lab)

### Files to submit:  

```Text
Book.cpp
Book.h
Chapter.cpp
Chapter.h
main.cpp

```

### Data Entry

No data entry required.

#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

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
> Please note that you can (and probably should) add more member functions to make the DIY part work.

In this part of the lab, you will create a Module with the name **Hero**.

## The Power module
Already fully implemented. Study this module and understand how it works.

## The Hero module.
needs to be implemented.

### Hero Data Members
Declare four private data members:
1) Declare an array to hold the name of a hero, not exceeding MAX_NAME_LEN characters.
2) Declare a Pointer of type Power that will hold a dynamic set of powers a hero may have.
3) Declare an integer variable for the number of powers a hero may have.
4) Declare a integer variable for the power level of a hero.<br />This will be a calculated value. Every time you need to calculate/update this variable it will be done as follows:<br />
Sum of rarity of all the heroes' powers multiplied by the total count of powers.

Store your class definition in a header file named `Hero.h` and your member function definitions in an implementation file named `Hero.cpp`.

### Constructors
- Default constructor to set a hero to a safe empty state.

- Overloaded constructor with 3 parameters to set the name, list of powers and the count of powers a hero have. This constructor will also set/update the `powerlevel` of a hero.

### Display Function
- A display function that will send the information about a hero to ostream in the following format and then returns the reference of ostream;
```
Name: XXXXXXXXXXX<ENDL>
List of available powers:
  powers listed here...
  powers listed here...
  powers listed here...
  powers listed here...
Power Level: XXXX<ENDL>
```

### Operator and conversion overloads

- overload the **+= operator** that accepts a power reference. The power should be added to the list of your hero. Your heroes' power level and power count should be updated too.

- overload the **-= operator** that accepts an integer reference. This operator will subtract the integer from the power level of your hero.


### Boolean helper operators

- operator< : This operator take two references to two hero parameters. It will return true if first hero power level is less than second hero power level. It will return false otherwise.

- operator> : This operator take two references to two hero parameters. It will return true if first hero power level is greater than second hero power level. It will return false otherwise.

- operator>> : This operator will take two parameters. The left parameter is a reference to a power. The right parameter is a reference to a hero. This operator will add the power to the hero and update the hero accordingly.
    > note: this is not istream extraction operator

- operator<< : This operator will take two parameters. The left parameter is a reference to a hero. The right parameter is a reference to a power. This operator will add the power to the hero and update the hero accordingly.
    > Note: this is not ostream insertion operator

## The tester program.
``` C++
/* ------------------------------------------------------
Workshop 3 part 1
Module: N/A
Author: Mohammad Shamas
Filename: main.cpp
Version 1.0
-------------------------------------------------------*/

#include <iostream>
#include <cstring>
using namespace std;
#include "Hero.h"
using namespace sdds;
void displayDetails(const Hero* heroes, int size);
int main() {

	Power powerlist1[4] = { 
		{"Flying", 2},
		{"Laser Eye", 8},
		{"Freezing Breath", 8},
		{"Super Strength", 2},
	};

	Power powerlist2[2] = {
		{"Super Speed", 8},
		{"Super Healing", 5}
	};

	Power powerlist3[3] = {
		{"Flying", 2},
		{"Super Strength", 2},
		{"Telepathy", 9}
	};

	Power powerlist4[3] = {
		{"Water Bending", 9},
		{"Super Strength", 2},
		{"Animal Telepathy", 9}
	};

	Power powerlist5[2] = {
		{"Strong Will", 10},
		{"Flying", 2}
	};

	Hero herolist[5] = {
		{"Superman", powerlist1, 4},
		{"Flash",powerlist2, 2},
		{"Martian-Man-Hunter",powerlist3,3},
		{"Aquaman",powerlist4,3},
		{"Green-Lantern",powerlist5,2},
	};
	// Test 1
	cout << "----------------------------------------" << endl;
	cout << "1. Testing the display function and constructors." << endl;
	cout << "----------------------------------------" << endl;
	displayDetails(herolist, 5);
	cout << "----------------------------------------" << endl << endl;
	// Test 2
	cout << "----------------------------------------" << endl;
	cout << "1. Testing the += operator" << endl;
	cout << "----------------------------------------" << endl;
	Power testing1 = {"Phasing through objects", 10};
	herolist[1] += testing1;
	herolist[1].display() << endl;
	herolist[2] += testing1;
	herolist[2].display() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 3
	cout << "----------------------------------------" << endl;
	cout << "3. Testing the -= operator" << endl;
	cout << "----------------------------------------" << endl;
	herolist[1] -= 10;
	herolist[1].display() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 4
	cout << "----------------------------------------" << endl;
	cout << "4. Testing the >> and << operators" << endl;
	cout << "----------------------------------------" << endl;
	Power testing2 = { "Regeneration", 5 };
	testing2 >> herolist[4];
	herolist[4].display() << endl;
	herolist[0] << testing2;
	herolist[0].display() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 5
	cout << "----------------------------------------" << endl;
	cout << "5. Testing the < and > operators" << endl;
	cout << "----------------------------------------" << endl;
	cout << ((herolist[0] > herolist[2]) ? "Superman is stronger than Martian-Man-Hunter" : "Double check your < operator");
	cout << endl;
	cout << ((herolist[4] < herolist[3])? "Green-Lantern is weaker than Aquaman" : "Double check your < operator");
	cout << endl;
	cout << "----------------------------------------" << endl << endl;
	return 0;
}

void displayDetails(const Hero* heroes, int size) {
	cout << "Details of our heroes are as follow: " << endl;
	for (int i = 0; i < size; i++) {
		heroes[i].display() << endl;
	}
}
```
## Output
```text
----------------------------------------
1. Testing the display function and constructors.
----------------------------------------
Details of our heroes are as follow:
Name: Superman
List of available powers:
  Name: Flying, Rarity: 2
  Name: Laser Eye, Rarity: 8
  Name: Freezing Breath, Rarity: 8
  Name: Super Strength, Rarity: 2
Power Level: 80
Name: Flash
List of available powers:
  Name: Super Speed, Rarity: 8
  Name: Super Healing, Rarity: 5
Power Level: 26
Name: Martian-Man-Hunter
List of available powers:
  Name: Flying, Rarity: 2
  Name: Super Strength, Rarity: 2
  Name: Telepathy, Rarity: 9
Power Level: 39
Name: Aquaman
List of available powers:
  Name: Water Bending, Rarity: 9
  Name: Super Strength, Rarity: 2
  Name: Animal Telepathy, Rarity: 9
Power Level: 60
Name: Green-Lantern
List of available powers:
  Name: Strong Will, Rarity: 10
  Name: Flying, Rarity: 2
Power Level: 24
----------------------------------------

----------------------------------------
1. Testing the += operator
----------------------------------------
Name: Flash
List of available powers:
  Name: Super Speed, Rarity: 8
  Name: Super Healing, Rarity: 5
  Name: Phasing through objects, Rarity: 10
Power Level: 69
Name: Martian-Man-Hunter
List of available powers:
  Name: Flying, Rarity: 2
  Name: Super Strength, Rarity: 2
  Name: Telepathy, Rarity: 9
  Name: Phasing through objects, Rarity: 10
Power Level: 92
----------------------------------------

----------------------------------------
3. Testing the -= operator
----------------------------------------
Name: Flash
List of available powers:
  Name: Super Speed, Rarity: 8
  Name: Super Healing, Rarity: 5
  Name: Phasing through objects, Rarity: 10
Power Level: 59
----------------------------------------

----------------------------------------
4. Testing the >> and << operators
----------------------------------------
Name: Green-Lantern
List of available powers:
  Name: Strong Will, Rarity: 10
  Name: Flying, Rarity: 2
  Name: Regeneration, Rarity: 5
Power Level: 51
Name: Superman
List of available powers:
  Name: Flying, Rarity: 2
  Name: Laser Eye, Rarity: 8
  Name: Freezing Breath, Rarity: 8
  Name: Super Strength, Rarity: 2
  Name: Regeneration, Rarity: 5
Power Level: 125
----------------------------------------

----------------------------------------
5. Testing the < and > operators
----------------------------------------
Superman is stronger than Martian-Man-Hunter
Green-Lantern is weaker than Aquaman
----------------------------------------

```

> Modify the tester program to test all the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

### Files to submit:  
```Text
power.h
power.cpp
hero.h
hero.cpp
main.cpp
```

#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

No data entry required.

#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

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

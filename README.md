# Data Structures (CMPS 260) Class Projects

## About

Class projects for Data Structures (CMPS 260) in the Spring of 2005.

## Build & Run

### 60x60 Array

```bash
$ make
g++ -c proj1.cpp
g++ -o proj1 proj1.o
```

```bash
$ ./proj1 
sh: cls: command not found
Main Menu: 

1. Enter Data
2. View Data
3. View Infection Rates
4. View Average Infection Rate
0. Exit

Choice? 0
sh: cls: command not found
Are you sure? yes

Bye!
```

### Bank Teller

```bash
$ make
g++ -c bank.cpp
g++ -c teller.cpp
g++ -c account.cpp
account.cpp:3:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.
g++ -o bank bank.o teller.o account.o
```

```bash
$ ./bank 
sh: cls: command not found

1. Teller Options
0. Exit

Choice: 1


Welcome! Would you like to

1. Login to an existing account.
2. Create a new account.
3. Back

Choice: 3
sh: cls: command not found

1. Teller Options
0. Exit

Choice: 0
sh: cls: command not found
Are you sure you want to exit? yes
```

### Check Digit

```bash
$ make
javac ErrorCheck.java
java ErrorCheck

1. Check Passcode
2. Generate Passcode
3. Calculate Slugging Average
0. Exit

Choice? 0
```

### Line Editor

```bash
$ make
g++ -c lineeditor.cpp
g++ -c lineEdit.cpp
g++ -c arrayStringListType.cpp
g++ -o lineeditor lineeditor.o lineEdit.o arrayStringListType.o
```

```bash
$ ./lineeditor 
 *******************
 *** LINE EDITOR ***
 *******************

1. New
2. Open

0. Exit

Choice? 2

* OPEN *

FILENAME: f

 *******************
 *** LINE EDITOR ***
 *******************

1. New
2. Open
3. Save
4. Show
5. Edit

0. Exit

Choice? 
```

### Anagram

```bash
$ make
g++ -c 2005\ 03\ 05.cpp
g++ -o prog 2005\ 03\ 05.o
```

```bash
$ ./prog 

  * Mr. Anagram *

 o - (O)pen File
 f - (F)ix File to Lowercase
 d - (D)isplay Anagrams
 w - (W)rite Anagrams to File
 x - E(x)it

> x
```

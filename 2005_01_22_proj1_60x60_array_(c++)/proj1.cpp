//  Author        : Mark McKelvy
//  CLID          : jmm0468
//  Class         : CMPS 260 - 3
//  Assignment    : Programming Assignment 1
//  Date Assigned : 2005, January 24
//  Due Date      : 2005, January 31
//  Due Time      : 10:00 AM
//
//  Program Description: This program uses multidimensional arrays
//   of structs to simulate a city with wells, their population (around
//   a certain cell), and the number of infections at that location.
//  
//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

// total number of cell rows
const int ROWS = 60;
// total number of cell columns
const int COLUMNS = 60;

// one-unit cell
struct cell{
    int population;
    int cases;
};

void menu(cell cells[ROWS][COLUMNS]);
// pre:  passed a multidimensional array of structs, clears
//       the screen and displays a menu of options.
// post: passes the array to the appropriate "handler" 
//       function for further processing, or cycles over
//       if a valid choice is not made
void readData(ifstream& fin, cell cells[ROWS][COLUMNS]);
// pre:  passed an input filestream for a file, and a multi-
//       dimensional array
// post: reads data from the input filestream into the 
//       multidimensional array
void defaultInitialize(cell cells[ROWS][COLUMNS]);
// pre:  passed a multidimensional array of structs
// post: initializes the array to default values
//       (ex: cells[0][0].population = 0;)
void saveToFile(ofstream& fout, cell cells[ROWS][COLUMNS]);
// pre:  passed an output filestream for a file, and a
//       multidimensional array
// post: copies the information from the multidimensional
//       array and puts it into the output filestream
void enterData(cell cells[ROWS][COLUMNS]);
// pre:  passed a multidimensional array of structs
// post: asks the user to input data for a (user-specified)
//       cell in the array, and returns to the menu()
void viewCell(cell cells[ROWS][COLUMNS]);
// pre:  passed a multidimensional array of structs
// post: shows the raw data for a (user-specified) cell
//       in the array, and returns to the menu()
void viewRates(cell cells[ROWS][COLUMNS]);
// pre:  passed a multidimensional array of structs
// post: displays to the screen the percentages of 
//       (cases/population) for each cell in the array
//       that has a value > 1.0%. Then returns to the menu()
float viewAvg(cell cells[ROWS][COLUMNS]);
// pre:  passed a multidimensional array of structs
// post: calculates the value of (total cases / total
//       population) * 100 and returns the floating point value

int main(){
    char achoice;
    ifstream fin;
    
    cell cells[ROWS][COLUMNS];
    fin.open("data.dat", ios::in);
    // handle loading of saved data
    readData(fin, cells);      
    fin.close();
    // proceed to main menu
    menu(cells);  
    return 0;  
}

void menu(cell cells[ROWS][COLUMNS]){
     char choice;
     
     system("cls");
     cout << "Main Menu: " << endl << endl;
     cout << "1. Enter Data" << endl;
     cout << "2. View Data" << endl;
     cout << "3. View Infection Rates" << endl;
     cout << "4. View Average Infection Rate" << endl;
     cout << "0. Exit" << endl << endl;
     cout << "Choice? ";
     cin >> choice;
     // handle the choice made
     switch(choice){
       case '1':
            // input data for a cell
            enterData(cells);
            break;
       case '2':
            // view data for a cell
            viewCell(cells);
            break;
       case '3':
            // view percentages of infections
            viewRates(cells);
            break;
       case '4':
            // view average infection rate
            system("cls");
            cout << "The average infection rate is " << viewAvg(cells) << "%" << endl;
            cout << endl << "Press Enter";
            getch();
            menu(cells);            
            break;
       case '0':
            // quit program
            char temp;
            system("cls");
            cout << "Are you sure? ";
            cin >> temp;
            if((temp == 'y') || (temp == 'Y')){
              ofstream fout;
              fout.open("data.dat", ios::out);
              saveToFile(fout, cells);
              fout.close();
              cout << endl << "Bye!" << endl;
            }
            // or don't quit the program
            else
              menu(cells);
            break;
       default:
            // re-show the menu
            menu(cells);
            break;
     }    
}
void readData(ifstream& fin, cell cells[ROWS][COLUMNS]){
     if(fin == NULL)
            defaultInitialize(cells);
     else{
         for(int x = 0; x < ROWS; x++){
                 for(int y = 0; y < COLUMNS; y++){
                         fin >> cells[x][y].population >> cells[x][y].cases;               
                 }
         }
     }
}
void defaultInitialize(cell cells[ROWS][COLUMNS]){
     for(int x = 0; x < ROWS; x++){
             for(int y = 0; y < COLUMNS; y++){
                     cells[x][y].population = 0;
                     cells[x][y].cases = 0;
             }
     }
}
void saveToFile(ofstream& fout, cell cells[ROWS][COLUMNS]){
     for(int x = 0; x < ROWS; x++){
             for(int y = 0; y < COLUMNS; y++){
                     fout << cells[x][y].population << " "
                          << cells[x][y].cases << endl;
             }
     }                     
}
void enterData(cell cells[ROWS][COLUMNS]){
     int x,y;     
     system("cls");
     cout << "You chose to enter data." << endl << endl;
     cout << "Row #";
     cin >> x;
     cout << "Column #";
     cin >> y;
     system("cls");
     cout << "Cell " << x << "-" << y << endl << endl;
     cout << "Population? ";
     cin >> cells[x][y].population;
     cout << endl << "Cholera cases? ";
     cin >> cells[x][y].cases;
     cout << endl << endl << "Data recorded. Press Enter";
     getch();
     menu(cells);
}
void viewCell(cell cells[ROWS][COLUMNS]){
     int x,y;
     system("cls");
     cout << "You chose to enter data." << endl << endl;
     cout << "Row #";
     cin >> x;
     cout << "Column #";
     cin >> y;
     system("cls");
     cout << "Cell " << x << "-" << y << endl << endl;
     cout << "Population: " << cells[x][y].population << endl;
     cout << "Cholera cases: " << cells[x][y].cases << endl;
     cout << endl << "Press Enter";
     getch();
     menu(cells);
}
void viewRates(cell cells[ROWS][COLUMNS]){
     int counter = 0;
     float temp;
     system("cls");
     for(int x = 0; x < ROWS; x++){
             for(int y = 0; y < COLUMNS; y++){
                     if(cells[x][y].population != 0)
                       temp = ((float)cells[x][y].cases / (float)cells[x][y].population) * 100;
                     if(temp > 1.0){
                       cout << "Cell " << x << "-" << y << ": " << temp << "%" << endl;
                       counter++;
                     }
                     if(counter == 10){
                       counter = 0;
                       getch();
                     }
                     temp = 0.0;                     
             }
     }
     cout << endl << endl << "Press Enter";
     getch();
     menu(cells);
}
float viewAvg(cell cells[ROWS][COLUMNS]){
     int counter = ROWS * COLUMNS;
     int cases = 0, population = 0;
     for(int x = 0; x < ROWS; x++){
             for(int y = 0; y < COLUMNS; y++){
                     cases += cells[x][y].cases;
                     population += cells[x][y].population;
             }
     }
     if(population != 0)
        return (((float)cases / (float)population) * (100.0 / (float)counter));
     else return 0.0;
}

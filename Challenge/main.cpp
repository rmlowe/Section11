// Section 11
// Challenge - Solution
/*
    Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses uses functions.
    
    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it
        
        DO NOT move the vector object outside main and make it a global variable.
        
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
    
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally, don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void display_menu();
char read_selection();
void print_numbers(const vector<int> &numbers);
void add_number(vector<int> &number);
double calc_mean(const vector<int> &numbers);
void display_mean(const vector<int> &numbers);
int find_smallest(const vector<int> &numbers);
void display_smallest(const vector<int> &numbers);
int find_largest(const vector<int> &numbers);
void display_largest(const vector<int> &numbers);

void display_menu() {
    // Display menu
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
}

char read_selection() {
    char selection {};
    cout << "\nEnter your choice: ";
    cin >> selection;
    return toupper(selection);
}

void print_numbers(const vector<int> &numbers) {
    if (numbers.size() == 0)
        cout << "[] - the list is empty" << endl;
    else {
        cout << "[ ";
        for (auto num: numbers)
            cout << num << " ";
        cout << "]" << endl;
    }
}

void add_number(vector<int> &numbers)  {
    int num_to_add {};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    numbers.push_back(num_to_add);
    cout << num_to_add << " added" << endl;
}

double calc_mean(const vector<int> &numbers) {
    int total {};
    for (auto num: numbers)
        total += num;
    return static_cast<double>(total)/numbers.size();
}

void display_mean(const vector<int> &numbers) {
    if (numbers.size() == 0)
        cout << "Unable to calculate mean - no data" << endl;
    else {
        cout << "The mean is : " << calc_mean(numbers) << endl;
    }
}

int find_smallest(const vector<int> &numbers) {
    int smallest = numbers.at(0);
    for (auto num: numbers)
        if (num < smallest)
            smallest = num;
    return smallest;
}

void display_smallest(const vector<int> &numbers) {
    if (numbers.size() == 0)
        cout << "Unable to determine the smallest - list is empty" << endl;
    else {
        cout << "The smallest number is: " << find_smallest(numbers) << endl;
    }
}

int find_largest(const vector<int> &numbers) {
    int largest = numbers.at(0);
    for (auto num: numbers)
        if (num > largest)
            largest = num;
    return largest;
}

void display_largest(const vector<int> &numbers) {
    if (numbers.size() == 0)
        cout << "Unable to determine largest - list is empty"<< endl;
    else {
        cout << "The largest number is: " << find_largest(numbers) << endl;
    }
}

int main() {
    
    vector<int> numbers {};
    char selection {};
    
    do {
        display_menu();
        selection = read_selection();
        
        
        if (selection == 'P') {
            print_numbers(numbers);
        } else if (selection == 'A') {
            add_number(numbers);
        } else if (selection == 'M') {
            display_mean(numbers);
        } else if (selection == 'S') {
            display_smallest(numbers);
        } else if (selection == 'L') {
            display_largest(numbers);
        } else if (selection == 'Q') {
            cout << "Goodbye" << endl;
        } else {
            cout << "Unknown selection, please try again" << endl;
        }
    } while (selection != 'Q');
    
    cout << endl;
    return 0;
}


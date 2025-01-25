/*


 main.cpp  Todo Project
 
 
 Menu that I want to use: 
 
 to add any additional tasks to the list
 to view current to-do list
 to quit the program

 
 Created by Nicholas Brown on 4/10/24.
 
 
*/

#include <iostream>
#include <string> // Include <string> header for string operations
using namespace std;

// Function prototypes
void addTask(string tasks[], int& task_count);
void viewTasks(const string tasks[], int task_count);
void removeTask(string tasks[], int& task_count);

int main() {
    string tasks[10] = {""};
    int task_count = 0;
    int option = -1; /* this -1 acts as a place holder that
     eventually gets overridden in the loop below.
    */
    while (option != 4) {
        // Menu display
        cout << "-------8<---------[ TO - DO LIST ]----" << endl;
        cout << "1 - To Add Task To Do " << endl;
        cout << "2 - To View Current Tasks " << endl;
        cout << "3 - To Delete A Task  " << endl;
        cout << "4 - To Quit Program " << endl;
        cout << "--------------------------->8---------" << endl;
        cin >> option;
        
        switch (option) { //takes user input from 1-4 and allows them to customize the list
            case 1:
                addTask(tasks, task_count);
                break;
            case 2:
                viewTasks(tasks, task_count);
                break;
            case 3:
                removeTask(tasks, task_count);
                break;
            case 4:
                cout << "X X     Exiting program...     X X" << endl;
                break;
            default:
                cout << "X X Invalid. Please try again. X X" << endl;
                break; // returns to the beginning of loop
        }
    }
    return 0;
}

// Function to add a task
void addTask(string tasks[], int& task_count) {
    if (task_count > 9) {
        cout << "X X              LIST IS FULL         X X" << endl;
    } else {
        cout << "Enter A New Task: ";
        cin.ignore(); // Ignores the spaces from input
        getline(cin, tasks[task_count]); // Store task in array
        task_count++; // Increment task count
    }
}

// Function to view tasks
void viewTasks(const string tasks[], int task_count) {
  cout << "Current Tasks:" << endl;
    for (int i = 0; i < task_count; i++) { //increments as i is less than the task counter
    cout << i + 1 << ". " << tasks[i] << endl;
 }
}

// Function to delete a task
void removeTask(string tasks[], int& task_count) {
    int task_num;
    cout << "Enter the task number to delete: ";
    
    cin >> task_num;
    
    if (task_num >= 1 && task_num <= task_count) {
        /*
            As long as task number is greater than 1 AND is less than or equal to the task counter we can start the process of removing the task and shifting the remaining ones upwards.
         */
        for (int i = task_num - 1; i < task_count - 1; i++) {
            tasks[i] = tasks[i + 1]; // Shift tasks left to fill the gap
        }
        task_count--; // Decrement task count
        cout << "Task deleted successfully." << endl;
    } else {
        cout << "Invalid task number. Please try again." << endl;
 }
}


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "taskmanager.hpp"
#include <stdio.h>
#include <stdlib.h>

/*

This is a basic to-do list manager. The user is met with an interface that prompts an action, to add, delete, view, or update a task.
We use a vector to store the tasks.
Adding a task: program reads line input and adds the task to the Task vector.
Deleting a task: program outputs all available tasks, if any, and waits for user input to delete a certain task from the tasks vector
Viewing the tasks: using a for loop to iterate through to last index, information is recieved from the Task class
Updating a task: Outputs list of tasks and waits for user input to update specific one. Error checking is handled. The new status is updated within the task class.
This is a do-while loop, so when the user enters 5 for exis, the program ends.

*/

int main() {
  //tasks are being stored in a vector. can also use map, unordered map, list, dequeue, set, etc. much versatility.
  std::vector<Task> tasks;
  //task description variable, what the task is
  std::string task_desc;
  //option variable for menu selection
  int option;

  //do while for making sure a condition is met. could also probably use a regular while
  do {
    system("CLS");
    std::cout << "1. Add Task | 2. Delete Task | 3. View Tasks | 4. Update Task Status | 5. Exit.\n";
    std::cin >> option;
    //cin.ignore() clears out the previous input. this is important.
    std::cin.ignore();

    /* ---------- option 1 ---------- */
    if (option == 1) {
      system("CLS");
      std::cout << "Enter task description:\n";
      std::getline(std::cin,task_desc);
      tasks.push_back(Task(task_desc));
      std::cout << "Operation complete!\n";

    /* ---------- option 2 ---------- */
    } else if (option == 2) {
      system("CLS");
      std::cout << "Choose task to delete (0 for main menu):\n";
      for (int i = 0;i<tasks.size();i++){
          std::cout << i+1 << ": " << tasks[i].getStatus() << " | " << tasks[i].getDescription() << "\n";
      }

      int deleted;
      std::cin >> deleted;
      std::cin.ignore();

      if (deleted == 0){
        std::cout << "Returning to main menu...\n";
        continue;
      }

      if (deleted < 1 || deleted > tasks.size()){
          std::cout << "Invalid index, try again.\n";
          continue;
      }

      int index = deleted - 1;  

      tasks.erase(tasks.begin() + index);
      

    /* ---------- option 3 ---------- */
    } else if (option == 3) {
      system("CLS");
      if (tasks.empty()) {
        std::cout << "No tasks yet!\n";
      } else {
        std::cout << "(0 for main menu)\n";
        for (int i =0;i<tasks.size();i++){
          std::cout << tasks[i].getStatus() << " | " << tasks[i].getDescription() << "\n";
        }
        int num;
        std::cin >> num;
        std::cin.ignore();
        if (num == 0){
        std::cout << "Returning to main menu...\n";
        continue;
      }
      }
    
    /* ---------- option 4---------- */
    } else if (option == 4) {
      system("CLS");
      if (tasks.empty()) {
        std::cout << "No tasks yet!\n";
        std::cout << "Returning to main menu...\n";
        continue;
      }

      std::cout << "Your tasks:\n";
      for (int i = 0;i<tasks.size();i++){
          std::cout << i+1 << ": " << tasks[i].getStatus() << " | " << tasks[i].getDescription() << "\n";
      }

      std::cout << "Enter the task number to update (0 for main menu):\n";
      int chosen1;
      std::cin >> chosen1;
      std::cin.ignore();

      if (chosen1 == 0){
        std::cout << "Returning to main menu...\n";
        continue;
      }

      if (chosen1 < 1 || chosen1 > tasks.size()){
          std::cout << "Invalid index, try again.\n";
          continue;
      }

      int index = chosen1 - 1;  
      
      std::cout << "1. Mark Completed\n2. Update Status\n0. Main Menu.\n";

      int chosen2;
      std::cin >> chosen2;
      std::cin.ignore();

      if (chosen2 == 0){
        std::cout << "Returning to main menu...\n";
        continue;
      }

      if (chosen2 == 1) {
        tasks[index].setStatus("Complete");
      } else if (chosen2 == 2) {
          std::string new_desc;
          std::cout << "Enter new status for the task:\n";
          std::getline(std::cin,new_desc);
          tasks[index].setStatus(new_desc);
          std::cout << "Task updated!\n";
      } else {
        std::cout << "Invalid index, try again.\n";
          continue;
      }
    }

  /* ---------- option 5 ---------- */
  //add error checking later for non-integers
  } while (option != 5);
  std::cout << "Goodbye!\n";
  return 0;
  
}
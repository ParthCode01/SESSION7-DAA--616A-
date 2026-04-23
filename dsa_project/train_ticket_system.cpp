#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> waitingList;

void displayMenu() {
    cout << "\n==============================" << endl;
    cout << "  Train Ticket System (Queue)" << endl;
    cout << "==============================" << endl;
    cout << "1. Book Ticket" << endl;
    cout << "2. Serve Passenger" << endl;
    cout << "3. Show Waiting List" << endl;
    cout << "4. Show Next Passenger" << endl;
    cout << "5. Exit" << endl;
    cout << "==============================" << endl;
    cout << "Enter your choice: ";
}


void bookTicket() {
    string passengerName;
    cout << "\nEnter passenger name: ";
    cin.ignore();
    getline(cin, passengerName);
    
    waitingList.push(passengerName);
    
    cout << "✓ Ticket booked successfully for " << passengerName << endl;
}

void servePassenger() {
    
    if (waitingList.empty()) {
        cout << "\n✗ No passengers in waiting list!" << endl;
        return;
    }
    
    
    string passenger = waitingList.front();
    
    waitingList.pop();
    
    cout << "\n✓ Serving Passenger: " << passenger << endl;
    cout << "Ticket issued successfully!" << endl;
}

void showWaitingList() {

    if (waitingList.empty()) {
        cout << "\n✗ Waiting list is empty!" << endl;
        return;
    }
    
    cout << "\n--- Waiting List ---" << endl;
    
    
    queue<string> tempQueue = waitingList;
    int position = 1;
    
    while (!tempQueue.empty()) {
        cout << position << ". " << tempQueue.front() << endl;
        tempQueue.pop();
        position++;
    }
    
    cout << "Total passengers waiting: " << waitingList.size() << endl;
}


void showNextPassenger() {
    
    if (waitingList.empty()) {
        cout << "\n✗ No passengers in waiting list!" << endl;
        return;
    }
    
   
    cout << "\nNext Passenger: " << waitingList.front() << endl;
}

int main() {
    int choice;
    
    cout << "\n*** Welcome to Train Ticket Booking System ***" << endl;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                bookTicket();
                break;
            
            case 2:
                servePassenger();
                break;
            
            case 3:
                showWaitingList();
                break;
            
            case 4:
                showNextPassenger();
                break;
            
            case 5:
                cout << "\nThank you for using Train Ticket System!" << endl;
                cout << "Goodbye!" << endl;
                return 0;
            
            default:
                cout << "\n✗ Invalid choice! Please enter 1-5." << endl;
        }
    }
    
    return 0;
}

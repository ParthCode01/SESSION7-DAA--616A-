# Train Ticket System Using Queue Data Structure

## Project Overview
This project demonstrates the Queue (FIFO) data structure through a Train Ticket Waiting List System. It includes:
- Console-based C++ application
- Web-based application with Node.js backend and HTML/CSS/JavaScript frontend

## How Queue is Used in This Project

**Queue (FIFO - First In First Out):**
- The first passenger to book a ticket is the first one to be served
- New passengers are added at the rear of the queue (Enqueue)
- Passengers are served from the front of the queue (Dequeue)
- This ensures fair ticket distribution in order of booking

**Real-World Application:**
Just like a real train ticket counter where people stand in line, the first person in line gets served first.

## Functions Used

| Function | Purpose | Queue Operation |
|----------|---------|-----------------|
| `bookTicket()` | Add passenger to waiting list | Enqueue (push) |
| `servePassenger()` | Issue ticket to next passenger | Dequeue (pop) |
| `showWaitingList()` | Display all waiting passengers | Traverse |
| `showNextPassenger()` | Show who's next in line | Front (peek) |
| `displayMenu()` | Show menu options | - |

## Queue Operations Explained

### 1. Enqueue (push)
```cpp
waitingList.push(passengerName);
```
- Adds a new passenger to the rear of the queue
- Used in `bookTicket()` function

### 2. Dequeue (pop)
```cpp
waitingList.pop();
```
- Removes the passenger from the front of the queue
- Used in `servePassenger()` function

### 3. Front (peek)
```cpp
waitingList.front();
```
- Views the front passenger without removing
- Used in `showNextPassenger()` function

### 4. Empty Check
```cpp
waitingList.empty();
```
- Checks if queue has any passengers
- Prevents errors when queue is empty

## How to Compile and Run

### Using g++ compiler:
```bash
g++ train_ticket_system.cpp -o train_ticket_system
./train_ticket_system
```

### Using Windows:
```bash
g++ train_ticket_system.cpp -o train_ticket_system.exe
train_ticket_system.exe
```

## Sample Run

```
*** Welcome to Train Ticket Booking System ***

==============================
  Train Ticket System (Queue)
==============================
1. Book Ticket
2. Serve Passenger
3. Show Waiting List
4. Show Next Passenger
5. Exit
==============================
Enter your choice: 1

Enter passenger name: Rahul
✓ Ticket booked successfully for Rahul

Enter your choice: 1

Enter passenger name: Anjali
✓ Ticket booked successfully for Anjali

Enter your choice: 3

--- Waiting List ---
1. Rahul
2. Anjali
Total passengers waiting: 2

Enter your choice: 2

✓ Serving Passenger: Rahul
Ticket issued successfully!

Enter your choice: 3

--- Waiting List ---
1. Anjali
Total passengers waiting: 1
```

## Features

✓ Simple menu-driven interface
✓ Book tickets (Enqueue operation)
✓ Serve passengers in FIFO order (Dequeue operation)
✓ View complete waiting list
✓ Check next passenger without removing
✓ Input validation and error handling
✓ Clean and readable code with comments

## Code Statistics

- Total Lines: ~140 lines
- Functions: 5
- Data Structure: STL Queue
- Complexity: Beginner-friendly


## Web Application Setup

### Prerequisites
- Node.js installed (v14 or higher)
- npm (comes with Node.js)

### Installation Steps

1. Install dependencies:
```bash
npm install
```

2. Start the server:
```bash
npm start
```

3. Open your browser and visit:
```
http://localhost:3000
```

### Web Application Features

✓ Beautiful, responsive UI with gradient design
✓ Real-time queue visualization
✓ Book tickets with passenger names
✓ Serve passengers in FIFO order
✓ View next passenger without removing
✓ Clear entire queue
✓ Visual feedback with animations
✓ Toast notifications for all actions

### API Endpoints

| Method | Endpoint | Description | Queue Operation |
|--------|----------|-------------|-----------------|
| GET | `/api/passengers` | Get all passengers | View Queue |
| POST | `/api/book` | Book a ticket | Enqueue |
| POST | `/api/serve` | Serve next passenger | Dequeue |
| GET | `/api/next` | Get next passenger | Front |
| DELETE | `/api/clear` | Clear all passengers | Clear |

### Project Structure

```
train-ticket-system/
├── public/
│   ├── index.html          # Frontend HTML
│   ├── style.css           # Styling
│   └── script.js           # Frontend JavaScript
├── server.js               # Backend Node.js server
├── package.json            # Dependencies
├── train_ticket_system.cpp # C++ console version
└── README.md               # Documentation
```

### Backend (server.js)
- Express.js server
- Queue class implementation
- RESTful API endpoints
- CORS enabled for cross-origin requests

### Frontend (public/)
- Clean, modern UI design
- Responsive layout (mobile-friendly)
- Real-time updates
- Visual queue representation
- Interactive buttons and forms

### Technologies Used

**Backend:**
- Node.js
- Express.js
- CORS middleware

**Frontend:**
- HTML5
- CSS3 (with animations and gradients)
- Vanilla JavaScript (ES6+)
- Fetch API for HTTP requests

**C++ Version:**
- STL Queue
- Console-based interface

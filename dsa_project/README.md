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

## Viva Questions & Answers

**Q1: What is a Queue?**
A: Queue is a linear data structure that follows FIFO (First In First Out) principle. The element inserted first is removed first.

**Q2: Why use Queue for this project?**
A: Queue ensures fair ticket distribution. Passengers who book first get served first, just like a real waiting line.

**Q3: What is the time complexity of enqueue and dequeue?**
A: Both operations have O(1) time complexity - constant time.

**Q4: What happens if we try to serve when queue is empty?**
A: The program checks using `empty()` function and displays "No passengers in waiting list".

**Q5: Can we see who's next without removing them?**
A: Yes, using the `front()` function which returns the front element without removing it.

## Advantages of Using Queue

1. Fair ordering - First come, first served
2. Simple to implement and understand
3. Efficient operations (O(1) for enqueue/dequeue)
4. Prevents confusion in ticket distribution
5. Easy to track waiting passengers

## Project Suitability

✓ Perfect for DSA college assignments
✓ Easy to explain in viva
✓ Demonstrates practical use of Queue
✓ Clean, commented code
✓ No advanced concepts required
✓ Compiles without errors


---

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

## Screenshots Description

### Web Interface:
- Left panel: Action buttons for all queue operations
- Right panel: Visual representation of the queue
- Top shows total passenger count
- First passenger highlighted in green (NEXT)
- Toast notifications for user feedback

## Demonstration Tips

1. Start with the C++ console version to explain basic queue concepts
2. Show the web version for visual demonstration
3. Explain how both implementations use the same Queue logic
4. Demonstrate FIFO principle by booking multiple tickets and serving them in order
5. Show the API endpoints using browser DevTools or Postman

## Viva Questions for Web Version

**Q1: Why use Node.js for backend?**
A: Node.js is lightweight, fast, and perfect for building REST APIs. It handles multiple requests efficiently.

**Q2: How does frontend communicate with backend?**
A: Using Fetch API to make HTTP requests (GET, POST, DELETE) to the Express server endpoints.

**Q3: Where is the queue stored?**
A: In server memory as a JavaScript array. For production, you'd use a database.

**Q4: What happens if server restarts?**
A: All queue data is lost since it's stored in memory. For persistence, use a database like MongoDB or Redis.

**Q5: How is FIFO maintained in the web version?**
A: Using JavaScript array methods: `push()` for enqueue and `shift()` for dequeue, maintaining FIFO order.

## Advantages of Web Version

1. Visual representation of queue
2. Multiple users can access simultaneously
3. Better user experience with animations
4. Easy to demonstrate and showcase
5. Can be deployed online for remote access
6. Professional presentation for projects

## Future Enhancements

- Add database for data persistence
- User authentication
- Multiple train routes
- Ticket priority levels
- Email notifications
- Payment integration
- Admin dashboard
- Real-time updates using WebSockets

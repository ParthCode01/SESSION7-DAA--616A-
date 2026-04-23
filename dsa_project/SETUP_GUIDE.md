# Quick Setup Guide - Train Ticket System

## Option 1: C++ Console Version

### Requirements:
- C++ compiler (g++, MinGW, or Visual Studio)

### Steps:
1. Open terminal in project folder
2. Compile:
   ```bash
   g++ train_ticket_system.cpp -o train_ticket_system
   ```
3. Run:
   ```bash
   ./train_ticket_system
   ```

---

## Option 2: Web Application

### Requirements:
- Node.js (Download from: https://nodejs.org/)

### Steps:

1. **Install Node.js** (if not installed)
   - Visit https://nodejs.org/
   - Download LTS version
   - Install with default settings

2. **Install Dependencies**
   ```bash
   npm install
   ```
   This will install:
   - express (web server)
   - cors (cross-origin support)

3. **Start the Server**
   ```bash
   npm start
   ```
   You should see:
   ```
   ========================================
     Train Ticket System Server Running
   ========================================
     URL: http://localhost:3000
   ========================================
   ```

4. **Open in Browser**
   - Open your web browser
   - Go to: http://localhost:3000
   - Start using the application!

---

## Troubleshooting

### Problem: "npm: command not found"
**Solution:** Node.js is not installed. Install it from nodejs.org

### Problem: "Port 3000 is already in use"
**Solution:** 
- Close other applications using port 3000
- Or change port in server.js (line 8): `const PORT = 3001;`

### Problem: "Cannot GET /"
**Solution:** Make sure you're accessing http://localhost:3000 (not https)

### Problem: C++ compilation error
**Solution:** 
- Make sure g++ is installed
- On Windows, install MinGW or use Visual Studio
- Check file name is correct: train_ticket_system.cpp

---

## Testing the Application

### Web Version Test Steps:
1. Book 3 tickets with different names
2. Check waiting list shows all 3 passengers
3. Click "Show Next" - should show first passenger
4. Click "Serve Next" - first passenger gets ticket
5. Check waiting list now shows 2 passengers
6. Verify FIFO order is maintained

### C++ Version Test Steps:
1. Choose option 1 to book tickets
2. Enter 3 different passenger names
3. Choose option 3 to view waiting list
4. Choose option 2 to serve passenger
5. Verify first passenger is served
6. Check waiting list again

---

## For Presentation/Demo

### Recommended Demo Flow:
1. Start with C++ version to explain Queue concept
2. Show code and explain enqueue/dequeue operations
3. Switch to web version for visual demonstration
4. Show how both use same Queue logic
5. Demonstrate FIFO principle with live examples

### Key Points to Highlight:
- Queue follows FIFO (First In First Out)
- Enqueue adds to rear, Dequeue removes from front
- Real-world application: ticket booking systems
- Time complexity: O(1) for both operations
- Simple and efficient data structure

---

## Quick Commands Reference

### Web Application:
```bash
npm install          # Install dependencies
npm start           # Start server
Ctrl+C              # Stop server
```

### C++ Application:
```bash
g++ train_ticket_system.cpp -o train_ticket_system    # Compile
./train_ticket_system                                  # Run (Linux/Mac)
train_ticket_system.exe                                # Run (Windows)
```

---

## Need Help?

- Check README.md for detailed documentation
- Review code comments for explanations
- Test API endpoints using browser DevTools
- Check console for error messages

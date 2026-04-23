/*
=======================================================
    TRAIN TICKET SYSTEM - BACKEND SERVER
    Using Queue Data Structure (FIFO)
=======================================================
*/

const express = require('express');
const cors = require('cors');
const path = require('path');

const app = express();
const PORT = 3000;

// Middleware
app.use(cors());
app.use(express.json());
app.use(express.static('public'));

// Queue Implementation using Array
class Queue {
    constructor() {
        this.items = [];
    }

    // Enqueue: Add passenger to the queue
    enqueue(passenger) {
        this.items.push(passenger);
    }

    // Dequeue: Remove and return front passenger
    dequeue() {
        if (this.isEmpty()) {
            return null;
        }
        return this.items.shift();
    }

    // Front: View front passenger without removing
    front() {
        if (this.isEmpty()) {
            return null;
        }
        return this.items[0];
    }

    // Check if queue is empty
    isEmpty() {
        return this.items.length === 0;
    }

    // Get queue size
    size() {
        return this.items.length;
    }

    // Get all passengers
    getAll() {
        return this.items;
    }

    // Clear the queue
    clear() {
        this.items = [];
    }
}

// Create global queue instance
const waitingList = new Queue();

// API Routes

// Get all passengers in waiting list
app.get('/api/passengers', (req, res) => {
    res.json({
        success: true,
        passengers: waitingList.getAll(),
        count: waitingList.size()
    });
});

// Book a ticket (Enqueue)
app.post('/api/book', (req, res) => {
    const { name } = req.body;

    if (!name || name.trim() === '') {
        return res.status(400).json({
            success: false,
            message: 'Passenger name is required'
        });
    }

    const passenger = {
        id: Date.now(),
        name: name.trim(),
        bookedAt: new Date().toLocaleString()
    };

    waitingList.enqueue(passenger);

    res.json({
        success: true,
        message: `Ticket booked successfully for ${passenger.name}`,
        passenger: passenger,
        queueSize: waitingList.size()
    });
});

// Serve passenger (Dequeue)
app.post('/api/serve', (req, res) => {
    if (waitingList.isEmpty()) {
        return res.status(400).json({
            success: false,
            message: 'No passengers in waiting list'
        });
    }

    const passenger = waitingList.dequeue();

    res.json({
        success: true,
        message: `Ticket issued to ${passenger.name}`,
        passenger: passenger,
        queueSize: waitingList.size()
    });
});

// Get next passenger (Front)
app.get('/api/next', (req, res) => {
    if (waitingList.isEmpty()) {
        return res.status(400).json({
            success: false,
            message: 'No passengers in waiting list'
        });
    }

    const passenger = waitingList.front();

    res.json({
        success: true,
        passenger: passenger
    });
});

// Clear all passengers
app.delete('/api/clear', (req, res) => {
    waitingList.clear();
    res.json({
        success: true,
        message: 'Waiting list cleared'
    });
});

// Serve index.html
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

// Start server
app.listen(PORT, () => {
    console.log(`\n========================================`);
    console.log(`  Train Ticket System Server Running`);
    console.log(`========================================`);
    console.log(`  URL: http://localhost:${PORT}`);
    console.log(`========================================\n`);
});

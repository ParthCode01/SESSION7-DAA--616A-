/*
=======================================================
    TRAIN TICKET SYSTEM - FRONTEND JAVASCRIPT
    Queue Operations: Enqueue, Dequeue, Front, isEmpty
=======================================================
*/

const API_URL = 'http://localhost:3000/api';

// Load passengers on page load
document.addEventListener('DOMContentLoaded', () => {
    loadPassengers();
});

// Handle Enter key in input field
function handleEnter(event) {
    if (event.key === 'Enter') {
        bookTicket();
    }
}

// Book Ticket (Enqueue Operation)
async function bookTicket() {
    const nameInput = document.getElementById('passengerName');
    const name = nameInput.value.trim();

    if (!name) {
        showMessage('Please enter passenger name', 'error');
        return;
    }

    try {
        const response = await fetch(`${API_URL}/book`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ name })
        });

        const data = await response.json();

        if (data.success) {
            showMessage(data.message, 'success');
            nameInput.value = '';
            loadPassengers();
        } else {
            showMessage(data.message, 'error');
        }
    } catch (error) {
        showMessage('Error booking ticket', 'error');
        console.error(error);
    }
}

// Serve Passenger (Dequeue Operation)
async function servePassenger() {
    try {
        const response = await fetch(`${API_URL}/serve`, {
            method: 'POST'
        });

        const data = await response.json();

        if (data.success) {
            showMessage(data.message, 'success');
            loadPassengers();
        } else {
            showMessage(data.message, 'error');
        }
    } catch (error) {
        showMessage('Error serving passenger', 'error');
        console.error(error);
    }
}

// Show Next Passenger (Front Operation)
async function showNext() {
    try {
        const response = await fetch(`${API_URL}/next`);
        const data = await response.json();

        if (data.success) {
            showMessage(`Next Passenger: ${data.passenger.name}`, 'info');
        } else {
            showMessage(data.message, 'error');
        }
    } catch (error) {
        showMessage('Error fetching next passenger', 'error');
        console.error(error);
    }
}

// Clear Queue
async function clearQueue() {
    if (!confirm('Are you sure you want to clear all passengers?')) {
        return;
    }

    try {
        const response = await fetch(`${API_URL}/clear`, {
            method: 'DELETE'
        });

        const data = await response.json();

        if (data.success) {
            showMessage(data.message, 'success');
            loadPassengers();
        }
    } catch (error) {
        showMessage('Error clearing queue', 'error');
        console.error(error);
    }
}

// Load and Display Passengers
async function loadPassengers() {
    try {
        const response = await fetch(`${API_URL}/passengers`);
        const data = await response.json();

        if (data.success) {
            displayPassengers(data.passengers, data.count);
        }
    } catch (error) {
        console.error('Error loading passengers:', error);
    }
}

// Display Passengers in Queue
function displayPassengers(passengers, count) {
    const queueList = document.getElementById('queueList');
    const totalCount = document.getElementById('totalCount');

    totalCount.textContent = count;

    if (passengers.length === 0) {
        queueList.innerHTML = '<div class="empty-message">No passengers in queue</div>';
        return;
    }

    let html = '';
    passengers.forEach((passenger, index) => {
        const isFirst = index === 0;
        html += `
            <div class="passenger-item ${isFirst ? 'first' : ''}">
                <span class="position-badge">#${index + 1}</span>
                <span class="passenger-name">${passenger.name}</span>
                ${isFirst ? ' <span style="color: #27ae60; font-weight: 500;">• Next</span>' : ''}
                <div class="passenger-time">${passenger.bookedAt}</div>
            </div>
        `;
    });

    queueList.innerHTML = html;
}

// Show Message
function showMessage(message, type) {
    const messageBox = document.getElementById('messageBox');
    
    messageBox.textContent = message;
    messageBox.className = `message-box ${type} show`;

    setTimeout(() => {
        messageBox.classList.remove('show');
    }, 3000);
}

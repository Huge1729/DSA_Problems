
************************************************** What is Busy Waiting?
Busy waiting occurs when a process or thread continuously checks for a condition to become true (like access to a shared resource), 
without releasing the CPU. It keeps the CPU engaged by running a loop repeatedly until the required condition is met.

************************************************** Peterson's Algorithm for Mutual Exclusion in C++ (Pseudocode)
bool flag[2] = {false, false};  // Flag array to indicate if a process wants to enter the critical section
int turn = 0;                   // Variable to indicate whose turn it is

void process_0() {
    // Request to enter critical section
    flag[0] = true;
    turn = 1;  // Give turn to process 1
    // Wait until process 1 is not in its critical section or it's process 0's turn
    while (flag[1] && turn == 1) {
        // Busy waiting (spin-waiting)
    }
    // Critical Section (only one process executes this at a time)
    // ...
    // Exit the critical section
    flag[0] = false;
}

void process_1() {
    // Request to enter critical section
    flag[1] = true;
    turn = 0;  // Give turn to process 0
    // Wait until process 0 is not in its critical section or it's process 1's turn
    while (flag[0] && turn == 0) {
        // Busy waiting (spin-waiting)
    }
    // Critical Section (only one process executes this at a time)
    // ...
    // Exit the critical section
    flag[1] = false;
}
************************************************************************** Producer-Consumer  ****************************************************************
Producer-Consumer Pseudocode
Variables Used:
empty: Semaphore to track empty slots.
full: Semaphore to track filled slots.
mutex: A mutex to prevent simultaneous access to the buffer.
Buffer: Shared space where items are produced and consumed.

Pseudocode for Producer
do {
   wait(empty);      // Wait if no empty slots
   wait(mutex);      // Lock the buffer

   // Critical Section: Add item to buffer
   produce_item();

   signal(mutex);    // Unlock the buffer
   signal(full);     // Signal that a new item is available
} while (true);

Pseudocode for Consumer
do {
   wait(full);       // Wait if no items to consume
   wait(mutex);      // Lock the buffer

   // Critical Section: Remove item from buffer
   consume_item();

   signal(mutex);    // Unlock the buffer
   signal(empty);    // Signal that a slot is now empty
} while (true);

Explanation:

Producer:
Waits for an empty slot.
Locks the buffer to add an item.
After adding, unlocks the buffer.
Signals that a new item is available.
  
Consumer:
Waits for an available item.
Locks the buffer to remove the item.
After removing, unlocks the buffer.
Signals that a slot is now empty.
Mutex: Ensures only one thread accesses the buffer at a time.

Semaphores: Used to track the number of available slots/items.
*************************************************************************************** Reader Writer problem *******************************************************
Problem Overview:
Readers can read simultaneously if no writer is writing.
Writers need exclusive access to the shared resource (critical section), meaning no other reader or writer can access it when a writer is writing.
Pseudocode for Writers:
Writers need exclusive access, so they use a semaphore (wrt).
do {
    wait(wrt);   // Request access to the critical section (exclusive lock).
    
    // Critical Section: Writing happens here.

    signal(wrt); // Release the lock after writing.
} while(1);

Pseudocode for Readers:
Readers need to coordinate access using a shared read_count (number of active readers).
We also use a mutex to modify read_count safely.
int read_count = 0;  // Keeps track of the number of active readers.

do {
    wait(mutex);      // Lock to update `read_count`.
    read_count++;     // A new reader arrives.

    if (read_count == 1) {  
        wait(wrt);    // First reader locks writers out.
    }
    signal(mutex);    // Unlock after updating `read_count`.

    // Critical Section: Reading happens here.

    wait(mutex);      // Lock to update `read_count`.
    read_count--;     // Reader leaves.

    if (read_count == 0) {  
        signal(wrt);  // Last reader unlocks writers.
    }
    signal(mutex);    // Unlock after updating `read_count`.
} while(1);

Explanation:
For Writers:
Writers wait for the wrt semaphore before entering the critical section.
Only one writer can write at a time (exclusive access).
Once writing is done, the writer signals wrt to allow other readers or writers.
For Readers:
Multiple readers can read simultaneously.
The first reader locks writers out (wait(wrt)).
The last reader signals wrt, allowing writers to access the resource.
Why Mutex for Readers?
Mutex ensures that read_count is updated safely, preventing race conditions when multiple readers try to increment or decrement it simultaneously.
****************************************************************************** Dining Philosophers Problem ******************************************************************************
Problem Overview:
There are five philosophers sitting at a table.
Each philosopher needs two chopsticks (left and right) to eat.
The goal is to avoid deadlock and ensure that philosophers can eat when possible.
  
Pseudocode for Dining Philosophers Problem
// Assuming chopstick[5] are semaphores initialized to 1
chopstick[5] = {1, 1, 1, 1, 1}; // Each chopstick is available

do {
    think(); // Philosopher is thinking

    // Acquire chopsticks
    wait(chopstick[i]);              // Pick up the left chopstick
    wait(chopstick[(i + 1) % 5]);    // Pick up the right chopstick

    eat(); // Philosopher is eating

    // Release chopsticks
    signal(chopstick[i]);            // Put down the left chopstick
    signal(chopstick[(i + 1) % 5]);  // Put down the right chopstick
} while(1);

Explanation:
Chopsticks as Semaphores:
Each chopstick is represented as a semaphore, initialized to 1, indicating that the chopstick is available

Philosopher Actions:
Each philosopher thinks before trying to eat.
To eat, they must acquire both chopsticks (left and right).
The wait operation decrements the semaphore value, blocking the philosopher if the chopstick is unavailable.
After eating, they release both chopsticks using the signal operation, incrementing the semaphore value

Deadlock Avoidance:
This implementation may lead to deadlock if all philosophers pick up their left chopstick simultaneously.
To avoid deadlock, you can implement additional strategies:
Limit the number of philosophers that can sit at the table.
Introduce an arbitrator to control access to chopsticks.
Resource hierarchy: Always pick up the lower-numbered chopstick first.

Additional Considerations:
Thinking and Eating Functions: The think() and eat() functions can be defined with the philosopher's specific actions, like waiting for a certain time to simulate thinking or eating.
Concurrency Control: Proper handling of the semaphores is essential to avoid race conditions and ensure the correctness of the program.


*********************************************************************** LRU Cache ******************************************************************************
class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};

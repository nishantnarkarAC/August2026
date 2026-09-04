#include <iostream>
#include <cstring>

using namespace std;

class LogBuffer {
private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

public:
    // Constructor
    LogBuffer(int cap) : capacity(cap), size(0) {
        buffer = new char[capacity];
        buffer[0] = '\0';
        ++instanceCount;
        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }

    // Copy Constructor (Deep Copy)
    LogBuffer(const LogBuffer& other) : capacity(other.capacity), size(other.size) {
        buffer = new char[capacity];
        for (int i = 0; i <= size; ++i) {
            buffer[i] = other.buffer[i];
        }
        ++instanceCount;
        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }

    // Copy Assignment Operator
    LogBuffer& operator=(const LogBuffer& other) {
        if (this == &other) {
            cout << "[Self-assignment detected no operation]" << endl;
            return *this;
        }

        delete[] buffer;

        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity];
        for (int i = 0; i <= size; ++i) {
            buffer[i] = other.buffer[i];
        }

        cout << "[LogBuffer Assigned]" << endl;
        return *this;
    }

    // Destructor
    ~LogBuffer() {
        delete[] buffer;
        --instanceCount;
        cout << "[LogBuffer Destroyed]" << endl;
    }

    // Appends msg to buffer (up to capacity)
    void append(const char* msg) {
        int i = 0;
        while (msg[i] != '\0' && size < capacity - 1) {
            buffer[size++] = msg[i++];
        }
        buffer[size] = '\0';
    }

    // Prints current buffer contents
    void print() const {
        cout << buffer << endl;
    }

    // Resets size to 0
    void clear() {
        size = 0;
        if (capacity > 0) {
            buffer[0] = '\0';
        }
    }

    // Returns current live object count
    static int getInstanceCount() {
        return instanceCount;
    }
};

// Initialize static member
int LogBuffer::instanceCount = 0;

int main() {
    // Objective 1: Basic usage
    LogBuffer log1(256);
    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");
    log1.print();

    // Objective 2: Deep copy via copy constructor
    LogBuffer log2 = log1; // copy constructor
    log2.append(" | Cached response sent");
    cout << "log1: "; log1.print(); // must NOT contain log2's append
    cout << "log2: "; log2.print();

    // Objective 3: Copy assignment operator
    LogBuffer log3(128);
    log3 = log1; // copy assignment
    log3.print();

    // Objective 4: Self-assignment guard
    log1 = log1; // must not crash or corrupt data
    log1.print();

    // Objective 5: Static member
    cout << "Live LogBuffer objects: " << LogBuffer::getInstanceCount() << endl;

    return 0;
    // All 3 objects destroyed here destructors must print and decrement count
}
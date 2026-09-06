#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using namespace std;


class DataProcessor {
public:
    virtual void loadData(const string& source) = 0;
    virtual void processData() = 0;
    virtual void exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;

    virtual void printSummary() const {
        cout << "Processor: " << processorType() << " | Total Records: " << recordCount() << endl;
    }

    virtual ~DataProcessor() = default;
};


class CSVProcessor : public DataProcessor {
private:
    vector<string> records;

public:
    void loadData(const string& source) override {
        // Simulating reading CSV data
        records = {"id,name,role", "1,alice,admin", "2,bob,user", "3,charlie,moderator", "4,diana,user"};
    }

    void processData() override {
        for (auto& row : records) {
            transform(row.begin(), row.end(), row.begin(), ::toupper);
        }
    }

    void exportResult(const string& destination) override {
        cout << "[CSV EXPORT <" << destination << ">]" << endl;
        for (const auto& row : records) {
            cout << row << endl;
        }
    }

    string processorType() const override { return "CSV Processor"; }
    int recordCount() const override { return records.size(); }
};

class SensorStreamProcessor : public DataProcessor {
private:
    vector<double> readings;
    double meanVal = 0.0;
    double minVal = 0.0;
    double maxVal = 0.0;

public:
    void loadData(const string& source) override {
        readings = {23.4, 21.8, 25.1, 24.2, 22.9, 26.5, 23.0, 24.8};
    }

    void processData() override {
        if (readings.empty()) return;
        double sum = 0.0;
        minVal = readings[0];
        maxVal = readings[0];
        for (double r : readings) {
            sum += r;
            if (r < minVal) minVal = r;
            if (r > maxVal) maxVal = r;
        }
        meanVal = sum / readings.size();
    }

    void exportResult(const string& destination) override {
        cout << "[SENSOR EXPORT <" << destination << ">]" << endl;
        cout << "Mean: " << meanVal << ", Min: " << minVal << ", Max: " << maxVal << endl;
    }

    string processorType() const override { return "Sensor Stream Processor"; }
    int recordCount() const override { return readings.size(); }

    double getMean() const { return meanVal; }
};


template <typename T>
class DataBuffer {
private:
    T* data;
    int capacity;
    int head;
    int tail;
    int count;

public:
    DataBuffer(int cap) : capacity(cap), head(0), tail(0), count(0) {
        data = new T[capacity];
    }

    ~DataBuffer() {
        delete[] data;
    }

    void push(const T& value) {
        data[tail] = value;
        tail = (tail + 1) % capacity;
        if (count < capacity) {
            count++;
        } else {
            head = (head + 1) % capacity; // Overwrite oldest element when full
        }
    }

    T pop() {
        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }
        T val = data[head];
        head = (head + 1) % capacity;
        count--;
        return val;
    }

    T peek() const {
        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }
        return data[head];
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    int size() const { return count; }

    template <typename U>
    friend ostream& operator<<(ostream& out, const DataBuffer<U>& buf);
};


template <typename U>
ostream& operator<<(ostream& out, const DataBuffer<U>& buf) {
    out << "[";
    for (int i = 0; i < buf.count; ++i) {
        int idx = (buf.head + i) % buf.capacity;
        out << buf.data[idx];
        if (i < buf.count - 1) out << ", ";
    }
    out << "]";
    return out;
}

int main() {
    
    vector<DataProcessor*> pipeline;
    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());

    for (auto* p : pipeline) {
        p->loadData("source_data");
        p->processData();
        p->printSummary();
        p->exportResult("output_dir");
        cout << "---" << endl;
    }

    for (auto* p : pipeline) {
        if (auto* csv = dynamic_cast<CSVProcessor*>(p)) {
            cout << "Found CSV Processor with " << csv->recordCount() << " records." << endl;
        } else if (auto* sensor = dynamic_cast<SensorStreamProcessor*>(p)) {
        
            cout << "Found Sensor Processor Mean: " << sensor->getMean() << endl;
        }
    }
    
    for (auto* p : pipeline) {
        delete p;
    }
    pipeline.clear();

    cout << "\n--- DataBuffer Template Tests ---" << endl;


    DataBuffer<int> tickBuffer(5);
    for (int i = 1; i <= 7; ++i) tickBuffer.push(i * 10);
    cout << "Tick Buffer: " << tickBuffer << endl;

    
    DataBuffer<double> tempBuffer(4);
    tempBuffer.push(36.6); 
    tempBuffer.push(37.1);
    tempBuffer.push(38.2); 
    tempBuffer.push(36.9);
    cout << "Before pop: " << tempBuffer << endl;
    cout << "Popped: " << tempBuffer.pop() << endl;
    cout << "After pop: " << tempBuffer << endl;

    
    DataBuffer<string> logBuffer(3);
    logBuffer.push("\"INFO: Server started\"");
    logBuffer.push("\"WARN: High memory usage\"");
    logBuffer.push("\"ERROR: DB connection timeout\"");
    logBuffer.push("\"INFO: Retry successful\""); 
    cout << "Log Buffer: " << logBuffer << endl;

    return 0;
}
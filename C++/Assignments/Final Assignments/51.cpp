#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>
#include <iomanip>
#include <algorithm>

namespace LibrarySystem {

class LibraryException : public std::exception {
protected:
    std::string message;
public:
    LibraryException(const std::string& msg, const std::string& func, int line) {
        std::ostringstream ss;
        ss << "Error: " << msg << " [Function: " << func << ", Line: " << line << "]";
        message = ss.str();
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BookNotFoundException : public LibraryException {
public:
    BookNotFoundException(const std::string& func, int line) : LibraryException("Book not found", func, line) {}
};

class MemberNotFoundException : public LibraryException {
public:
    MemberNotFoundException(const std::string& func, int line) : LibraryException("Member not found", func, line) {}
};

class BookNotAvailableException : public LibraryException {
public:
    BookNotAvailableException(const std::string& func, int line) : LibraryException("Book not available", func, line) {}
};

class MaxBooksExceededException : public LibraryException {
public:
    MaxBooksExceededException(const std::string& func, int line) : LibraryException("Max books limit exceeded", func, line) {}
};

class Person {
protected:
    std::string id;
    std::string name;
    std::string phone;
public:
    Person(const std::string& i, const std::string& n, const std::string& p) : id(i), name(n), phone(p) {}
    virtual ~Person() {}
    virtual void displayInfo() const = 0;
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
};

class Member : public Person {
private:
    int booksIssuedCount;
    int maxBooksCapacity;
    std::string* issuedBookIds;
public:
    Member(const std::string& i = "", const std::string& n = "", const std::string& p = "", int cap = 3) 
        : Person(i, n, p), booksIssuedCount(0), maxBooksCapacity(cap) {
        issuedBookIds = new std::string[maxBooksCapacity];
    }
    Member(const Member& other) : Person(other.id, other.name, other.phone), booksIssuedCount(other.booksIssuedCount), maxBooksCapacity(other.maxBooksCapacity) {
        issuedBookIds = new std::string[maxBooksCapacity];
        for (int i = 0; i < booksIssuedCount; ++i) {
            issuedBookIds[i] = other.issuedBookIds[i];
        }
    }
    Member& operator=(const Member& other) {
        if (this != &other) {
            id = other.id;
            name = other.name;
            phone = other.phone;
            booksIssuedCount = other.booksIssuedCount;
            maxBooksCapacity = other.maxBooksCapacity;
            delete[] issuedBookIds;
            issuedBookIds = new std::string[maxBooksCapacity];
            for (int i = 0; i < booksIssuedCount; ++i) {
                issuedBookIds[i] = other.issuedBookIds[i];
            }
        }
        return *this;
    }
    ~Member() {
        delete[] issuedBookIds;
    }
    void displayInfo() const override {
        std::cout << "Member ID: " << id << ", Name: " << name << ", Phone: " << phone << ", Books Issued: " << booksIssuedCount << std::endl;
    }
    bool operator==(const Member& other) const {
        return id == other.id;
    }
    bool addBookId(const std::string& bId) {
        if (booksIssuedCount >= maxBooksCapacity) return false;
        issuedBookIds[booksIssuedCount++] = bId;
        return true;
    }
    bool removeBookId(const std::string& bId) {
        for (int i = 0; i < booksIssuedCount; ++i) {
            if (issuedBookIds[i] == bId) {
                for (int j = i; j < booksIssuedCount - 1; ++j) {
                    issuedBookIds[j] = issuedBookIds[j + 1];
                }
                booksIssuedCount--;
                return true;
            }
        }
        return false;
    }
    int getBooksIssuedCount() const { return booksIssuedCount; }
    std::string getBookId(int index) const {
        if (index >= 0 && index < booksIssuedCount) return issuedBookIds[index];
        return "";
    }
    friend std::ostream& operator<<(std::ostream& out, const Member& m) {
        out << m.id << "|" << m.name << "|" << m.phone << "|" << m.booksIssuedCount;
        for (int i = 0; i < m.booksIssuedCount; ++i) {
            out << "|" << m.issuedBookIds[i];
        }
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Member& m) {
        std::string line;
        if (std::getline(in, line)) {
            std::stringstream ss(line);
            std::string countStr;
            std::getline(ss, m.id, '|');
            std::getline(ss, m.name, '|');
            std::getline(ss, m.phone, '|');
            if (std::getline(ss, countStr, '|')) {
                m.booksIssuedCount = std::stoi(countStr);
                delete[] m.issuedBookIds;
                m.maxBooksCapacity = m.booksIssuedCount > 0 ? m.booksIssuedCount + 2 : 3;
                m.issuedBookIds = new std::string[m.maxBooksCapacity];
                for (int i = 0; i < m.booksIssuedCount; ++i) {
                    std::getline(ss, m.issuedBookIds[i], '|');
                }
            }
        }
        return in;
    }
};

class Librarian : public Person {
private:
    std::string employeeId;
    double salary;
public:
    Librarian(const std::string& i = "", const std::string& n = "", const std::string& p = "", const std::string& empId = "", double sal = 0.0)
        : Person(i, n, p), employeeId(empId), salary(sal) {}
    void displayInfo() const override {
        std::cout << "Librarian ID: " << id << ", Name: " << name << ", Phone: " << phone << ", Employee ID: " << employeeId << ", Salary: " << salary << std::endl;
    }
};

enum class BookStatus { AVAILABLE, ISSUED };
enum class BookGenre { FICTION, NON_FICTION, SCIENCE, HISTORY, TECHNOLOGY };

class Book {
private:
    std::string bookId;
    std::string title;
    std::string author;
    std::string isbn;
    BookStatus status;
    int quantity;
    int availableCopies;
public:
    Book(const std::string& id = "", const std::string& t = "", const std::string& a = "", const std::string& i = "", BookStatus s = BookStatus::AVAILABLE, int q = 1, int ac = 1)
        : bookId(id), title(t), author(a), isbn(i), status(s), quantity(q), availableCopies(ac) {}
    
    Book& operator++() {
        quantity++;
        availableCopies++;
        return *this;
    }
    Book operator++(int) {
        Book temp = *this;
        quantity++;
        availableCopies++;
        return temp;
    }
    bool operator==(const Book& other) const {
        return bookId == other.bookId;
    }
    bool operator<(const Book& other) const {
        return bookId < other.bookId;
    }
    std::string operator[](int index) const {
        switch (index) {
            case 0: return bookId;
            case 1: return title;
            case 2: return author;
            case 3: return isbn;
            case 4: return (status == BookStatus::AVAILABLE ? "AVAILABLE" : "ISSUED");
            case 5: return std::to_string(quantity);
            case 6: return std::to_string(availableCopies);
            default: return "";
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Book& b) {
        out << b.bookId << " | " << b.title << " | " << b.author << " | " << b.isbn << " | " 
            << (b.status == BookStatus::AVAILABLE ? "AVAILABLE" : "ISSUED") << " | " 
            << b.quantity << " | " << b.availableCopies;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Book& b) {
        std::string line;
        if (std::getline(in, line)) {
            std::stringstream ss(line);
            std::string statStr, qtyStr, availStr;
            std::getline(ss, b.bookId, '|');
            std::getline(ss, b.title, '|');
            std::getline(ss, b.author, '|');
            std::getline(ss, b.isbn, '|');
            std::getline(ss, statStr, '|');
            std::getline(ss, qtyStr, '|');
            std::getline(ss, availStr, '|');
            
            b.bookId.erase(0, b.bookId.find_first_not_of(" \t"));
            b.bookId.erase(b.bookId.find_last_not_of(" \t") + 1);
            b.title.erase(0, b.title.find_first_not_of(" \t"));
            b.title.erase(b.title.find_last_not_of(" \t") + 1);
            b.author.erase(0, b.author.find_first_not_of(" \t"));
            b.author.erase(b.author.find_last_not_of(" \t") + 1);
            b.isbn.erase(0, b.isbn.find_first_not_of(" \t"));
            b.isbn.erase(b.isbn.find_last_not_of(" \t") + 1);
            statStr.erase(0, statStr.find_first_not_of(" \t"));
            statStr.erase(statStr.find_last_not_of(" \t") + 1);

            b.status = (statStr == "AVAILABLE" ? BookStatus::AVAILABLE : BookStatus::ISSUED);
            b.quantity = std::stoi(qtyStr);
            b.availableCopies = std::stoi(availStr);
        }
        return in;
    }
    std::string getId() const { return bookId; }
    std::string getTitle() const { return title; }
    BookStatus getStatus() const { return status; }
    int getAvailableCopies() const { return availableCopies; }
    void setAvailableCopies(int ac) { availableCopies = ac; }
    void setStatus(BookStatus s) { status = s; }
};

template <typename T>
class Container {
private:
    T* items;
    int sizeVal;
    int capacity;
    void resize() {
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i = 0; i < sizeVal; ++i) {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
    }
public:
    Container(int cap = 10) : sizeVal(0), capacity(cap) {
        items = new T[capacity];
    }
    Container(const Container& other) : sizeVal(other.sizeVal), capacity(other.capacity) {
        items = new T[capacity];
        for (int i = 0; i < sizeVal; ++i) {
            items[i] = other.items[i];
        }
    }
    Container& operator=(const Container& other) {
        if (this != &other) {
            delete[] items;
            sizeVal = other.sizeVal;
            capacity = other.capacity;
            items = new T[capacity];
            for (int i = 0; i < sizeVal; ++i) {
                items[i] = other.items[i];
            }
        }
        return *this;
    }
    ~Container() {
        delete[] items;
    }
    void add(const T& item) {
        if (sizeVal >= capacity) {
            resize();
        }
        items[sizeVal++] = item;
    }
    bool remove(const std::string& id) {
        for (int i = 0; i < sizeVal; ++i) {
            if (items[i].getId() == id) {
                for (int j = i; j < sizeVal - 1; ++j) {
                    items[j] = items[j + 1];
                }
                sizeVal--;
                return true;
            }
        }
        return false;
    }
    T* find(const std::string& id) {
        for (int i = 0; i < sizeVal; ++i) {
            if (items[i].getId() == id) {
                return &items[i];
            }
        }
        return nullptr;
    }
    T* findByName(const std::string& name) {
        for (int i = 0; i < sizeVal; ++i) {
            if (items[i].getName() == name) {
                return &items[i];
            }
        }
        return nullptr;
    }
    int getSize() const { return sizeVal; }
    T& get(int index) {
        return items[index];
    }
    const T& get(int index) const {
        return items[index];
    }
};

class Transaction {
private:
    static int idCounter;
    int transactionId;
    std::string memberId;
    std::string bookId;
    std::string issueDate;
    std::string dueDate;
    std::string returnDate;
    double fineAmount;
public:
    static const double FINE_RATE_PER_DAY;
    Transaction(const std::string& mId = "", const std::string& bId = "", const std::string& iDate = "", const std::string& dDate = "")
        : transactionId(++idCounter), memberId(mId), bookId(bId), issueDate(iDate), dueDate(dDate), returnDate(""), fineAmount(0.0) {}
    
    std::string getBookId() const { return bookId; }
    std::string getMemberId() const { return memberId; }
    std::string getReturnDate() const { return returnDate; }
    void setReturnDate(const std::string& rDate, double fine) {
        returnDate = rDate;
        fineAmount = fine;
    }
    int getTransactionId() const { return transactionId; }
};

int Transaction::idCounter = 0;
const double Transaction::FINE_RATE_PER_DAY = 5.0;

class Library {
private:
    Container<Book> books;
    Container<Member> members;
    std::vector<Transaction> transactions;
    std::map<std::string, std::string> bookToMemberMap;
public:
    void addBook(const Book& b) {
        books.add(b);
    }
    void removeBook(const std::string& id, const std::string& func, int line) {
        if (!books.remove(id)) {
            throw BookNotFoundException(func, line);
        }
    }
    Book* searchBook(const std::string& id, const std::string& func, int line) {
        Book* b = books.find(id);
        if (!b) {
            throw BookNotFoundException(func, line);
        }
        return b;
    }
    void displayAllBooks() const {
        for (int i = 0; i < books.getSize(); ++i) {
            std::cout << books.get(i) << std::endl;
        }
    }
    void registerMember(const Member& m) {
        members.add(m);
    }
    void removeMember(const std::string& id, const std::string& func, int line) {
        if (!members.remove(id)) {
            throw MemberNotFoundException(func, line);
        }
    }
    Member* searchMember(const std::string& id, const std::string& func, int line) {
        Member* m = members.find(id);
        if (!m) {
            throw MemberNotFoundException(func, line);
        }
        return m;
    }
    void displayAllMembers() const {
        for (int i = 0; i < members.getSize(); ++i) {
            members.get(i).displayInfo();
        }
    }
    void issueBook(const std::string& memberId, const std::string& bookId, const std::string& func, int line) {
        Book* b = books.find(bookId);
        if (!b) throw BookNotFoundException(func, line);
        if (b->getAvailableCopies() <= 0) throw BookNotAvailableException(func, line);

        Member* m = members.find(memberId);
        if (!m) throw MemberNotFoundException(func, line);
        if (!m->addBookId(bookId)) throw MaxBooksExceededException(func, line);

        b->setAvailableCopies(b->getAvailableCopies() - 1);
        if (b->getAvailableCopies() == 0) {
            b->setStatus(BookStatus::ISSUED);
        }
        bookToMemberMap[bookId] = memberId;
        transactions.push_back(Transaction(memberId, bookId, "2026-09-04", "2026-09-14"));
    }
    void returnBook(const std::string& memberId, const std::string& bookId, const std::string& func, int line) {
        Book* b = books.find(bookId);
        if (!b) throw BookNotFoundException(func, line);

        Member* m = members.find(memberId);
        if (!m) throw MemberNotFoundException(func, line);

        if (!m->removeBookId(bookId)) throw BookNotFoundException(func, line);

        b->setAvailableCopies(b->getAvailableCopies() + 1);
        b->setStatus(BookStatus::AVAILABLE);
        bookToMemberMap.erase(bookId);

        for (auto& t : transactions) {
            if (t.getBookId() == bookId && t.getMemberId() == memberId && t.getReturnDate() == "") {
                t.setReturnDate("2026-09-06", 0.0);
                break;
            }
        }
    }
    void viewOverdueBooks() const {
        std::cout << "Overdue Books View (Simulated): None currently." << std::endl;
    }
    void saveData() {
        std::ofstream outfile("books.txt");
        for (int i = 0; i < books.getSize(); ++i) {
            outfile << books.get(i) << std::endl;
        }
        outfile.close();

        std::ofstream outmember("members.txt");
        for (int i = 0; i < members.getSize(); ++i) {
            outmember << members.get(i) << std::endl;
        }
        outmember.close();
    }
    void loadData() {
        std::ifstream infile("books.txt");
        if (infile.is_open()) {
            std::string line;
            while (std::getline(infile, line)) {
                std::stringstream ss(line);
                Book b;
                ss >> b;
                books.add(b);
            }
            infile.close();
        }

        std::ifstream inmember("members.txt");
        if (inmember.is_open()) {
            std::string line;
            while (std::getline(inmember, line)) {
                std::stringstream ss(line);
                Member m;
                ss >> m;
                members.add(m);
            }
            inmember.close();
        }
    }
};

}

int main() {
    LibrarySystem::Library lib;
    int choice = -1;
    do {
        std::cout << "\n1. Add New Book\n2. Remove Book\n3. Search Book\n4. Display All Books\n5. Register Member\n6. Remove Member\n7. Search Member\n8. Display All Members\n9. Issue Book\n10. Return Book\n11. View Overdue Books\n12. Save Data\n13. Load Data\n0. Exit\nChoice: ";
        if (!(std::cin >> choice)) break;
        try {
            if (choice == 1) {
                std::string id, title, author, isbn;
                int qty;
                std::cout << "Enter ID, Title, Author, ISBN, Quantity: ";
                std::cin >> id >> title >> author >> isbn >> qty;
                lib.addBook(LibrarySystem::Book(id, title, author, isbn, LibrarySystem::BookStatus::AVAILABLE, qty, qty));
            } else if (choice == 2) {
                std::string id;
                std::cout << "Enter Book ID to remove: ";
                std::cin >> id;
                lib.removeBook(id, __FUNCTION__, __LINE__);
            } else if (choice == 3) {
                std::string id;
                std::cout << "Enter Book ID to search: ";
                std::cin >> id;
                LibrarySystem::Book* b = lib.searchBook(id, __FUNCTION__, __LINE__);
                std::cout << *b << std::endl;
            } else if (choice == 4) {
                lib.displayAllBooks();
            } else if (choice == 5) {
                std::string id, name, phone;
                std::cout << "Enter ID, Name, Phone: ";
                std::cin >> id >> name >> phone;
                lib.registerMember(LibrarySystem::Member(id, name, phone));
            } else if (choice == 6) {
                std::string id;
                std::cout << "Enter Member ID to remove: ";
                std::cin >> id;
                lib.removeMember(id, __FUNCTION__, __LINE__);
            } else if (choice == 7) {
                std::string id;
                std::cout << "Enter Member ID to search: ";
                std::cin >> id;
                LibrarySystem::Member* m = lib.searchMember(id, __FUNCTION__, __LINE__);
                m->displayInfo();
            } else if (choice == 8) {
                lib.displayAllMembers();
            } else if (choice == 9) {
                std::string mId, bId;
                std::cout << "Enter Member ID and Book ID: ";
                std::cin >> mId >> bId;
                lib.issueBook(mId, bId, __FUNCTION__, __LINE__);
            } else if (choice == 10) {
                std::string mId, bId;
                std::cout << "Enter Member ID and Book ID: ";
                std::cin >> mId >> bId;
                lib.returnBook(mId, bId, __FUNCTION__, __LINE__);
            } else if (choice == 11) {
                lib.viewOverdueBooks();
            } else if (choice == 12) {
                lib.saveData();
                std::cout << "Data saved successfully." << std::endl;
            } else if (choice == 13) {
                lib.loadData();
                std::cout << "Data loaded successfully." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    } while (choice != 0);

    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    string category;
    string availability;

public:
    Book() {}

    Book(string i, string t, string a, string c, string av)
        : isbn(i), title(t), author(a), category(c), availability(av) {}

    string getISBN() const {
        return isbn;
    }

    string getTitle() const {
        return title;
    }

    string getAvailability() const {
        return availability;
    }

    void display() const {
        cout << "ISBN: " << isbn
             << " | Title: " << title
             << " | Author: " << author
             << " | Category: " << category
             << " | Status: " << availability << endl;
    }

    string toFileString() const {
        return isbn + "|" + title + "|" + author + "|" +
               category + "|" + availability;
    }
};

// Add a new book
void addBook() {
    string isbn, title, author, category;

    cout << "\nEnter ISBN: ";
    getline(cin, isbn);

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Category: ";
    getline(cin, category);

    ofstream file("books.txt", ios::app);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    file << isbn << "|" << title << "|" << author
         << "|" << category << "|Available\n";

    file.close();

    cout << "Book added successfully.\n";
}

// Display all books
void displayBooks() {
    ifstream file("books.txt");

    if (!file) {
        cout << "No book records found.\n";
        return;
    }

    string line;

    cout << "\n===== LIBRARY BOOKS =====\n";

    while (getline(file, line)) {
        stringstream ss(line);

        string isbn, title, author, category, availability;

        getline(ss, isbn, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, category, '|');
        getline(ss, availability, '|');

        Book book(isbn, title, author, category, availability);
        book.display();
    }

    file.close();
}

// Search book
void searchBook() {
    string searchISBN;

    cout << "\nEnter ISBN to search: ";
    getline(cin, searchISBN);

    ifstream file("books.txt");

    if (!file) {
        cout << "File not found.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);

        string isbn, title, author, category, availability;

        getline(ss, isbn, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, category, '|');
        getline(ss, availability, '|');

        if (isbn == searchISBN) {
            Book book(isbn, title, author, category, availability);

            cout << "\nBook Found:\n";
            book.display();

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Book not found.\n";
    }
}

// Update availability
void updateAvailability(string isbn, string newStatus) {
    ifstream input("books.txt");
    ofstream temp("temp.txt");

    if (!input || !temp) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(input, line)) {
        stringstream ss(line);

        string bookISBN, title, author, category, availability;

        getline(ss, bookISBN, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, category, '|');
        getline(ss, availability, '|');

        if (bookISBN == isbn) {
            temp << bookISBN << "|"
                 << title << "|"
                 << author << "|"
                 << category << "|"
                 << newStatus << "\n";

            found = true;
        }
        else {
            temp << line << "\n";
        }
    }

    input.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        cout << "Book status updated successfully.\n";
    else
        cout << "Book not found.\n";
}

// Issue book
void issueBook() {
    string isbn;

    cout << "\nEnter ISBN to issue: ";
    getline(cin, isbn);

    updateAvailability(isbn, "Issued");
}

// Return book
void returnBook() {
    string isbn;

    cout << "\nEnter ISBN to return: ";
    getline(cin, isbn);

    updateAvailability(isbn, "Available");
}

// Availability report
void availabilityReport() {
    ifstream file("books.txt");

    if (!file) {
        cout << "No book records found.\n";
        return;
    }

    string line;

    int available = 0;
    int issued = 0;

    cout << "\n===== AVAILABILITY REPORT =====\n";

    while (getline(file, line)) {
        stringstream ss(line);

        string isbn, title, author, category, availability;

        getline(ss, isbn, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, category, '|');
        getline(ss, availability, '|');

        if (availability == "Available")
            available++;
        else if (availability == "Issued")
            issued++;

        cout << title << " -> " << availability << endl;
    }

    file.close();

    cout << "\nTotal Available Books: " << available << endl;
    cout << "Total Issued Books: " << issued << endl;
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n=================================\n";
        cout << "   LIBRARY BOOK MANAGEMENT SYSTEM\n";
        cout << "=================================\n";

        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Availability Report\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            availabilityReport();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}

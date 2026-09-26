OOP with C++ – Unit IV: Files and Streams
📘 About This Repository

This repository contains C++ programs and practical examples based on Unit IV – Files and Streams of Object-Oriented Programming with C++.

The programs demonstrate file handling, different types of files, streams, header files, file operations, reading and writing files, file pointers and navigation, and error handling.

👩‍🎓 Student Details
Student Name: Bhumika Barave
Course: Object-Oriented Programming with C++
Unit: Unit IV – Files and Streams
Year: Second Year Engineering
Branch: Artificial Intelligence and Data Science
Programming Language: C++
Standard: C++17 or later
🎯 Objective

The main objective of this unit is to understand File Handling and Streams in C++ and learn how to store, read, write, and manage data permanently using files.

📚 Topics Covered
1. Introduction to File Handling

File handling is used to store data permanently in files.

Normally, data stored in variables is lost when the program terminates. File handling allows data to be stored permanently and accessed later.

C++ provides file handling facilities using the fstream library.

📁 2. Types of Files

There are mainly two types of files used in C++.

Text Files

Text files store data in a human-readable format.

Example:

Student Name: Bhumika
Roll Number: 101
Branch: AI & DS

Common extension:

.txt
Binary Files

Binary files store data in binary format.

They are useful for storing data in a form that can be efficiently processed by programs.

Common extensions include:

.dat
.bin
🌊 3. Streams

A stream represents the flow of data between a program and a file.

C++ provides different stream classes for file operations.

Stream	Purpose
ifstream	Used for reading from files
ofstream	Used for writing to files
fstream	Used for both reading and writing

Example:

#include <fstream>
📌 4. Header Files

The main header file used for file handling is:

#include <fstream>

Other commonly used headers are:

#include <iostream>
#include <string>

The <fstream> header provides classes such as:

ifstream
ofstream
fstream
📂 File Operations
5. Opening Files

A file can be opened using the open() function.

Example:

ofstream file;

file.open("data.txt");

A file can also be opened while creating the file stream object:

ofstream file("data.txt");
✍️ 6. Writing to Files

The insertion operator << is used to write data into a file.

Example:

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("data.txt");

    file << "Hello World";
    file << "\nWelcome to C++ File Handling";

    file.close();

    return 0;
}

The close() function is used to close the file after writing.

📖 7. Reading from Files

The ifstream class is used to read data from a file.

Example:

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("data.txt");

    string data;

    while (file >> data)
    {
        cout << data << endl;
    }

    file.close();

    return 0;
}
Reading Complete Lines

The getline() function can be used to read a complete line.

string line;

while (getline(file, line))
{
    cout << line << endl;
}
📍 File Pointers and Navigation
8. File Pointers

File pointers represent the current position in a file.

C++ provides two types of file pointers:

Get pointer – used for reading
Put pointer – used for writing
🔹 seekg()

The seekg() function is used to move the get/read pointer to a particular position.

Example:

file.seekg(0);
🔹 seekp()

The seekp() function is used to move the put/write pointer.

Example:

file.seekp(0);
🔹 tellg()

The tellg() function returns the current position of the get pointer.

Example:

cout << file.tellg();
🔹 tellp()

The tellp() function returns the current position of the put pointer.

Example:

cout << file.tellp();

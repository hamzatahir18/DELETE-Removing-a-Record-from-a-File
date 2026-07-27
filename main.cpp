#include <iostream>
#include <fstream>
#include <cstdio>     // For remove() and rename()
using namespace std;

int main()
{
    int searchRoll, rollNo;
    string name;
    float marks;
    bool found = false;

    // Open original file for reading
    ifstream inFile("students.txt");

    // Create temporary file for writing
    ofstream tempFile("temp.txt");

    // Check if files opened successfully
    if (!inFile.is_open() || !tempFile.is_open())
    {
        cout << "Error opening files!" << endl;
        return 1;
    }

    // Take Roll No from user
    cout << "Enter Roll No to delete: ";
    cin >> searchRoll;

    // Copy all records except the one to delete
    while (inFile >> rollNo >> name >> marks)
    {
        if (rollNo == searchRoll)
        {
            found = true;
            continue;   // Skip this record
        }

        tempFile << rollNo << " "
                 << name << " "
                 << marks << endl;
    }

    // Close both files
    inFile.close();
    tempFile.close();

    // Delete original file
    remove("students.txt");

    // Rename temp.txt to students.txt
    rename("temp.txt", "students.txt");

    // Display result
    if (found)
        cout << "\nRecord deleted successfully." << endl;
    else
        cout << "\nRoll No not found." << endl;

    return 0;
}


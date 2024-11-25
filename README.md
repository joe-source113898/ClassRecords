# ClassRecords
This C++ program allows users to manage a student database. It supports adding, updating, deleting records, and generating reports based on various criteria.

---

## Code Implementation

```cpp
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <set>

#define LIMIT_OF_RECORDS 100

using namespace std;

set<int> rollNoSet;

typedef struct 
{
  int rollNo;
  string name;
  string fathersName;
  string dateOfBirth;
  string branch;
  int yearOfAdmission;
  int tentativeYearOfPassing;
  string state;
  string pin;
  string country;
} Record;

// Function to add a new record
void addRecord(Record records[], int &totalRecords)
{
  // Function implementation here
}

// Function to update an existing record
void updateRecord(Record records[], int totalRecords, int rollNo)
{
  // Function implementation here
}

// Function to delete a record
void deleteRecord(Record records[], int &totalRecords, int rollNo)
{
  // Function implementation here
}

// Function to generate report by name
void generateReportByName(Record records[], int totalRecords, string name)
{
  // Function implementation here
}

// Function to generate report by state
void generateReportByState(Record records[], int totalRecords, string state)
{
  // Function implementation here
}

// Function to generate report by district
void generateReportByDistrict(Record records[], int totalRecords, string district)
{
  // Function implementation here
}

int main()
{
  Record records[LIMIT_OF_RECORDS];
  int totalRecords = 0;
  int choice;

  do
  {
    cout << "\nMenu:\n";
    cout << "1. Add record\n";
    cout << "2. Update record\n";
    cout << "3. Delete record\n";
    cout << "4. Generate report by name\n";
    cout << "5. Generate report by state\n";
    cout << "6. Generate report by district\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
      case 1:
        addRecord(records, totalRecords);
        break;
      case 2:
      {
        int rollNoToUpdate;
        cout << "Enter the roll number of the record to be updated: ";
        cin >> rollNoToUpdate;
        updateRecord(records, totalRecords, rollNoToUpdate);
        break;
      }
      case 3:
      {
        int rollNoToDelete;
        cout << "Enter the roll number of the record to be deleted: ";
        cin >> rollNoToDelete;
        deleteRecord(records, totalRecords, rollNoToDelete);
        break;
      }
      case 4:
      {
        string name;
        cout << "Enter the name: ";
        cin >> name;
        generateReportByName(records, totalRecords, name);
        break;
      }
      case 5:
      {
        string state;
        cout << "Enter the state: ";
        cin >> state;
        generateReportByState(records, totalRecords, state);
        break;
      }
      case 6:
      {
        string district;
        cout << "Enter the district: ";
        cin >> district;
        generateReportByDistrict(records, totalRecords, district);
        break;
      }
      case 0:
        cout << "Exiting program.\n";
        break;
      default:
        cout << "Invalid choice! Please try again.\n";
    }
  } while (choice != 0);

  return 0;
}
```

---

## Features

1. **Add Records**: Add a new student record.
2. **Update Records**: Modify details of an existing record.
3. **Delete Records**: Remove a student record using their roll number.
4. **Generate Reports**:
   - By Name
   - By State
   - By District

---

## Limitations

- Maximum of 100 records.
- Roll numbers must be unique.

---

## How to Use

1. Compile the program using a C++ compiler:
   ```bash
   g++ -o student_records student_records.cpp
   ```
2. Run the compiled program:
   ```bash
   ./student_records
   ```
3. Follow the menu instructions to interact with the program.

---

### Example Menu

```
Menu:
1. Add record
2. Update record
3. Delete record
4. Generate report by name
5. Generate report by state
6. Generate report by district
0. Exit
Enter your choice:
```

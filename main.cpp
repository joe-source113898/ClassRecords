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

void addRecord(Record records[], int &totalRecords)
{
  if (totalRecords < LIMIT_OF_RECORDS)
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

    cout << "\nEnter the roll number: ";
    cin >> rollNo;
  
    while (rollNoSet.find(rollNo) != rollNoSet.end())
    {
      cout << "Enter the roll number again, the roll number can not be repeated: ";
      cin >> rollNo;
    }
    rollNoSet.insert(rollNo);
    records[totalRecords].rollNo = rollNo;

    cout << "Enter the name: ";
    cin >> name;
    records[totalRecords].name = name;

    cout << "Enter the father's name: ";
    cin >> fathersName;
    records[totalRecords].fathersName = fathersName;

    cout << "Enter the date of birth: ";
    cin >> dateOfBirth;
    records[totalRecords].dateOfBirth = dateOfBirth;

    cout << "Enter the branch: ";
    cin >> branch;
    records[totalRecords].branch = branch;

    cout << "Enter the year of admission: ";
    cin >> yearOfAdmission;
    records[totalRecords].yearOfAdmission = yearOfAdmission;

    cout << "Enter the tentative year of passing: ";
    cin >> tentativeYearOfPassing;
    records[totalRecords].tentativeYearOfPassing = tentativeYearOfPassing;

    cout << "Enter the state: ";
    cin >> state;
    records[totalRecords].state = state;

    cout << "Enter the PIN: ";
    cin >> pin; 
    records[totalRecords].pin = pin;

    cout << "Enter the country: ";
    cin >> country;
    records[totalRecords].country = country;

    totalRecords++;
  } 
  else
  {
    cout << "The limit of records has been reached." << endl;
    return;
  }
}

void updateRecord(Record records[], int totalRecords, int rollNo)
{
  if (totalRecords == 0)
  {
    cout << "There is not any record yet." << endl;
    return;
  }
  if (rollNoSet.find(rollNo) != rollNoSet.end())
  {
    for (int idx = 0; idx < totalRecords; idx++)
    {
      if (records[idx].rollNo == rollNo)
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

        cout << "\nEnter the roll number: ";
        cin >> rollNo;
      
        while (rollNoSet.find(rollNo) != rollNoSet.end())
        {
          cout << "Enter the roll number again, the roll number can not be repeated: ";
          cin >> rollNo;
        }
        rollNoSet.erase(records[idx].rollNo);
        rollNoSet.insert(rollNo);    
        records[idx].rollNo = rollNo;

        cout << "Enter the name: ";
        cin >> name;
        records[idx].name = name;

        cout << "Enter the father's name: ";
        cin >> fathersName;
        records[idx].fathersName = fathersName;

        cout << "Enter the date of birth: ";
        cin >> dateOfBirth;
        records[idx].dateOfBirth = dateOfBirth;

        cout << "Enter the branch: ";
        cin >> branch;
        records[idx].branch = branch;

        cout << "Enter the year of admission: ";
        cin >> yearOfAdmission;
        records[idx].yearOfAdmission = yearOfAdmission;

        cout << "Enter the tentative year of passing: ";
        cin >> tentativeYearOfPassing;
        records[idx].tentativeYearOfPassing = tentativeYearOfPassing;

        cout << "Enter the state: ";
        cin >> state;
        records[idx].state = state;

        cout << "Enter the PIN: ";
        cin >> pin; 
        records[idx].pin = pin;

        cout << "Enter the country: ";
        cin >> country;
        records[idx].country = country;

        break;
      }
    }
  }
  else
  {
    cout << "This record was not found." << endl;
    return;
  }
}

void deleteRecord(Record records[], int &totalRecords, int rollNo)
{
  if (totalRecords == 0)
  {
    cout << "There is not any record yet." << endl;
    return;
  }
  if (totalRecords == 1)
  {
    totalRecords = 0;
    cout << "The only record has been successfully deleted." << endl;
    return;
  }

  auto it = rollNoSet.find(rollNo);
  int idx = -1;

  if (it != rollNoSet.end())
  { 
    for (int i = 0; i < totalRecords; i++)
    {
      if (records[i].rollNo == rollNo)
      {
        idx = i;
        break;
      }
    }

    for (int i = idx; i < totalRecords - 1; i++) 
    {
        records[i] = records[i + 1];
    }

    if (idx != -1)
    {
      rollNoSet.erase(it);
      totalRecords--;
    }
  }
  else
  {
    cout << "This record was not found." << endl;
    return;
  }
}

void generateReportByName(Record records[], int totalRecords, string name)
{
  if (totalRecords == 0)
  {
    cout << "There is not any record yet." << endl;
    return;
  }
  
  for (int idx = 0; idx < totalRecords; idx++)
  {
    if (records[idx].name == name)
    {
      cout << "\nRoll no.: " << records[idx].rollNo << endl;
      cout << "Name: " << records[idx].name << endl;
      cout << "Father's name: " << records[idx].fathersName << endl;
      cout << "Date of birth: " << records[idx].dateOfBirth << endl;
      cout << "Branch: " << records[idx].branch << endl;
      cout << "Year of admission: " << records[idx].yearOfAdmission << endl;
      cout << "Tentative year of passing: " << records[idx].tentativeYearOfPassing << endl;
      cout << "State: " << records[idx].state << endl;
      cout << "Country: " << records[idx].country << endl;
    }
  }
}

void generateReportByState(Record records[], int totalRecords, string state)
{
  if (totalRecords == 0)
  {
    cout << "There is not any record yet." << endl;
    return;
  }

  for (int idx = 0; idx < totalRecords; idx++)
  {
    if (records[idx].state == state)
    {
      cout << "\nRoll no.: " << records[idx].rollNo << endl;
      cout << "Name: " << records[idx].name << endl;
      cout << "Father's name: " << records[idx].fathersName << endl;
      cout << "Date of birth: " << records[idx].dateOfBirth << endl;
      cout << "Branch: " << records[idx].branch << endl;
      cout << "Year of admission: " << records[idx].yearOfAdmission << endl;
      cout << "Tentative year of passing: " << records[idx].tentativeYearOfPassing << endl;
      cout << "State: " << records[idx].state << endl;
      cout << "Country: " << records[idx].country << endl;
    }
  }
}

void generateReportByDistrict(Record records[], int totalRecords, string district)
{
  if (totalRecords == 0)
  {
    cout << "There is not any record yet." << endl;
    return;
  }

  for (int idx = 0; idx < totalRecords; idx++)
  {
    if (records[idx].country == district)
    {
      cout << "\nRoll no.: " << records[idx].rollNo << endl;
      cout << "Name: " << records[idx].name << endl;
      cout << "Father's name: " << records[idx].fathersName << endl;
      cout << "Date of birth: " << records[idx].dateOfBirth << endl;
      cout << "Branch: " << records[idx].branch << endl;
      cout << "Year of admission: " << records[idx].yearOfAdmission << endl;
      cout << "Tentative year of passing: " << records[idx].tentativeYearOfPassing << endl;
      cout << "State: " << records[idx].state << endl;
      cout << "Country: " << records[idx].country << endl;
    }
  }
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

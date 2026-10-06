#include <iostream>
using namespace std;

int main()
{
    int student[10];      // roll numbers
    int marks[10];        // marks of each student
    int n = 0;            // number of students added so far
    int choice;
    int searchRollNo;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add student (roll no & marks)\n";
        cout << "2. Display all student records\n";
        cout << "3. Search student by roll no\n";
        cout << "4. Display students from highest to lowest marks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (n == 10)
            {
                cout << "Student list is full!\n";
            }
            else
            {
                cout << "Enter roll no: ";
                cin >> student[n];
                cout << "Enter marks: ";
                cin >> marks[n];
                n++;
                cout << "Student added successfully.\n";
            }
            break;

        case 2:
            if (n == 0)
            {
                cout << "No records found.\n";
            }
            else
            {
                cout << "\nRoll No\tMarks\n";
                for (int i = 0; i < n; i++)
                {
                    cout << student[i] << "\t" << marks[i] << endl;
                }
            }
            break;

        case 3:
        {
            cout << "Enter roll no to search: ";
            cin >> searchRollNo;
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (student[i] == searchRollNo)
                {
                    cout << "Record found -> Roll No: " << student[i]
                         << ", Marks: " << marks[i] << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Roll no does not exist.\n";
            }
            break;
        }

        case 4:
        {
            if (n == 0)
            {
                cout << "No records found.\n";
                break;
            }

            // copy the data so the original order stays the same
            int r[10], m[10];
            for (int i = 0; i < n; i++)
            {
                r[i] = student[i];
                m[i] = marks[i];
            }

            // bubble sort: highest marks first
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (m[j] < m[j + 1])
                    {
                        int t = m[j]; m[j] = m[j + 1]; m[j + 1] = t;
                        t = r[j]; r[j] = r[j + 1]; r[j + 1] = t;
                    }
                }
            }

            cout << "\nRoll No\tMarks (Highest to Lowest)\n";
            for (int i = 0; i < n; i++)
            {
                cout << r[i] << "\t" << m[i] << endl;
            }
            break;
        }

        case 5:
            cout << "Exiting program. Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

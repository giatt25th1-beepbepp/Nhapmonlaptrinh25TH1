#include <iostream>
#include <string>
#include "Account.h"
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<Account> accounts;
    int choice;

    do {
        system("cls");
        cout << "======= ACCOUNT MANAGEMENT =======" << endl;
        cout << "1. Show all accounts" << endl;
        cout << "2. Add an account" << endl;
        cout << "3. Delete an account" << endl;
        cout << "4. Update an account" << endl;
        cout << "5. Find account by username" << endl;
        cout << "6. Export to file" << endl;
        cout << "7. Import from file" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            accounts.Show();
            break;
        case 2: {
            Account a;
            cin >> a;
            accounts.Add(a);
            break;
        }
        case 3: {
            int id;
            cout << "Enter ID to remove: "; cin >> id;
            if (accounts.Remove(id)) cout << "Success!" << endl;
            else cout << "ID not found!" << endl;
            break;
        }
        case 4: {
            int id;
            cout << "Enter ID to update: "; cin >> id;
            if (accounts.Update(id)) cout << "Updated!" << endl;
            else cout << "ID not found!" << endl;
            break;
        }
        case 5: {
            string user;
            cout << "Enter username: ";
            cin.ignore();
            getline(cin, user);
            accounts.Find(user);
            break;
        }
        case 6:
            accounts.Export("data.txt");
            cout << "Exported to data.txt" << endl;
            break;
        case 7:
            accounts.Import("data.txt");
            cout << "Imported from data.txt" << endl;
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 0);

    return 0;
}
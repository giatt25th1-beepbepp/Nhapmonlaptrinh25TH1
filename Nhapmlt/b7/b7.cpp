
#include <iostream>
#include <string>
#include "Account.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<Account> accounts= { NULL };
	do {
		system("cls");
		cout << "-------BOOK MANAGEMANT-------" << endl;
		cout << "1. Show all books" << endl;
		cout << "2. Add a book" << endl;
		cout << "3. Delete a book" << endl;
		cout << "4.Update a book" << endl;
		cout << "5. Find book" << endl;
		cout << "6. Export to file" << endl;
		cout << "7. Import to file" << endl;
		cout << "0. Exit" << endl;
		cout << "-----------------------------" << endl;
		cout << "Enter your choice" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			accounts.Show();
			break;
		}
		case 2: {
			Account a;;
			cin >> a;
			accounts.Add(a);
			break;
		}
		case 3: {
			int removeid;
			cout << "Enter account id to remove :" << endl;
			cin >> removeid;
			bool res = accounts.Remove(removeid);
			if (res)
				cout << "Removed account with id" << endl;
			else
				cout << "Not found account id" << endl;
			break;
		}
		case 4: {
			int updateid;
			cout << "Enter account id to update: ";
			cin >> updateid;
			bool res = accounts.Update(updateid);
			if (res)
				cout << "Updated account with id: "  updateid << endl;
			else
				cout << "Not found account id: " << updateid << endl;

			break;
		}
		case 5: {
			string username;
			cout << "Enter account name : ";
			cin.ignore();
			getline(cin, username);
			accounts.Find(username);
			break;
		}
		case 6: {
			accounts.Export("25TH1.dla");
			cout << "Export successsfully" << endl;
			break;
		}
		case 7: {
			accounts.Import("25TH!.dla");
			cout << "Import successfully" << endl;
			break;
		}
		case 0: {
			break;
		}
	
	}

	
defaut:
	cout << "Invailid choice try again..." << endl;
	system("pause");
	cout << "Press Enter to countinue...";
} while (true);
return 0;
	}

   



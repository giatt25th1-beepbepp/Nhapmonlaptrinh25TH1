#pragma once
#include <iostream>
#include "Acccount.h"
#include "LinkedList.h"
using namespace std;
int main() {
	LinkedList<Acccount> account = { NULL };
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
			Account.Show();
			break;
		}
		case 2: {
			/*Book b;
			cin >> b;
			Node* newNode = new Node;
			newNode->Create(b);
			books.Addfirst(newNode);*/
			break;
		}
		case 3: {
			/*int removeid;
			cout << "Enter book`s id to remove :" << endl;
			cin >> removeid;
			bool res = books.Remove(removeid);
			if (res)
				cout << "Remove book successfuly" << endl;
			else
				cout << "Invailid book id" << endl;*/
			break;
		}
		case 4: {
			/*int updateid;
			cout << "Enter book`s id to update" << endl;
			cin >> updateid;
			bool res = books.Update(updateid);
			if (res)
				cout << "Update book successfully" << endl;
			else
				cout << "Invailid book id " << endl*/;
			break;
		}
		case 5: {
			/*string bookname;
			cout << "Enter book`s name to find: ";
			cin.ignore();
			getline(cin, bookname);
			Book* res = books.Find(bookname);
			if (res != NULL) {
				cout << *res;
			}
			else {
				cout << "No book with name: " << bookname << endl;
			}*/
			break;
		}
		case 6: {
			/*books.Export("25TH1.dla");
			cout << "Export successsfully" << endl;*/
			break;
		}
		case 7: {
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
}
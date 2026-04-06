#include <iostream>
#include <string>
using namespace std;
struct Author {
	int id;
	string name;
};
struct Book {
	int id;
	string name;
	Author author;
	friend ostream& operator<<(ostream & os, const Book & b) {
		os << "Book information:" << endl;
		os << "\t+ Id:" << b.id<< endl;
		os << "\t+ Name:" << b.name<< endl;
		os << "\t+ Author name:" << b.author.name<< endl;
		return os;
	}
	friend istream& operator>>(istream&in,Book& b){
		cout << "\t + Id: ";
		in >>b.id;
		cout << "\t Name: ";
		getline(in, b.author.name);
		in >> b.author.name;
		return in;
	}
};
struct Node {
	Book data;
	Node* next;
	void Create(Book b) {
		data = b;
		next = nullptr;
	}
};
struct Linkedlist {
	Node* head;
	void Show(Linkedlist books) {
		if (books.head == NULL) {
			cout << "No book available" << endl;
			return;
		}
		Node* item = books.head;
		while (item != NULL) {
			cout << item->data;
			item = item->next;
		}
	}
	void Addfirst(Node* p) {
		p->next = head;
		head = p;
	}
	bool Remove(int removeid) {
		if (head == NULL) {
			cout << "NO book available" << endl;
			return true;
		}
		Node* item = head;
		if (item->data.id == removeid) {
			head = item->next;
			delete item;
			return true;
		}
		while (item->next != NULL) {
			if (item->next->data.id == removeid) {
				Node* temp = item->next;
				item->next = item->next->next;
				delete temp;
				return true;
			}
			item = item->next;
		}
		return false;

	}
	bool Update(int updateid) {
		if (head == NULL) {
			cout << "NO book available" << endl;
			return false;
			Node* item = head;
			while (item != NULL)
				if (item->data.id == updateid) {
					cin >> item->data;
					return true;
				}
			item = item->next;
		}
		return false;
	}
};
	int main()
	{
		Linkedlist books = { NULL };
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
				books.Show();
				break;
			}
			case 2: {
				Book b;
				cin >> b;
				Node* newNode = new Node;
				newNode->Create(b);
				books.Addfirst(newNode);
				break;
			}
			case 3: {
				int removeid;
				cout << "Enter book`s id to remove :" << endl;
				cin >> removeid;
				bool res = books.Remove(removeid);
				if (res)
					cout << "Remove book successfuly" << endl;
				else
					cout << "Invailid book id" << endl;
				break;
			}
			case 4: {
				int updateid;
				cout << "Enter book`s id to update" << endl;
				cin >> updateid;
				bool res = books.Update(updateid);
				if (res)
					cout << "Update book successfully" << endl;
				else
					cout << "Invailid book id " << endl;
				break;
			}
			case 5: {
				break;
			}
			case 6: {
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

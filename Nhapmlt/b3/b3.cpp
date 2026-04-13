#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Author {
	int id;
	string name;
	friend istream& operator>>(istream& in, Author& a) {
		cout << "Author information: " << endl;
		cout << "\t+ Id: ";
		in >> a.id;
		cout << "\t+ Name: ";
		in.ignore();
		getline(in, a.name);
		return in;
		
	}
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
	void Export(string filename) {
		ofstream out(filename, ios::binary);
		if (!out.is_open()) {
			cout << "Cannot open file" << endl;
			return;
		}
		Node* item = head;
		while (item != NULL) {
			out.write(reinterpret_cast<const char*>(&item->data.id), sizeof(item->data.id));
			size_t namelenght = item->data.name.size();
			out.write(reinterpret_cast<const char*>(&namelenght), sizeof(namelenght));
			out.write(item->data.name.c_str(), namelenght);
			out.write(reinterpret_cast<const char*>(&item->data.author.id), sizeof(item->data.author.id));
			size_t authornamelenght = item->data.author.name.size();
			out.write(reinterpret_cast<const char*>(&authornamelenght), sizeof(authornamelenght));
			out.write(item->data.author.name.c_str(), authornamelenght); 
		}
	}
	Book* Find(string bookname) {
		if (head == NULL) {
			cout << "No book available" << endl;
			return NULL;
		}
		Node* item = head;
		while (item != NULL) {
			if (item->data.name.find(bookname) != std::string::npos) {
				return &(item->data);
			}
			item = item->next;
		}
		return NULL;
	}
	void Import(string filename) {
		ifstream in(filename, ios::binary);
		if (in.is_open()) {
			cout << "Cannot open file" << endl;
			return;
		}
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		while (in.peek() != EOF) {
			Book b;
			in.read(reinterpret_cast<char*>(&b.id), sizeof(b.id));
			size_t namelanght;
			in.read(reinterpret_cast<char*>(&namelenght), sizeof(namelenght));
			b.name.resize(namelenght);
			in.read(&b.name[0], namelenght);
			in.read(reinterpret_cast<char*>(&b.author.id), sizeof(b.author.id));
			size_t authornamelenght;
			in.read(reinterpret_cast<char*>(&authornamelenght), sizeof(authornamelenght));
			b.author.name.resize(authornamelenght);
			in.read(&b.author.name[0], authornamelenght);
			Node* newNode = new Node;
			newNode->Create(b);
			Addfirst(newNode);
		}
		in.close();
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
				string bookname;
				cout << "Enter book`s name to find: ";
				cin.ignore();
				getline(cin, bookname);
				Book* res = books.Find(bookname);
				if (res != NULL) {
					cout << *res;
				}
				else {
					cout << "No book with name: " << bookname << endl;
				}
				break;
			}
			case 6: {
				books.Export("25TH1.dla");
				cout << "Export successsfully" << endl;
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

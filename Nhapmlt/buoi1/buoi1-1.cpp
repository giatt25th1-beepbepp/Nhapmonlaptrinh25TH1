#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Person {
	int id;
	string name;
	int age;
	string address;

};
void ViewPersonList(vector<Person> p) {
	if (p.size() == 0)
		cout << "A Emty list" << endl;
	else {
		for (int i = 0; i << p.size(); i++) {
			cout << "Person " << (i + 1) << endl;
			cout << "\t+ Id: " << p[i].id <<endl;
			cout << "\t+ Name: " << p[i].name <<endl;
			cout << "\t+ Age: " << p[i].age <<endl;
			cout << "\t+ Address: " << p[i].address <<endl;
		}
	}
}
void AddPerson(vector<Person>& p) {
	Person a;
	cout << "+ Id: ";
	cin >> a.id;
	cout << "+ Name: ";
	cin.ignore();
	getline(cin, a.name);
	cout << "+ age: ";
	cin >> a.age;
	cout << "+ Addrerss: ";
	cin.ignore();
	getline(cin, a.address);
	p.push_back(a);
	cout << "Add a person successfully" << endl;
}
void RemovePerson(vector<Person>& p, int id) {
	for (auto i = p.begin(); i != p.end(); i++) {
		if (i->id == id) {
			p.erase(i);
			cout << "Remove a person successfully" << endl;
		}
	}
}


int main() {
	vector<Person> list;
	do {
		system("cls");
		cout << "_____HUMAN_RESOURCE___________" << endl;
		cout << "1. View person list" << endl;
		cout << "2. Add a person" << endl;
		cout << "3. Remove a person" << endl;
		cout << "4. Find a person by name" << endl;
		cout << "5. Export to file" << endl;
		cout << "6. Import from file" << endl;
		cout << "Exit" << endl;
		cout << "_________________________________" << endl;
		cout << "Your command: " << endl;
		int cmd;
		cin >> cmd;
		switch (cmd) 
		{
		case 1: {
			ViewPersonList(list);
			break;
		}
		case 2: {
			AddPerson(list);
			break;
		}
		case 3: {
			int id;
			cout << "Inout ID to Remove: ";
			cin >> id;
			RemovePerson(list, id);
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 0: {
			return 0;
		}
		default:
			cout << "Your command isn`t found, Try again..." << endl;
			break;
		}
		cout << "Press Enter to Countinue...";
		cin.ignore();
		cin.get();
	} while (true);
	return 0;
}
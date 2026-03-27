

#include <iostream>
using namespace std;
struct Person {
    int id;
    string name;

};
struct Node {
    Person data;
    Node* next;
};
struct Linkedlist {
    Node* head;
};

int main()
{
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
			
			break;
		}
		case 2: {
			
			break;
		}
		case 3: {
			int id;
			cout << "Inout ID to Remove: ";
			cin >> id;
			
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




#include <iostream>
using namespace std;
#define MAX 100
struct Book {
    int id;
    char name[50];
    double price;
    friend istream& operator>> (istream& in, Book& b) {
        cout << "Book information: " << endl;
        cout << "\t+ Id: ";
        in >> b.id;
        cout << "\t+ Name: ";
        cin.ignore();
        in.getline(b.name, 50);
        cout << "\t+ Price: ";
        in >> b.price;
        return in;
    }
    friend ostream& operator << (ostream& out, Book& b) {
        out << "\t+ Id: " << b.id << endl;
        out << "\t+ Name: " << b.name << endl;
        out << "\t+ Price: " << b.price << endl;
        return out;
    }
};
#define MAX 100
int nBook = 0;
Book books[MAX];


void AddBook(Book b) {
    if (nBook >= MAX) {
        cout << "Out of storage" << endl;
        return;
    }
    books[nBook++] = b;
}
void Show() {
    for (int i = 0; i < nBook;i++) {
        cout << books[i];
    }
}
void Sort() {
    for (int i = 0; i < nBook - 1; i++) {
        for (int j = 0; j < nBook; j++) {
            if (books[j].price > books[i].price) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
void Find(int bookId) {
    int left = 0, right = nBook - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (books[mid].id == bookId){
            cout << books[mid];
            return;
        }
        if (books[mid].id > bookId) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Unavailable books" << endl;
}
int main()
{
    bool sorted = false;
    do {
        system("cls");
        cout << "___________BOOK MANAGEMENT____________" << endl;
        cout << "1.Add a book" << endl;
        cout << "2.Show books" << endl;
        cout << "3.Sort books" << endl;
        cout << "4.Find a book" << endl;
        cout << "0.Exit" << endl;
        cout << "______________________________________" << endl;
        cout << "choose: ";
        int choose;
        cin >> choose;
        switch (choose) {
        case 1: {
            Book b;
            cin >> b;
            AddBook(b);
            break;
        }
        case 2: {
            Show();
            break;
        }
        case 3: {
            Sort();
            sorted = true;
            break;
        }
        case 4: {
            if (!sorted) {
                cout << "Books aren`t sorted" << endl;
            }
            else {
                int bookId;
                cout << "Book ID to find:  ";
                cin >> bookId;
                Find(bookId);
            }
            break;
        }
        case 0: {
            return 0;

        defaut: {
            cout << "Invalid comand!!" << endl;
            break;
            }
        }
        }
        system("pause");
        cout << "Press enter to countinue..." << endl;
     }while (true);
    
}


#include <string>

using namespace std;
struct Account {
	int id;
	string lnk, usr, pwd, desc;
	friend ostream& operator<<(ostream& os, const Account& b) {
		os << "Account formation:" << endl;
		os << "\t+ Id:" << b.id << endl;
		os << "\t+ Link: " << b.lnk << endl;
		os << "\t+ User name: " << b.usr << endl;
		os << "\t+ Password: " << b.pwd << endl;
		os << "\t+ Description: " << b.desc << endl;
		return os;
	}
	friend istream& operator>>(istream& in, Account& b){
		cout << "Author information: " << endl;
		cout << "\t+ Id: ";
		in >> b.id;
		cout << "\t+ Link:";
		in.ignore();
		getline(in, b.lnk);
		cout << "\t+ User name";
		in.ignore();
		getline(in, b.usr);
		cout << "\t+ Password: " << endl;
		cin >> b.pwd;
		cout << "\t+ Description: " << endl;
		cin >> b.desc;
		return in;

	}
};
#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Account {
    int id;
    string lnk, usr, pwd, desc;

    
    friend ostream& operator<<(ostream& os, const Account& b) {
        os << "----------------------------" << endl;
        os << "\t+ Id: " << b.id << endl;
        os << "\t+ Link: " << b.lnk << endl;
        os << "\t+ Username: " << b.usr << endl;
        os << "\t+ Password: " << b.pwd << endl;
        os << "\t+ Description: " << b.desc << endl;
        return os;
    }

    
    friend istream& operator>>(istream& in, Account& b) {
        cout << "\t+ Id: ";
        in >> b.id;
        in.ignore(); // Xóa bộ nhớ đệm sau khi nhập số
        cout << "\t+ Link: "; getline(in, b.lnk);
        cout << "\t+ User name: "; getline(in, b.usr);
        cout << "\t+ Password: "; getline(in, b.pwd);
        cout << "\t+ Description: "; getline(in, b.desc);
        return in;
    }
};
// co dung ai
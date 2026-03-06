#include <iostream>
#include <vector>
using namespace std;
struct sinhvien {
	string hoten;
	int tuoi;
	bool gioitinh;
	string diachi;
};
int main() {
	sinhvien b;
	b.hoten = "Le Van A";
	b.tuoi = 20;
	b.gioitinh = true;
	b.diachi = "Tay Ninh";
	sinhvien c;
	c.hoten = "Tran Thi B";
	c.tuoi = 30;
	c.gioitinh = false;
	c.diachi = "Tay Ninh";
	vector <sinhvien> mang;
	mang.push_back(b);
	mang.push_back(c);
	for (int i = 0; i < mang.size(); i++) {
		cout << "Sinh vien " << (i + 1) << endl;
		cout << "\t+ Ho ten:" << mang[i].hoten << endl;
		cout << "\t+ Tuoi:" << mang[i].tuoi << endl;
		cout << "\t+ Gioi tinh(1 = Nam , 0 = Nu):" << mang[i].gioitinh << endl;
		cout << "\t+ Dia chi:" << mang[i].diachi << endl;
	}
	/*int a = 5;
	int* p = &a;
	a += 6;
	a = *p + 2;
	cout << *p << endl; */
	/*vector <float> diemthi;
	diemthi.push_back(5.9);
	diemthi.push_back(6.2);
	diemthi.push_back(1.2);
	diemthi.pop_back();
	for (int i = 0; i < diemthi.size(); i++) {
		cout << diemthi[i] << endl;
	}*/

}
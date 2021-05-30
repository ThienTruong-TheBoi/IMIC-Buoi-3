#include <iostream>
#include <string>
using namespace std;

enum Loai_t
{
	Gioi, Kha, Trung_Binh, Yeu
};

typedef struct
{
	string HoTen;
	float Toan;
	float Van;
	float Tb;
	Loai_t Loai;
}hoc_sinh_t;

hoc_sinh_t HocSinh[];

int main()
{
	int n;
	cout << "Nhap so luong hoc sinh. ";
	cin >> n;

	hoc_sinh_t HocSinh[] = new hoc_sinh_t[];

	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin hoc sinh thu " << i + 1;
		cout << "Ho ten: ";
		cin >> HocSinh[i].HoTen;
		cout << "Diem Toan: ";
		cin >> HocSinh[i].Toan;
		cout << "Diem Van: ";
		cin >> HocSinh[i].Van;

		HocSinh[i].Tb = (HocSinh[i].Toan + HocSinh[i].Van) * 1.0 / 2;
		cout << "Diem trung binh: " << HocSinh[i].Tb;
		if (HocSinh[i].Tb > 8)
			HocSinh[i].Loai = Gioi;
		else if (HocSinh[i].Tb < 8)
			HocSinh[i].Loai = Kha;
		else if (HocSinh[i].Tb < 6.5)
			HocSinh[i].Loai = Trung_Binh;
		else if (HocSinh[i].Tb < 5)
			HocSinh[i].Loai = Yeu;
		cout << "Loai: " << HocSinh[i].Loai;
	}

	hoc_sinh_t MaxDiem = HocSinh[0];

	for (int i = 1; i < n; i++)
	{
		if (HocSinh[i].Tb > MaxDiem.Tb)
			MaxDiem = HocSinh[i];
	}

	cout << "\n\n\n";

	for (int i = 0; i < n; i++)
	{
		cout << "\nHo ten hoc sinh: " << HocSinh[i].HoTen;
		cout << "\nDiem Toan: " << HocSinh[i].Toan;
		cout << "\nDiem Van: " << HocSinh[i].Van;
		cout << "\nDiem trung binh: " << HocSinh[i].Tb;
		cout << "\nLoai: " << HocSinh[i].Loai;
	}

	cout << "\n\n\n";
	cout << "Thong tin hoc sinh co diem trung binh cao nhat.";
	cout << "\nHo ten hoc sinh: " << MaxDiem.HoTen;
	cout << "\nDiem Toan: " << MaxDiem.Toan;
	cout << "\nDiem Van: " << MaxDiem.Van;
	cout << "\nDiem trung binh: " << MaxDiem.Tb;
	cout << "\nLoai: " << MaxDiem.Loai;

	return 0;
}
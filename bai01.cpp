#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sach
{
private:
    string TenSach;
public:
    virtual void Nhap();
    virtual void Xuat();
};
class SachGiaoKhoa: public Sach
{
private:
    int Lop;
public:
    void Nhap();
    void Xuat();
};
class SachTieuThuyet: public Sach
{
private:
    string TheLoaiTT;
    string TacGia;
public:
    void Nhap();
    void Xuat();
};
class SachTapChi: public Sach
{
private:
    string TheLoai;
public:
    void Nhap();
    void Xuat();
    
};
class QuanLiSach
{
private:
    vector<Sach*> dsSach;
public:
    void Nhapds();
    void Xuatds();

};
void Sach::Nhap()
{
    cin.ignore();
    cout << "\nNhap ten sach: ";
    getline(cin, TenSach);
}
void Sach::Xuat()
{
    cout << "\nTen sach: " << TenSach;
}
void SachGiaoKhoa::Nhap()
{
    Sach::Nhap();
    cout << "\nNhap lop: ";
    cin >> Lop;
}
void SachGiaoKhoa::Xuat()
{
    Sach::Xuat();
    cout << "\nLop: " << Lop;
}
void SachTieuThuyet::Nhap()
{
    Sach::Nhap();
    cout << "Nhap the loai: ";
    getline(cin, TheLoaiTT);
    cout << "Nhap tac gia: ";
    getline(cin, TacGia);
}
void SachTieuThuyet::Xuat()
{
    Sach::Xuat();
    cout << "\nThe loai: " << TheLoaiTT;
    cout << "\nTac gia: " << TacGia;
}
void SachTapChi::Nhap()
{
    Sach::Nhap();
    cout << "Nhap the loai: ";
    getline(cin, TheLoai);
}
void SachTapChi::Xuat()
{
    Sach::Xuat();
    cout << "\nThe loai: " << TheLoai;
}
void QuanLiSach::Nhapds()
{
    Sach* s;
    int loai;
    while (1)
    {
        cout << "\nMENU: \n1. Sach giao khoa.\n2. Sach tieu thuyet. \n3. Sach tap chi. \n4. Thoat!!!" << endl;
        cin >> loai;
        if (loai == 1)
        {
            s = new SachGiaoKhoa;
            s->Nhap();
            dsSach.push_back(s);
        }
        if (loai == 2)
        {
            s = new SachTieuThuyet;
            s->Nhap();
            dsSach.push_back(s);
        }
        if (loai == 3)
        {
            s = new SachTapChi;
            s->Nhap();
            dsSach.push_back(s);
        }
        if (loai == 4)
            break;
    }
}
void QuanLiSach::Xuatds()
{
    for (int i = 0; i < dsSach.size(); i++)
    {
        dsSach[i]->Xuat();
        cout << endl;
    }
}
int main()
{
    QuanLiSach ql;
    ql.Nhapds();
    cout << "********************" << endl;
    cout << "********************" << endl;cout << "********************" << endl;
    ql.Xuatds();
    return 0;
}

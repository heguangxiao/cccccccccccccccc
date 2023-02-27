#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct sinhvien
{
    int idsv;
    char ten[30];
    char gioitinh[5];
    int tuoi;
};
typedef sinhvien SV;

struct nodeSV
{
    SV data;
    nodeSV *next;
};
typedef struct nodeSV NODESV;

struct listSV
{
    NODESV *pHead;
    NODESV *pTail;
};
typedef struct listSV LISTSV;

void KhoiTaoSV(LISTSV &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}

int KiemTraRongSV(LISTSV ds)
{
    if (ds.pHead == NULL)
    {
        return 1;
    }
    return 0;
}

NODESV *TaoNodeSV(SV x)
{
    NODESV *p;
    p = new NODESV;
    if (p == NULL)
    {
        printf("\n Khong du bo nho \n");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void ChenCuoiSV(LISTSV &ds, NODESV *p)
{
    if (ds.pHead == NULL)
    {
        ds.pHead = p;
        ds.pTail = p;
    }
    else
    {
        ds.pTail->next = p;
        ds.pTail = p;
    }
}

struct monhoc
{
    int idmh;
    char ten[30];
};
typedef monhoc MH;

struct nodeMH
{
    MH data;
    nodeMH *next;
};
typedef struct nodeMH NODEMH;

struct listMH
{
    NODEMH *pHead;
    NODEMH *pTail;
};
typedef struct listMH LISTMH;

void KhoiTaoMH(LISTMH &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}

int KiemTraRongMH(LISTMH ds)
{
    if (ds.pHead == NULL)
    {
        return 1;
    }
    return 0;
}

NODEMH *TaoNodeMH(MH x)
{
    NODEMH *p;
    p = new NODEMH;
    if (p == NULL)
    {
        printf("\n Khong du bo nho \n");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void ChenCuoiMH(LISTMH &ds, NODEMH *p)
{
    if (ds.pHead == NULL)
    {
        ds.pHead = p;
        ds.pTail = p;
    }
    else
    {
        ds.pTail->next = p;
        ds.pTail = p;
    }
}

struct bangdiem
{
    int idsv;
    int idmh;
    float diem;
};
typedef bangdiem BD;

struct nodeBD
{
    BD data;
    nodeBD *next;
};
typedef struct nodeBD NODEBD;

struct listBD
{
    NODEBD *pHead;
    NODEBD *pTail;
};
typedef struct listBD LISTBD;

void KhoiTaoBD(LISTBD &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}

int KiemTraRongBD(LISTBD ds)
{
    if (ds.pHead == NULL)
    {
        return 1;
    }
    return 0;
}

NODEBD *TaoNodeBD(BD x)
{
    NODEBD *p;
    p = new NODEBD;
    if (p == NULL)
    {
        printf("\n Khong du bo nho \n");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void ChenCuoiBD(LISTBD &ds, NODEBD *p)
{
    if (ds.pHead == NULL)
    {
        ds.pHead = p;
        ds.pTail = p;
    }
    else
    {
        ds.pTail->next = p;
        ds.pTail = p;
    }
}

void printLine(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "_";
    }
    cout << endl;
}

void NhapMH(LISTMH &dsmh, int slmh, int idmh)
{
    printLine(40);
    cin.ignore(1);
    printf("\n\n\tNhap thong tin mon hoc thu %d: ", slmh + 1);
    MH x;
    x.idmh = idmh;
    printf("\n\n\tNhap ten mon hoc : ");
    cin.getline(x.ten, 30);
    fflush(stdin);
    printf("\n\n");
    NODEMH *p = new NODEMH;
    p = TaoNodeMH(x);
    ChenCuoiMH(dsmh, p);
    printLine(40);
}

void NhapSV(LISTSV &dssv, int slsv, int idsv)
{
    printLine(40);
    cin.ignore(1);
    printf("\n\n\tNhap thong tin sinh vien thu %d: ", (slsv + 1));
    SV x;
    x.idsv = idsv;
    printf("\n\n\tNhap ten sinh vien : ");
    cin.getline(x.ten, 30);
    fflush(stdin);
    printf("\n\tNhap gioi tinh sinh vien : ");
    cin.getline(x.gioitinh, 30);
    fflush(stdin);
    printf("\n\tNhap tuoi sinh vien : ");
    scanf("%d", &x.tuoi);
    printf("\n\n");
    NODESV *p = new NODESV;
    p = TaoNodeSV(x);
    ChenCuoiSV(dssv, p);
    printLine(40);
}

void nhapDiemSV(LISTBD &bd, LISTMH mh, LISTSV sv)
{
    printLine(40);

    for (NODESV *p = sv.pHead; p != NULL; p = p->next)
    {
        printf("\n\n\tNhap diem cho sinh vien: %s", p->data.ten);
        for (NODEMH *q = mh.pHead; q != NULL; q = q->next)
        {
            cin.ignore(1);
            BD x;
            x.idsv = p->data.idsv;
            x.idmh = q->data.idmh;
            printf("\n\n\tNhap diem mon %s: ", q->data.ten);
            cin >> x.diem;
            NODEBD *o = new NODEBD;
            o = TaoNodeBD(x);
            ChenCuoiBD(bd, o);
        }
    }

    printLine(40);
}

void hienThiMonHoc(LISTMH mh)
{
    printLine(40);
    if (KiemTraRongMH(mh) == 0)
    {
        cout << "\n\tSTT\tID\tTEN";
        int i = 0;
        for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
        {
            printf("\n\t%d", ++i);
            printf("\t%d", p->data.idmh);
            printf("\t%s", p->data.ten);
        }
        printf("\n");
    }
    else
    {
        cout << "\nSanh sach mon hoc trong!";
    }
    printLine(40);
}

void hienThiSinhVien(LISTSV ds)
{
    printLine(100);
    if (KiemTraRongSV(ds) == 0)
    {
        cout << "\n\tSTT\tID\tGioi tinh\tTuoi\tHo va ten";
        int i = 0;
        for (NODESV *p = ds.pHead; p != NULL; p = p->next)
        {
            printf("\n\t%d", ++i);
            printf("\t%d", p->data.idsv);
            printf("\t%s\t", p->data.gioitinh);
            printf("\t%d", p->data.tuoi);
            printf("\t%s", p->data.ten);
        }
        printf("\n");
    }
    else
    {
        cout << "\nDanh sach sinh vien trong!";
    }
    printLine(100);
}

void hienThiBangDiem(LISTBD bd, LISTMH mh, LISTSV sv)
{
    printLine(100);

    cout << "\n";

    for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
    {
        printf("\t%s", p->data.ten);
    }

    cout << "\tTen";

    for (NODESV *p = sv.pHead; p != NULL; p = p->next)
    {
        cout << "\n";
        for (NODEMH *q = mh.pHead; q != NULL; q = q->next)
        {
            for (NODEBD *o = bd.pHead; o != NULL; o = o->next)
            {
                if (o->data.idmh == q->data.idmh && o->data.idsv == p->data.idsv)
                {
                    printf("\t%.2f", o->data.diem);
                    break;
                }
            }
        }
        printf("\t%s", p->data.ten);
    }

    printLine(100);
}

void capNhatThongTinSV(SV &sv)
{
    cin.ignore(1);
    cout << "\n\n\tNhap ten: ";
    cin.getline(sv.ten, 30);
    fflush(stdin);
    cout << "\n\n\tNhap gioi tinh: ";
    cin.getline(sv.gioitinh, 30);
    fflush(stdin);
    cout << "\n\n\tNhap tuoi: ";
    cin >> sv.tuoi;
}

void capNhatSV(LISTSV sv)
{
    printLine(100);
    int id;
    cout << "\n Nhap ID sinh vien can thay doi thong tin: ";
    cin >> id;
    int found = 0;
    for (NODESV *p = sv.pHead; p != NULL; p = p->next)
    {
        if (p->data.idsv == id)
        {
            found = 1;
            cout << "\n Cap nhat thong tin sinh vien co ID = " << id;
            capNhatThongTinSV(p->data);
        }
    }
    if (found == 0)
    {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
    }
    printLine(100);
}

void pressAnyKey()
{
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}

int menu(int x)
{
    cout << "CHUONG TRINH QUAN LY DIEM SINH VIEN C/C++\n";
    cout << "*************************MENU*************************************************\n";
    cout << "**  1. Them mon hoc.                                                        **\n";
    cout << "**  2. Them sinh vien.                                                      **\n";
    cout << "**  3. Nhap diem cho sinh vien.                                             **\n";
    cout << "**  4. Hien thi danh sach mon hoc.                                          **\n";
    cout << "**  5. Hien thi danh sach sinh vien.                                        **\n";
    cout << "**  6. Hien thi bang diem.                                                  **\n";
    cout << "**  7. Cap nhat thong tin sinh vien boi ID.                                 **\n";
    cout << "**  8. Xoa sinh vien boi ID.                                                **\n";
    cout << "**  9. Tim kiem sinh vien theo ten.                                         **\n";
    cout << "**  0. Thoat                                                                **\n";
    cout << "******************************************************************************\n";
    cout << "Nhap tuy chon: ";
    scanf("%d", &x);
    return x;
}

int main()
{

    LISTSV dssv;
    KhoiTaoSV(dssv);
    int slsv = 0;
    int idsv = 1;
    LISTMH dsmh;
    KhoiTaoMH(dsmh);
    int slmh = 0;
    int idmh = 1;
    LISTBD dsbd;
    KhoiTaoBD(dsbd);

    int key;

    while (true)
    {
        key = menu(key);
        switch (key)
        {
        case 1:
            printf("\n");
            NhapMH(dsmh, slmh, idmh);
            slmh++;
            idmh++;
            pressAnyKey();
            break;
        case 2:
            printf("\n");
            NhapSV(dssv, slsv, idsv);
            slsv++;
            idsv++;
            pressAnyKey();
            break;
        case 3:
            cout << "\n3. Nhap diem cho sinh vien.";
            nhapDiemSV(dsbd, dsmh, dssv);
            pressAnyKey();
            break;
        case 4:
            cout << "\n4. Hien thi danh sach mon hoc.";
            hienThiMonHoc(dsmh);
            pressAnyKey();
            break;
        case 5:
            cout << "\n5. Hien thi danh sach sinh vien.";
            hienThiSinhVien(dssv);
            pressAnyKey();
            break;
        case 6:
            cout << "\n6. Hien thi bang diem.";
            hienThiBangDiem(dsbd, dsmh, dssv);
            pressAnyKey();
            break;
        case 7:
            cout << "\n7. Cap nhat thong tin sinh vien boi ID.";
            capNhatSV(dssv);
            pressAnyKey();
            break;
        case 0:
            cout << "\nBan da chon thoat chuong trinh!";
            getch();
            return 0;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            pressAnyKey();
            break;
        }
    }

    return 0;
}
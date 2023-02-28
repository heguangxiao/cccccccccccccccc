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

int SLSV(LISTSV list)
{
    NODESV *p = list.pHead;
    int size = 0;
    while (p != NULL)
    {
        p = p->next;
        size++;
    }
    return size;
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

int SLMH(LISTMH list)
{
    NODEMH *p = list.pHead;
    int size = 0;
    while (p != NULL)
    {
        p = p->next;
        size++;
    }
    return size;
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

void NhapMH(LISTMH &dsmh, int idmh)
{
    printLine(40);
    cin.ignore(1);
    printf("\n\n\tNhap thong tin mon hoc thu %d: ", SLMH(dsmh) + 1);
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

void NhapSV(LISTSV &dssv, int idsv)
{
    printLine(40);
    cin.ignore(1);
    printf("\n\n\tNhap thong tin sinh vien thu %d: ", (SLSV(dssv) + 1));
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

    cout << "\tTen";

    for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
    {
        printf("\t%s", p->data.ten);
    }

    for (NODESV *p = sv.pHead; p != NULL; p = p->next)
    {
        printf("\n\t%s", p->data.ten);
        for (NODEMH *q = mh.pHead; q != NULL; q = q->next)
        {
            for (NODEBD *o = bd.pHead; o != NULL; o = o->next)
            {
                if (o->data.idmh == q->data.idmh && o->data.idsv == p->data.idsv)
                {
                    printf("\t%.2f", o->data.diem > 0.0 ? o->data.diem : 0.0);
                    break;
                }
            }
        }
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

void xoaTheoID(LISTSV &sv, int id)
{
    NODESV *pDel = sv.pHead; // tạo một node pDel để xóa
    NODESV *pPre = NULL;
    // dùng vòng lặp while để tìm ra pDel và pPre (vị trí đứng trước pDel)
    while (pDel != NULL)
    {
        if (pDel->data.idsv == id)
        {
            break;
        }
        pPre = pDel;
        pDel = pDel->next;
    }
    // Nếu pDel == null tức là không tìm thấy số cần xóa
    if (pDel == NULL)
    {
        printf("\n\n\tSinh vien co ID = %d khong ton tai.", id);
    }
    // Ngược lại tiếp tục xét điều kiện
    else
    {
        // Nếu pDel == list.pHead, tức là số cần xóa ở đầu danh sách
        if (pDel == sv.pHead)
        {
            sv.pHead = sv.pHead->next;
            pDel->next = NULL;
            delete pDel;
            pDel = NULL;
        }
        // Nếu pDel == list.pTail, tức là số cần xóa ở cuối danh sách
        else if (pDel->next == NULL)
        {
            sv.pTail = pPre;
            pPre->next = NULL;
            delete pDel;
            pDel = NULL;
        }
        // và trường hợp cuối cùng số muốn xóa nằm ở giữa danh sách
        else
        {
            pPre->next = pDel->next;
            pDel->next = NULL;
            delete pDel;
            pDel = NULL;
        }
        printf("\n\n\tDelete success");
    }
}

void timKiemTheoTen(LISTSV sv, LISTMH mh, LISTBD bd, char ten[])
{
    char tenSV[30];
    int found = 0;
    int i = 0;
    int count = 0;
    cout << "\n\tSTT\tID\tTen\tGioi tinh\tTuoi";
    for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
    {
        printf("\t%s", p->data.ten);
    }
    for (NODESV *p = sv.pHead; p != NULL; p = p->next)
    {
        strcpy(tenSV, p->data.ten);
        if (strstr(strupr(tenSV), strupr(ten)))
        {
            count++;
            printf("\n\t%d", ++i);
            printf("\t%d", p->data.idsv);
            printf("\t%s", p->data.ten);
            printf("\t%s\t", p->data.gioitinh);
            printf("\t%d", p->data.tuoi);
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
        }
    }
    if (count == 0)
    {
        cout << "Khong tim thay sinh vien co ten: %s", ten;
    }
}
void timKiemTheoTuoi(LISTSV sv, LISTMH mh, LISTBD bd, int start, int end)
{
    NODESV *p = sv.pHead;
    cout << "\n\tSTT\tID\tTen\tGioiTinh\tTuoi";
    NODEMH *q = mh.pHead;
    NODEBD *o = bd.pHead;
    while (q != NULL)
    {
        printf("\t%s", q->data.ten);
        q = q->next;
    }
    int i = 0;
    while (p != NULL)
    {
        if (p->data.tuoi >= start && p->data.tuoi <= end)
        {
            printf("\n\t%d", ++i);
            printf("\t%d", p->data.idsv);
            printf("\t%s", p->data.ten);
            printf("\t%s\t", p->data.gioitinh);
            printf("\t%d", p->data.tuoi);
            q = mh.pHead;
            while (q != NULL)
            {
                o = bd.pHead;
                while (o != NULL)
                {
                    if (o->data.idmh == q->data.idmh && o->data.idsv == p->data.idsv)
                    {
                        printf("\t%.2f", o->data.diem);
                        break;
                    }
                    o = o->next;
                }
                q = q->next;
            }
        }
        p = p->next;
    }
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
    cout << "**  10. Tim kiem sinh vien theo tuoi.                                       **\n";
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
    int idsv = 1;
    LISTMH dsmh;
    KhoiTaoMH(dsmh);
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
            cout << "\n1. Them mon hoc.";
            NhapMH(dsmh, idmh);
            idmh++;
            pressAnyKey();
            break;
        case 2:
            cout << "\n2. Them sinh vien.";
            NhapSV(dssv, idsv);
            idsv++;
            pressAnyKey();
            break;
        case 3:
            cout << "\n3. Nhap diem cho sinh vien.";
            if (SLSV(dssv) == 0)
            {
                cout << "\nDanh sach sinh vien rong!!";
            }
            else if (SLMH(dsmh) == 0)
            {
                cout << "\nDanh sach mon hoc rong!!";
            }
            else
            {
                nhapDiemSV(dsbd, dsmh, dssv);
            }
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
            if (SLSV(dssv) == 0)
            {
                cout << "\nDanh sach sinh vien rong!!";
            }
            else if (SLMH(dsmh) == 0)
            {
                cout << "\nDanh sach mon hoc rong!!";
            }
            else
            {
                hienThiBangDiem(dsbd, dsmh, dssv);
            }
            pressAnyKey();
            break;
        case 7:
            cout << "\n7. Cap nhat thong tin sinh vien boi ID.";
            capNhatSV(dssv);
            pressAnyKey();
            break;
        case 8:
            cout << "\n8. Xoa sinh vien boi ID.";
            if (SLSV(dssv) == 0)
            {
                cout << "\nDanh sach rong!!";
            }
            else
            {
                int id;
                cout << "\n Nhap ID: ";
                cin >> id;
                xoaTheoID(dssv, id);
            }
            pressAnyKey();
            break;
        case 9:
            cout << "\n9. Tim kiem sinh vien theo ten.";
            if (SLSV(dssv) == 0)
            {
                cout << "\nDanh sach sinh vien rong!!";
            }
            else
            {
                char ten[30];
                cin.ignore(1);
                cout << "\nNhap ten de tim kiem: ";
                cin.getline(ten, 30);
                fflush(stdin);
                timKiemTheoTen(dssv, dsmh, dsbd, ten);
            }
            pressAnyKey();
            break;
        case 10:
            cout << "\n10. Tim kiem sinh vien theo tuoi.";
            if (SLSV(dssv) == 0)
            {
                cout << "\nDanh sach sinh vien rong!!";
            }
            else
            {
                int start;
                int end;
                cout << "\nDanh sach sinh vien co do tuoi tu: ";
                cin >> start;
                cout << " den :";
                cin >> end;
                timKiemTheoTuoi(dssv, dsmh, dsbd, start, end);
            }
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
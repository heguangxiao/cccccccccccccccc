#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

struct sinhvien
{
    int idsv;
    char ten[30];
    char gioitinh[5];
    int tuoi;
    float DTB = 0.00;
    char hocluc[10] = "Yeu";
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
    float diem = 0.00;
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

int SLBD(LISTBD list)
{
    NODEBD *p = list.pHead;
    int size = 0;
    while (p != NULL)
    {
        p = p->next;
        size++;
    }
    return size;
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

void tinhDTB(SV &sv, LISTMH mh, LISTBD bd)
{
    float dtb = 0;
    if (SLMH(mh) > 0)
    {
        for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
        {
            for (NODEBD *q = bd.pHead->next; q != NULL; q = q->next)
            {
                if (sv.idsv == q->data.idsv && p->data.idmh == q->data.idmh)
                {
                    dtb = dtb + q->data.diem;
                    // printf("\n ---- %.2f ----", dtb);
                    break;
                }
            }
        }
    }
    dtb = dtb / SLMH(mh);
    sv.DTB = dtb;
}

void xeploai(SV &sv, LISTMH mh, LISTBD bd)
{
    if (sv.DTB >= 8)
        strcpy(sv.hocluc, "Gioi");
    else if (sv.DTB >= 6.5)
        strcpy(sv.hocluc, "Kha");
    else if (sv.DTB >= 5)
        strcpy(sv.hocluc, "TB");
    else
        strcpy(sv.hocluc, "Yeu");
}
void hienThiBD(LISTBD bd)
{
    printLine(40);
    if (KiemTraRongBD(bd) == 0)
    {
        cout << "\n\tSTT\tIDSV\tIDMH\tDIEM";
        int i = 0;
        for (NODEBD *p = bd.pHead; p != NULL; p = p->next)
        {
            printf("\n\t%d", ++i);
            printf("\t%d", p->data.idsv);
            printf("\t%d", p->data.idmh);
            printf("\t%.2f", p->data.diem);
        }
        printf("\n");
    }
    else
    {
        cout << "\nDanh sach mon hoc trong!";
    }
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
            NODEBD *o = new NODEBD;
            BD x;
            x.idsv = p->data.idsv;
            x.idmh = q->data.idmh;
            printf("\n\n\tNhap diem mon %s: ", q->data.ten);
            cin >> x.diem;
            o = TaoNodeBD(x);
            ChenCuoiBD(bd, o);
        }
    }

    for (NODESV *p = sv.pHead; p != NULL; p = p->next)
    {
        tinhDTB(p->data, mh, bd);
        xeploai(p->data, mh, bd);
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
        cout << "\nDanh sach mon hoc trong!";
    }
    printLine(40);
}

void hienThiSinhVien(LISTSV ds)
{
    printLine(100);
    if (KiemTraRongSV(ds) == 0)
    {
        cout << "\n\tSTT\tID\tTen\tGioi tinh\tTuoi";
        int i = 0;
        for (NODESV *p = ds.pHead; p != NULL; p = p->next)
        {
            printf("\n\t%d", ++i);
            printf("\t%d", p->data.idsv);
            printf("\t%s", p->data.ten);
            printf("\t%s\t", p->data.gioitinh);
            printf("\t%d", p->data.tuoi);
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

    cout << "\tDTB\tHocLuc";

    for (NODESV *p = sv.pHead; p != NULL; p = p->next)
    {
        printf("\n\t%s", p->data.ten);
        for (NODEMH *q = mh.pHead; q != NULL; q = q->next)
        {
            int count = 0;
            for (NODEBD *o = bd.pHead; o != NULL; o = o->next)
            {
                if (o->data.idmh == q->data.idmh && o->data.idsv == p->data.idsv)
                {
                    count++;
                    printf("\t%.2f", o->data.diem);
                    break;
                }
            }
            if (count == 0)
            {
                printf("\t0.00");
            }
        }
        printf("\t%.2f", p->data.DTB);
        printf("\t%s", p->data.hocluc);
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
    NODESV *pDel = sv.pHead; // t???o m???t node pDel ????? x??a
    NODESV *pPre = NULL;
    // d??ng v??ng l???p while ????? t??m ra pDel v?? pPre (v??? tr?? ?????ng tr?????c pDel)
    while (pDel != NULL)
    {
        if (pDel->data.idsv == id)
        {
            break;
        }
        pPre = pDel;
        pDel = pDel->next;
    }
    // N???u pDel == null t???c l?? kh??ng t??m th???y s??? c???n x??a
    if (pDel == NULL)
    {
        printf("\n\n\tSinh vien co ID = %d khong ton tai.", id);
    }
    // Ng?????c l???i ti???p t???c x??t ??i???u ki???n
    else
    {
        // N???u pDel == list.pHead, t???c l?? s??? c???n x??a ??? ?????u danh s??ch
        if (pDel == sv.pHead)
        {
            sv.pHead = sv.pHead->next;
            pDel->next = NULL;
            delete pDel;
            pDel = NULL;
        }
        // N???u pDel == list.pTail, t???c l?? s??? c???n x??a ??? cu???i danh s??ch
        else if (pDel->next == NULL)
        {
            sv.pTail = pPre;
            pPre->next = NULL;
            delete pDel;
            pDel = NULL;
        }
        // v?? tr?????ng h???p cu???i c??ng s??? mu???n x??a n???m ??? gi???a danh s??ch
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

void xoaAllBd(LISTBD &bd)
{
    NODEBD *pDel = bd.pHead;
    NODEBD *pPre = NULL;
    while (pDel != NULL)
    {
        bd.pHead = bd.pHead->next;
        pDel->next = NULL;
        delete pDel;
        pDel = bd.pHead;
    }
}

void xoaAllSv(LISTSV &sv)
{
    NODESV *pDel = sv.pHead;
    NODESV *pPre = NULL;
    while (pDel != NULL)
    {
        sv.pHead = sv.pHead->next;
        pDel->next = NULL;
        delete pDel;
        pDel = sv.pHead;
    }
}

void xoaAllMh(LISTMH &mh)
{
    NODEMH *pDel = mh.pHead;
    NODEMH *pPre = NULL;
    while (pDel != NULL)
    {
        mh.pHead = mh.pHead->next;
        pDel->next = NULL;
        delete pDel;
        pDel = mh.pHead;
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

void sapXepMonHocTheoTen(LISTMH &mh)
{
    MH tmp;
    char tenSV1[30];
    char tenSV2[30];
    for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
    {
        strcpy(tenSV1, p->data.ten);
        for (NODEMH *q = mh.pHead->next; q != NULL; q = q->next)
        {
            strcpy(tenSV2, q->data.ten);
            if (strcmp(strupr(tenSV1), strupr(tenSV2)) > 0)
            {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
    hienThiMonHoc(mh);
}

void HoanViSV(SV &a, SV &b)
{
    SV c = a;
    a = b;
    b = c;
}

void sapXepSinhVienTheoTen(LISTSV &l)
{
    NODESV *i, *j;
    char tenSV1[30];
    char tenSV2[30];
    for (i = l.pHead; i != l.pTail; i = i->next)
    {
        strcpy(tenSV1, i->data.ten);
        for (j = i->next; j != NULL; j = j->next)
        {
            strcpy(tenSV2, j->data.ten);
            if (strcmp(strupr(tenSV1), strupr(tenSV2)) > 0)
            {
                HoanViSV(i->data, j->data);
            }
        }
    }
    hienThiSinhVien(l);
}

void sapXepSinhVienTheoTuoi(LISTSV &ds)
{
    NODESV *min;
    NODESV *p, *q;
    p = ds.pHead;
    while (p != ds.pTail)
    {
        min = p;
        q = p->next;
        while (q != NULL)
        {
            if (q->data.tuoi < min->data.tuoi)
            {
                min = q;
            }
            q = q->next;
        }
        HoanViSV(min->data, p->data);
        p = p->next;
    }
    hienThiSinhVien(ds);
}

void sapXepSinhVienTheoDTB(LISTSV &ds, LISTMH mh, LISTBD bd)
{
    NODESV *min;
    NODESV *p, *q;
    p = ds.pHead;
    while (p != ds.pTail)
    {
        min = p;
        q = p->next;
        while (q != NULL)
        {
            if (q->data.DTB < min->data.DTB)
            {
                min = q;
            }
            q = q->next;
        }
        HoanViSV(min->data, p->data);
        p = p->next;
    }
    hienThiBangDiem(bd, mh, ds);
}

void sinhVienCoTuoiNhoNhat(LISTSV sv)
{
    if (SLSV(sv) > 0)
    {
        printLine(100);
        NODESV *p = sv.pHead;
        SV tmp = sv.pHead->data;
        while (p != NULL)
        {
            if (p->data.tuoi < tmp.tuoi)
            {
                tmp = p->data;
            }
            p = p->next;
        }
        cout << "\n\tID\tTen\tGioi tinh\tTuoi";
        printf("\n\t%d", tmp.idsv);
        printf("\t%s", tmp.ten);
        printf("\t%s\t", tmp.gioitinh);
        printf("\t%d", tmp.tuoi);
        printf("\n");
        printLine(100);
    }
    else
    {
        printf("\nDanh sach trong\n");
    }
}

void sinhVienCoTuoiLonNhat(LISTSV sv)
{
    if (SLSV(sv) > 0)
    {
        printLine(100);
        NODESV *p = sv.pHead;
        SV tmp = sv.pHead->data;
        while (p != NULL)
        {
            if (p->data.tuoi > tmp.tuoi)
            {
                tmp = p->data;
            }
            p = p->next;
        }
        cout << "\n\tID\tTen\tGioi tinh\tTuoi";
        printf("\n\t%d", tmp.idsv);
        printf("\t%s", tmp.ten);
        printf("\t%s\t", tmp.gioitinh);
        printf("\t%d", tmp.tuoi);
        printf("\n");
        printLine(100);
    }
    else
    {
        printf("\nDanh sach trong\n");
    }
}

void sinhVienCoDiemTrungBinhNhoNhat(LISTSV sv, LISTMH mh, LISTBD bd)
{
    if (SLSV(sv) > 0)
    {
        printLine(100);
        NODESV *p = sv.pHead;
        SV tmp = sv.pHead->data;
        while (p != NULL)
        {
            if (p->data.DTB < tmp.DTB)
            {
                tmp = p->data;
            }
            p = p->next;
        }
        cout << "\n\tID\tTen\tGioi tinh\tTuoi";
        for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
        {
            printf("\t%s", p->data.ten);
        }
        cout << "\tDTB\tHocLuc";
        printf("\n\t%d", tmp.idsv);
        printf("\t%s", tmp.ten);
        printf("\t%s\t", tmp.gioitinh);
        printf("\t%d", tmp.tuoi);
        for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
        {
            for (NODEBD *q = bd.pHead; q != NULL; q = q->next)
            {
                if (q->data.idsv == tmp.idsv && q->data.idmh == p->data.idmh)
                {
                    printf("\t%.2f", q->data.diem);
                    break;
                }
            }
        }
        printf("\t%.2f", tmp.DTB);
        printf("\t%s", tmp.hocluc);
        printf("\n");
        printLine(100);
    }
    else
    {
        printf("\nDanh sach trong\n");
    }
}

int idlnsv(LISTSV sv)
{
    int x = 1;
    NODESV *p = sv.pHead;
    while (p != NULL)
    {
        if (p->data.idsv > x)
        {
            x = p->data.idsv;
        }
        p = p->next;
    }
    return x;
}

int idlnmh(LISTMH mh)
{
    int x = 1;
    NODEMH *p = mh.pHead;
    while (p != NULL)
    {
        if (p->data.idmh > x)
        {
            x = p->data.idmh;
        }
        p = p->next;
    }
    return x;
}

void sinhVienCoDiemTrungBinhLonNhat(LISTSV sv, LISTMH mh, LISTBD bd)
{
    if (SLSV(sv) > 0)
    {
        printLine(100);
        NODESV *p = sv.pHead;
        SV tmp = sv.pHead->data;
        while (p != NULL)
        {
            if (p->data.DTB > tmp.DTB)
            {
                tmp = p->data;
            }
            p = p->next;
        }
        cout << "\n\tID\tTen\tGioi tinh\tTuoi";
        for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
        {
            printf("\t%s", p->data.ten);
        }
        cout << "\tDTB\tHocLuc";
        printf("\n\t%d", tmp.idsv);
        printf("\t%s", tmp.ten);
        printf("\t%s\t", tmp.gioitinh);
        printf("\t%d", tmp.tuoi);
        for (NODEMH *p = mh.pHead; p != NULL; p = p->next)
        {
            for (NODEBD *q = bd.pHead; q != NULL; q = q->next)
            {
                if (q->data.idsv == tmp.idsv && q->data.idmh == p->data.idmh)
                {
                    printf("\t%.2f", q->data.diem);
                    break;
                }
            }
        }
        printf("\t%.2f", tmp.DTB);
        printf("\t%s", tmp.hocluc);
        printf("\n");
        printLine(100);
    }
    else
    {
        printf("\nDanh sach trong\n");
    }
}

int soLuongSinhVienNu(LISTSV sv)
{
    int result = 0;
    NODESV *p = sv.pHead;
    char gioitinh[30];
    while (p != NULL)
    {
        strcpy(gioitinh, p->data.gioitinh);
        if (strcmp(strupr(gioitinh), "NU") == 0)
        {
            result++;
        }
        p = p->next;
    }
    return result;
}

int soLuongSinhVienNam(LISTSV sv)
{
    int result = 0;
    NODESV *p = sv.pHead;
    char gioitinh[30];
    while (p != NULL)
    {
        strcpy(gioitinh, p->data.gioitinh);
        if (strcmp(strupr(gioitinh), "NAM") == 0)
        {
            result++;
        }
        p = p->next;
    }
    return result;
}

int soLuongXepLoaiYeu(LISTSV sv)
{
    int result = 0;
    NODESV *p = sv.pHead;
    while (p != NULL)
    {
        if (p->data.DTB < 5)
        {
            result++;
        }
        p = p->next;
    }
    return result;
}

int soLuongXepLoaiTrungBinh(LISTSV sv)
{
    int result = 0;
    NODESV *p = sv.pHead;
    while (p != NULL)
    {
        if (p->data.DTB < 6.5 && p->data.DTB >= 5)
        {
            result++;
        }
        p = p->next;
    }
    return result;
}

int soLuongXepLoaiKha(LISTSV sv)
{
    int result = 0;
    NODESV *p = sv.pHead;
    while (p != NULL)
    {
        if (p->data.DTB < 8 && p->data.DTB >= 6.5)
        {
            result++;
        }
        p = p->next;
    }
    return result;
}

int soLuongXepLoaiGioi(LISTSV sv)
{
    int result = 0;
    NODESV *p = sv.pHead;
    while (p != NULL)
    {
        if (p->data.DTB >= 8)
        {
            result++;
        }
        p = p->next;
    }
    return result;
}

void thongKeXepLoaiSinhVien(LISTSV sv)
{
    printLine(100);
    printf("\n\tSo luong sinh vien xep loai Yeu: %d", soLuongXepLoaiYeu(sv));
    printf("\n\tSo luong sinh vien xep loai Trung Binh: %d", soLuongXepLoaiTrungBinh(sv));
    printf("\n\tSo luong sinh vien xep loai Kha: %d", soLuongXepLoaiKha(sv));
    printf("\n\tSo luong sinh vien xep loai Gioi: %d", soLuongXepLoaiGioi(sv));
    printLine(100);
}

void chick(LISTBD &bd)
{
    BD x;
    x.idmh = 0;
    x.idsv = 0;
    x.diem = 0.00;
    NODEBD *p = new NODEBD;
    p = TaoNodeBD(x);
    ChenCuoiBD(bd, p);
}

void ghiFile(LISTSV sv, LISTMH mh, LISTBD bd, char fileName[])
{
    FILE *fp;
    fp = fopen(fileName, "w");

    fprintf(fp, "%5s%5s%30s%30s%5s", "STT", "ID", "Ten", "GioiTinh", "Tuoi");

    NODESV *p = sv.pHead;
    NODEMH *q = mh.pHead;
    NODEBD *o = bd.pHead;
    int i = 0;

    while (q != NULL)
    {
        fprintf(fp, "%10s", q->data.ten);
        q = q->next;
    }

    fprintf(fp, "%10s%15s\n", "DTB", "HocLuc");

    while (p != NULL)
    {
        fprintf(fp, "%5d%5d%30s%30s%5d", ++i, p->data.idsv, p->data.ten, p->data.gioitinh, p->data.tuoi);
        q = mh.pHead;
        while (q != NULL)
        {
            o = bd.pHead;
            while (o != NULL)
            {
                if (o->data.idsv == p->data.idsv && o->data.idmh == q->data.idmh)
                {
                    fprintf(fp, "%10.2f", o->data.diem);
                    break;
                }
                o = o->next;
            }
            q = q->next;
        }
        fprintf(fp, "%10.2f%15s\n", p->data.DTB, p->data.hocluc);
        p = p->next;
    }

    fclose(fp);
}

string split(string str, string delimiter)
{
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        cout << token << endl;
        str.erase(0, pos + delimiter.length());
    }
    return str;
}

void docFile(LISTSV &sv, LISTMH &mh, LISTBD &bd, char fileName[])
{
    char *p;
    int n = 0;
    int coll = 0;
    int idmh = 1;
    // Khai b??o vector ????? l??u c??c d??ng ?????c ???????c
    vector<string> lines;
    string line;
    // M??? file b???ng ifstream
    ifstream ifs(fileName);
    // Ki???m tra file ???? m??? th??nh c??ng hay ch??a
    if (!ifs.is_open())
    {
        cerr << "Could not open the file - '"
             << fileName << "'" << endl;
    }
    else
    {
        // ?????c t???ng d??ng trong
        while (getline(ifs, line))
        {
            lines.push_back(line); // L??u t???ng d??ng nh?? m???t ph???n t??? v??o vector lines.
            n++;
        }
        char arr[lines[0].length() + 1];
        strcpy(arr, lines[0].c_str());
        p = strtok(arr, " ");
        while (p != NULL)
        {
            // Ch??? d???nh ?????i s??? NULL trong h??m strtok ????? ti???p t???c t??ch chu???i ban ?????u
            p = strtok(NULL, " ");

            if (p != NULL)
            {
                // printf("--%s--", p);
                if (strcmp(p, "STT") == 0 || strcmp(p, "ID") == 0 || strcmp(p, "Ten") == 0 ||
                    strcmp(p, "GioiTinh") == 0 || strcmp(p, "Tuoi") == 0 || strcmp(p, "DTB") == 0 ||
                    strcmp(p, "HocLuc") == 0)
                {
                }
                else
                {
                    MH x;
                    x.idmh = idmh;
                    for (int i = 0; i < 30; i++)
                    {
                        x.ten[i] = p[i];
                    }
                    // x.ten = p;
                    NODEMH *m = new NODEMH;
                    m = TaoNodeMH(x);
                    ChenCuoiMH(mh, m);
                    idmh++;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            idmh = 1;
            char arr[lines[i].length() + 1];
            strcpy(arr, lines[i].c_str());
            p = strtok(arr, " ");

            SV x;
            BD y;
            coll = 0;
            while (p != NULL)
            {
                p = strtok(NULL, " ");
                if (coll == 0)
                {
                    x.idsv = atoi(p);
                }
                else if (coll == 1)
                {
                    for (int i2 = 0; i2 < 30; i2++)
                    {
                        x.ten[i2] = p[i2];
                    }
                }
                else if (coll == 2)
                {
                    for (int i2 = 0; i2 < 30; i2++)
                    {
                        x.gioitinh[i2] = p[i2];
                    }
                }
                else if (coll == 3)
                {
                    x.tuoi = atoi(p);
                }
                else if (coll > 3 && coll <= (3 + SLMH(mh)))
                {
                    if (idmh <= SLMH(mh))
                    {
                        y.idsv = x.idsv;
                        y.idmh = idmh;
                        y.diem = atof(p);
                        NODEBD *z = new NODEBD;
                        z = TaoNodeBD(y);
                        ChenCuoiBD(bd, z);
                    }
                    idmh++;
                }
                else if (coll == (4 + SLMH(mh)))
                {
                    x.DTB = atof(p);
                }
                else if (coll == (5 + SLMH(mh)))
                {
                    for (int i2 = 0; i2 < 30; i2++)
                    {
                        x.hocluc[i2] = p[i2];
                    }
                }
                coll++;
            }
            NODESV *s = new NODESV;
            s = TaoNodeSV(x);
            ChenCuoiSV(sv, s);
        }
    }

    // ????ng file
    ifs.close();
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
    cout << "**  11. Sap xep mon hoc theo ten.                                           **\n";
    cout << "**  12. Sap xep sinh vien theo ten.                                         **\n";
    cout << "**  13. Sap xep sinh vien theo tuoi.                                        **\n";
    cout << "**  14. Sap xep sinh vien theo diem TB.                                     **\n";
    cout << "**  15. Sinh vien co tuoi nho nhat.                                         **\n";
    cout << "**  16. Sinh vien co tuoi lon nhat.                                         **\n";
    cout << "**  17. Sinh vien co diem trung binh nho nhat.                              **\n";
    cout << "**  18. Sinh vien co diem trung binh lon nhat.                              **\n";
    cout << "**  19. So luong sinh vien nu.                                              **\n";
    cout << "**  20. So luong sinh vien nam.                                             **\n";
    cout << "**  21. Thong ke xep loai sinh vien.                                        **\n";
    cout << "**  22. Doc file.                                                           **\n";
    cout << "**  23. Ghi file.                                                           **\n";
    cout << "**  0. Thoat                                                                **\n";
    cout << "******************************************************************************\n";
    cout << "Nhap tuy chon: ";
    scanf("%d", &x);
    return x;
}

int main()
{
    char fileName[] = "sinhvien.txt";
    LISTSV dssv;
    KhoiTaoSV(dssv);
    int idsv = 1;
    LISTMH dsmh;
    KhoiTaoMH(dsmh);
    int idmh = 1;
    LISTBD dsbd;
    KhoiTaoBD(dsbd);
    chick(dsbd);

    int key;
    bool check = true;

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
        case 11:
            cout << "\n11. Sap xep mon hoc theo ten.";
            sapXepMonHocTheoTen(dsmh);
            pressAnyKey();
            break;
        case 12:
            cout << "\n12. Sap xep sinh vien theo ten.";
            sapXepSinhVienTheoTen(dssv);
            pressAnyKey();
            break;
        case 13:
            cout << "\n13. Sap xep sinh vien theo tuoi.";
            sapXepSinhVienTheoTuoi(dssv);
            pressAnyKey();
            break;
        case 14:
            cout << "\n14. Sap xep sinh vien theo DTB.";
            sapXepSinhVienTheoDTB(dssv, dsmh, dsbd);
            pressAnyKey();
            break;
        case 15:
            cout << "\n15. Sinh vien co tuoi nho nhat.";
            sinhVienCoTuoiNhoNhat(dssv);
            pressAnyKey();
            break;
        case 16:
            cout << "\n16. Sinh vien co tuoi lon nhat.";
            sinhVienCoTuoiLonNhat(dssv);
            pressAnyKey();
            break;
        case 17:
            cout << "\n17. Sinh vien co diem trung binh nho nhat.";
            sinhVienCoDiemTrungBinhNhoNhat(dssv, dsmh, dsbd);
            pressAnyKey();
            break;
        case 18:
            cout << "\n18. Sinh vien co dien trung binh lon nhat.";
            sinhVienCoDiemTrungBinhLonNhat(dssv, dsmh, dsbd);
            pressAnyKey();
            break;
        case 19:
            cout << "\n19. So luong sinh vien nu.";
            printLine(100);
            printf("\n\n\tSo luong sinh vien nu: %d\n\n", soLuongSinhVienNu(dssv));
            printLine(100);
            pressAnyKey();
            break;
        case 20:
            cout << "\n20. So luong sinh vien nam.";
            printLine(100);
            printf("\n\n\tSo luong sinh vien nam: %d\n\n", soLuongSinhVienNam(dssv));
            printLine(100);
            pressAnyKey();
            break;
        case 21:
            cout << "\n21. Thong ke xep loai sinh vien.";
            thongKeXepLoaiSinhVien(dssv);
            pressAnyKey();
            break;
        case 22:
            cout << "\n22. Doc file.";
            printLine(100);
            check = true;
            if (SLSV(dssv) > 0 || SLMH(dsmh) > 0 || SLBD(dsbd) > 1)
            {
                char flag[5], temp[5] = "yes";
                cin.ignore(1);
                printf("\n\n\tDanh sach hien dang co du lieu.\n\tDoc file len co the bi trung du lieu.\n\tBan co dong y xoa het du lieu roi doc file khong? (Yes/No): ");
                cin.getline(flag, 5);
                fflush(stdin);
                if (strcmp(strupr(flag), strupr(temp)) == 0)
                {
                    xoaAllBd(dsbd);
                    xoaAllMh(dsmh);
                    xoaAllSv(dssv);
                }
                else
                {
                    check = false;
                    printf("\n\tBan da tu choi su dung chuc nang nay!!!");
                }
            }

            if (check)
            {
                printf("\nBegin read file.");
                docFile(dssv, dsmh, dsbd, fileName);
                idmh = idlnmh(dsmh) + 1;
                idsv = idlnsv(dssv) + 1;
                printf("%d", idmh);
                printf("%d", idsv);
                printf("\nRead file success.");
            }
            printLine(100);
            pressAnyKey();
            break;
        case 23:
            printLine(100);
            if (SLSV(dssv) > 0)
            {
                cout << "\n23. Ghi file.";
                ghiFile(dssv, dsmh, dsbd, fileName);
                printf("\n\tGhi danh sach sinh vien vao file %s thanh cong!", fileName);
            }
            else
            {
                cout << "\nDanh sach sinh vien trong!";
            }
            printLine(100);
            pressAnyKey();
            break;
        case 99:
            cout << "\n99. Hien thi bang diem.";
            hienThiBD(dsbd);
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
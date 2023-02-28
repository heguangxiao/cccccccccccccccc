#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Clothing {
    string name;
    int size;
    int price;
};

struct Node {
    Clothing info;
    Node *next;
};

struct LIST {
    Node *head;
    Node *tail;
};

struct Invoice {
    string customerName;
    int quantity;
    int totalAmount;
};

struct DNode {
    Invoice info;
    DNode *next;
    DNode *prev;
};

struct DLIST {
    DNode *head;
    DNode *tail;
};

// Quần áo
void addClothing(LIST &lst, Clothing cloth) {
    Node *p = new Node;
    p->info = cloth;
    p->next = NULL;
    if (lst.head == NULL) {
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

bool updateClothing(LIST &lst) {
    Clothing newCloth;
    string name;
    cout << "Enter name clothing:" << endl;
    cin >> name;
    cout << "Enter clothing item :" << endl;
    cout << "Name: ";
    cin >> newCloth.name;
    cout << "Size: ";
    cin >> newCloth.size;
    cout << "Price: ";
    cin >> newCloth.price;
    Node *p = lst.head;
    while (p != NULL) {
        if (p->info.name == name) {
            p->info = newCloth;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool removeClothing(LIST &lst) {
    string name;
    cout << "Enter name clothing:" << endl;
    cin >> name;
    // Nếu danh sách rỗng, không làm gì cả
    if (lst.head == NULL) {
        cout << "Empty clothing:" << endl;
        return false;
    }

    // Nếu đối tượng cần xóa là đầu danh sách
    if (lst.head->info.name == name) {
        Node *p = lst.head;
        lst.head = lst.head->next;
        delete p;
        cout << "delete clothing success" << endl;
        return true;
    }

    // Nếu đối tượng cần xóa nằm ở giữa danh sách hoặc cuối danh sách
    Node *p = lst.head->next;
    Node *prev = lst.head;
    while (p != NULL) {
        if (p->info.name == name) {
            prev->next = p->next;
            if (p == lst.tail) {
                lst.tail = prev;
            }
            delete p;
            cout << "delete clothing success" << endl;
            return true;
        }
        prev = p;
        p = p->next;
    }
    cout << "delete clothing fail" << endl;
    return false;
}

void addClothing(LIST lst) {
    Clothing cloth;
    cout << "Enter clothing item :" << endl;
    cout << "Name: ";
    cin >> cloth.name;
    cout << "Size: ";
    cin >> cloth.size;
    cout << "Price: ";
    cin >> cloth.price;
    addClothing(lst, cloth);
}

// Hàm tìm kiếm theo tên
void searchByName(LIST &list) {
    string name;
    cout << "Search by name: ";
    cin >> name;

    Node *p = list.head;
    bool found = false;
    while (p != NULL) {
        if (p->info.name == name) {
            cout << "Found: " << p->info.name << ", " << p->info.size << ", " << p->info.price << endl;
            found = true;
        }
        p = p->next;
    }
    if (!found) {
        cout << "Not found." << endl;
    }
}

// Hàm tìm kiếm theo giá
void searchByPrice(LIST &list) {
    int price;
    cout << "Search by name: ";
    cin >> price;

    Node *p = list.head;
    bool found = false;
    while (p != NULL) {
        if (p->info.price == price) {
            cout << "Found: " << p->info.name << ", " << p->info.size << ", " << p->info.price << endl;
            found = true;
        }
        p = p->next;
    }
    if (!found) {
        cout << "Not found." << endl;
    }
}

// Sắp xếp theo tên
void sortClothingByName(LIST &lst) {
    Node *i, *j, *prev_j;
    Clothing key;

    if (lst.head == nullptr || lst.head->next == nullptr) {
        // danh sách rỗng hoặc chỉ có một phần tử
        return;
    }

    i = lst.head->next;
    while (i != nullptr) {
        key = i->info;
        j = lst.head;
        prev_j = nullptr;

        // tìm vị trí chèn phần tử key vào danh sách đã sắp xếp trước đó
        while (j != i && key.name > j->info.name) {
            prev_j = j;
            j = j->next;
        }

        if (j != i) {
            // cần chèn key vào trước j
            i->next = j;
            if (prev_j != nullptr) {
                prev_j->next = i;
            } else {
                lst.head = i;
            }
        }

        // chuyển sang phần tử tiếp theo để sắp xếp
        i = i->next;
    }

    // cập nhật tail
    Node *p = lst.head;
    while (p->next != nullptr) {
        p = p->next;
    }
    lst.tail = p;
}

// sắp xếp theo giá
void sortClothingByPrice(LIST &lst) {
    Node *i, *j, *prev_j;
    Clothing key;

    if (lst.head == nullptr || lst.head->next == nullptr) {
        // danh sách rỗng hoặc chỉ có một phần tử
        return;
    }

    i = lst.head->next;
    while (i != nullptr) {
        key = i->info;
        j = lst.head;
        prev_j = nullptr;

        // tìm vị trí chèn phần tử key vào danh sách đã sắp xếp trước đó
        while (j != i && key.price > j->info.price) {
            prev_j = j;
            j = j->next;
        }

        if (j != i) {
            // cần chèn key vào trước j
            i->next = j;
            if (prev_j != nullptr) {
                prev_j->next = i;
            } else {
                lst.head = i;
            }
        }

        // chuyển sang phần tử tiếp theo để sắp xếp
        i = i->next;
    }

    // cập nhật tail
    Node *p = lst.head;
    while (p->next != nullptr) {
        p = p->next;
    }
    lst.tail = p;
}

void sortListByName(DLIST &list) {
    if (list.head == nullptr || list.head == list.tail) {
        // Danh sách rỗng hoặc chỉ có một phần tử
        return;
    }

    DNode *curr = list.head->next;

    while (curr != nullptr) {
        // Lưu trữ nút hiện tại
        DNode *temp = curr;

        // Lấy customerName của nút hiện tại
        string name = curr->info.customerName;

        // Duyệt về phía trước danh sách liên kết để tìm nút phù hợp để chèn
        while (temp->prev != nullptr && temp->prev->info.customerName > name) {
            // Di chuyển nút temp về phía trước
            temp = temp->prev;
        }

        // Kiểm tra xem nút temp đã đến đầu danh sách liên kết chưa
        if (temp->prev == nullptr && temp->info.customerName > name) {
            // Nút hiện tại cần chèn vào đầu danh sách liên kết
            curr->prev->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            } else {
                list.tail = curr->prev;
            }
            curr->prev = nullptr;
            curr->next = temp;
            temp->prev = curr;
            list.head = curr;
        } else if (temp != curr) {
            // Chèn nút hiện tại vào giữa danh sách liên kết
            curr->prev->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            } else {
                list.tail = curr->prev;
            }
            curr->prev = temp->prev;
            curr->next = temp;
            temp->prev->next = curr;
            temp->prev = curr;
        }

        // Di chuyển đến nút tiếp theo trong danh sách liên kết
        curr = curr->next;
    }
}

void sortListByTotalAmount(DLIST &list) {
    // Trường hợp danh sách rỗng hoặc chỉ có một nút
    if (list.head == nullptr || list.head == list.tail) {
        return;
    }

    // Duyệt từ nút thứ hai đến nút cuối cùng
    DNode *curr = list.head->next;
    while (curr != nullptr) {
        Invoice tmp = curr->info;
        DNode *prev = curr->prev;

        // Duyệt từ nút hiện tại về đầu danh sách liên kết, tìm vị trí chèn tmp vào
        while (prev != nullptr && prev->info.totalAmount > tmp.totalAmount) {
            prev->next->info = prev->info;
            prev = prev->prev;
        }

        // Chèn tmp vào danh sách liên kết
        if (prev == nullptr) {
            // Chèn tmp vào đầu danh sách liên kết
            list.head->info = tmp;
        } else {
            prev->next->info = tmp;
        }

        curr = curr->next;
    }
}

void displayClothing(Clothing p) {
    cout << "Name: " << p.name << ", Size: " << p.size << ", Price: " << p.price << endl;
}

// Tìm phần tử lớn nhất trong danh sách liên kết đơn
void findMaxByPrice(LIST list) {
    // Trường hợp danh sách rỗng
    if (list.head == nullptr) {
        displayClothing(Clothing{"", 0, 0});
    } else {
        // Duyệt danh sách liên kết đơn từ đầu đến cuối để tìm phần tử lớn nhất
        Node *curr = list.head;
        Clothing maxClothing = curr->info;
        while (curr != nullptr) {
            if (curr->info.price > maxClothing.price) {
                maxClothing = curr->info;
            }
            curr = curr->next;
        }
        displayClothing(maxClothing);
    }
}

// Tìm phần tử nhỏ nhất trong danh sách liên kết đơn
void findMinByPrice(LIST list) {
    // Trường hợp danh sách rỗng
    if (list.head == nullptr) {
        displayClothing(Clothing{"", 0, 0});
    } else {
        // Duyệt danh sách liên kết đơn từ đầu đến cuối để tìm phần tử nhỏ nhất
        Node *curr = list.head;
        Clothing minClothing = curr->info;
        while (curr != nullptr) {
            if (curr->info.price < minClothing.price) {
                minClothing = curr->info;
            }
            curr = curr->next;
        }
        displayClothing(minClothing);
    }
}

// Hàm tính tổng giá trị của các sản phẩm
void sum(LIST list) {
    int sum = 0;
    Node *p = list.head;
    while (p != NULL) {
        sum += p->info.price;
        p = p->next;
    }
    cout << "Tong tien mat hang 'QUAN-AO' : " << sum << " VND";
}

// Hàm tính trung bình giá trị của các sản phẩm
void average(LIST list) {
    if (list.head == NULL) {
        cout << "Tong tien trung bình mat hang 'QUAN-AO' : " << 0 << " VND";
    } else {
        int sum = 0, count = 0;
        Node *p = list.head;
        while (p != NULL) {
            sum += p->info.price;
            count++;
            p = p->next;
        }
        cout << "Tong tien trung bình mat hang 'QUAN-AO' : " << (float) sum / count << " VND";
    }

}

// Hàm đếm số lượng sản phẩm trong danh sách
void count(LIST list) {
    int count = 0;
    Node *p = list.head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    cout << "So luong 'QUAN-AO' co trong he thong : " << count << " chiec";
}

// Hàm tính tổng giá trị của các sản phẩm có kích cỡ nhỏ hơn một giá trị cho trước
void sumBySize(LIST list) {
    int sizeLimit;
    cout << "Size limit : ";
    cin >> sizeLimit;

    int sum = 0;
    Node *p = list.head;
    while (p != NULL) {
        if (p->info.size < sizeLimit) {
            sum += p->info.price;
        }
        p = p->next;
    }

    cout << "Tong tien 'QUAN-AO' co size nho hon  " << sizeLimit << " = " << sum << " VND";
}

// Hàm tính số lượng sản phẩm có giá trị lớn hơn một giá trị cho trước
void countByPrice(LIST list) {
    int priceLimit;
    cout << "Size limit : ";
    cin >> priceLimit;

    int count = 0;
    Node *p = list.head;
    while (p != NULL) {
        if (p->info.price > priceLimit) {
            count++;
        }
        p = p->next;
    }
    cout << "So luong 'QUAN-AO' co gia lon hon  " << priceLimit << " = " << count << " chiec.";
}


void displayClothing(LIST lst) {
    cout << "List of clothing: " << endl;
    Node *p = lst.head;
    while (p != NULL) {
        cout << "Name: " << p->info.name << ", Size: " << p->info.size << ", Price: " << p->info.price << endl;
        p = p->next;
    }
}


void inputClothingList(LIST &lst) {
    int n;
    cout << "Enter the number of clothing items: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Clothing cloth;
        cout << "Enter clothing item #" << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> cloth.name;
        cout << "Size: ";
        cin >> cloth.size;
        cout << "Price: ";
        cin >> cloth.price;
        addClothing(lst, cloth);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////// Hóa đơn
/**
 *
 *
 *
 *
 *
 * //////////////////////////////////////////////////////////////////////////////////////////////////
 *
 *
 *
 *
 * /////////////////////////////////////////////////////////////////////////////////////////////
 * */

void addInvoice(DLIST &dlst, Invoice inv) {
    DNode *p = new DNode;
    p->info = inv;
    p->next = NULL;
    p->prev = dlst.tail;
    if (dlst.head == NULL) {
        dlst.head = dlst.tail = p;
    } else {
        dlst.tail->next = p;
        dlst.tail = p;
    }
}

void addInvoice(DLIST &dlst) {
    Invoice inv;
    cout << "Enter invoice " << endl;
    cout << "Customer name: ";
    cin >> inv.customerName;
    cout << "Quantity: ";
    cin >> inv.quantity;
    cout << "TotalAmount: ";
    cin >> inv.totalAmount;
    addInvoice(dlst, inv);
}


void displayInvoice(Invoice p) {
    cout << "Customer name: " << p.customerName << ", Total amount: " << p.totalAmount << ", Quantity: "
         << p.totalAmount << endl;
}

// Hàm cập nhật thông tin của một đối tượng Hóa đơn trong danh sách
bool updateInvoice(DLIST &lst) {
    string customerName;
    Invoice newIn;

    cout << "Customer name: ";
    cin >> newIn.customerName;

    cout << "Enter invoice " << endl;
    cout << "New customer name: ";
    cin >> newIn.customerName;
    cout << "Quantity: ";
    cin >> newIn.quantity;
    cout << "TotalAmount: ";
    cin >> newIn.totalAmount;

    DNode *p = lst.head;
    while (p != NULL) {
        if (p->info.customerName == customerName) {
            p->info = newIn;
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hàm xóa một đối tượng Hóa đơn trong danh sách
bool removeInvoice(DLIST &lst) {
    string customerName;
    cout << "Customer name: ";
    cin >> customerName;

    DNode *p = lst.head;
    while (p != NULL) {
        if (p->info.customerName == customerName) {
            if (p == lst.head && p == lst.tail) {
                lst.head = lst.tail = NULL;
            } else if (p == lst.head) {
                lst.head = p->next;
                lst.head->prev = NULL;
            } else if (p == lst.tail) {
                lst.tail = p->prev;
                lst.tail->next = NULL;
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p;
            return true;
        }
        p = p->next;
    }
    return false;
}

void *searchInvoiceByName(DLIST DQ) {
    string customerName;
    cout << "Search by customer name: ";
    cin >> customerName;

    DNode *p;
    p = DQ.head;
    while (p != NULL) {
        if (p->info.customerName == customerName) {
            cout << "Found: " << p->info.customerName << ", " << p->info.quantity << ", " << p->info.totalAmount
                 << endl;
        }
        p = p->next;
    }
}

void findMaxByTotalAmount(DLIST list) {
    // Trường hợp danh sách rỗng
    if (list.head == nullptr) {
        displayInvoice(Invoice{"", 0, 0});
    } else {
        // Duyệt danh sách liên kết kép từ đầu đến cuối để tìm phần tử lớn nhất
        DNode *curr = list.head;
        Invoice maxInvoice = curr->info;
        while (curr != nullptr) {
            if (curr->info.totalAmount > maxInvoice.totalAmount) {
                maxInvoice = curr->info;
            }
            curr = curr->next;
        }
        displayInvoice(maxInvoice);
    }
}

Invoice findMinTotalAmount(DLIST list) {
    // Trường hợp danh sách rỗng
    if (list.head == nullptr) {
        displayInvoice(Invoice{"", 0, 0});
    } else {
        // Duyệt danh sách liên kết kép từ đầu đến cuối để tìm phần tử nhỏ nhất
        DNode *curr = list.head;
        Invoice minInvoice = curr->info;
        while (curr != nullptr) {
            if (curr->info.totalAmount < minInvoice.totalAmount) {
                minInvoice = curr->info;
            }
            curr = curr->next;
        }
        displayInvoice(minInvoice);
    }
}

//Tính tổng của trường totalAmount của các Invoice trong danh sách liên kết kép
void getTotal(DLIST list) {
    // Trường hợp danh sách rỗng
    if (list.head == nullptr) {
        cout << "Tong tien 'HOA DON' : " << 0 << " VND";
    } else {
        // Duyệt danh sách liên kết kép từ đầu đến cuối để tính tổng
        DNode *curr = list.head;
        int total = 0;
        while (curr != nullptr) {
            total += curr->info.totalAmount;
            curr = curr->next;
        }
        cout << "Tong tien 'HOA DON' : " << total << " VND";
    }
}

// Tính trung bình của trường totalAmount của các Invoice trong danh sách liên kết kép
void getAverage(DLIST list) {
    // Trường hợp danh sách rỗng
    if (list.head == nullptr) {
        cout << "Tong tien trung binh 'HOA DON'" << 0 << " VND";
    } else {
        // Tính tổng và đếm số lượng phần tử trong danh sách liên kết kép
        int total = 0;
        int count = 0;
        DNode *curr = list.head;
        while (curr != nullptr) {
            total += curr->info.totalAmount;
            count++;
            curr = curr->next;
        }

        cout << "Tong tien trung binh 'HOA DON'" << (float) total / count << " VND";
    }
}

// Đếm số lượng phần tử trong danh sách liên kết kép
int getCount(DLIST list) {
    // Trường hợp danh sách rỗng
    if (list.head == nullptr) {
        cout << "So luong 'HOA DON' : " << 0;
        return 0;
    } else {
        // Duyệt danh sách liên kết kép từ đầu đến cuối để đếm số lượng phần tử
        int count = 0;
        DNode *curr = list.head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        cout << "So luong 'HOA DON' : " << count;
    }
}

// Thống kê những hóa đơn có totalAmount lớn hơn 50.000
void findLargeInvoices(DLIST list) {
    DNode *p = list.head;
    bool found = false;
    cout << "Cac hoa don co gia tri lon hon 50000:" << endl;
    while (p != NULL) {
        if (p->info.totalAmount > 50000) {
            found = true;
            cout << "Hoa don cua khach hang " << p->info.customerName << " co gia tri " << p->info.totalAmount << endl;
        }
        p = p->next;
    }
    if (!found) {
        cout << "Khong co hoa don nao co gia tri lon hon 50000." << endl;
    }
}

// Thống kê Khách hàng A mua bao nhiêu sản phẩm
void countProductByCustomerName(DLIST list) {
    string customerName;
    cout << "Nhap tien khach hang \n";
    cin >> customerName;

    int count = 0;
    DNode *p = list.head;
    while (p != NULL) {
        if (p->info.customerName == customerName) {
            count += p->info.quantity;
        }
        p = p->next;
    }
    cout << "Khach hang " << customerName << "da mua " << count << " san pham.";
}

void displayInvoice(DLIST dlst) {
    cout << "List of invoices: " << endl;
    DNode *p = dlst.head;
    while (p != NULL) {
        cout << "Customer name: " << p->info.customerName << ", Total amount: " << p->info.totalAmount << ", Quantity: "
             << p->info.totalAmount << endl;
        p = p->next;
    }
}


void inputInvoiceList(DLIST &lst) {
    int n;
    cout << "Enter the number of invoices: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Invoice inv;
        cout << "Enter invoice #" << i + 1 << ":" << endl;
        cout << "Customer name: ";
        cin >> inv.customerName;
        cout << "Quantity: ";
        cin >> inv.quantity;
        cout << "TotalAmount: ";
        cin >> inv.totalAmount;
        addInvoice(lst, inv);
    }
}


int main() {
    LIST clothingList;
    DLIST invoiceList;
    clothingList.head = NULL;
    clothingList.tail = NULL;
    invoiceList.head = NULL;
    invoiceList.tail = NULL;

    int choice, choice1, choice2, choice3, choice4, choice5, choice6, choice7;
    do {
        cout << "Menu:\n";
        cout << "1. Nhap-In danh sach 'Quan ao' - 'Hoa don' .\n";
        cout << "2. Thêm -  sửa - xóa hàng hóa.\n";
        cout << "3. Tìm kiếm.\n";
        cout << "4. Sắp xếp mặt hàng \n";
        cout << "5. Tìm kiếm phần tử lớn nhất, nhỏ nhất. \n";
        cout << "6. Tính tổng, trung bình và đếm mặt hàng . \n";
        cout << "7.Thống kê. \n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice) {
            case 1:
                do {
                    cout << "MENU CHUC NANG 1:\n";
                    cout << "1.1 Nhap danh sach 'QUAN-AO'\n";
                    cout << "1.2 Nhap danh sach 'HOA DON'\n";
                    cout << "1.3 Hien thi danh sach 'QUAN-AO'\n";
                    cout << "1.4 Hien thi danh sach 'HOA DON'\n";
                    cout << "1.5 Luu file danh sach 'QUAN-AO'\n";
                    cout << "1.6 Luu file danh sach 'HOA DON'\n";
                    cout << "0. Tro ve\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice1;
                    switch (choice1) {
                        case 1:
                            inputClothingList(clothingList);
                            break;
                        case 2:
                            inputInvoiceList(invoiceList);
                            break;
                        case 3:
                            displayClothing(clothingList);
                            break;
                        case 4:
                            displayInvoice(invoiceList);
                            break;
                        case 5:
                            // Code cho chuc nang 1.3
                            break;
                        case 6:
                            // Code cho chuc nang 1.3
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    }
                } while (choice1 != 0);
                break;
            case 2:
                // Code cho chuc nang 2
                do {
                    cout << "MENU CHUC NANG 2:\n";
                    cout << "2.1 Them QUAN-AO  \n";
                    cout << "2.2 Sua QUAN-AO theo ten \n";
                    cout << "2.3 Xoa 'QUAN-AO' theo ten\n";
                    cout << "2.4 Them 'HOA DON'\n";
                    cout << "2.5 Sua 'HOA DON' theo ten khach hang\n";
                    cout << "2.6 Xoa 'HOA DON' theo ten khach hang\n";
                    cout << "0. Tro ve\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice2;
                    switch (choice2) {
                        case 1:
                            addClothing(clothingList);
                            break;
                        case 2:
                            updateClothing(clothingList);
                            break;
                        case 3:
                            removeClothing(clothingList);
                            break;
                        case 4:
                            addInvoice(invoiceList);
                            break;
                        case 5:
                            updateInvoice(invoiceList);
                            break;
                        case 6:
                            removeInvoice(invoiceList);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    }
                } while (choice2 != 0);
                break;
            case 3:
                do {
                    cout << "MENU CHUC NANG 3:\n";
                    cout << "3.1 Tim kiem 'QUAN-AO' theo ten  \n";
                    cout << "3.2 Tim kiem 'HOA DON' theo ten khach hang \n";
                    cout << "0. Tro ve\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice3;
                    switch (choice3) {
                        case 1:
                            searchByName(clothingList);
                            break;
                        case 2:
                            searchInvoiceByName(invoiceList);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    }
                } while (choice3 != 0);
                break;
            case 4:
                do {
                    cout << "MENU CHUC NANG 4:\n";
                    cout << "4.1 Sap xem 'QUAN-AO' theo ten ten san pham\n";
                    cout << "4.2 Sap xem 'QUAN-AO' theo gia tien\n";
                    cout << "4.3 Sap xep 'HOA DON' theo ten khach hang \n";
                    cout << "4.4 Sap xep 'HOA DON' theo tong tien hoa don\n";
                    cout << "0. Tro ve\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice4;
                    switch (choice4) {
                        case 1:
                            sortClothingByName(clothingList);
                            break;
                        case 2:
                            sortClothingByPrice(clothingList);
                            break;
                        case 3:
                            sortListByName(invoiceList);
                            break;
                        case 4:
                            sortListByTotalAmount(invoiceList);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    }
                } while (choice4 != 0);
                break;
            case 5:
                do {
                    cout << "MENU CHUC NANG 5:\n";
                    cout << "5.1 'QUAN-AO' co gia cao nhat\n";
                    cout << "5.2 'QUAN-AO' co gia thap nhat\n";
                    cout << "5.3 'HOA DON' co don gia cao nhat \n";
                    cout << "5.4 'HOA DON' co don gia cao nhat\n";
                    cout << "0. Tro ve\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice5;
                    switch (choice5) {
                        case 1:
                            findMaxByPrice(clothingList);
                            break;
                        case 2:
                            findMinByPrice(clothingList);
                            break;
                        case 3:
                            findMaxByTotalAmount(invoiceList);
                            break;
                        case 4:
                            findMinTotalAmount(invoiceList);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    }
                } while (choice5 != 0);
                break;
            case 6:
                do {
                    cout << "MENU CHUC NANG 6:\n";
                    cout << "6.1 Tong tien mat hang 'QUAN-AO'\n";
                    cout << "6.2 Tong tien trung binh mat hang 'QUAN-AO'\n";
                    cout << "6.3 So luong 'QUAN-AO' co trong he thong\n";
                    cout << "6.4 Tong tien 'HOA DON'\n";
                    cout << "6.5 Tong tien trung binh 'HOA DON'\n";
                    cout << "6.6 So luong 'HOA DON' \n";
                    cout << "0. Tro ve\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice6;
                    switch (choice6) {
                        case 1:
                            sum(clothingList);
                            break;
                        case 2:
                            average(clothingList);
                            break;
                        case 3:
                            count(clothingList);
                            break;
                        case 4:
                            getTotal(invoiceList);
                            break;
                        case 5:
                            getAverage(invoiceList);
                            break;
                        case 6:
                            getCount(invoiceList);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    }
                } while (choice6 != 0);
                break;
            case 7:
                do {
                    cout << "MENU CHUC NANG 7:\n";
                    cout << "7.1 Tong tien mat hang 'QUAN-AO' co size nho hon 12\n";
                    cout << "7.2 Tong tien mat hang 'QUAN-AO' co gia lon hon 10.000 VND\n";
                    cout << "7.3 Nhung 'HOA DON' có tong gia lớn hơn 50.000\n";
                    cout << "7.4 Thong ke khach hang mua bao nhieu 'HOA DON'\n";
                    cout << "0. Tro ve\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice7;
                    switch (choice7) {
                        case 1:
                            sumBySize(clothingList);
                            break;
                        case 2:
                            countByPrice(clothingList);
                            break;
                        case 3:
                            findLargeInvoices(invoiceList);
                            break;
                        case 4:
                            countProductByCustomerName(invoiceList);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                    }
                } while (choice7 != 0);
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
using namespace std;
class Hotel {
private:
    struct Node {
        int id, date;
        string name, roomtype;
        Node* next;
    };

public:
    Node* head = NULL;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void sort();
    void show();
    void list();
};
void Hotel::menu() {
p:
    int choice;
    cout << "\n";
    cout << "\tWelcome to hotel management system applications\n" << endl;
    cout << "\n\t_______Hotel Mangement System________";
    cout << "\n\nS.No   Functions                          Description" << endl;
    cout << "\n1\tAllocate Room\t\t\tInsert New Room";
    cout << "\n2\tSearch Room\t\t\t Search Room with RommID";
    cout << "\n3\tUpdate Room\t\t\t Update Room Record";
    cout << "\n4\tDelete Room\t\t\t Delete Room with RoomID";
    cout << "\n5\tShow Room Records\t\t\tShow Roome Records that (we add)";
    cout << "\n6\Exit" << endl;

    cout << "Enter Your Choise" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        insert();
        break;
    case 2:
        search();
        break;
    case 3:
        update();
        break;
    case 4:
        del();
        break;
    case 5:
        show();
        break;
    case 6:
        exit(0);
    default:
        cout << "Invalid"; 
    }
}

void Hotel::insert() {
    cout << "\n\t__________Hotel Management System_________";
    Node* new_Node = new Node;
    cout << "\nEnter Room ID" << endl;
    cin >> new_Node->id;
    cout << "\nEnter Customer Name" << endl;
    cin >> new_Node->name;
    cout << "\nEnter Allocated Date" << endl;
    cin >> new_Node->date;
    cout << "\nEnter Room Type(single/double/twin)" << endl;
    cin >> new_Node->roomtype;

    if (head == NULL) {
        head = new_Node;
    }
    else
    {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_Node;
    }

    cout << "\n\n\t\t New Room Inserted";
}

void Hotel::search() {
    cout << "\n\t__________Hotel Management System_________";
    int t_id;

    if (head == NULL) {
        cout << "\n\nLinked list is Empty";
    }
    else
    {
        cout << "\n\nRoom ID";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL) {
            if (t_id == ptr->id)
            {
                cout << "\n\nRoom ID" << ptr->id;
                cout << "\n\nCustomer Name" << ptr->name;
                cout << "\n\nRoom Allocated Date" << ptr->date;
                cout << "\n\nRoom Type" << ptr->roomtype;
            }
            ptr = ptr->next;
        }
    }
}

void Hotel::update() {
    cout << "\n\t__________Hotel Management System_________";
    int t_id;

    if (head == NULL) {
        cout << "\n\nLinked list is Empty";
    }
    else
    {
        cout << "\n\nRoom ID";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL) {
            if (t_id == ptr->id)
            {
                cout << "\n\nNew Room ID";
                cin >> ptr->id;
                cout << "\n\nNew Customer Name";
                cin >> ptr->name;
                cout << "\n\nNew Room Allocated Date" << ptr->date;
                cin >> ptr->date;
                cout << "\n\nNew RoomType";
                cin >> ptr->roomtype;

                cout << "\n\n\t\t Update Record Successfully";
            }
            ptr = ptr->next;
        }
    }
}

void Hotel::del() {
    cout << "\n\t__________Hotel Management System_________";
    int t_id;

    if (head == NULL) {
        cout << "\n\nLinked list is Empty";
    }
    else {
        cout << "\n\nRoom ID";
        cin >> t_id;
        if (t_id == head->id)
        {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Delete Room Record Successfuly\n"; 
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while (ptr!=NULL)
            {
                if (t_id == ptr->id) {
                    pre->next = ptr->next;
                    delete ptr;
                    cout << "Delete Room Record Successfully\n";
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }
}

void Hotel::show() {
    Node* ptr = head;
    while (ptr!=NULL)
    {
        cout << "\n\nRoomID" << ptr->id;
        cout << "\n\nCustomer Name" << ptr->name;
        cout << "\n\nAllocated Date" << ptr->date;
        cout << "\n\nRoom Type" << ptr->roomtype;
        ptr = ptr->next;
    }
}

void Hotel::sort() {
    if (head == NULL)
    {
        cout << "\n\nLinked list is Empty";
        menu();
    }
    int count = 0, t_date, t_id;
    string t_name, t_roomtype;
    Node* ptr = head;
    while (ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    for (int i = 0; i <=count; i++)
    {
        Node* ptr = head;
        for (int j = 0; j < count; j++)
        {
            if (ptr->id > ptr->next->id)
            {
                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;
                //Save Date Into Current Node
                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->date = ptr->next->date;
                ptr->roomtype = ptr->next->roomtype;
                //Save data into Next Node
                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->date = t_date;
                ptr->next->roomtype = t_roomtype;
            }
        }
    }
}

int main() {
    Hotel h;
    h.menu();
}
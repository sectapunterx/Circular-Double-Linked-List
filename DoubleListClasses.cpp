#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct LiveArea {
    string name;
    string population;
    string area;
    string republic;
    string region;
    string okrug;
    string animals;
    string forests;
    string rivers;
    string lakes;
};

class Node {
public:
    LiveArea* data;
    Node* next;
    Node* prev;

    Node() {
        data = new LiveArea;
        next = nullptr;
        prev = nullptr;
    }

    void create_node() const {
        cout << "Enter the name of the okrug: ";
        cin >> this->data->name;
    }
};

class List {
public:
    Node* head;
    Node* current;

    List() {
        head = nullptr;
        current = nullptr;
    }

    [[nodiscard]] bool isEmpty() const {
        if (this->head == nullptr) {
            cout << "List is empty" << endl;
            return true;
        }
        cout << "List is not empty" << endl;
        return false;
    }

    int size() const {
        int size = 0;
        if (this->head == nullptr) {
            cout << "List is empty" << endl;
            return size;
        }
        Node* temp = this->head;
        do {
            size++;
            temp = temp->next;
        } while (temp != this->head);
        cout << "Size of list: " << size << endl;
        return size;
    }

    void add_back() {
        if (this->head == nullptr) {
            this->head = new Node;
            this->head->create_node();
            this->head->prev = this->head;
            this->head->next = this->head;
            this->current = this->head;
            cout << "Element added to end of list, its address: " << this->head << endl;
            cout << "You have switched to the created element. Previous element: " << this->head->prev << endl;
        } else {
            Node* temp = new Node;
            temp->create_node();
            temp->prev = this->current;
            temp->next = this->head;
            this->current->next = temp;
            this->head->prev = temp;
            this->current = temp;
            cout << "Element added to end of list, its address: " << this->current << endl;
            cout << "You have switched to the created element. Previous element: " << this->current->prev << endl;
        }
    }

    void clear() {
        if (this->head == nullptr) {
            cout << "List is already empty" << endl;
            return;
        }
        Node* temp = this->head;
        do {
            Node* next = temp->next;
            delete temp;
            temp = next;
        } while (temp != this->head);
        this->head = nullptr;
        this->current = nullptr;
        cout << "List cleared" << endl;
    }

    void next() {
        if (this->head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        this->current = this->current->next;
        cout << "Next element: " << this->current << endl;
        cout << "You have switched to the next element. Previous element: " << this->current->prev << endl;
    }

    void prev() {
        if (this->head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        this->current = this->current->prev;
        cout << "Previous element: " << this->current << endl;
        cout << "You have switched to the previous element. Next element: " << this->current->next << endl;
    }
    void print_data() const {
        if (this->head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        cout << "Name: " << this->current->data->name << endl;
        cout << "Population: " << this->current->data->population << endl;
        cout << "Area: " << this->current->data->area << endl;
        cout << "Republic: " << this->current->data->republic << endl;
        cout << "Region: " << this->current->data->region << endl;
        cout << "Okrug: " << this->current->data->okrug << endl;
        cout << "Animals: " << this->current->data->animals << endl;
        cout << "Forests: " << this->current->data->forests << endl;
        cout << "Rivers: " << this->current->data->rivers << endl;
        cout << "Lakes: " << this->current->data->lakes << endl;
    }
    void delete_current() {
        if (this->head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = this->current;
        if (temp == this->head && temp->next == this->head) {
            this->head = nullptr;
            this->current = nullptr;
            delete temp;
            cout << "Current element deleted" << endl;
            return;
        }
        if (temp == this->head) {
            this->head = this->head->next;
            this->current = this->head;
            this->head->prev = temp->prev;
            temp->prev->next = this->head;
            delete temp;
            cout << "Current element deleted" << endl;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        this->current = temp->next;
        delete temp;
        cout << "Current element deleted" << endl;
    }

    void insert(bool left) {
        if (this->head == nullptr) {
            this->head = new Node;
            this->head->create_node();
            this->head->prev = this->head;
            this->head->next = this->head;
            this->current = this->head;
            cout << "Element inserted to " << (left ? "left" : "right") << " of current element, its address: " << this->head << endl;
            cout << "You have switched to the created element. " << (left ? "Previous" : "Next") << " element: " << (left ? this->head->prev : this->head->next) << endl;
            return;
        }
        Node* temp = new Node;
        temp->create_node();
        temp->prev = this->current;
        temp->next = this->current->next;
        this->current->next->prev = temp;
        this->current->next = temp;
        if (!left) this->current = temp;
        cout << "Element inserted to " << (left ? "left" : "right") << " of current element, its address: " << this->current << endl;
        cout << "You have switched to the created element. " << (left ? "Previous" : "Next") << " element: " << (left ? this->current->prev : this->current->next) << endl;
    }

};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    List list;

    int choice;
    while (true)
    {
        cout << "Menu:\n1. Check if list is empty\n2. Determine size of list\n3. Add element to end of list\n4. Clear list\n5. Go to next element\n6. Go to previous element\n7. Read information about current element\n8. Delete current element\n9. Insert element to the left or right of current element\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                list.isEmpty();
                break;
            case 2:
                list.size();
                break;
            case 3:
                list.add_back();
                break;
            case 4:
                list.clear();
                break;
            case 5:
                list.next();
                break;
            case 6:
                list.prev();
                break;
            case 7:
                list.print_data();
                break;
            case 8:
                list.delete_current();
                break;
            case 9:
                cout << "Insert element to the (L)eft or (R)ight of current element: ";
                char pos;
                cin >> pos;
                if (pos == 'L') {
                    list.insert(true);
                } else if (pos == 'R') {
                    list.insert(false);
                } else {
                    cout << "Invalid input" << endl;
                }
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}


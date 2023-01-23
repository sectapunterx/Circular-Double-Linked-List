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

struct Node {
    LiveArea* data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* current = nullptr;

void create_node(Node* node)
{
    node->data = new LiveArea;
    cout << "Введите название округа: ";
    cin >> node->data->name;
    cout << "Введите население округа: ";
    cin >> node->data->population;
    cout << "Введите площадь округа: ";
    cin >> node->data->area;
    cout << "Введите республику: ";
    cin >> node->data->republic;
    cout << "Введите регион: ";
    cin >> node->data->region;
    cout << "Введите округ: ";
    cin >> node->data->okrug;
    cout << "Введите количество животных: ";
    cin >> node->data->animals;
    cout << "Введите количество лесов: ";
    cin >> node->data->forests;
    cout << "Введите количество рек: ";
    cin >> node->data->rivers;
    cout << "Введите количество озер: ";
    cin >> node->data->lakes;
}

bool isEmpty() {
    if(head == nullptr)
    {
        cout << "Список пуст" << endl;
        return true;
    }
    else cout << "Список не пуст" << endl;
    return false;
}

int size() {
    int size = 0;
    if(head == nullptr)
        cout << "Список пуст" << endl;
    else {
        Node *temp = head;
        do {
            size++;
            temp = temp->next;
        } while (temp != head);
        cout << "Размер списка: " << size << endl;
        return size;
    }
}

void add_back() {
    if (head == nullptr) {
        head = new Node;
        create_node(head);
        head->prev = head;
        head->next = head;
        current = head;
        cout << "Элемент добавлен в конец списка, его адрес: " << head << endl;
        cout << "Вы перешли к созданному элементу. Предыдущий элемент: " << head->prev << endl;
    } else {
        Node *temp = new Node;
        create_node(temp);
        temp->prev = current;
        temp->next = head;
        current->next = temp;
        head->prev = temp;
        current = temp;
        cout << "Элемент добавлен в конец списка, его адрес: " << current << endl;
        cout << "Вы перешли к созданному элементу. Предыдущий элемент: " << current->prev << endl;
    }
}
void clear() {
    if (head == nullptr) {
        cout << "Список уже пуст" << endl;
        return;
    }
    Node* temp = head;
    do {
        Node* next = temp->next;
        delete temp;
        temp = next;
    } while (temp != head);
    head = nullptr;
    current = nullptr;
    cout << "Список очищен" << endl;
}
void next() {
    if (head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }
    current = current->next;
    cout << "Следующий элемент: " << current << endl;
}

void prev() {
    if (head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }
    current = current->prev;
    cout << "Предыдущий элемент: " << current << endl;
}
void read_current() {
    if (head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }
    cout << "Информация о текущем элементе: " << endl;
    cout << "Название округа: " << current->data->name << endl;
    cout << "Население округа: " << current->data->population << endl;
    cout << "Площадь округа: " << current->data->area << endl;
    cout << "Республика: " << current->data->republic << endl;
    cout << "Регион: " << current->data->region << endl;
    cout << "Округ: " << current->data->okrug << endl;
    cout << "Количество животных: " << current->data->animals << endl;
    cout << "Количество лесов: " << current->data->forests << endl;
    cout << "Количество рек: " << current->data->rivers << endl;
    cout << "Количество озер: " << current->data->lakes << endl;
}
void delete_current() {
    if (head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }
    if(current == head && current->next == head) {
        delete current;
        head = nullptr;
        current = nullptr;
        cout << "Элемент удален" << endl;
        return;
    }
    if (current == head) {
        Node* temp = head;
        head = head->next;
        head->prev = current->prev;
        current->prev->next = head;
        delete temp;
        current = head;
    }
    else {
        Node* temp = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current = current->prev;
        delete temp;
    }
    cout << "Текущий элемент удален" << endl;
}
void insert(bool left) {
    cout << "Вставить слева от текущего (1) или справа (0)? ";
    cin >> left;
    if (head == nullptr) {
        head = new Node;
        create_node(head);
        head->prev = head;
        head->next = head;
        current = head;
        cout << "Элемент добавлен в конец списка, его адрес: " << head << endl;
        cout << "Вы перешли к созданному элементу. Предыдущий элемент: " << head->prev << endl;
        return;
    }
    Node* temp = new Node;
    create_node(temp);
    if (left) {
        temp->prev = current->prev;
        temp->next = current;
        current->prev->next = temp;
        current->prev = temp;
        current = temp;
    }
    else {
        temp->prev = current;
        temp->next = current->next;
        current->next->prev = temp;
        current->next = temp;
        current = temp;
    }
    cout << "Элемент добавлен в список, его адрес: " << current << endl;
    cout << "Вы перешли к созданному элементу. Предыдущий элемент: " << current->prev << endl;
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Проверка на пустоту списка" << endl;
        cout << "2. Определение размера списка" << endl;
        cout << "3. Добавление элемента в конец списка" << endl;
        cout << "4. Очистка списка" << endl;
        cout << "5. Переход к следующему элементу" << endl;
        cout << "6. Переход к предыдущему элементу" << endl;
        cout << "7. Чтение информации о текущем элементе" << endl;
        cout << "8. Удаление текущего элемента" << endl;
        cout << "9. Вставка элемента слева или справа от текущего" << endl;
        cout << "0. Выход" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                isEmpty();
                break;
            case 2:
                size();
                break;
            case 3:
                add_back();
                break;
            case 4:
                clear();
                break;
            case 5:
                next();
                break;
            case 6:
                prev();
                break;
            case 7:
                read_current();
                break;
            case 8:
                delete_current();
                break;
            case 9: {
                cout << "Вставить слева от текущего (1) или справа (0)? ";
                bool left;
                cin >> left;
                insert(left);
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Неверный выбор" << endl;
                break;
        }
    }
}





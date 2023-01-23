#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Element {
protected:
    string name;
    int population;
    string area;
    string republic;
    string region;
    string okrug;
    string animals;
    string forests;
    string rivers;
    string lakes;
    Element* next;
    Element* prev;
public:
    void read() {
        if (this == nullptr) {
            cout << "Список пуст" << endl;
            return;
        }
        else{
            cout << this << endl;
        }
    }
    string getvalue_name()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return "Список пуст";
        }
        return this->name;
    }
    int getvalue_pop()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return 0;
        }
        return this->population;
    }
    string getvalue_area()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->area;
    }
    string getvalue_rep()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->republic;
    }
    string getvalue_region()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->region;
    }
    string getvalue_okrug()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->okrug;
    }
    string getvalue_anim()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->animals;
    }
    string getvalue_for()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->forests;
    }
    string getvalue_riv()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->rivers;
    }
    string getvalue_lakes()
    {
        if (this == nullptr) {
            //cout <<  << endl;
            return " ";
        }
        return this->lakes;
    }
    Element* adress() {
        return this;
    }

    Element* getnext()
    {
        return next;
    }
    void setnext(Element* tmp)
    {
        next = tmp;
    }
    Element* getprev()
    {
        return prev;
    }
    void setprev(Element* tmp)
    {
        prev = tmp;
    }

    //Конструкторы
    //Для создания:
public:
    Element() {
            cout << "Введите название округа: ";
            cin >> this->name;
            cout << "Введите население округа: ";
            cin >> this->population;
            /*cout << "Введите площадь округа: ";
            cin >> this->area;
            cout << "Введите республику: ";
            cin >> this->republic;
            cout << "Введите регион: ";
            cin >> this->region;
            cout << "Введите округ: ";
            cin >> this->okrug;
            cout << "Введите количество животных: ";
            cin >> this->animals;
            cout << "Введите количество лесов: ";
            cin >> this->forests;
            cout << "Введите количество рек: ";
            cin >> this->rivers;
            cout << "Введите количество озер: ";
            cin >> this->lakes;*/
            this->next = this;
            this->prev = this;
            cout << "Элемент создан " << endl;
            cout << "Его адрес: "  << adress() << endl;
    }
    Element(Element* connected)
    {
        int tmp;
        cout << "Введите название округа: ";
        cin >> this->name;
        cout << "Введите население округа: ";
        cin >> this->population;
        /*cout << "Введите площадь округа: ";
        cin >> this->area;
        cout << "Введите республику: ";
        cin >> this->republic;
        cout << "Введите регион: ";
        cin >> this->region;
        cout << "Введите округ: ";
        cin >> this->okrug;
        cout << "Введите количество животных: ";
        cin >> this->animals;
        cout << "Введите количество лесов: ";
        cin >> this->forests;
        cout << "Введите количество рек: ";
        cin >> this->rivers;
        cout << "Введите количество озер: ";
        cin >> this->lakes;*/
        this->next = connected->next;
        this->prev = connected;
        connected->next = this;
        this->next->prev = this;
        cout << "Объект типа элемент кольцевого двусвязного списка создан!\n";
        cout << "Его адрес: " << adress() << endl;
        cout << "Объект присоединён к другим элементам!\n";
        //  count++;
    }
    ~Element()
    {
        this->next->setprev(this->prev);
        this->prev->setnext(this->next);

        cout << "Элемент удалён!\n";
        cout << "Связи в структуре переопределены!\n";
    }
    int getpopulation()
    {
        return this->population;
    }
    //перегрузка операторов
    bool operator>(const Element& tmp) const
    {
        return (this->population > tmp.population);
    }
    bool operator<(const Element& tmp) const
    {
        return (this->population < tmp.population);
    }
    bool operator==(const Element& tmp)
    {
        if (this->population == tmp.population)
            return true;
        else
            return false;
    }
    bool operator!=(const Element& tmp)
    {
        if (this->population != tmp.population)
            return true;
        else
            return false;
    }
    bool operator>=(const Element& tmp)
    {
        if (this->population >= tmp.population)
            return true;
        else
            return false;
    }
    bool operator<=(const Element& tmp)
    {
        if (this->population <= tmp.population)
            return true;
        else
            return false;
    }

};

class Spisok {
protected:
    Element* start;
    Element* now;

public:
    int sumpopulation() const
    {
        Element* tmp = this->start;
        int sum = 0;
        do {
            sum += tmp->getpopulation();
            tmp = tmp->getnext();
        } while (tmp != this->start);
        return sum;
    }

    bool operator>(Spisok& tmp) const
    {
        return (this->sumpopulation() > tmp.sumpopulation());
    }
    bool operator<(Spisok& tmp)
    {
        return (this->sumpopulation() < tmp.sumpopulation());
    }
    bool operator==(Spisok& tmp)
    {
        if (this->sumpopulation() == tmp.sumpopulation())
            return true;
        else
            return false;
    }
    bool operator!=(Spisok& tmp)
    {
        if (this->sumpopulation() != tmp.sumpopulation())
            return true;
        else
            return false;
    }
    bool operator>=(Spisok& tmp)
    {
        if (this->sumpopulation() >= tmp.sumpopulation())
            return true;
        else
            return false;
    }
    bool operator<=(Spisok& tmp)
    {
        if (this->sumpopulation() <= tmp.sumpopulation())
            return true;
        else
            return false;
    }
    friend ostream& operator<<(ostream& out, const Spisok* tmp)
    {
        out << "Название округа: " << tmp->now->getvalue_name() << endl;
        out << "Население округа: " << tmp->now->getvalue_pop() << endl;
        out << "Площадь округа: " << tmp->now->getvalue_area() << endl;
        out << "Республика: " << tmp->now->getvalue_rep() << endl;
        out << "Регион: " << tmp->now->getvalue_region() << endl;
        out << "Округ: " << tmp->now->getvalue_okrug() << endl;
        out << "Количество животных: " << tmp->now->getvalue_anim() << endl;
        out << "Количество лесов: " << tmp->now->getvalue_for() << endl;
        out << "Количество рек: " << tmp->now->getvalue_riv() << endl;
        out << "Количество озер: " << tmp->now->getvalue_lakes() << endl;
        return out;
    }
    void add() {
        if (start == NULL)
        {
            start = new Element();
            now = start;

        }
        else
        {
            new Element(start);
        }
    }

    bool isEmpty() {
        if (now == NULL) {
            cout << "Список пуст" << endl;
            return true;}
        else { cout << "Список не пуст" << endl;
            return false; }
    }

    void next() {
        if (start == NULL) {
            cout << "Список пуст" << endl;
            return;
        }
        now = now->getnext();
        cout << "Переход к следующему элементу произведён!" << endl;
        cout << "Его адрес: " << now->adress() << endl;
    }

    void prev() {
        if (start == nullptr) {
            cout << "Список пуст" << endl;
            return;
        }
        now = now->getprev();
        cout << "Переход к предыдущему элементу произведён!" << endl;
        cout << "Его адрес: " << now->adress() << endl;
    }
    void read_current() {
        //cout << now->getvalue() << endl;
        if (now == nullptr) {
            cout << "Список пуст" << endl;
            return;
        }
        else{
            cout << this << endl;
        }

    }
    void del()
    {
        Element* tmp = now;
        if (now == NULL) { cout << "Список пуст" << endl; return; }
        else
        {
            if (tmp == start && start->getnext() == start)
            {
                start = NULL;
                now = NULL;
                cout << "Единственный элемент удален, теперь список пуст" << endl;
                return;
            }
            else
            {
                start = start->getnext();
                now = start->getnext();
            }
        }
        delete tmp;
        now = start->getnext();
        return;
    }

    int size() {
        int size = 0;
        if (start == nullptr)
            cout << "Список пуст" << endl;
        else {
            //Element* tmp = start;
            now = start;
            do {
                size++;
                now = now->getnext();
            } while (now != start);
            cout << "Размер списка: " << size << endl;
            return size;
        }
    }
    void clear() {
        if (start == nullptr) {
            cout << "Список уже пуст" << endl;
            return;
        }
        Element* temp = start;
        do {
            Element* nextt = temp->getnext();
            delete temp;
            temp = nextt;
        } while (temp != start);
        start = nullptr;
        now = nullptr;
        cout << "Список очищен" << endl;
    }
    void create_right() {
        if (start == NULL) {
            start = new Element();
            now = start;
        }
        else
        {
            new Element(start);
        }
        return;
    }
    void create_left() {
        if (start == NULL) {
            start = new Element();
            now = start;
        }
        else
        {
            new Element(start);
        }
        return;
    }
    void insert(bool left) {
        if (start == nullptr) {
            start = new Element();
            now = start;
            cout << "Элемент добавлен в конец списка, его адрес: " << now->adress() << endl;
            return;
        }
        //Element* temp = new Element();

        if (left) {
            Element* temp = new Element(start);
            start = temp;
            now = start;
            cout << "Элемент добавлен в начало списка, его адрес: " << now->adress() << endl;
            return;
        }
        else {
            Element* temp = new Element(start);
            now = temp;
            cout << "Элемент добавлен в конец списка, его адрес: " << now->adress() << endl;
            return;
        }
    }
};

int main() {
    //setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(CP_UTF8);
    Spisok* list1 = new Spisok();
    Spisok* list2 = new Spisok();

    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Меню списка 1" << endl;
        cout << "2. Меню списка 2" << endl;
        cout << "3. Сравнить списки" << endl;
        cout << "4. Выход" << endl;
        int a;
        cin >> a;
        switch (a) {
            case 1:
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
                        list1->isEmpty();
                        break;
                    case 2:
                        list1->size();
                        break;
                    case 3:
                        list1->add();
                        break;
                    case 4:
                        list1->clear();
                        break;
                    case 5:
                        list1->next();
                        break;
                    case 6:
                        list1->prev();
                        break;
                    case 7:
                        list1->read_current();
                        break;
                    case 8:
                        list1->del();
                        break;
                    case 9:
                        cout << "Вставить слева от текущего (1) или справа (0)? ";
                        bool left;
                        cin >> left;
                        list1->insert(left);
                        break;


                    case 0:
                        return 0;
                    default:
                        cout << "Неверный выбор" << endl;
                        break;
                }
                break;
            case 2:
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
                int choicee;
                cin >> choicee;
                switch (choicee) {
                    case 1:
                        list2->isEmpty();
                        break;
                    case 2:
                        list2->size();
                        break;
                    case 3:
                        list2->add();
                        break;
                    case 4:
                        list2->clear();
                        break;
                    case 5:
                        list2->next();
                        break;
                    case 6:
                        list2->prev();
                        break;
                    case 7:
                        list2->read_current();
                        break;
                    case 8:
                        list2->del();
                        break;
                    case 9:
                        cout << "Вставить слева от текущего (1) или справа (0)? ";
                        bool left;
                        cin >> left;
                        list2->insert(left);
                        break;


                    case 0:
                        return 0;
                    default:
                        cout << "Неверный выбор" << endl;
                        break;
                }
                break;
            case 3:
                if(list1->isEmpty() || list2->isEmpty()){
                    cout << "Один из списков пуст" << endl;
                    break;
                } else{
                    cout << (list1>list2) << endl;
                }

        }
    }
}
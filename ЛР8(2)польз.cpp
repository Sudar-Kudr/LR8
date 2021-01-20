#include <iostream>
using namespace std;

template<typename T, int cnt>
struct ArrList{
    T arr[cnt];
    int count;
};

template<typename T, int cnt>
void constructor(ArrList<T, cnt>& list){
    list.count = 0;
}

template<typename T, int cnt>
void destructor(ArrList<T, cnt>& list){
    list.count = 0;
}

template<typename T, int cnt>
int getCount(ArrList<T, cnt> list){
    return list.count;
}

template<typename T, int cnt>
int push_back(ArrList<T, cnt>& list, T value){
    if(list.count == cnt)
        return -1;
    
    list.arr[list.count++] = value;
    return 1;
}

template<typename T, int cnt>
int insert(ArrList<T, cnt>& list, int ind, T value){
    if(list.count == cnt)
        return -1;
    if(ind < 0 || ind >= list.count)
        return -2;
    
    for(int i = list.count; i > ind; i--){
        list.arr[i] = list.arr[i-1];
    }
    list.arr[ind] = value;
    list.count++;
    return 1;
}

template<typename T, int cnt>
T pop_front(ArrList<T, cnt>& list){
    T value = list.arr[0];
    if (list.count == 0){
        cout << "Пустой, нечего удалять, потому что имеет размер ";
        return 0;
    }
    else
        for(int i = 0; i < list.count - 1; i++){
            list.arr[i] = list.arr[i + 1];
        }
    list.count--;
    return value;
    
}

template<typename T, int cnt>
T pop_back(ArrList<T, cnt>& list){
    if (list.count == 0){
        cout << "Пустой, нечего удалять, потому что имеет размер ";
        return 0;
    }
    else{
        list.count--;
        return list.arr[list.count];
    }
}

template<typename T, int cnt>
T pop(ArrList<T, cnt>& list, int ind){
    T value = list.arr[ind];
    for(int i = ind; i < list.count - 1; i++)
        list.arr[i] = list.arr[i + 1];
    list.count--;
    return value;
}

template<typename T, int cnt>
T get(const ArrList<T, cnt>& list, int ind){
    if (list.count == 0){
        return 0;
    }
    return list.arr[ind];
}

template<typename T, int cnt>
int search(const ArrList<T, cnt>& list, T value){
    for(int i = 0 ; i < list.count; i++){
        if(list.arr[i] == value)
            return i;
    }
    return -1;
}

template<typename T, int cnt>
void print(const ArrList<T, cnt>& list){
    for(int i = 0; i < list.count; i++)
        cout << list.arr[i] << " ";
    cout << endl;
}

int main() {
    int numb, n;
    cout << "Выберете тип данных:\n" << "1 - int\n2 - float\n3 - char\n";
    cin >> numb;
    switch (numb){
        case 1: {
            ArrList<int, 100> lst;
            
            cout << "Конструктор\n";
            constructor(lst);
            
            int value;
            
            cout << "Введите размер:\n";
            cin >> n;
            cout << "Введите...\n";
            for (int i = 0; i < n; i++) {
                cin >>value;
                push_back(lst, value);
            }
            
            cout << "После ввода\n";
            print(lst);
            
            cout << "Подсчет: "<<getCount(lst) << endl;
            int ind;
            
            cout << "Извлечение значаения из начала\n";
            cout << pop_front(lst) <<endl;
            print(lst);

            cout << "Извлечение значаения из конца\n";
            cout << pop_back(lst) <<endl;
            print(lst);
            
            if (getCount(lst) != 0){
                cout << "Введите индекс для извлечения\n";
                cin>>ind;
                cout << "Извлечение значаения по индексу\n";
                cout << pop(lst, ind) <<endl;
                print(lst);
            }
            else
                cout << "Извлечение по индексу не получится, т.к. пустой \n";
            
            if (get(lst, ind) == 0)
                cout << "Получение значаения по индексу и поиск не получится, т.к. пустой \n";
            else{
                cout << "Введите индекс для получения значаения\n";
                cin>>ind;
                cout << "Значаение:\n";
                cout << get(lst, ind) <<endl;
                print(lst);
                
                cout << "Введите значение для поиска\n";
                cin>>value;
                cout << "Поиск по значению: "<<search(lst, value)<<endl;
            }
            
            
            cout << "Введите число для конца\n";
            cin>>value;
            push_back(lst, value);
            cout << "После вставки в конец\n";
            print(lst);

            cout << "Введите индекс\n";
            cin>>ind;
            cout << "Введите число для вставки\n";
            cin>>value;
            insert(lst, ind, value);
            cout << "После вставки по индексу\n";
            print(lst);
            
            destructor(lst);
            cout << "После деструктора:\n";
            print(lst);
            break;
        }
            case 2: {
                ArrList<float, 100> lst;
                
                cout << "Конструктор\n";
                constructor(lst);
                
                float value;
                
                cout << "Введите размер:\n";
                cin >> n;
                cout << "Введите...\n";
                for (int i = 0; i < n; i++) {
                    cin >>value;
                    push_back(lst, value);
                }
                
                cout << "После ввода\n";
                print(lst);
                
                cout << "Подсчет: "<<getCount(lst) << endl;
                int ind;
                
                cout << "Извлечение значаения из начала\n";
                cout << pop_front(lst) <<endl;
                print(lst);

                cout << "Извлечение значаения из конца\n";
                cout << pop_back(lst) <<endl;
                print(lst);
                
                if (getCount(lst) != 0){
                    cout << "Введите индекс для извлечения\n";
                    cin>>ind;
                    cout << "Извлечение значаения по индексу\n";
                    cout << pop(lst, ind) <<endl;
                    print(lst);
                }
                else
                    cout << "Извлечение по индексу не получится, т.к. пустой \n";
                
                if (get(lst, ind) == 0)
                    cout << "Получение значаения по индексу и поиск не получится, т.к. пустой \n";
                else{
                    cout << "Введите индекс для получения значаения\n";
                    cin>>ind;
                    cout << "Значаение:\n";
                    cout << get(lst, ind) <<endl;
                    print(lst);
                    
                    cout << "Введите значение для поиска\n";
                    cin>>value;
                    cout << "Поиск по значению: "<<search(lst, value)<<endl;
                }
                
                
                cout << "Введите число для конца\n";
                cin>>value;
                push_back(lst, value);
                cout << "После вставки в конец\n";
                print(lst);

                cout << "Введите индекс\n";
                cin>>ind;
                cout << "Введите число для вставки\n";
                cin>>value;
                insert(lst, ind, value);
                cout << "После вставки по индексу\n";
                print(lst);
                
                destructor(lst);
                cout << "После деструктора:\n";
                print(lst);
                break;
            }
            case 3: {
                ArrList<char, 100> lst;
                
                cout << "Конструктор\n";
                constructor(lst);
                
                char value;
                
                cout << "Введите размер:\n";
                cin >> n;
                cout << "Введите...\n";
                for (int i = 0; i < n; i++) {
                    cin >>value;
                    push_back(lst, value);
                }
                
                cout << "После ввода\n";
                print(lst);
                
                cout << "Подсчет: "<<getCount(lst) << endl;
                int ind;
                
                cout << "Извлечение значаения из начала\n";
                cout << pop_front(lst) <<endl;
                print(lst);

                cout << "Извлечение значаения из конца\n";
                cout << pop_back(lst) <<endl;
                print(lst);
                
                if (getCount(lst) != 0){
                    cout << "Введите индекс для извлечения\n";
                    cin>>ind;
                    cout << "Извлечение значаения по индексу\n";
                    cout << pop(lst, ind) <<endl;
                    print(lst);
                }
                else
                    cout << "Извлечение по индексу не получится, т.к. пустой \n";
                
                if (get(lst, ind) == 0)
                    cout << "Получение значаения по индексу и поиск не получится, т.к. пустой \n";
                else{
                    cout << "Введите индекс для получения значаения\n";
                    cin>>ind;
                    cout << "Значаение:\n";
                    cout << get(lst, ind) <<endl;
                    print(lst);
                    
                    cout << "Введите значение для поиска\n";
                    cin>>value;
                    cout << "Поиск по значению: "<<search(lst, value)<<endl;
                }
                
                
                cout << "Введите число для конца\n";
                cin>>value;
                push_back(lst, value);
                cout << "После вставки в конец\n";
                print(lst);

                cout << "Введите индекс\n";
                cin>>ind;
                cout << "Введите число для вставки\n";
                cin>>value;
                insert(lst, ind, value);
                cout << "После вставки по индексу\n";
                print(lst);
                
                destructor(lst);
                cout << "После деструктора:\n";
                print(lst);
                break;
            }
            
    return 0;
}
}

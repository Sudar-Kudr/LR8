#include <iostream>

using namespace std;

template<typename T>
struct Node{
    Node* prev;
    Node* next;
    T value;
};

template<typename T>
struct List{
    Node<T>* tail;
    Node<T>* head;
    unsigned int count;
};

template<typename T>
void constructor(List<T>& list){
    list.tail = nullptr;
    list.head = nullptr;
    list.count = 0;
}


//вставка в голову списка
template<typename T>
List<T>& push_front(List<T>& list, T value) {
    Node<T>* tmp = new Node<T>;
    tmp->value = value;
    if(list.count == 0){
        list.head = list.tail = tmp;
    }
    else{
        tmp->next = list.head;
        list.head->prev = tmp;
    }
    list.head = tmp;
    list.head->prev = list.tail; //для кольцевания
    list.count++;
    return list;
}

// вставка в хвост списка
template<typename T>
List<T>& push_back(List<T>& list, T value) {
    Node<T>* tmp = new Node<T>;
    if(list.count == 0){
        list.head = list.tail = tmp;
    }
    tmp->value = value;
    tmp->prev = list.tail;
    list.tail->next = tmp;
    list.tail = tmp;
    list.tail->next = list.head; //для кольцевания
    list.count++;
    return list;
}

template<typename T>
T pop_back(List<T>& list){
    Node<T>* deleted = list.tail;
    list.tail = list.tail->prev;
    list.tail->next = list.head; //для кольцевания
    list.count--;
    T value = deleted->value;
    delete deleted;
    return value;
}

template<typename T>
T pop_front(List<T>& list){
    Node<T>* deleted = list.head;
    list.head = list.head->next;
    list.head->prev = list.tail;
    list.count--;
    T value = deleted->value;
    delete deleted;
    return value;
}

template<typename T>
void destructor(List<T>& stack){
    while(stack.count != 0) {
        pop_back(stack);
    }
}

template<typename T>
void print(List<T>& list){
    Node<T>* top = list.head;
    for (int i = 0; i < list.count; i++) {
        cout << top->value << " ";
        top = top->next;
    }
    cout << endl;
}

template<typename T>
List<T>& push_ind(List<T>& list, int ind, T value) {
    if(ind < 0 || ind > list.count)
        return list;
    
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    
    if(ind == 0){
        return push_front(list, value);
    }
    if(ind == list.count){
        return push_back(list, value);
    }
    
    Node<T>* top = list.head;
       for (int i = 0; i < ind - 1; i++) {
           top = top->next;
       }
    newNode->prev = top;
    newNode->next = top->next;
    top->next = newNode;
    newNode->next->prev = newNode;
    list.count++;
    return list;
}

template<typename T>
Node<T>* find(List<T>& list,  T value) {
    int i = 0;
    Node<T>* node = list.head;
    while (i < list.count) {
        if (node->value != value) {
            node = node->next;
        }
        else {
            node = node->prev;
            return node->next;
        }
    }
    return nullptr;
}

template<typename T>
void pop_uk(List<T>& list, int ind){
    Node<T>* uk = find(list,ind);
    if (uk != nullptr) {
        uk->next->prev = uk->prev;
        uk->prev->next = uk->next;
        list.count--;
    }
}

template<typename T>
List<T>& push_uk(List<T>& list, Node<T>* ind, T value) {
    if(ind == nullptr)
        return list;
    
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    
    if(ind == list.head){
        return push_front(list, value);
    }
    if(ind == list.tail){
        return push_back(list, value);
    }
    
    Node<T>* top = list.head;
    for (int i = 0; i < list.count; i++) {
        if(top == ind){
            newNode->prev = top;
            newNode->next = top->next;
            top->next = newNode;
            newNode->next->prev = newNode;
            list.count++;
        }
        
        top = top->next;
    }
    return list;
}

template<typename T>
int pop_ind(List<T>& list, int ind, T& res){
    if(ind == 0){
        res = pop_front(list);
        return 1;
    }
    if(ind == list.count - 1){
        res = pop_back(list);
        return 1;
    }
    
    Node<T>* top = list.head;
    for (int i = 0; i < list.count; i++) {
        if(i == ind){
            Node<T>* tmp = top;
            res = top->value;
            top->next->prev = top->prev;
            top->prev->next = top->next;
            list.count--;
            delete tmp;
            return 1;
        }
        top = top->next;
    }
    return -1;
}

template<typename T>
Node<T>* getUkByInd(List<T>& list, int ind){
    if(ind >= list.count)
        return nullptr;
    Node<T>* top = list.head;
    for (int i = 0; i < ind; i++) {
        top = top->next;
    }
    return top;
}

template<typename T>
T getCount(List<T>& lst){
    return lst.count;
}

template<typename T>
int findIND (List<T>& list, T value){
    Node<T>* top = list.head;
    for (int i = 0; i < list.count; i++) {
        if (value == top->value )
            return i;
        top = top->next;
    }
    return -1;
}

//для извлечение по указателю
template<typename T>
T getNodeValue(Node<T>* node){
    return node->value;
}

int main()
{
    srand(time(0));
    List<int> st;
    int value, n;
    
        cout << "Конструктор\n";
        constructor(st);
        cout << "Введите размер:\n";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Введите "<<i<<"-ое значение\n";
            cin >> value;
            push_back(st, value);
        }
        cout << "После создания\n";
        print(st);
    
    cout << "Подсчет\n";
    cout << "Первый способ: "<< getCount(st) <<endl;
    cout << "Второй способ: "<< st.count <<endl;
     
    cout << "Введите число для начала\n";
    cin >> value;
    push_front(st, value);
    print(st);
    
    cout << "Введите число для конца\n";
    cin >> value;
    push_back(st, value);
    print(st);
    
    cout << "Введите индекс для вставки\n";
    cin >> n;
    cout << "Введите значение для вставки по индексу\n";
    cin >> value;
    push_ind(st, n, value);
    cout << "После вставки по индексу" <<endl;
    print(st);

    cout << "Вставка по указателю на узел\nВведите указатель\n";
    cin >> n;
    Node<int>* r = getUkByInd(st, n);
    cout << "Введи число для вставки" << endl;
    cin >> value;
    push_uk(st, r, value);
    print(st);

    cout << "После извлечения НАЧАЛА\n";
    cout << "Элемент удален: " << pop_front(st) << endl;
    print(st);
    
    cout << "После извлечения КОНЦА\n";
    cout << "Элемент удален: " << pop_back(st) << endl;
    print(st);
    
    int ind;
    cout << "Введите индекс(извлечение)\n";
    cin >> ind;
    int result;
    int rr = pop_ind(st, ind, result);
    cout << "После извлечения ИНДЕКСА\n";
    if(rr == -1){
        cout << "Элемент не найден!" << endl;
    }
    else{
        cout << "Элемент: " << result << endl;
    }
    print(st);
    
    cout << "Введите какой элемент по указателю вы хотите извлечь\n";
    cin >> ind;
    pop_uk(st, ind);
    cout << "После извлечения УКАЗАТЕЛЯ\n";
    print(st);
    
    cout << "Введите индекс чтобы получить значение" << endl;
    cin >> ind;
    Node<int>* e = getUkByInd(st, ind);
    int x = getNodeValue(e);
    cout << "Значение: "<<x;
    
    cout << "\nВведите элемент" <<endl;
    cin >> value;
    rr = findIND(st, value);
    if(rr == -1){
           cout << "Элемент не найден!";
       }
       else{
           cout << "Элемент: " << findIND(st, value);
       }
    
    destructor(st);
    cout << "\nПосле деструктора:\n" << endl;
    print(st);
    
    cout << st.count;
     
    return 0;
}

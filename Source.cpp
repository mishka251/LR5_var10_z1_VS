#include <iostream>

struct List {
    int value;
    List* next;
};


List* first;

void initList() {
    int n;
    std::cout << "elements count" << std::endl;
    std::cin >> n;
    int a;
    first = new List();
    List* last = first;
    for (int i = 0; i < n; ++i) {
        std::cout << "item " << i << " = ";
        std::cin >> a;
        last->value = a;
        if (i < n - 1) {
            List* newItem = new List();
            last->next = newItem;
            last = last->next;
        }
    }
}

void printList() {
    List* last = first;
    while (last != nullptr) {
        std::cout << last->value << "  ";
        last = last->next;
    }
    std::cout << std::endl;
}


void removeDuplicates() {
    List* last = first;
    while (last != nullptr && last->next != nullptr) {
        List* next = last->next;

        bool isIn = false;
        List* tmp = first;
        while (tmp != next) {
            if (tmp->value == next->value) {
                isIn = true;
                break;
            }
            tmp = tmp->next;
        }

        if (isIn) {
            last->next = next->next;
        }
        else {
            last = last->next;
        }
    }
}

int main() {
    initList();
    printList();
    removeDuplicates();
    printList();
    return 0;
}
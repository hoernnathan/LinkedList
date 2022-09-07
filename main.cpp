#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    LinkedList *l = new LinkedList();
    l->append(2);
    l->append(3);
    l->append(4);
    l->append(5);
    l->display();
    try {
        l->remove(3);
    }catch(exception &e){
        cout << "Caught exception: " << e.what() << endl;
    }
    l->display();
    l->insert(7,3);
    l->display();

    try {
        cout << l->get(3) << endl;
    }catch(exception &e){
        cout << "Caught exception: " << e.what() << endl;
    }

    l->reverse();
    l->display();
    delete l;
    return 0;
}
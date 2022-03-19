#include <iostream>
#include "collection.h"
using namespace std;
int main(){
    Collection c;
    c.init();
    cout << c.size()<<endl;
    c.add(7);
    cout << c.size()<<endl;
    cout<<c.nrOccurences(7)<<endl;
    c.add(3);
    c.add(7);
    cout<<c.size()<<endl;
    cout<<c.nrOccurences(7)<<endl;
    c.remove(3);
    cout<<c.size()<<endl;
    c.remove(7);
    cout<<c.size()<<endl;
    cout<<c.nrOccurences(7)<<endl;
    c.destroy();
    return 0;
}
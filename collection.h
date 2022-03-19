#ifndef SEMINAR2_COLLECTION_H
#define SEMINAR2_COLLECTION_H

class Collection
{
private:
    int * elements;
    int * nr;
    int nr_elements;
    int max_capacity;

public:
    void init();
    void add(int element);
    bool remove(int element);
    bool search(int element);
    int size();
    int nrOccurences(int element);
    void destroy();

};
#endif //SEMINAR2_COLLECTION_H

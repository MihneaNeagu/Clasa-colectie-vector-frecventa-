#include "collection.h"

void Collection::init(){
    this->max_capacity = 5;
    this->elements = new int[this->max_capacity];
    this->nr = new int[this->max_capacity];
    this->nr_elements = 0;
}

void Collection::add(int element){
    if(this->nr_elements == this->max_capacity)
    {
        this->max_capacity = this->max_capacity*2;
        int *temp;
        int *temp_occurencies;
        temp = new int[this->max_capacity];
        temp_occurencies = new int[this->max_capacity];
        for(int i=0; i<this->nr_elements;i++) {
            temp[i] = this->elements[i];
            temp_occurencies[i] = this->nr[i];
        }
        delete []elements;
        delete []nr;
        elements = temp;
        nr = temp_occurencies;
        delete [] temp;
        delete [] temp_occurencies;
    }
    bool found = false;
    int position;
    for(int i=0;i<this->nr_elements && !found;i++)
        if(this->elements[i]==element)
        {found=true;
        position=i;}
    if(found)
        this->nr[position]++;
    else{
        this->elements[nr_elements] = element;
        this->nr[nr_elements] = 1;
        this->nr_elements++;
    }
}

bool Collection::search(int element)
{
    for (int i=0;i<this->nr_elements;i++)
        if(this->elements[i]==element)
            return true;
    return false;
}

bool Collection::remove(int element)
{
    if(!search(element))
        return false;
    bool found = false;
    int position = -1;
    for(int i=0;i<this->nr_elements &&!found;i++)
        if(elements[i]==element)
        {position = i;
        found = true;
        }
    if(nr[position]==1){
        for(int i=position;i< this->nr_elements;i++)
        {this->elements[i]=this->elements[i+1];
        this->nr[i] = this->nr[i+1];}
        this->nr_elements--;
    }
    else
        this->nr[position]--;
    return true;
}

int Collection::size(){
    return this->nr_elements;
}

int Collection::nrOccurences(int element) {
    if(!search(element))
        return 0;
    for (int i =0; i<this->nr_elements;i++)
        if(this->elements[i]==element)
            return nr[i];
}

void Collection::destroy() {
    this->elements=nullptr;
    this->nr=nullptr;
}
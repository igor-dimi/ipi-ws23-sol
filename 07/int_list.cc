#include <iostream>

class IntListElement{
    public: 
        IntListElement();
        IntListElement(int value);
        ~IntListElement();
        IntListElement* get_succ();
        void set_succ(IntListElement)
    private:
        int value;
        IntListElement* succ;
};

class IntList {
    public:
        IntList(); //Constructor to create a new empty list
        ~IntList(); //Destructor deletes entire list
        int getCount(); //returns count of elements in the list
        bool isEmpty(); // querries whether list is empty
        void print(); // Outputs the list
        void insert(int element, int position); //insert element at the given position
        void remove(int position); //remove element at a given position
        int getElement(int position); //returns element at the given position
    private:
        int count; 
        IntListElement& head; 
};

IntListElement::IntListElement()
{
    value = 0;
    succ = nullptr;
}

IntListElement::IntListElement(int value)
{
    this->value = value;

}

IntList::IntList() : head() {};

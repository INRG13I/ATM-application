//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#ifndef LAB_2_SD_LIST_H
#define LAB_2_SD_LIST_H


#include <iostream>


template <class Class>
class List
{
private:

    Class* list;
    int size;

    void setSize(int newSize);
public:

//------------------------------------------------------------------------------------------------------ Constructors //
    List();
    List(const List<Class>& newList);

    ~List();

//----------------------------------------------------------------------------------------------------------- Methods //

    int find(Class element);
    int getSize()const;
    void add(Class newElement);
    void del(int position);
    void update(int position, Class newElement);
    Class getElement(int position)const;
    void bubblesort();


//------------------------------------------------------------------------------------------------ Operator overloads //
    List<Class>& operator=(const List<Class>& rList);

    friend std::ostream& operator<<(std::ostream& os, List<Class> list);

};

template<class Class>
inline void List<Class>::setSize(int newSize)
{
    size = newSize;
}

//------------------------------------------------------------------------------------------------------ Constructors //


template<class Class>
inline List<Class>::List()
{
    list = nullptr;
    size = 0;
}

template<class Class>
inline List<Class>::List(const List<Class>& newList)
{


    list = new Class[newList.getSize()];

    for (int i = 0; i < newList.getSize(); i++) {

        this->update(i, newList.getElement(i));
    }

    this->setSize(newList.getSize());
}

template<class Class>
inline List<Class>::~List()
{
    delete[] list;
}

//----------------------------------------------------------------------------------------------------------- Methods //

template<class Class>
inline int List<Class>::find(Class element)
{

    for (int i = 0; i < this->getSize(); i++)
    {
        if (this->getElement(i) == element) {
            return i;
        }
    }

    return -1;
}

template<class Class>
inline int List<Class>::getSize()const
{
    return size;
}

template<class Class>
inline void List<Class>::add(Class newElement)
{
    Class* temp = new Class[this->getSize() + 1];

    for (int i = 0; i < this->getSize(); i++)
    {
        temp[i] = this->getElement(i);
    }

    temp[this->getSize()] = newElement;
    this->setSize(this->getSize() + 1);

    if (list) {
        delete[] list;
    }
    list = temp;
}

template<class Class>
inline void List<Class>::del(int position)
{
    Class* temp = new Class[this->getSize() - 1];

    for (int i = 0; i < this->getSize() - 1; i++)
    {
        if (i == position) {
            temp[i] = this->getElement(this->getSize() - 1);
        }
        else
        {
            temp[i] = this->getElement(i);
        }

    }
    this->setSize(this->getSize() - 1);

    if (list) {
        delete[] list;
    }
    list = temp;
}

template<class Class>
inline void List<Class>::update(int position, Class newElement)
{
    list[position] = newElement;
}

template<class Class>
inline Class List<Class>::getElement(int position) const
{
    return list[position];
}

template<class Class>
inline void List<Class>::bubblesort()
{
    for (int i = 0; i < this->getSize() - 1; i++)
    {
        for (int j = 0; j < this->getSize() - i - 1; j++)
        {
            if (this->getElement(j) < this->getElement(j + 1)) {
                Class temp = this->getElement(j);

                this->update(j, this->getElement(j + 1));
                this->update(j + 1, temp);
            }
        }
    }
}

//------------------------------------------------------------------------------------------------ Operator overloads //

template<class Class>
inline List<Class>& List<Class>::operator=(const List<Class>& rList)
{
    if (this != &rList) {

        if (list) {
            delete[] list;
        }
        list = new Class[rList.getSize()];

        for (int i = 0; i < rList.getSize(); i++)
        {
            list[i] = rList.getElement(i);
        }
        this->setSize(rList.getSize());
    }

    return *this;
}

template<class Class>
inline std::ostream& operator<<(std::ostream& os, List<Class> list)
{

    for (int i = 0; i < list.getSize(); i++)
    {
        os << list.getElement(i) << "\n";
    }

    return os;
}



#endif //LAB_2_SD_LIST_H

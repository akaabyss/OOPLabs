#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MyVector
{
    class Node
    {
    public:
        Node(const T &_data)
        {
            data = _data;
            next = nullptr;
        }
        T data;
        Node *next;
        ~Node()
        {
            next = nullptr;
        }
    };
    Node *head;

public:
    MyVector()
    {
        head = nullptr;
    }
    // size_t lastIndex()
    // {
    //     return
    // }

    Node *begin()
    {
        return head;
    }

    // последний элемент
    Node *end()
    {
        if (head)
        {
            Node *p = head;
            while (p->next != nullptr)
            {
                p = p->next;
            }
            return p;
        }
        else
        {
            return head;
        }
    }
    // добавление
    void addElement(const T &data)
    {
        if (head)
            end()->next = new Node(data);
        else
        {
            head = new Node(data);
        }
    }
    // групповое добавление
    void addElements(vector<T> elements)
    {
        for (size_t i = 0; i < elements.size(); ++i)
            addElement(elements[i]);
    }
    // замена
    void replace(const T &oldValue, const T &newValue)
    {
        Node *p = head;
        while (p != nullptr)
        {
            if (p->data == oldValue)
            {
                p->data = newValue;
            }
            p = p->next;
        }
    }

    T &operator[](size_t index)
    {
        if (index <= size() - 1)
        {
            Node *p = head;
            for (size_t i = 0; i < index; i++)
            {
                p = p->next;
            }
            return p->data;
        }
    }
    // поиск элемента
    Node *getIteratorFromIndex(size_t index)
    {
        if (index < size())
        {
            Node *p = head;
            for (size_t i = 0; i < index; i++)
            {
                p = p->next;
            }
            return p;
        }
        else
        {
            return nullptr;
        }
    }
    T &search(T element)
    {
        Node *p = head;
        while (p != nullptr)
        {
            if (p->data == element)
                return &p->data;
            p = p->next;
        }
        return nullptr;
    }
    // подсчет количества элементов
    size_t count(T element)
    {
        Node *p = head;
        size_t count = 0;
        while (p != nullptr)
        {
            if (p->data == element)
                count += 1;
            p = p->next;
        }
        return count;
    }
    // Пересечение
    MyVector<T> intersectWith(MyVector<T> other)
    {
        MyVector<T> result;

        Node *p = other.head;

        while (p)
        {
            if (count(p->data) > 0)
            {
                result.addElement(p->data);
            }
            p = p->next;
        }

        return result;
    }
    // short searchIndexOfFirstElementThisGroup(vector<T> elements)
    // {
    //     Node *p = head;
    //     size_t cnt = count(elements[0]);
    //     if (cnt == 0)
    //         return -1;
    //     for (size_t i = 0; i < cnt; i++)
    //     {
    //         while (p != nullptr && p->data != elements[0])
    //         {
    //             // ищем начало искомого списка
    //             p = p->next;
    //         }
    //         // если не нашли, -1
    //         if (p == nullptr)
    //             return -1;
    //         // если нашли, нужно сохранить начало этого списка
    //         Node *p2 = p;
    //         // смотрим следующие элементы
    //         for (size_t i = 0; i < elements.size(); i++)
    //         {
    //             if (elements[i] == p2->data)
    //             {
    //                 p2 = p2->next;
    //             }
    //             else
    //             {
    //                 // если какой-то элемент не совпадает, -1
    //                 return -1;
    //             }
    //         }
    //     }
    // }

    // добавление группы

    void addGroup(Node *first, Node *last)
    {
        for (auto it = first; it != last; ++it)
        {
            add(*it);
        }
    }
    // удаление группы
    // если группа есть, удаляем ее

    void removeGroup(Node *first, Node *last)
    {
        if (containsGroup(first, last))
        {
            Node *p = head;
            size_t number = count(first->data); // считаем количество вхождений
            for (size_t i = 0; i < number; ++i)
            {
                // ищем вхождение
                while (p->next->data != first->data)
                {
                    p = p->next;
                }
                // смотрим после этого элемента
                auto x = getSubListFromTo(first, last), y = getSubList(p, getSubListFromTo(first, last).size());
                if (vectorEquals(getSubListFromTo(first, last), getSubList(p, getSubListFromTo(first, last).size())))
                {
                    for (size_t i = 0; i < getSubListFromTo(first, last).size(); i++)
                    {
                        removeElementFromIndex(getIndexOfThisIterator(p) - 1);
                    }
                }
            }
        }
    }
    // поиск группы

    bool containsGroup(Node *first, Node *last)
    {
        size_t number = count(first->data); // считаем количество вхождений
        Node *p = head;

        for (size_t i = 0; i < number; ++i)
        {
            // ищем вхождение
            while (p->data != first->data)
            {
                p = p->next;
            }
            // смотрим после этого элемента
            if (vectorEquals(getSubListFromTo(first, last), getSubList(p, getSubListFromTo(first, last).size())))
            {
                return 1;
            }
        }
        return 0;
    }
    bool vectorEquals(vector<T> one, vector<T> two)
    {
        if (one.size() == two.size())
        {
            for (size_t i = 0; i < one.size(); i++)
            {
                if (one[i] != two[i])
                    return 0;
            }
            return 1;
        }
        else
            return 0;
    }
    vector<T> getSubList(Node *beginIt, size_t countOfElements)
    {
        Node *p = head;
        while (p != beginIt)
        {
            p = p->next;
        }
        vector<T> result;
        if (getIndexOfThisIterator(p) + countOfElements - 1 < size())
        {

            for (size_t i = 0; i < countOfElements; ++i)
            {
                result.push_back(p->data);
                // if (p->next)
                p = p->next;
            }
        }
        return result;
    }
    vector<T> getSubListFromTo(Node *from, Node *to)
    {
        vector<T> result;
        Node *p = from;
        while (p != to)
        {
            result.push_back(p->data);
            p = p->next;
        }
        return result;
    }
    short getIndexOfThisIterator(Node *iterator)
    {
        Node *p = head;
        size_t index = 0;
        while (p)
        {
            if (p == iterator)
                return index;
            p = p->next;
            index += 1;
        }
    }
    // индекс первого фхождения этого элемента КАК СДЕЛАТЬ ЕГО ЕЩЕ И С *?
    short getIndexOfThisElement(T element)
    {
        if (head)
        {
            size_t index = 0;
            Node *p = head;
            while (p->next != nullptr)
            {

                if (p->data == element)
                {
                    return index;
                }
                index += 1;
                p = p->next;
            }
            return -1;
        }
    }
    // размер
    size_t size()
    {
        Node *p = head;
        size_t size = 0;
        while (p != nullptr)
        {
            p = p->next;
            size += 1;
        }
        return size;
    }
    friend ostream &operator<<(ostream &stream, const MyVector &object)
    {
        Node *p = object.head;
        while (p != nullptr)
        {
            stream << p->data << ' ';
            p = p->next;
        }
        return stream;
    }
    // удаление элемента по индексу
    void removeElementFromIndex(size_t index)
    {
        if (index > 0 && index <= size())
        {
            Node *p = head;
            for (size_t i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            Node *del = p->next;
            p->next = del->next;
            del->next = nullptr;
            delete del;
        }
        else if (index == 0)
        {
            delFromHead();
        }
    }
    // удаление из голвоы
    void delFromHead()
    {
        if (head)
        {
            Node *p = head;
            head = head->next;
            p->next = nullptr;
            delete p;
        }
    }
    // максимальный элемент
    T maxElement(vector<T> elements)
    {
        T maxx = elements[0];
        for (size_t i = 1; i < elements.size(); ++i)
        {
            if (elements[i] > maxx)
                maxx = elements[i];
        }
        return maxx;
    }
    // удаление элементов по индексам
    void removeElementsFromIndexes(vector<size_t> indexes)
    {
        // если максимальный индекс меньше размера MyVector
        if (maxElement(indexes) < size())
            for (size_t i = indexes.size() - 1; i > 0; i--)
            {
                removeElementFromIndex(i);
            }
    }
    // объединение списков
    MyVector<T> combineWith(const MyVector<T> &other)
    {
        MyVector<T> result;
        Node *current = other.head;
        while (current != nullptr)
        {
            if (count(current->data) == 0)
                result.addElement(current->data);
            current = current->next;
        }
        return result;
    }
    // очистка
    void clear()
    {
        while (head != nullptr)
        {
            removeElementFromIndex(0);
        }
    }
    ~MyVector()
    {
        clear();
    }
};

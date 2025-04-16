#include <iostream>
#include <cmath>
/*
Базовый конструктор+
Конструктор копирования+
Оператор присваивания копированием+
Деструктор+
Методы:
resize;+
reserve;+
shrink_to_fit;+
front;+
back;+
size;+
empty;+
capacity;+
push_back;+
insert+
erase+
Оператор []+
*/

class MyVector
{

    int* m_arr;
    size_t m_size;
    size_t m_cap;

public:

    MyVector()
    {
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }

    MyVector(size_t size)
    {
        m_size = size;
        m_cap = m_size;
        m_arr = new int[m_size];
    }
     

    MyVector(const MyVector& other) : MyVector{other.m_size}
    {
        std::copy(other.m_arr, other.m_arr + other.m_size, m_arr);
    }

    ~MyVector()
    {
        if(m_arr != nullptr)
            delete[] m_arr;
    }

    MyVector& operator=(const MyVector& other)
    {
        
        if(this != &other)
        {
        int* tmp = new int[other.m_size];

        std::copy(other.m_arr, other.m_arr + other.m_size, tmp);
            
        delete[] m_arr;

        m_arr = tmp;
        m_cap = other.m_cap;
        m_size = other.m_size;
        }

        return *this;
    }

    void push_back(int value)
    {
        if(m_size + 1 <= m_cap)
        {
            m_arr[m_size] = value;
            m_size++;
        }
        else
        {
            m_size++;
            m_cap = m_cap*2 + 1;
            int* tmp = new int[m_cap];
            
            std::copy(m_arr, m_arr + m_size-1, tmp);
            tmp[m_size-1] = value;
            delete[] m_arr;
            m_arr = tmp;
        }
    }

    size_t size()
    {
        return m_size;
    }

    size_t capacity()
    {
        return m_cap;
    }

    void reserve(size_t cap)
    {
        m_cap = cap;
        int* tmp = new int[m_cap];

        std::copy(m_arr, m_arr + m_size, tmp);
        
        delete[] m_arr;
        m_arr = tmp;
    }

    void shrink_to_fit()
    {
        m_cap = m_size;
        int* tmp = new int[m_cap];
        std::copy(m_arr, m_arr + m_size, tmp);
        delete[] m_arr;
        m_arr = tmp;
    }

    int& back()
    {
        return m_arr[m_size-1];
    }

    int& front()
    {
        return m_arr[0];
    }
    
    int& operator[](size_t index)
    {
        return m_arr[index];
    }

    bool empty()
    {
        return (m_size==0);
    }

    void erase(size_t index_1, size_t index_2)
    {
        if(index_1 < 0 || index_1 >=m_size || index_1 < 0 || index_1 >=m_size || index_1 > index_2)
            return;


        
        for(size_t i = index_1; i<=index_2; i++)
            m_arr[i] = 0;
        for(int i = index_1; i < m_size - (index_2 - index_1 + 1); i++)
            m_arr[i] = m_arr[i + index_2 - index_1 + 1];

        m_size = m_size - (index_2 - index_1 + 1);
        m_cap = m_cap - (index_2 - index_1 + 1);
        
    }

    void resize(size_t value)
    {
        m_size = value;
    }

    void insert(int value, size_t index)
    {
        if(index>=0 && index < m_size && value <= INT_MAX)
        {
            int* tmp = new int[m_size+1];
            m_size++;
            std::copy(m_arr, m_arr + index, tmp);
            tmp[index] = value;
            std::copy(m_arr + index, m_arr + m_size-1, tmp + index+1);
            delete[] m_arr;
            m_arr = tmp;
            m_cap++;
        }
    }

};

int main()
{

    MyVector A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    //A[2] = 67;
    //A.reserve(100);
    //MyVector B;
    //B = A;
    //A.shrink_to_fit();
    A.insert(123, 1);
    //A.erase(0, 1);
    //A.resize(6);
    for(int i = 0; i < A.size(); i++)
        std::cout << A[i] << std::endl;
    //std::cout << A.capacity();

    

    return 0;
}
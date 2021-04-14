#pragma once
#include<iostream>

using usi = unsigned short int;

template<typename T>
class Vector
{
    private:
    T* data;
    usi size;
    usi capacity;

    void destroy()
    {
        delete[] data;
    }
    
    void resize()
    {
        capacity += 8;
        T* newBuffer = new T[capacity];
        for(usi i = 0; i < size; i++)
        {
            newBuffer[i] = data[i];
        }
        destroy();
        data = newBuffer;
    }

    public:

    Vector()
    {
        capacity = 8;
        size = 0;
        data = new T[capacity];
    }

    Vector(const Vector<T>& others)
    {
        copy(others);   
    }

    void copy(const Vector<T>& others)
    {
        capacity = others.capacity;
        size = others.size;
        data = new T[capacity];

        for(usi i = 0; i < size; i++)
        {
            data[i] = others.data[i];
        }
    }

    Vector<T>& operator=(const Vector<T>& others)
    {
        if(this != &others)
        {
            destroy();
            copy(others);
        }
        return *this;
    }

    ~Vector()
    {
        destroy();   
    }

    usi getSize() const
    {
        return size;
    }

    usi getCapacity() const
    {
        return capacity;
    }

    T& at(usi i)
    {
        if(i < size)
        {
            return data[i];
        }
        throw;
    }

    T operator[](usi i) const
    {
        return at(i);
    }

    T& operator[](usi i)
    {
        return at(i);
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void push_back(const T& newElem)
    {
        if(size == capacity)
        {
            resize();
        }
        data[size++] = newElem;
    }

    void pop_back()
    {
        size--;
    }

    //void toFile(const char* fileName)
    //{
    //    std::ofstream output(fileName, std::fstream::app);
    //
    //    if(output.is_open())
    //    {
    //        for(int i = 0; i < size; i++)
    //        {
    //            output << data[i] << " ";
    //        }
    //        output << "\n";
    //        output.close();
    //    }
    //    else
    //    {
    //        std::cout << "File " << fileName << " not opened" << std::endl;
    //    }
    //}
};
#pragma once
#include <iostream>

using usi = unsigned short int;

class String
{
    private:

    char* data;
    usi length;
    usi capacity;

    void copy(const String&);
    void destroy();
    void resize();
    void resize(usi size);
    //char& at(unsigned short int) const;

    public:

    String();
    String(const String&);
    String(const char*);
    String(const char);
    void copy(const char*);
    String& operator=(const char *);
    String& operator=(const String&);
    ~String();

    const bool isEmpty() const;
    usi getLength() const;
    usi getCapacity() const;
    //char* begin() const;
    //char* end() const;
    //char* rbegin() const;
    //char* rend() const;
    char operator[](usi) const;
    char& operator[](usi);

    void copyString(char*, usi, usi);
    void shrink_to_fit();
    void push_back(const char&);
    void push_back(const char *);
    void push_back(const String&);
    //void pop_back();
    void swap(String);

    const bool operator==(const String&);
    
    friend std::ostream& operator<<(std::ostream& out, const String&);
};

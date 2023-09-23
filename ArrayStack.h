#pragma once
#include "TDAPila.h"
class ArrayStack :
    public TDAPila
{
private:
    Object** array;
    int capacidad;
    void resize();
public:
    ArrayStack();
    ~ArrayStack();
    virtual void push(Object*) override;
    virtual Object* pop() override;
    virtual Object* top() override;
    virtual void clear() override;
    virtual bool isEmpty() override;
    virtual void print() override;
};


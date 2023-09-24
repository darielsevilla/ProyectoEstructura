#pragma once
#include "TDACola.h"
class CircularQueue :
    public TDACola
{
private:
    Object** array;
    int capacidad;
    int primero;
    int ultimo;
    void resize();
public:
    CircularQueue();
    virtual void queue(Object*) override;
    virtual Object* dequeue() override;
    virtual void clear() override;
    virtual Object* peek() override;
    virtual void print() override;
    ~CircularQueue();
};


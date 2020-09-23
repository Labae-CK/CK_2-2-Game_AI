#pragma once
#include "Pizza.h"
class CKPizza :
    public Pizza
{
public:
    CKPizza() 
    {
        SetName("CK Style Pizza Margherita");
        SetDough("A little bit thin dough");
        SetSauce("Secret Tomato Sauce");
        AddTopping("Mozzarella Cheese");
        AddTopping("Basil");
    }
    virtual ~CKPizza() = default;
};


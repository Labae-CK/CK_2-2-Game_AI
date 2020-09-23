#pragma once
#include "PizzaStore.h"
#include "CKPizza.h"

class CKPizzaStore :
    public PizzaStore
{
public:
    CKPizzaStore() = default;
    virtual ~CKPizzaStore() = default;

    Pizza* CreatePizza(std::string type) override
    {
        if (type == "Mozzarella Cheese")
        {
            return new CKPizza();
        }
        else
        {
            return nullptr;
        }
    }
};


#ifndef STATIONERY_H
#define STATIONERY_H

#include <iostream>
#include <string>

class Stationery {
protected:
    std::string name;    // Название товара
    double price;        // Цена товара

public:
    Stationery(const std::string& name, double price);
    virtual ~Stationery() {}

    virtual void display() const; // Отображение информации о товаре
    virtual void updatePrice(double newPrice); // Изменение цены товара

    virtual double getPrice() const { return price; } // Получение цены
    virtual std::string getName() const { return name; }

    // Виртуальный метод для дополнительных данных
    virtual void extraInfo() const = 0;
};

#endif // STATIONERY_H


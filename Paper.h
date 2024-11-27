#ifndef PAPER_H
#define PAPER_H

#include "Stationery.h"

class Paper : public Stationery {
    int pages; // Количество страниц

public:
    Paper(const std::string& name, double price, int pages);
    void setPages(int newPages); // Установить количество страниц
    void extraInfo() const override; // Реализация виртуальной функции

    void display() const override; // Переопределение метода
};

#endif // PAPER_H


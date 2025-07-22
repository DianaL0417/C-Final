// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
public:
    std::string customerName;
    std::string date;
    std::string item;
    int quantity;

    Order();
    Order(std::string name, std::string date, std::string item, int quantity);

    std::string toString() const;
};

#endif
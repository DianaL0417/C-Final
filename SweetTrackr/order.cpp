// Order.cpp
#include "Order.h"
#include <sstream>
#include <exception>

Order::Order() {
    customerName = "";
    date = "";
    item = "";
    quantity = 0;
}

Order::Order(std::string name, std::string date, std::string item, int quantity) {
    this->customerName = name;
    this->date = date;
    this->item = item;
    this->quantity = quantity;
}

std::string Order::toString() const {
    std::ostringstream oss;
    oss << customerName << " | " << date << " | " << item << " x" << quantity;
    return oss.str();
}

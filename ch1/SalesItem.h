#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
#include <string>
#include <sstream>

namespace latenight {
  class SalesItem {
    // private:
    // made public for time being need to find how this is handled
    public:
      std::string m_isbn;
      int m_copiesSold;
      double m_revenue;
      double m_averagePrice;
      std::string randomInput;

    public:
      SalesItem();
      SalesItem(std::string isbn);
      friend SalesItem operator+(const SalesItem &item1, const SalesItem &item2);
      // friend is used allow another class to have access to to private members of SalesItem
      friend std::ostream &operator<<(std::ostream &os, const SalesItem &item);
      friend std::istream &operator>>(std::istream &is, SalesItem &item);

    private:
      void init();
  };
}

#endif

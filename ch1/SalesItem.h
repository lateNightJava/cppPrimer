#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>

namespace latenight {
  class SalesItem {
    private:
      std::string m_isbn;
      int m_copiesSold;
      double m_revenue;
      double m_averagePrice;

    public:
      SalesItem();
      SalesItem(std::string isbn);
      friend std::ostream& operator<<(std::ostream& os, const SalesItem& item);
  };
}

#endif

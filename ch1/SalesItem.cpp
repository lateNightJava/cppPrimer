#include "SalesItem.h"

namespace latenight {
  SalesItem::SalesItem() {
    m_isbn = "";
    m_copiesSold = 0;
    m_revenue = 0.00;
    m_averagePrice = 0.00;
  }

  SalesItem::SalesItem(std::string isbn) {
    m_isbn = isbn;
    m_copiesSold = 0;
    m_revenue = 0.00;
    m_averagePrice = 0.00;
  }

  std::ostream& operator<<(std::ostream& os, const SalesItem& item) {
    os << "isbn: " << item.m_isbn << std::endl;
    os << "copies sold: " << item.m_copiesSold << std::endl;
    os << "revenue: $" << item.m_revenue << std::endl;
    os << "average price: $" << item.m_averagePrice << std::endl;
    os << std::endl;

    return os;
  }
}

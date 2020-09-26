#include "SalesItem.h"

namespace latenight {
  SalesItem::SalesItem() {
    init();
  }

  SalesItem::SalesItem(std::string isbn) {
    init();
    m_isbn = isbn;
  }

  void SalesItem::init() {
    m_isbn = "";
    m_copiesSold = 0;
    m_revenue = 0.00;
    m_averagePrice = 0.00;
  }

  std::string SalesItem::isbn() {
    return m_isbn;
  }

  // how does this work?
  // parameters use '&' to use the same objects with different name, (alias)
  // return type says it returns the same "cout" object
  // I somewhat understand but maybe as time goes on it will be clearer
  std::ostream &operator<<(std::ostream &os, const SalesItem &item) {
    os << "isbn: " << item.m_isbn << std::endl;
    os << "copies sold: " << item.m_copiesSold << std::endl;
    os << "revenue: $" << item.m_revenue << std::endl;
    os << "average price: $" << item.m_averagePrice << std::endl;
    os << std::endl;

    return os;
  }

  // more to help understand
  // cin >> item is the same as saying >>(cin, item)
  // normally cin is expecting basic data types (or string)
  // but by overloading it it is able to handle the input differently
  // return type says it returns the same "cin" object
  std::istream &operator>>(std::istream &is, SalesItem &item) {
    std::string isbn = "";
    int copiesSold = 0;
    double pricePerBook = 0.00;

    for (int step = 0; step < 3; step++) {
      switch(step) {
        case 0:
          is >> isbn;
          break;
        case 1:
          is >> copiesSold;
          // std::cout << "tempVal = " << tempVal << " copiesSold = " << copiesSold << std::endl;
          break;
        case 2:
          is >> pricePerBook;
          // std::cout << "tempVal = " << tempVal << " pricePerBook = " << pricePerBook << std::endl;
          break;
      }
    }
    // something to note if "const SalesItem& item" this portion will not compile
    // use setters instead?
    item.m_isbn = isbn;
    item.m_copiesSold = copiesSold;
    item.m_revenue = copiesSold * pricePerBook;
    item.m_averagePrice = pricePerBook;

    return is;
  }

  // not the const is used to prevent re-assingnments
  // "item1 + item2" is like saying +(item1, item2)
  SalesItem operator+(const SalesItem &item1, const SalesItem &item2) {
    SalesItem salesItem;

    if (item1.m_isbn == item2.m_isbn) {
      salesItem.m_isbn = item1.m_isbn;
      salesItem.m_copiesSold = item1.m_copiesSold + item2.m_copiesSold;
      salesItem.m_revenue = item1.m_revenue + item2.m_revenue;
      salesItem.m_averagePrice = salesItem.m_revenue / salesItem.m_copiesSold;
    }

    return salesItem;
  }
}









// this was for thinking a one line input was one string however cin handles
// spaces as seperate inputs
// for (int i = 0; i <= input.length(); i++) {
//   std::cout << "i = " << i << std::endl;
//   if (i < input.length() && input[i] != ' ') {
//     tempVal += input[i];
//   } else {
//     std::cout << "tempVal = " << tempVal << std::endl;
//     std::cout << "step = " << step << std::endl;
//     switch(step) {
//       case 0:
//         isbn = tempVal;
//         break;
//       case 1:
//         std::istringstream(tempVal) >> copiesSold;
//         // std::cout << "tempVal = " << tempVal << " copiesSold = " << copiesSold << std::endl;
//         break;
//       case 2:
//         std::istringstream(tempVal) >> pricePerBook;
//         // std::cout << "tempVal = " << tempVal << " pricePerBook = " << pricePerBook << std::endl;
//         break;
//       default:
//         std::cout << "Wrong step." << std::endl;
//     }
//
//     tempVal = "";
//     step++;
//   }
// }

#include <iostream>
#include "SalesItem.h"

int main() {
  latenight::SalesItem salesItem("testISBN");
  std::cout << "Item info: " << std::endl << salesItem << std::endl;

  // std::cout << "Enter info: " << std::flush;
  // std::cin >> salesItem;

  latenight::SalesItem salesItem2;
  latenight::SalesItem salesItem3;
  std::cout << "Enter info: " << std::flush;
  std::cin >> salesItem2 >> salesItem3;
  std::cout << "Item2 info: " << std::endl << salesItem2 << std::endl;
  std::cout << "Item3 info: " << std::endl << salesItem3 << std::endl;

  std::cout << "End of main" << std::endl;

  return 0;
}

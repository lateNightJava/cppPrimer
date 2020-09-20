#include <iostream>
#include "SalesItem.h"

int main() {
  latenight::SalesItem salesItem("testISBN");

  std::cout << "Item info: " << salesItem << "End of Info" << std::endl;

  return 0;
}

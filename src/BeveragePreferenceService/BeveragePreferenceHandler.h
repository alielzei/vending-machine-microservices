#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void getBeverage(std::string &_return, const BeverageType::type btype);
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

void BeveragePreferenceServiceHandler::getBeverage(std::string &_return, const BeverageType::type btype) {
    int r = rand()%3;

    if (btype == BeverageType::type::COLD) {
      if (r == 0) _return = "lemonade";
      else if (r == 1) _return = "ice tea";
      else if (r == 2) _return = "soda";
    } else {
      if (r == 0) _return = "cappuccino";
      else if (r == 1) _return = "latte";
      else if (r == 2) _return = "espresso";
    }
    return;
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H


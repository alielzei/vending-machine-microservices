#ifndef VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeverageServiceHandler : public BeverageServiceIf {
 public:
  BeverageServiceHandler();
  ~BeverageServiceHandler() override=default;

  BeverageName::type GetBeverage(const BeverageType btype) override;
};

// Constructor
BeverageServiceHandler::BeverageServiceHandler() {

}

// Remote Procedure "PlaceOrder"

BeverageName::type BeverageServiceHandler::GetBeverage(const BeverageType btype) {
     // Your implementation goes here
     printf("GetBeverage\n");

    // randomly select a beverage
    auto beverages = {BeverageName::CAPPUCCINO, BeverageName::ESPRESSO, BeverageName::LATTE, BeverageName::LEMONADE, BeverageName::ICETEA, BeverageName::SODA};
    if (btype == BeverageType::HOT) { return beverages[rand()%3]; }
    else { return beverages[rand()%3 + 3]; }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H


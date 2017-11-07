#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include "LinkedListOfInts.h"

class test {
public:
  test();
  void runTests();

  bool isEmptyCp(LinkedListOfInts test); //Cp: copy
  std::string isEmptyWAE(); //WAE: Works as expected

  int sizeCp(LinkedListOfInts test);
  std::string sizeWAE();

  bool searchCp(LinkedListOfInts test, int testValue);
  std::string searchWAE();

  LinkedListOfInts addBackCp(LinkedListOfInts test, int testValue);
  std::string addBackWAE();

  LinkedListOfInts addFrontCp(LinkedListOfInts test, int testValue);
  std::string addFrontWAE();

  bool removeBackCp(LinkedListOfInts test);
  std::string removeBackWAE();

  bool removeFrontCp(LinkedListOfInts test);
  std::string removeFrontWAE();

};

#endif

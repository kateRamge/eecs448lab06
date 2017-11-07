#include "test.h"

test::test() {

}

void test::runTests() {
  std::cout<<"\n"<<isEmptyWAE()<<"\n";
  std::cout<<"\n"<<sizeWAE()<<"\n";
  std::cout<<"\n"<<searchWAE()<<"\n";
  std::cout<<"\n"<<addBackWAE()<<"\n";
  std::cout<<"\n"<<addFrontWAE()<<"\n";
  std::cout<<"\n"<<removeBackWAE()<<"\n";
  std::cout<<"\n"<<removeFrontWAE()<<"\n";
}

bool test::isEmptyCp(LinkedListOfInts test){
  return test.isEmpty();
}
std::string test::isEmptyWAE(){
  std::string returner = "\n-+-+- isEmptyWAE -+-+-\n";
  /*case 1: empty list*/
  LinkedListOfInts tester;
  if(!this->isEmptyCp(tester)) {
    returner += "ERROR! -+-+- New linkedList is considered not empty.\n";
  }
  /*case 2: list that used addback once*/
  LinkedListOfInts tester2;
  tester2 = addBackCp(tester2, 7);
  if(this->isEmptyCp(tester2)) {
    returner += "ERROR! -+-+- LinkedList is considered empty after calling addBack function.\n";
  }
  /*case 3: list that used addfront once*/
  LinkedListOfInts tester3;
  tester3 = addFrontCp(tester3, 7);
  if(this->isEmptyCp(tester3)) {
    returner += "ERROR! -+-+- LinkedList is considered empty after calling addFront function.\n";
  }
  return returner;
}

int test::sizeCp(LinkedListOfInts test){
  return test.size();
}
std::string test::sizeWAE(){
  std::string returner = "\n-+-+- sizeWAE -+-+-\n";
  /*case 1: empty list*/
  LinkedListOfInts tester;
  if(!(this->sizeCp(tester) == 0)) {
    returner += "ERROR! -+-+- New linkedList does not have size of zero.\n";
  }
  /*case 2: list that used addback twice*/
  LinkedListOfInts tester2;
  tester2 = addBackCp(tester2, 7);
  tester2 = addBackCp(tester2, 7);
  if(!(this->sizeCp(tester2) == 2)) {
    returner += "ERROR! -+-+- LinkedList does not have size of two after calling addback function twice.\n";
  }
  /*case 3: list that used addfront twice*/
  LinkedListOfInts tester3;
  tester3 = addFrontCp(tester3, 7);
  tester3 = addFrontCp(tester3, 7);
  if(!(this->sizeCp(tester3) == 2)) {
    returner += "ERROR! -+-+- LinkedList does not have size of two after calling addfront function twice.\n";
  }
  /*case 4: list that used addback twice and removeback once*/
  LinkedListOfInts tester4;
  tester4 = addBackCp(tester4, 7);
  tester4 = addBackCp(tester4, 7);
  if(!this->removeBackCp(tester4)) {
    returner += "__________ERROR: could not remove back from a linkedlist that had addback called twice.\n";
  }
  if(!(this->sizeCp(tester4) == 1)) {
    returner += "ERROR! -+-+- LinkedList does not have size of one after calling addback function twice and remove back function once.\n";
  }
  /*case 5: list that used addfront twice and removefront once*/
  LinkedListOfInts tester5;
  tester5 = addFrontCp(tester5, 7);
  tester5 = addFrontCp(tester5, 7);
  if(!this->removeFrontCp(tester5)) {
    returner += "__________ERROR: could not remove front from a linkedlist that had addfront called twice.\n";
  }
  if(!(this->sizeCp(tester5) == 1)) {
    returner += "ERROR! -+-+- LinkedList does not have size of one after calling addfront function twice and remove front function once.\n";
  }
  return returner;
}

bool test::searchCp(LinkedListOfInts test, int testValue){
  return test.search(testValue);
}
std::string test::searchWAE(){
  std::string returner = "\n-+-+- searchWAE -+-+-\n";
  /*case 1: empty list*/
  LinkedListOfInts tester;
  if(this->searchCp(tester, 7)) {
    returner += "ERROR! -+-+- New linkedList which should be empty has found a 7.\n";
  }
  /*case 2: addback twice search for number added*/
  LinkedListOfInts tester2;
  tester2 = addBackCp(tester2, 4);
  tester2 = addBackCp(tester2, 7);
  if(!this->searchCp(tester2, 7)) {
    returner += "ERROR! -+-+- LinkedList which should have a 7 did not find a 7.\n";
  }
  if(!this->searchCp(tester2, 4)) {
    returner += "ERROR! -+-+- LinkedList which should have a 4 did not find a 4.\n";
  }
  /*case 3: addback twice search for number not added*/
  LinkedListOfInts tester3;
  tester3 = addBackCp(tester3, 4);
  tester3 = addBackCp(tester3, 7);
  if(this->searchCp(tester3, 5)) {
    returner += "ERROR! -+-+- LinkedList which does not have a 5 has found a 5.\n";
  }

  return returner;
}

LinkedListOfInts test::addBackCp(LinkedListOfInts test, int testValue){
  test.addBack(testValue);
  return test;
}
std::string test::addBackWAE(){
  std::string returner = "\n-+-+- addBackWAE -+-+-\n";
  LinkedListOfInts tester;
  for (int i = 0; i < 15; i++) {
    tester = addBackCp(tester, i);
  }
  std::vector<int> vectorTester = tester.toVector();
  //from stackoverflow
  //stackoverflow.com/questions/10750057/how-to-print-out-the-contents-of-a-vector
  int k = 0;
  int m;
  bool store = 1;
  for(std::vector<int>::const_iterator j = vectorTester.begin(); j != vectorTester.end(); j++) {
    //std::cout<<*j<<" ";
    m = *j;
    store &= (m==k);
    k++;
  }
  if(!store) {
    returner += "ERROR! -+-+- addBack is not working properly.\n";
  }
  return returner;
}

LinkedListOfInts test::addFrontCp(LinkedListOfInts test, int testValue){
  test.addFront(testValue);
  return test;
}
std::string test::addFrontWAE() {
  std::string returner = "\n-+-+- addFrontWAE -+-+-\n";
  LinkedListOfInts tester;
  for (int i = 0; i < 15; i++) {
    tester = addFrontCp(tester, i);
  }
  std::vector<int> vectorTester = tester.toVector();
  //from stackoverflow
  //stackoverflow.com/questions/10750057/how-to-print-out-the-contents-of-a-vector
  int k = 14;
  int m;
  bool store = 1;
  for(std::vector<int>::const_iterator j = vectorTester.begin(); j != vectorTester.end(); j++) {
    m = *j;
    //std::cout<<*j<<" "<< m <<" "<< (m==k);
    store &= (m==k);
    k--;
  }
  if(!store) {
    returner += "ERROR! -+-+- addFront is not working properly.\n";
  }
  return returner;
}

bool test::removeBackCp(LinkedListOfInts test){
  return test.removeBack();
}
std::string test::removeBackWAE(){
  std::string returner = "\n-+-+- removeBackWAE -+-+-\n";
  /*case 1: empty list*/
  LinkedListOfInts tester;

  return returner;
}

bool test::removeFrontCp(LinkedListOfInts test){
  return test.removeFront();
}
std::string test::removeFrontWAE(){
  std::string returner = "\n-+-+- removeFrontWAE -+-+-\n";
  /*case 1: empty list*/
  LinkedListOfInts tester;

  return returner;
}





//hello world

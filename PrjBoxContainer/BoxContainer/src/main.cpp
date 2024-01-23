// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "BoxContainer/BoxContainer.hpp"

int main(int argc, char* argv[])
{
  TW::BoxContainer container = TW::BoxContainer();

  std::cout << "====== Initial Allocation ======" << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Push Into Container (9 Records) ======" << std::endl;
  std::cout << "====== Expected Contents: 1, 2, 3, 4, 5, 4, 3, 2, 1 ======" << std::endl;
  container.push(1);
  container.push(2);
  container.push(3);
  container.push(4);
  container.push(5);
  container.push(4);
  container.push(3);
  container.push(2);
  container.push(1);
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Remove 2 From Left (8 Records After Operation) ======" << std::endl;
  std::cout << "====== Expected Contents: 1, 1, 3, 4, 5, 4, 3, 2 ======" << std::endl;
  container.remove_first_of(2);
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Remove 3 From Right (7 Records After Operation) ======" << std::endl;
  std::cout << "====== Expected Contents: 1, 1, 3, 4, 5, 4, 2 ======" << std::endl;
  container.remove_first_of(3, true);
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Remove All 1s (5 Records After Operation) ======" << std::endl;
  std::cout << "====== Expected Contents: 2, 4, 3, 4, 5 ======" << std::endl;
  container.remove_all_of(1);
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Remove Duplicate 4s (4 Records After Operation) ======" << std::endl;
  std::cout << "====== Expected Contents: 2, 4, 3, 5 ======" << std::endl;
  container.remove_duplicates_of(4);
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Pop Off Last Record (3 Records After Operation) ======" << std::endl;
  std::cout << "====== Expected Contents: 2, 4, 3 ======" << std::endl;
  std::cout << "Popped Value: " <<  container.pop() << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Compress BoxContainer (3 Records & 3 Reserved After Operation) ======" << std::endl;
  container.compress();
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Push Into Container (Should Auto Expand by Default Increment) ======" << std::endl;
  std::cout << "====== Expected Contents: 2, 4, 3, 4, 5, 6 ======" << std::endl;
  std::cout << "====== Expected Sizes | Reservation: 8, Allocation: 6 ======" << std::endl;
  container.push(4);
  container.push(5);
  container.push(6);
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;


  std::cout << "====== Create New Container via Copy Constructor ======" << std::endl;
  std::cout << "====== Verify Data is Independent by pushing to 1 and poping from other ======" << std::endl;
  TW::BoxContainer container2 = TW::BoxContainer(container);
  std::cout << "------ Pushing 7 to Container 1 ------" << std::endl;
  container.push(7);
  std::cout << "------ Poping 6 from Container 2 ------" << std::endl;
  container2.pop();
  std::cout << "------ Container 1 Contents ------" << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;
  std::cout << "------ Container 2 Contents ------" << std::endl;
  std::cout << "Reservation Size: " <<  container2.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container2.get_allocated() << std::endl;
  std::cout << container2 << std::endl;



  std::cout << "====== Assign New Container the Same values as Container 1 Via Assigment Operator ======" << std::endl;
  std::cout << "------ Creating New Empty Container with size 15 ------" << std::endl;
  TW::BoxContainer container3 = TW::BoxContainer(15);
  std::cout << "------ Container 3 Contents Pre-Assigment ------" << std::endl;
  std::cout << "Reservation Size: " <<  container3.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container3.get_allocated() << std::endl;
  std::cout << container3 << std::endl;
  std::cout << "------ Updating Container 3 with Container 1 Values via Assigment (=) ------" << std::endl;
  container3 = container;
  std::cout << "------ Pushing 8 to Container 1 ------" << std::endl;
  container.push(8);
  std::cout << "------ Pushing 10 to Container 3 ------" << std::endl;
  container3.push(10);
  std::cout << "------ Container 1 Contents ------" << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << container << std::endl;
  std::cout << "------ Container 3 Contents ------" << std::endl;
  std::cout << "Reservation Size: " <<  container3.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container3.get_allocated() << std::endl;
  std::cout << container3 << std::endl;



  std::cout << "====== Sum Container 1 and Container 2 into Container 1 (+= Operator) ======" << std::endl;
  std::cout << "------ Container 1 Contents Pre-Assigment ------" << std::endl;
  std::cout << container << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << "------ Container 2 Contents Pre-Assigment ------" << std::endl;
  std::cout << container2 << std::endl;
  std::cout << "Reservation Size: " <<  container2.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container2.get_allocated() << std::endl;
  container += container2;
  std::cout << "------ Container 1 Contents Post-Assigment ------" << std::endl;
  std::cout << container << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << "------ Container 2 Contents Post-Assigment ------" << std::endl;
  std::cout << container2 << std::endl;
  std::cout << "Reservation Size: " <<  container2.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container2.get_allocated() << std::endl;


  std::cout << "====== Sum Container 1 and Container 3 into new Container (+ Operator) ======" << std::endl;
  std::cout << "------ Container 1 Contents Pre-Operation ------" << std::endl;
  std::cout << container << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << "------ Container 3 Contents Pre-Operation ------" << std::endl;
  std::cout << container3 << std::endl;
  std::cout << "Reservation Size: " <<  container3.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container3.get_allocated() << std::endl;
  TW::BoxContainer container4 = container + container3;
  std::cout << "------ Container 1 Contents Post-Operation ------" << std::endl;
  std::cout << container << std::endl;
  std::cout << "Reservation Size: " <<  container.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container.get_allocated() << std::endl;
  std::cout << "------ Container 3 Contents Post-Operation ------" << std::endl;
  std::cout << container3 << std::endl;
  std::cout << "Reservation Size: " <<  container3.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container3.get_allocated() << std::endl;
  std::cout << "------ Container 4 (New) Contents Post-Operation ------" << std::endl;
  std::cout << container4 << std::endl;
  std::cout << "Reservation Size: " <<  container4.get_reserved() << std::endl;
  std::cout << "Allocation Size: " << container4.get_allocated() << std::endl;

  return 0;
}

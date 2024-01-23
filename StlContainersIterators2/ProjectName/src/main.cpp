// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <functional> // This Library Includes Definitions for System Provided Functors
#include <vector>
#include <array>

#include "STD_Vector.hpp"
#include "STD_Array.hpp"
#include "STD_Deque.hpp"
#include "STD_FWDList.hpp"
#include "STD_List.hpp"
#include "STD_Pair.hpp"
#include "STD_Set.hpp"
#include "STD_Map.hpp"
#include "STD_Stack.hpp"
#include "STD_Queue.hpp"
#include "STD_PriorityQueue.hpp"


int main(int argc, char* argv[])
{ 
  bool run_deque = false;
  bool run_forward_list = false;
  bool run_list = false;
  bool run_pair = false;
  bool run_set = false;
  bool run_map = false;
  bool run_stack = false;
  bool run_queue = false;
  bool run_priority_queue = true;

  if (run_deque) {
    STD_Deque dq_01 = STD_Deque();
    dq_01.execute();
  }
  
  if (run_forward_list) {
    STD_FWDList fwl_01 = STD_FWDList();
    fwl_01.execute();
  }
  
  if (run_list) {
    STD_List list_01 = STD_List();
    list_01.execute();
  }
  
  if (run_pair) {
    STD_Pair pair_01 = STD_Pair();
    pair_01.execute();
  }
  
  if (run_set) {
    STD_Set set_01 = STD_Set();
    set_01.execute();
  }

  if (run_map) {
    STD_Map map_01 = STD_Map();
    map_01.execute();
  }

  if (run_stack) {
    STD_Stack stack_01 = STD_Stack();
    stack_01.execute();
  }

  if (run_queue) {
    STD_Queue queue_01 = STD_Queue();
    queue_01.execute();
  }

  if (run_priority_queue) {
    STD_PriorityQueue pqueue_01 = STD_PriorityQueue();
    pqueue_01.execute();
  }

  return 0;
}

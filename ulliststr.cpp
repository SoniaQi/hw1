#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{ 
  // check if the list is empty
  if (empty()) {
    // create a new item, add val, update parameters
    Item *newI = new Item;
    newI->val[0] = val;
    newI->first = 0;
    newI->last = 1;
    newI->prev = NULL;
    newI->next = NULL;
    // update head_ and tail_ pointers
    head_ = newI;
    tail_ = newI;
    size_ = 1;
  }
  else {
    Item *lastI = tail_;
    if (lastI->last == 10) {
      // when no more space at the back of last item
      // create a new item, add val, update parameters
      Item *newI = new Item;
      newI->val[0] = val;
      newI->first = 0;
      newI->last = 1;
      // update the relationship between previous last item and newI
      newI->prev = tail_;
      tail_->next = newI;
      tail_ = newI;
      newI->next = NULL;
      tail_ = newI;
      size_ += 1;
    }
    else {
      // add val after the last occupied slot 
      lastI->val[lastI->last] = val;
      lastI->last += 1;
      size_ += 1;
    }
  }
}

void ULListStr::pop_back()
{
  Item *lastI = tail_;
  if (lastI->last - lastI->first == 1) {
    // when the current last item only has 1 element
    // update relaitonship between items
    Item *temp = lastI;
    lastI = lastI->prev;
    // update tail_
    tail_=lastI;
    if (lastI!=NULL) {
      // when list is not empty after deletion, update next of lastI
      lastI->next = NULL;
    }
    else {
      // set head_ to null as well
      head_=NULL;
    }
    delete temp;
    size_-=1;
  }
  else 
  {
    // delete the last occupied item, update parameters
    lastI->val[lastI->last-1]="";
    lastI->last--;
    size_-=1;
  }
}

void ULListStr::push_front(const std::string& val) 
{
  // check if the list is empty
  if (empty()) {
    // create a new item, add val, update parameters
    Item *newI = new Item;
    newI->val[9] = val;
    newI->first = 9;
    newI->last = 10;
    newI->prev = NULL;
    newI->next = NULL;
    // update head_ and tail_ pointers
    head_ = newI;
    tail_ = newI;
    size_ = 1;
  }
  else {
    Item *firstI = head_;
    if (firstI->first == 0) {
      // when no more space at the front of last item
      // create a new item, add val, update parameters
      Item *newI = new Item;
      newI->val[9] = val;
      newI->first = 9;
      newI->last = 10;
      // update the relationship between previous first item and newI
      newI->prev = NULL;
      newI->next = firstI;
      firstI->prev = newI;
      head_ = newI;
      size_ += 1;
    }
    else {
      // add val before the first occupied slot
      firstI->val[firstI->first-1] = val;
      firstI->first -= 1;
      size_ += 1;
    }
  }
}

void ULListStr::pop_front(){
  Item* firstI = head_;
  if (firstI->last - firstI->first == 1) {
    // when the current first item only has 1 element
    // update relaitonship between items
    Item *temp = firstI;
    firstI = firstI->next;
    head_=firstI;
    if (firstI!=NULL) {
      // when list is not empty after deletion, update prev of firstI
      firstI->prev = NULL;
    }
    else {
      // set head_ to null as well
      tail_=NULL;
    }
    delete temp;
    size_-=1;
  }
  else {
    // delete the first occupied item, update parameters
    firstI->val[firstI->first]="";
    firstI->first++;
    size_-=1;
  }
  
}

std::string const & ULListStr::back() const 
{
  // return the last occupied slot for tail_
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const 
{
  // return the first occupied slot for head_
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const 
{
  int cnt = 0;
  Item *temp = head_;
  while (cnt+temp->last - temp->first < loc) {
    // while loc is not in the current item, proceed to the next item
    cnt += temp->last - temp->first;
    temp = temp->next;
  }
  if (cnt+temp->last - temp->first == loc) {
    // if loc is after the last, proceed to the next item
    cnt += temp->last - temp->first;
    temp = temp->next;
  }
  // return pointer to val at loc of current item (starting at first)
  return &(temp->val[loc-cnt+temp->first]);
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


#include <string>
#include <vector>
#include <cctype> 
#include <iostream>
#include <memory>
using namespace std;

#ifndef HW06_H
#define HW06_H

class MyIntVector{
   std::shared_ptr<int[]> startptr;
   size_t _capacity=0;
   size_t _size=0;

public: 
   MyIntVector() : _size(0), _capacity(1),startptr(new int[1]) {}
   MyIntVector(size_t s) : _size(0), _capacity(s), startptr(new int[_capacity]) {}
   MyIntVector(size_t s, int value) : _size(0), _capacity(s), startptr(new int[_capacity]) {
       for(int i=0; i<s; i++)
       {
           startptr[_size] = value;
           _size++;
       }
   }
   size_t size() { return _size; }
   size_t capacity() { return _capacity; }
   void push_back(int value) {
       if(_size >= _capacity)
       {
           std::shared_ptr<int[]> old = std::shared_ptr<int[]>(new int[_capacity]);
           startptr.swap(old);
           size_t oldc = _capacity;
           _capacity *= 2;
           _size = 0;
           startptr.reset(new int[_capacity]);

           for(int i=0; i<oldc; i++)
           {
               startptr[_size] = old[i];
               _size++;
           }
       }
       startptr[_size] = value;
       _size++;
   }

   void resize(size_t count) {
       for(int i=0; i<count; i++)
       {
           push_back(0);
       }
   }
   void resize(size_t count, int value) {
       for(int i=0; i<count; i++)
       {
           push_back(value);
       }
   }
   void reserve(size_t newc) {
       std::shared_ptr<int[]> old = std::shared_ptr<int[]>(new int[_capacity]);
       startptr.swap(old);
       size_t oldc = _capacity;
       _capacity = newc;
       _size = 0;
       startptr.reset(new int[_capacity]);

       for(int i=0; i<oldc && i<_capacity; i++)
       {
           startptr[i] = old[i];
           _size++;
       }
   }
   void shrink_to_fit() {
       std::shared_ptr<int[]> old = std::shared_ptr<int[]>(new int[_capacity]);
       startptr.swap(old);
       size_t oldc = _capacity;
       _capacity = _size;
       startptr.reset(new int[_capacity]);

       for(int i=0; i<_size; i++)
       {
           startptr[i] = old[i];
       }
   }
   std::shared_ptr<int[]> get_array()
   {
       return startptr;
   }
   void print() {
       for(int i=0; i<_capacity; i++)
       {
           std::cout<<startptr[i]<<" ";
       }
       std::cout<<"\n";
   }
   ~MyIntVector()
   {
   }
};


#endif 
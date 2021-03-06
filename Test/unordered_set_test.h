﻿#ifndef MYTINYSTL_UNORDERED_SET_TEST_H_
#define MYTINYSTL_UNORDERED_SET_TEST_H_

// unordered_set test : 测试 unordered_set, unordered_multiset 的接口与它们 insert 的性能

#include <unordered_set>

#include "../MyTinySTL/unordered_set.h"
#include "set_test.h"
#include "test.h"

namespace mystl
{
namespace test
{
namespace unordered_set_test
{

void unordered_set_test()
{
  std::cout << "[===============================================================]" << std::endl;
  std::cout << "[-------------- Run container test : unordered_set -------------]" << std::endl;
  std::cout << "[-------------------------- API test ---------------------------]" << std::endl;
  int a[] = { 5,4,3,2,1 };
  mystl::unordered_set<int> us1;
  mystl::unordered_set<int> us2(520);
  mystl::unordered_set<int> us3(520, mystl::hash<int>());
  mystl::unordered_set<int> us4(520, mystl::hash<int>(), mystl::equal_to<int>());
  mystl::unordered_set<int> us5(a, a + 5);
  mystl::unordered_set<int> us6(a, a + 5);
  mystl::unordered_set<int> us7(a, a + 5, mystl::hash<int>());
  mystl::unordered_set<int> us8(a, a + 5, mystl::hash<int>(), mystl::equal_to<int>());
  mystl::unordered_set<int> us9(us5);
  mystl::unordered_set<int> us10(std::move(us5));
  mystl::unordered_set<int> us11 = us6;
  mystl::unordered_set<int> us12 = std::move(us6);
  mystl::unordered_set<int> us13{ 1,2,3,4,5 };
  mystl::unordered_set<int> us14 = { 1,2,3,4,5 };

  FUN_AFTER(us1, us1.insert(a, a + 5));
  FUN_AFTER(us1, us1.insert(5));
  FUN_AFTER(us1, us1.insert_noresize(5));
  FUN_AFTER(us1, us1.erase(us1.begin()));
  FUN_AFTER(us1, us1.erase(1));
  FUN_AFTER(us1, us1.erase(us1.begin(), us1.find(3)));
  FUN_AFTER(us1, us1.clear());
  FUN_AFTER(us1, us1.swap(us7));
  FUN_VALUE(*us1.begin());
  std::cout << std::boolalpha;
  FUN_VALUE(us1.empty());
  std::cout << std::noboolalpha;
  FUN_VALUE(us1.size());
  FUN_VALUE(us1.max_size());
  FUN_VALUE(us1.bucket_count());
  FUN_VALUE(us1.max_bucket_count());
  FUN_AFTER(us1, us1.reserve(1000));
  FUN_VALUE(us1.size());
  FUN_VALUE(us1.bucket_count());
  FUN_VALUE(us1.elems_in_bucket(1));
  FUN_VALUE(us1.elems_in_bucket(2));
  FUN_VALUE(us1.elems_in_bucket(3));
  FUN_VALUE(us1.count(1));
  FUN_VALUE(*us1.find(3));
  auto first = *us1.equal_range(3).first;
  auto second = *us1.equal_range(3).second;
  std::cout << " us1.equal_range(3) : from " << first << " to " << second << std::endl;
  PASSED;
#if PERFORMANCE_TEST_ON
  std::cout << "[--------------------- Performance Testing ---------------------]" << std::endl;
  std::cout << "|---------------------|-------------|-------------|-------------|" << std::endl;
  std::cout << "|       insert        |";
#if MEMORY_IS_ENOUGH
  CON_TEST_P1(unordered_set<int>, insert, rand(), LEN1 _S, LEN2 _S, LEN3 _S);
#else
  CON_TEST_P1(unordered_set<int>, insert, rand(), LEN1 _SS, LEN2 _SS, LEN3 _SS);
#endif
  std::cout << std::endl;
  std::cout << "|---------------------|-------------|-------------|-------------|" << std::endl;
  PASSED;
#endif
  std::cout << "[-------------- End container test : unordered_set -------------]" << std::endl;
}

void unordered_multiset_test()
{
  std::cout << "[===============================================================]" << std::endl;
  std::cout << "[------------ Run container test : unordered_multiset ----------]" << std::endl;
  std::cout << "[-------------------------- API test ---------------------------]" << std::endl;
  int a[] = { 5,4,3,2,1 };
  mystl::unordered_multiset<int> us1;
  mystl::unordered_multiset<int> us2(520);
  mystl::unordered_multiset<int> us3(520, mystl::hash<int>());
  mystl::unordered_multiset<int> us4(520, mystl::hash<int>(), mystl::equal_to<int>());
  mystl::unordered_multiset<int> us5(a, a + 5);
  mystl::unordered_multiset<int> us6(a, a + 5);
  mystl::unordered_multiset<int> us7(a, a + 5, mystl::hash<int>());
  mystl::unordered_multiset<int> us8(a, a + 5, mystl::hash<int>(), mystl::equal_to<int>());
  mystl::unordered_multiset<int> us9(us5);
  mystl::unordered_multiset<int> us10(std::move(us5));
  mystl::unordered_multiset<int> us11 = us6;
  mystl::unordered_multiset<int> us12 = std::move(us6);
  mystl::unordered_multiset<int> us13{ 1,2,3,4,5 };
  mystl::unordered_multiset<int> us14 = { 1,2,3,4,5 };

  FUN_AFTER(us1, us1.insert(a, a + 5));
  FUN_AFTER(us1, us1.insert(5));
  FUN_AFTER(us1, us1.insert_noresize(5));
  FUN_AFTER(us1, us1.erase(us1.begin()));
  FUN_AFTER(us1, us1.erase(1));
  FUN_AFTER(us1, us1.erase(us1.begin(), us1.find(3)));
  FUN_AFTER(us1, us1.clear());
  FUN_AFTER(us1, us1.swap(us7));
  FUN_VALUE(*us1.begin());
  std::cout << std::boolalpha;
  FUN_VALUE(us1.empty());
  std::cout << std::noboolalpha;
  FUN_VALUE(us1.size());
  FUN_VALUE(us1.max_size());
  FUN_VALUE(us1.bucket_count());
  FUN_VALUE(us1.max_bucket_count());
  FUN_AFTER(us1, us1.reserve(1000));
  FUN_VALUE(us1.size());
  FUN_VALUE(us1.bucket_count());
  FUN_VALUE(us1.elems_in_bucket(1));
  FUN_VALUE(us1.elems_in_bucket(2));
  FUN_VALUE(us1.elems_in_bucket(3));
  FUN_VALUE(us1.count(1));
  FUN_VALUE(*us1.find(3));
  auto first = *us1.equal_range(3).first;
  auto second = *us1.equal_range(3).second;
  std::cout << " us1.equal_range(3) : from " << first << " to " << second << std::endl;
  PASSED;
#if PERFORMANCE_TEST_ON
  std::cout << "[--------------------- Performance Testing ---------------------]" << std::endl;
  std::cout << "|---------------------|-------------|-------------|-------------|" << std::endl;
  std::cout << "|       insert        |";
#if MEMORY_IS_ENOUGH
  CON_TEST_P1(unordered_multiset<int>, insert, rand(), LEN1 _S, LEN2 _S, LEN3 _S);
#else
  CON_TEST_P1(unordered_multiset<int>, insert, rand(), LEN1 _SS, LEN2 _SS, LEN3 _SS);
#endif
  std::cout << std::endl;
  std::cout << "|---------------------|-------------|-------------|-------------|" << std::endl;
  PASSED;
#endif
  std::cout << "[------------ End container test : unordered_multiset ----------]" << std::endl;
}

} // namespace unordered_set_test
} // namespace test
} // namespace mystl
#endif // !MYTINYSTL_UNORDERED_SET_TEST_H_


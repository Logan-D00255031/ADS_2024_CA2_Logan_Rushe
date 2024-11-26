#include "pch.h"
#include "CppUnitTest.h"
#include "../CA2/TreeMap.h"
#include "../CA2/TreeMapNode.h"
#include "../CA2/BinaryTree.h"
#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTest
{
	TEST_CLASS(TreeMapTest)
	{
		string s1, s2, s3;
		list<string> l1, l2, l3;
		TreeMapNode<string, list<string>> n1, n2, n3;

		TEST_METHOD_INITIALIZE(setUp)
		{
			s1 = "a";
			s2 = "b";
			s3 = "c";

			l1.push_front("apple");
			l1.push_front("and");
			l1.push_front("around");
			
			l2.push_front("banana");
			l2.push_front("but");
			l2.push_front("better");
			
			l3.push_front("cake");
			l3.push_front("can");
			l3.push_front("current");

			TreeMapNode<string, list<string>> n1(s1, l1);
			TreeMapNode<string, list<string>> n2(s2, l2);
			TreeMapNode<string, list<string>> n3(s3, l3);
		}

	public:
		
		TEST_METHOD(testClear)
		{
			TreeMap<string, list<string>> *map = new TreeMap<string, list<string>>();
			map->put(s1, l1);
			map->put(s2, l2);
			map->put(s3, l3);
			Assert::AreEqual(map->get(s1).size(), l1.size(), L"Key value has incorrect size");
			Assert::AreEqual(map->get(s3).front(), l3.front(), L"Key value has incorrect front value");
			map->clear();
			auto funct = [&]() {map->get(s2); };
			Assert::ExpectException<logic_error>(funct, L"Exception not thrown");
		}

		TEST_METHOD(testTreeMapContainsKey)
		{
			TreeMap<string, list<string>>* map = new TreeMap<string, list<string>>();
			map->put(s1, l1);
			map->put(s2, l2);
			map->put(s3, l3);
			Assert::IsTrue(map->containsKey(s3), L"Tree Map does not contain Key");
		}

		TEST_METHOD(testTreeMapDoesNotContainKey)
		{
			TreeMap<string, list<string>>* map = new TreeMap<string, list<string>>();
			map->put(s2, l2);
			map->put(s3, l3);
			map->put(s1, l1);
			string s4 = "e";
			Assert::IsFalse(map->containsKey(s4), L"Tree Map contains Key");
		}

		TEST_METHOD(testGetValueOfKeyNotInTreeMap)
		{
			TreeMap<string, list<string>>* map = new TreeMap<string, list<string>>();
			map->put(s3, l3);
			auto funct = [&]() {map->get(s1); };
			Assert::ExpectException<logic_error>(funct, L"No exception thrown");
		}

		TEST_METHOD(testGetValueOfKeyFromClearedTreeMap)
		{
			TreeMap<string, list<string>>* map = new TreeMap<string, list<string>>();
			map->clear();
			auto funct = [&]() {map->get(s3); };
			Assert::ExpectException<logic_error>(funct, L"No exception thrown");
		}

		TEST_METHOD(testGetValueOfKeyContainedInTreeMap)
		{
			TreeMap<string, list<string>>* map = new TreeMap<string, list<string>>();
			map->put(s1, l1);
			map->put(s2, l2);
			Assert::AreEqual(map->get(s2).size(), l2.size(), L"Tree key value has incorrect size");
		}

		TEST_METHOD(testReturnEmptyKeySet)
		{
			TreeMap<string, list<string>>* map = new TreeMap<string, list<string>>();
			BinaryTree<string> keyMap(map->keySet());
			Assert::AreEqual(keyMap.count(), 0, L"Key Set size is greater than 0");
		}

		TEST_METHOD(testReturnKeySet)
		{
			TreeMap<string, list<string>>* map = new TreeMap<string, list<string>>();
			map->put(s2, l2);
			map->put(s1, l1);
			map->put(s3, l3);
			BinaryTree<string> keyMap(map->keySet());
			Assert::AreEqual(keyMap.count(), 3, L"Key Set has incorrect size");
		}
	};
}

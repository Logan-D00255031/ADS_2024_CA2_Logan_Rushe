#include "pch.h"
#include "CppUnitTest.h"
#include "../CA2/TreeMap.h"
#include "../CA2/TreeMapNode.h"
#include "../CA2/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTest
{
	TEST_CLASS(TreeMapTest)
	{
	public:
		
		TEST_METHOD(TestClear)
		{
			TreeMap<int, string> *map = new TreeMap<int, string>();
			string a = "a";
			string b = "b";
			string c = "c";
			map->put(1, a);
			map->put(2, b);
			map->put(3, c);
			Assert::AreEqual(map->get(1), a);
			Assert::AreEqual(map->get(3), c);
			map->clear();
			Assert::ExpectException<logic_error>([&]() {
				map->get(2);
			});
		}
	};
}

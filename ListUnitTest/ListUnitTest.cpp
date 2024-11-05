#include "CppUnitTest.h"
#include <functional>
#include "../List/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTest
{
	TEST_CLASS(ListUnitTest)
	{
	public:
		TEST_METHOD(ConstructedListIsEmpty)
		{
			List<int> list;
		}
		TEST_METHOD(DeleteListSize0)
		{
			List<int> list;
		}
		TEST_METHOD(DeleteListSize1ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 2);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize2ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 3);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize5ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 6);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(ExistsInEmptyListy)
		{
			List<int> list;
			Assert::IsFalse(list.exists(4));
		}
		TEST_METHOD(ExistsInListOfSize1ThereIsNoItem)
		{
			List<int> list;
			list.pushFront(6);
			Assert::IsFalse(list.exists(4));
		}
		TEST_METHOD(ExistsInListOfSize1ThereIsItem)
		{
			List<int> list;
			list.pushFront(5);
			Assert::IsTrue(list.exists(5));
		}
		TEST_METHOD(ExistsInListOfSize2ThereIsNoItem)
		{
			List<int> list;
			list.pushFront(6);
			list.pushFront(3);
			Assert::IsFalse(list.exists(4));
		}
		TEST_METHOD(ExistsInListOfSize2ThereIsItemInTheBeginning)
		{
			List<int> list;
			list.pushFront(23);
			list.pushFront(42);
			Assert::IsTrue(list.exists(23));
		}
		TEST_METHOD(ExistsInListOfSize2ThereIsItemAtTheEnd)
		{
			List<int> list;
			list.pushFront(26);
			list.pushFront(13);
			Assert::IsTrue(list.exists(13));
		}
		TEST_METHOD(ExistsInListOfSize3ThereIsNoItem)
		{
			List<int> list;
			list.pushFront(7);
			list.pushFront(8);
			list.pushFront(2);
			Assert::IsFalse(list.exists(4));
		}
		TEST_METHOD(ExistsInListOfSize3ThereIsItemInTheBeginning)
		{
			List<int> list;
			list.pushFront(41);
			list.pushFront(32);
			list.pushFront(75);
			Assert::IsTrue(list.exists(41));
		}
		TEST_METHOD(ExistsInListOfSize3ThereIsItemAtTheEnd)
		{
			List<int> list;
			list.pushFront(36);
			list.pushFront(94);
			list.pushFront(51);
			Assert::IsTrue(list.exists(51));
		}
		TEST_METHOD(ExistsInListOfSize3ThereIsItemInTheMiddle)
		{
			List<int> list;
			list.pushFront(29);
			list.pushFront(71);
			list.pushFront(46);
			Assert::IsTrue(list.exists(71));
		}
		TEST_METHOD(ExistsInListOfSize5ThereIsNoItem)
		{
			List<int> list;
			list.pushFront(43);
			list.pushFront(81);
			list.pushFront(52);
			list.pushFront(78);
			list.pushFront(25);
			Assert::IsFalse(list.exists(89));
		}
		TEST_METHOD(ExistsInListOfSize5ThereIsItemInTheBeginning)
		{
			List<int> list;
			list.pushFront(12);
			list.pushFront(32);
			list.pushFront(7);
			list.pushFront(28);
			list.pushFront(76);
			Assert::IsTrue(list.exists(12));
		}
		TEST_METHOD(ExistsInListOfSize5ThereIsItemAtTheEnd)
		{
			List<int> list;
			list.pushFront(36);
			list.pushFront(49);
			list.pushFront(51);
			list.pushFront(18);
			list.pushFront(23);
			Assert::IsTrue(list.exists(23));
		}
		TEST_METHOD(ExistsInListOfSize5ThereIsItemInTheMiddle)
		{
			List<int> list;
			list.pushFront(9);
			list.pushFront(48);
			list.pushFront(14);
			list.pushFront(67);
			list.pushFront(91);
			Assert::IsTrue(list.exists(14));
		}
	};
}

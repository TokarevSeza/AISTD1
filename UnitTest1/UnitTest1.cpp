#include "pch.h"
#include "CppUnitTest.h"
#include "../СтруктурыЛаба1/List.h"
#include "../СтруктурыЛаба1/List.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		List* test1;
		List* test2;
		TEST_METHOD_INITIALIZE(setUp)
		{
			test1 = new List();
			test2 = new List();
		}
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete test1;
			delete test2;
		}
		TEST_METHOD(push_back)
		{
			test1->push_front(0);
			test1->push_back(1);
			test1->push_front(2);
			test1->push_back(3);
			Assert::AreEqual(test1->at(2), 1);
			Assert::AreEqual(test1->at(3), 3);
		}
		TEST_METHOD(push_front)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			Assert::AreEqual(test1->at(0), 3);
			Assert::AreEqual(test1->at(1), 43);
		}
		TEST_METHOD(pop_back)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			test1->pop_back();
			Assert::AreEqual((int)test1->get_size(), 4);
		}
		TEST_METHOD(pop_front)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			test1->pop_front();
			Assert::AreEqual((int)test1->get_size(), 4);
			Assert::AreEqual(test1->at(0), 43);
		}
		TEST_METHOD(insert)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			test1->insert(5, 2);
			Assert::AreEqual(test1->at(2), 5);
		}
		TEST_METHOD(at)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			Assert::AreEqual(test1->at(2), 7);
		}
		TEST_METHOD(remove)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			test1->remove(2);
			Assert::AreEqual((int)test1->get_size(), 4);
			Assert::AreEqual(test1->at(2), 1);
		}
		TEST_METHOD(get_size)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			Assert::AreEqual((int)test1->get_size(), 5);
		}
		TEST_METHOD(clear)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			test1->clear();
			Assert::AreEqual((int)test1->get_size(), 0);
		}
		TEST_METHOD(set)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			test1->set(1, 15);
			Assert::AreEqual(test1->at(1), 15);
		}
		TEST_METHOD(IsEmpry)
		{
			test1->push_back(7);
			test1->push_front(43);
			test1->push_back(1);
			test1->push_back(2);
			test1->push_front(3);
			test1->clear();
			Assert::AreEqual((int)test1->get_size(), 0);
		}
	};
}


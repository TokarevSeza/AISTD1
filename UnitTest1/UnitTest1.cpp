#include "pch.h"
#include "CppUnitTest.h"
#include "../СтруктурыЛаба1/List.h"
#include "../СтруктурыЛаба1/List.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		List* test;
		TEST_METHOD_INITIALIZE(setUp)
		{
			test = new List();
		}
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete test;
		}
		TEST_METHOD(push_back)
		{
			test->push_front(0);
			test->push_back(1);
			test->push_front(2);
			test->push_back(3);
			Assert::AreEqual(test->at(2), 1);
			Assert::AreEqual(test->at(3), 3);
		}
		TEST_METHOD(push_front)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			Assert::AreEqual(test->at(0), 3);
			Assert::AreEqual(test->at(1), 43);
		}
		TEST_METHOD(pop_back)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			test->pop_back();
			Assert::AreEqual((int)test->get_size(), 4);
		}
		TEST_METHOD(pop_front)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			test->pop_front();
			Assert::AreEqual((int)test->get_size(), 4);
			Assert::AreEqual(test->at(0), 43);
		}
		TEST_METHOD(insert)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			test->insert(5, 2);
			Assert::AreEqual(test->at(2), 5);
		}
		TEST_METHOD(at)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			Assert::AreEqual(test->at(2), 7);
		}
		TEST_METHOD(remove)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			test->remove(2);
			Assert::AreEqual((int)test->get_size(), 4);
			Assert::AreEqual(test->at(2), 1);
		}
		TEST_METHOD(get_size)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			Assert::AreEqual((int)test->get_size(), 5);
		}
		TEST_METHOD(clear)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			test->clear();
			Assert::AreEqual((int)test->get_size(), 0);
		}
		TEST_METHOD(set)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			test->set(1, 15);
			Assert::AreEqual(test->at(1), 15);
		}
		TEST_METHOD(IsEmpry)
		{
			test->push_back(7);
			test->push_front(43);
			test->push_back(1);
			test->push_back(2);
			test->push_front(3);
			test->clear();
			Assert::AreEqual((int)test->get_size(), 0);
		}
	};
}


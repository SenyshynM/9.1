#include "pch.h"
#include "CppUnitTest.h"
#include "../9.1.2 B/9.1.2 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* p = new Student[3];
			p[0].mat = 5;
			p[0].fiz = 5;
			p[0].spec = KN;
			p[0].prog = 5;

			p[1].mat = 3;
			p[1].fiz = 3;
			p[1].spec = KN;
			p[1].prog = 4;

			p[2].mat = 5;
			p[2].fiz = 5;
			p[2].spec = KN;
			p[2].prog = 4;

			Assert::AreEqual(66.6667, percent(p, 3), 0.0001);
		}
	};
}

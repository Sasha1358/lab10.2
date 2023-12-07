#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string input1 = "sds dded";
			int expected1 = 2;
			Assert::AreEqual(CountWords(input1), expected1);
		}
	};
}

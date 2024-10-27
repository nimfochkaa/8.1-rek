#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1 рек/8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My81
{
	TEST_CLASS(My81)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* str = "HelloQSWorld";
			Assert::IsTrue(hasSQorQS_recursive(str), L"Expected to find 'QS' in the string.");
		}
	};
}

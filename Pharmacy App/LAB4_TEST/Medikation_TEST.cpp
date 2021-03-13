#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB4/Medikation.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


// namespace: LAB4_TEST
//
// summary:	.

namespace LAB4_TEST
{
	/// <summary>	Copy constructor. </summary>
	///
	/// <remarks>	Maria, 4/10/2020. </remarks>
	///
	/// <param name="parameter1">	The first parameter. </param>

	TEST_CLASS(Medikation_TEST)
	{
	public:
		TEST_METHOD(ConstructorTest)
		{
			auto  medikation = new Medikation("Nurofen", 70, 200, 25.50);
			Assert::AreEqual(70, medikation->get_Konzentration());
			Assert::AreEqual(200, medikation->get_Menge());
			Assert::AreEqual(25.50, medikation->get_Preis());
			Assert::AreNotEqual(30.40, medikation->get_Preis());
		}
	};
}
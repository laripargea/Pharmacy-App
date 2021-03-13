#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB4/ApothekeRepo.h"
#include <cassert>


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

	TEST_CLASS(ApothekeRepo_TEST)
	{
	public:
		TEST_METHOD(ConstructorTest)
		{
		}
		TEST_METHOD(bearbeitenTest)
		{
			ApothekeRepo test;
			ApothekeRepo auxiliar;
			
			Medikation medik = Medikation("Nurofen", 70, 200, 25.00);
			test.hinzufugen(medik);
			test.bearbeiten("Nurofen", 70);
			Medikation med_modif;
			med_modif = Medikation("Nurofen", 70, 200, 50.00);
			auxiliar.hinzufugen(med_modif);
			assert(test == auxiliar);
		}
		
	
		TEST_METHOD(existierenTest)
		{
			ApothekeRepo test;
			Medikation medikation = Medikation("Nurofen", 70, 200, 25.50);
			test.hinzufugen(medikation);
			assert(test.existieren(medikation));
		}

		TEST_METHOD(loschenTest)
		{
			ApothekeRepo test;
			ApothekeRepo auxiliar;
			Medikation medikation = Medikation("Nurofen", 70, 200, 25.50);
			test.hinzufugen(medikation);
			test.loschen("Nurofen", 70);
			assert(test == auxiliar);
		}

		TEST_METHOD(undoTest)
		{
			ApothekeRepo test;
			ApothekeRepo auxiliar;
			Medikation medikation = Medikation("Nurofen", 70, 200, 25.50);
			test.hinzufugen(medikation);
			test.undo();
			assert(test == auxiliar);
		}

		TEST_METHOD(redoTest)
		{
			ApothekeRepo test;
			ApothekeRepo auxiliar;
			Medikation medikation = Medikation("Nurofen", 70, 200, 25.50);
			test.hinzufugen(medikation);
			test.undo();
			test.redo();
			auxiliar.hinzufugen(medikation);
			assert(test == auxiliar);
		}
	};
}
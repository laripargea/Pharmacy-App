#include <iostream>
#include "UI.h"
#include "ApothekeController.h"
#include "Medikation.h"
#include "ApothekeRepo.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

UI::UI() {
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Menus this.  </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void UI::Menu()
{
	ApothekeController ctrl;
	ApothekeRepo med;
	Medikation m;

	int option;
	do {
		cout << "Main Menu:" << endl;
		cout << "0. Exit" << endl;
		cout << "1. Medikament hinzufugen" << endl;
		cout << "2. Medikament loschen" << endl;
		cout << "3. Medikament bearbeiten" << endl;
		cout << "4. Medikamente zeigen" << endl;
		cout << "5. Kleiner als Menge X" << endl;
		cout << "6. Sortieren nach Preis " << endl;
		cout << "7.UNDO" << endl;
		cout << "8.REDO" << endl;
		cout << "Wahlen Sie bitte eine Option: "; cin >> option; cout << endl;

		ctrl.meniu(option,&med,m);

	} while (option != 0);
}
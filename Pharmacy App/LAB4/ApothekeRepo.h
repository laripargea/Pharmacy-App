#pragma once
#include "Medikation.h"
#include <vector>
using namespace std;

class ApothekeRepo
{
	//friend class Medikation;
private:
	vector <Medikation> med;

public:
	
	vector <vector <Medikation>> istoric_undo, istoric_redo; //istoric pt undo si pt redo


	ApothekeRepo();
	void hinzufugen(Medikation m);
	void loschen(string n, int k);
	void bearbeiten(string n, int k);
	bool existieren(Medikation m);
	void sortieren_nach_Name();
	void suchen_string(Medikation m);
	void kleiner_als_menge(int menge);
	void sortieren_nach_Preis();
	void undo();
	void redo();
	

	bool operator==(const ApothekeRepo& repo);

	vector <Medikation> get_med();
};


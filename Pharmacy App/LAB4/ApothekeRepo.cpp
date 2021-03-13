#include <iostream>
#include "ApothekeRepo.h"
#include "Medikation.h"
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

ApothekeRepo::ApothekeRepo()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Hinzufugens the given m. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
///
/// <param name="m">	A Medikation to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::hinzufugen(Medikation m)
{
	istoric_undo.push_back(med); //salvez in istoric inainte sa adaug cv nou

	med.push_back(m);
	//cout << med.size() << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Loschens. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
///
/// <param name="n">	A string to process. </param>
/// <param name="k">	An int to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::loschen(string n, int k)
{
	istoric_undo.push_back(med); //salvez in istoric inainte sa adaug cv nou

	for (int i = 0; i < med.size(); i++)
		if (med.at(i).get_Name() == n && med.at(i).get_Konzentration() == k) //unice dupa nume si concentratie
		{
			med.erase(med.begin() + i); //inceputul+offset i
			break;
		}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Bearbeitens. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
///
/// <param name="n">	A string to process. </param>
/// <param name="k">	An int to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::bearbeiten(string n, int k)
{
	istoric_undo.push_back(med); //salvez in istoric inainte sa adaug cv nou

	for (int i = 0; i < med.size(); i++)
		if (med.at(i).get_Name() == n && med.at(i).get_Konzentration() == k)
		{
			med.at(i).set_Preis(med.at(i).get_Preis() * 2); //dubleaza pretul
		}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Existierens the given m. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
///
/// <param name="m">	A Medikation to process. </param>
///
/// <returns>	True if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool ApothekeRepo::existieren(Medikation m) {
	for (int i = 0; i < med.size(); i++)
		if (med.at(i).get_Name() == m.get_Name() && med.at(i).get_Konzentration() == m.get_Konzentration())
			return true;

	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sortieren nach name. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::sortieren_nach_Name()
{
	auto relation = [](Medikation a, Medikation b) { return a.get_Name() < b.get_Name(); };
	sort(med.begin(), med.end(), relation);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Suchen string. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
///
/// <param name="m">	A Medikation to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::suchen_string(Medikation m)
{
	string s;
	cin >> s;
	vector <Medikation> t; //vector temporar

	sortieren_nach_Name();
	for (int i = 0; i < med.size(); i++)
	{
		if (med.at(i).get_Name().find(s) != string::npos && med.at(i).get_Menge() > 0)
			t.push_back(med.at(i));
	}

	for (int i = 0; i < t.size(); i++)
		t[i].zeigen();

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Kleiner als menge. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
///
/// <param name="menge">	The menge. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::kleiner_als_menge(int menge)
{
	for (int i = 0; i < med.size(); i++)
	{
		if (med.at(i).get_Menge() < menge)
			med.at(i).zeigen();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sortieren nach preis. </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::sortieren_nach_Preis()
{
	auto relation = [](Medikation a, Medikation b) { return a.get_Preis() < b.get_Preis(); };
	sort(med.begin(), med.end(), relation);

	for (int i = 0; i < med.size(); i++)
		med.at(i).zeigen();

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Undoes this.  </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::undo()
{
	if (istoric_undo.size() != 0)
	{
		istoric_redo.push_back(med);
		med = istoric_undo.at(istoric_undo.size() - 1);
		istoric_undo.erase(istoric_undo.begin() + istoric_undo.size() - 1);
		//cout << "undo"<<" "<<endl;
	}
	else
		cout << " Nu este posibil! " << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Redoes this.  </summary>
///
/// <remarks>	Larisa, 4/4/2020. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ApothekeRepo::redo()
{
	if (istoric_redo.size() != 0)
	{
		istoric_undo.push_back(med);
		med = istoric_redo.at(istoric_redo.size() - 1);
		istoric_redo.erase(istoric_redo.begin() + istoric_redo.size() - 1);
		//cout << "redo" <<" "<<endl;
	}
	else
		cout << " Nu este posibil! " << endl;
}

bool ApothekeRepo::operator==(const ApothekeRepo& repo)
{
	if (med.size() != repo.med.size()) return false;

	for (int i = 0; i < med.size(); i++)
	{
		if (med.at(i) != repo.med.at(i))
			return false;
	}
	return true;

}

vector <Medikation> ApothekeRepo::get_med()
{
	return med;
}
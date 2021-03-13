#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class Medikation
{
	friend class ApothekeRepo;

private:
	string Name;
	int Konzentration;
	int Menge;
	double Preis;

public:
	Medikation();
	Medikation(string name, int konzentration, int menge, float preis);

	string get_Name();
	int get_Konzentration();
	int get_Menge();
	double get_Preis();
	void set_Name(string name);
	void set_Konzentration(int konzentration);
	void set_Menge(int menge);
	void set_Preis(float preis);
	void zeigen(); //print

	bool operator==(const Medikation& med1);
	bool operator!=(const Medikation& med1);
};


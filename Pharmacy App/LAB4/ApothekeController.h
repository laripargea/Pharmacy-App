#pragma once
#include "ApothekeRepo.h"
#include <iostream>
#include <string>
#include <algorithm>

class ApothekeController
{
public:
	vector <Medikation> med;
	ApothekeController();
	void meniu(int i,ApothekeRepo* repo, Medikation m);
};


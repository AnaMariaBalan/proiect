#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <string.h>

// meniu

void adauga_angajat(string location);
vector<Angajat *> make_vector_angajati(string source);
int search_by_CNP(vector<Angajat *> a, string CNP);
string ask_for_CNP();

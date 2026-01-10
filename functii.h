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
vector<Electrocasnic *> make_vector_electrocasnice(string source); //sau cu template
vector <int> seek_for_aparate (vector <Electrocasnic* > electrocasnice, string interest, string denumire); //interest poate fi tipul/marca/model

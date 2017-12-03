//============================================================================
// Author      : Muhamed Isabegovic
//============================================================================

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Nastavnik.h"
#include "MyFunctions.h"

int main ()
{
	std::cout << "Nastavnici: " << std::endl << std::endl;

	std::vector<Nastavnik> nastavnici;
	nastavnici = readNastavnikFile();

	ispisiListuNastavnika(nastavnici);

	std::cout << std::endl;

	std::cout << "Studijski Programi: " << std::endl << std::endl;

	std::vector<StudijskiProgram> studijskiProgrami;
	studijskiProgrami = readSPFile();

	ispisiListuStudijskihPrograma(studijskiProgrami);

	std::cout << std::endl;

  //updateNastavnikFile(nastavnici);

  return 0;
}
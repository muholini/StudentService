/*
 * ZajednickeMetode.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: muhamed
 */

#include "ZajednickeMetode.h"

int nadjiStudentaPoIndexu(std::vector<Student> aListaStudenata, std::string aIndexNr){
	std::vector<Student>::iterator it;
	int aReturn = 0;

	for(it = aListaStudenata.begin(); it != aListaStudenata.end(); ++it){
	  if( (*it).getBrIndexa() == aIndexNr ){
		  aReturn = 1;
	  }
	}

	return aReturn;
}

int nadjiPredmetPoKratici(std::vector<Predmet> aListaPredmeta, std::string aKratica){
	std::vector<Predmet>::iterator it;
	int aReturn = 0;

	for(it = aListaPredmeta.begin(); it != aListaPredmeta.end(); ++it){
	  if( (*it).getSifraP() == aKratica ){
		  aReturn = 1;
	  }
	}

	return aReturn;
}

int nadjiSPPoKratici(std::vector<StudijskiProgram> aListaPredmeta, std::string aKratica){
	std::vector<StudijskiProgram>::iterator it;
	int aReturn = 0;

	for(it = aListaPredmeta.begin(); it != aListaPredmeta.end(); ++it){
	  if( (*it).getShortTitle() == aKratica ){
		  aReturn = 1;
	  }
	}

	return aReturn;
}

int nadjiUsmjerenjePoKratici(std::vector<Usmjerenje> aListaUsmjerenja, std::string aKratica){
	std::vector<Usmjerenje>::iterator it;
	int aReturn = 0;

	for(it = aListaUsmjerenja.begin(); it != aListaUsmjerenja.end(); ++it){
	  if( (*it).getShortName() == aKratica ){
		  aReturn = 1;
	  }
	}

	return aReturn;
}

int nadjiIspitPoDatumuStudentuPredmetu(
		std::vector<Ispit> aListaIspita,
		std::string datum,
		std::string indexNr,
		std::string kratica)
{

	std::vector<Ispit>::iterator it;
	int aReturn = 0;

	for(it = aListaIspita.begin(); it != aListaIspita.end(); ++it){
	  if( (*it).getPredmetShort() == kratica &&
		  (*it).getStudentIndexNr() == indexNr &&
		  (*it).getTheDate() == datum){
		  aReturn = 1;
	  }
	}

	return aReturn;
}

void prikazListeNastavnika(std::vector<Nastavnik> listaNastavnika){
	std::cout << "\nNastavnici: \n\n";
	ispisiListu(listaNastavnika);
	std::cout << std::endl;
}

void prikazListeStudijskihPrograma(std::vector<StudijskiProgram> studijskiProgrami){
	std::cout << "\nStudijski Programi: \n\n";
	ispisiListu(studijskiProgrami);
	std::cout << std::endl;
}

void prikazListePredmeta(std::vector<Predmet> predmeti){
	std::cout << "\nPredmeti: \n\n";
	ispisiListu(predmeti);
	std::cout << std::endl;
}

void prikazListeStudenata(std::vector<Student> studenti){
	std::cout << "\nStudenti: \n\n";
	ispisiListu(studenti);
	std::cout << std::endl;
}

void prikazListeUsmjerenja(std::vector<Usmjerenje> usmjerenja){
	std::cout << "\nUsmjerenja: \n\n";
	ispisiListu(usmjerenja);
	std::cout << std::endl;
}

void prikazListeIspita(std::vector<Ispit> ispiti){
	std::cout << "\nIspiti: \n\n";
	ispisiListu(ispiti);
	std::cout << std::endl;
}

std::vector<Nastavnik> promjeniListuNastavnika(std::vector<Nastavnik> listaNastavnika){

	std::cout << "Ulazite u promjeniNastavnika \n";
	std::cout << "Nadjite nastavnika kojeg zelite promjeniti po JMBG: \n\n";

	std::string jmbgNastavnika;
	std::cin >> jmbgNastavnika;
	bool nastavnikFound = false;
	std::vector<Nastavnik>::iterator iter;

	for(iter = listaNastavnika.begin(); iter != listaNastavnika.end(); ++iter){
		if((*iter).getJmbg() == jmbgNastavnika){
			promjeniNastavnika((*iter));
			nastavnikFound = true;
		}
	}

	if(!nastavnikFound){
		std::cout << "Nastavnik sa takvim JMBG-om ne postoji u bazi \n";
	}

	return listaNastavnika;

}

std::vector<StudijskiProgram> promjeniListuStudijskihPrograma(std::vector<StudijskiProgram> studijskiProgrami){

	std::cout << "Ulazite u promjeniListuStudijskihPrograma \n";
	std::cout << "Nadjite studijski program kojega zelite promjeniti po kratici (2 slova): \n\n";

	std::string shortTitle;
	std::cin >> shortTitle;
	bool spFound = false;
	std::vector<StudijskiProgram>::iterator iter;

	for(iter = studijskiProgrami.begin(); iter != studijskiProgrami.end(); ++iter){
		if((*iter).getShortTitle() == shortTitle){
			promjeniStudijskiProgram((*iter));
			spFound = true;
		}
	}

	if(!spFound){
		std::cout << "Studijski Program sa takvom kraticom ne postoji u bazi \n";
	}

	return studijskiProgrami;
}

std::vector<Predmet> promjeniListuPredmeta(std::vector<Predmet> listaPredmeta){

	std::cout << "Ulazite u promjeniListuPredmeta \n";
	std::cout << "Nadjite predmet koji zelite promjeniti po sifri (2 slova): \n\n";

	std::string sifraPredmeta;
	std::cin >> sifraPredmeta;
	bool spFound = false;
	std::vector<Predmet>::iterator iter;

	for(iter = listaPredmeta.begin(); iter != listaPredmeta.end(); ++iter){
		if((*iter).getSifraP() == sifraPredmeta){
			promjeniPredmet((*iter));
			spFound = true;
		}
	}

	if(!spFound){
		std::cout << "Predmet sa takvom kraticom ne postoji u bazi \n";
	}

	return listaPredmeta;
}

std::vector<Student> promjeniListuStudenata(std::vector<Student> listaStudenata){

	std::cout << "Ulazite u promjeniListuStudenata \n";
	std::cout << "Nadjite studenta kojeg zelite promjeniti po JMBG: \n\n";

	std::cout << "JMBG: ";
	std::string jmbgStudenta;
	std::cin >> jmbgStudenta;
	bool studentFound = false;
	std::vector<Student>::iterator iter;

	for(iter = listaStudenata.begin(); iter != listaStudenata.end(); ++iter){
		if((*iter).getJmbg() == jmbgStudenta){
			promjeniStudenta((*iter));
			studentFound = true;
		}
	}

	if(!studentFound){
		std::cout << "Student sa takvim JMBG-om ne postoji u bazi \n";
	}

	return listaStudenata;

}

std::vector<Usmjerenje> promjeniListuUsmjerenja(std::vector<Usmjerenje> listaUsmjerenja){

	std::cout << "Ulazite u promjeniListuUsmjerenja \n";
	std::cout << "Nadjite usmjerenje koje zelite promjeniti po kratici (2 slova): \n\n";

	std::cout << "Kratica: ";
	std::string kratica;
	std::cin >> kratica;
	std::cout << '\n';
	bool usmjerenjeFound = false;
	std::vector<Usmjerenje>::iterator iter;

	for(iter = listaUsmjerenja.begin(); iter != listaUsmjerenja.end(); ++iter){
		if((*iter).getShortName() == kratica){
			promjeniUsmjerenje((*iter));
			usmjerenjeFound = true;
		}
	}

	if(!usmjerenjeFound){
		std::cout << "Usmjerenje sa takvom kraticom ne postoji u bazi \n";
	}

	return listaUsmjerenja;
}

std::vector<Ispit> promjeniListuIspita(std::vector<Ispit> listaIspita){

	std::cout << "Ulazite u promjeniListuIspita \n";
	std::cout << "Nadjite ispit koje zelite promjeniti po 3 parametra \n";
	std::cout << "Potrebno je da unesete sifru predmeta, JMBG profesora i index studenta \n";

	std::cin.clear();
	std::cout << "Sifra Predmeta: ";
	std::string sifraPredmeta;
	std::cin >> sifraPredmeta;
	std::cout << '\n';
	std::cin.clear();

	std::cout << "JMBG profesora: ";
	std::string jmbgProfesora;
	std::cin >> jmbgProfesora;
	std::cout << '\n';
	std::cin.clear();

	std::cout << "Index studenta: ";
	std::string indexStudenta;
	std::cin >> indexStudenta;
	std::cout << '\n';
	std::cin.clear();

	bool usmjerenjeFound = false;
	std::vector<Ispit>::iterator iter;

	for(iter = listaIspita.begin(); iter != listaIspita.end(); ++iter){
		if(
			(*iter).getPredmetShort() == sifraPredmeta &&
			(*iter).getProfesorJmbg() == jmbgProfesora &&
			(*iter).getStudentIndexNr() == indexStudenta
			){
			promjeniIspit((*iter));
			usmjerenjeFound = true;
		}
	}

	if(!usmjerenjeFound){
		std::cout << "Usmjerenje sa takvim parametrima ne postoji u bazi \n";
	}

	return listaIspita;
}

void promjeniNastavnika(Nastavnik &aNastavnik){
	std::cout << "Nastavnik prije editovanja: \n\n";
	aNastavnik.ispisiPodatke();

	std::cout << "Sta zelite promjeniti? \n\n";
	std::cout << "Upisite // kada zavrsite sa promjenama \n";
	std::cout << "Dostupno za promjenu: ime , prezime , pozicija , predmet \n\n";

	std::cout << "Promjena: ";
	std::string aTemp;
	std::cin >> aTemp;
	std::cout << '\n';

	while(aTemp != "//"){

		if( aTemp == "ime"){
			std::cout << "Upisite novo ime: ";
			std::string aIme;
			std::cin >> aIme;
			aNastavnik.setFirstName(aIme);
			std::cout << '\n';
		}else if(aTemp == "prezime"){
			std::cout << "Upisite novo prezime: ";
			std::string aPrezime;
			std::cin >> aPrezime;
			aNastavnik.setLastName(aPrezime);
			std::cout << '\n';
		}else if(aTemp == "pozicija"){
			std::cout << "Upisite novu poziciju: ";
			std::string aPoz;
			std::cin >> aPoz;
			aNastavnik.setPosition(aPoz);
			std::cout << '\n';
		}else if(aTemp == "predmet"){
			std::cout << "Upisite novi predmet: ";
			std::string aPred;
			std::cin >> aPred;
			aNastavnik.setSubject(aPred);
			std::cout << '\n';
		}else{
			std::cout << "Niste unijeli ispravan naziv varijable \n";
		}

		std::cout << "Upisite // kada zavrsite sa promjenama \n";
		std::cout << "Dostupno za promjenu: ime , prezime , pozicija , predmet \n\n";

		std::cin.clear();
		std::cin >> aTemp;

	}

	std::cout << "Nastavnik poslije editovanja: \n\n";
	aNastavnik.ispisiPodatke();
}

void promjeniStudijskiProgram(StudijskiProgram &aSP){
	std::cout << "Studijski program prije editovanja: \n\n";
	aSP.ispisiPodatke();

	std::cout << "Sta zelite promjeniti? \n\n";
	std::cout << "Upisite // kada zavrsite sa promjenama \n";
	std::cout << "Dostupno za promjenu: kratica , puniNaziv \n\n";

	std::cout << "Promjena: ";
	std::string aTemp;
	std::cin >> aTemp;
	std::cout << '\n';

	while(aTemp != "//"){

		if( aTemp == "kratica"){
			std::cout << "Upisite novu kraticu koje zelite (2 slova): \n\n";
			std::string aKratica;
			std::cin >> aKratica;
			while(aKratica.length() <= 0 || aKratica.length() > 2){
				std::cout << "Ponovo upisite novu kraticu koje zelite\n";
				std::cout << "Ne smije biti veca od 2 slova: \n\n";
				std::cin.clear();
				std::cin >> aKratica;
			}
			aSP.setShortTitle(aKratica);
		}else if(aTemp == "puniNaziv"){
			std::cout << "Upisite novi naziv koje zelite: \n\n";
			std::string aPuniNaziv;
			std::cin >> aPuniNaziv;
			aSP.setFullTitle(aPuniNaziv);
		}else{
			std::cout << "Niste unijeli ispravan naziv varijable \n";
		}

		std::cout << "Upisite // kada zavrsite sa promjenama \n";
		std::cout << "Dostupno za promjenu: kratica , puniNaziv \n\n";

		std::cin.clear();
		std::cin >> aTemp;

	}

	std::cout << "Studijski program poslije editovanja: \n\n";
	aSP.ispisiPodatke();
}

void promjeniPredmet(Predmet &aPredmet){
	std::cout << "Studijski program prije editovanja: \n\n";
	aPredmet.ispisiPodatke();

	std::cout << "Sta zelite promjeniti? \n\n";
	std::cout << "Upisite // kada zavrsite sa promjenama \n";
	std::cout << "Dostupno za promjenu: \n\n";
	std::cout << "sifraPredmeta , nazivPredmeta , studijskiProgram, usmjerenje \n";
	std::cout << "uSemestru, predavanjaSati, auditorneSati \n";
	std::cout << "labVjezbeSati , nosiEcts , trajeSemestara \n\n";

	std::cout << "Promjena: ";
	std::string aTemp;
	std::cin >> aTemp;
	std::cout << '\n';

	while(aTemp != "//"){

		if( aTemp == "sifraPredmeta"){
			std::cout << "Upisite novu sifru predmeta (2 slova): ";
			std::string aSifra;
			std::cin >> aSifra;
			while(aSifra.length() <= 0 || aSifra.length() > 2){
				std::cout << "Ponovo upisite novu sifru koje zelite: \n";
				std::cout << "Ne smije biti duza od 2 slova \n";
				std::cout << "Nova sifra: ";
				std::cin.clear();
				std::cin >> aSifra;
			}
			aPredmet.setSifraP(aSifra);
			std::cout << '\n';
		}else if(aTemp == "nazivPredmeta"){
			std::cout << "Upisite novi naziv: ";
			std::string aPuniNaziv;
			std::cin >> aPuniNaziv;
			aPredmet.setNazivP(aPuniNaziv);
			std::cout << '\n';
		}else if(aTemp == "studijskiProgram"){
			std::cout << "Upisite novu kraticu za studijski program (2 slova): ";
			std::string kratica;
			std::cin >> kratica;
			while(kratica.length() <= 0 || kratica.length() > 2){
				std::cout << "Ponovo upisite novu kraticu koje zelite\n";
				std::cout << "Ne smije biti duza od 2 slova \n";
				std::cout << "Nova kratica: ";
				std::cin.clear();
				std::cin >> kratica;
			}
			aPredmet.setSP(kratica);
			std::cout << '\n';
		}else if(aTemp == "usmjerenje"){
			std::cout << "Upisite novu kraticu za usmjerenje (2 slova): ";
			std::string kratica;
			std::cin >> kratica;
			while(kratica.length() <= 0 || kratica.length() > 2){
				std::cout << "Ponovo upisite novu sifru koje zelite\n";
				std::cout << "Ne smije biti duza od 2 slova \n";
				std::cout << "Nova kratica: ";
				std::cin.clear();
				std::cin >> kratica;
			}
			aPredmet.setUsmjerenje(kratica);
			std::cout << '\n';
		}else if(aTemp == "uSemestru"){
			std::cout << "Upisite novi broj semestra: ";

			int brSem;
			if (std::cin >> brSem) {
				aPredmet.setUSemestru(brSem);
				std::cout << "\n\n Uspješno ste napravili promjenu. \n\n ";
			} else {
				std::cout << "\n\n Unesite broj, tekst nije dozvoljen. \n\n ";
			}

			std::cout << '\n';
		}else if(aTemp == "predavanjaSati"){
			std::cout << "Upisite novi broj sedmicnih sati za predavanja: ";

			int brSati;
			if (std::cin >> brSati) {
				aPredmet.setPredavanjaSati(brSati);
				std::cout << "\n\n Uspješno ste napravili promjenu. \n\n ";
			} else {
				std::cout << "\n\n Unesite broj, tekst nije dozvoljen. \n\n ";
			}

			std::cout << '\n';
		}else if(aTemp == "auditorneSati"){
			std::cout << "Upisite novi broj sedmicnih sati za auditorne vjezbe: ";

			int brSati;
			if (std::cin >> brSati) {
				aPredmet.setAuditorneSati(brSati);
				std::cout << "\n\n Uspješno ste napravili promjenu. \n\n ";
			} else {
				std::cout << "\n\n Unesite broj, tekst nije dozvoljen. \n\n ";
			}

			std::cout << '\n';
		}else if(aTemp == "labVjezbeSati"){
			std::cout << "Upisite novi broj sedmicnih sati za laboratorijske vjezbe: ";

			int brSati;
			if (std::cin >> brSati) {
				aPredmet.setLabVSati(brSati);
				std::cout << "\n\n Uspješno ste napravili promjenu. \n\n ";
			} else {
				std::cout << "\n\n Unesite broj, tekst nije dozvoljen. \n\n ";
			}

			std::cout << '\n';
		}else if(aTemp == "nosiEcts"){
			std::cout << "Upisite novi broj ECTS-ova za predmet: ";

			int brEcts;
			if (std::cin >> brEcts) {
				aPredmet.setNosiEcts(brEcts);
				std::cout << "\n\n Uspješno ste napravili promjenu. \n\n ";
			} else {
				std::cout << "\n\n Unesite broj, tekst nije dozvoljen. \n\n ";
			}

			std::cout << '\n';
		}else if(aTemp == "trajeSemestara"){
			std::cout << "Upisite trajanjeSemestara za predmet: ";

			int brSemestara;
			if (std::cin >> brSemestara) {
				aPredmet.setTrajeSemestara(brSemestara);
				std::cout << "\n\n Uspješno ste napravili promjenu. \n\n ";
			} else {
				std::cout << "\n\n Unesite broj, tekst nije dozvoljen. \n\n ";
			}

			std::cout << '\n';
		}else{
			std::cout << "Niste unijeli ispravan naziv varijable \n";
		}

		std::cout << "Upisite // kada zavrsite sa promjenama \n";
		std::cout << "Dostupno za promjenu: \n\n";
		std::cout << "sifraPredmeta , nazivPredmeta , studijskiProgram, usmjerenje \n";
		std::cout << "uSemestru, predavanjaSati, auditorneSati \n";
		std::cout << "labVjezbeSati , nosiEcts , trajeSemestara \n\n";

		std::cin.clear();
		std::cin >> aTemp;

	}

	std::cout << "Studijski program poslije editovanja: \n\n";
	aPredmet.ispisiPodatke();
}

void promjeniStudenta(Student &aStudent){
	std::cout << "Student prije editovanja: \n\n";
	aStudent.ispisiPodatke();

	std::cout << "Sta zelite promjeniti? \n\n";
	std::cout << "Upisite // kada zavrsite sa promjenama \n";
	std::cout << "Dostupno za promjenu: ime , prezime , brIndexa , smjer \n\n";

	std::cout << "Promjeni: ";
	std::string aTemp;
	std::cin >> aTemp;
	std::cout << '\n';

	while(aTemp != "//"){

		if( aTemp == "ime"){
			std::cout << "Upisite novo ime: ";
			std::string aIme;
			std::cin >> aIme;
			aStudent.setFirstName(aIme);
			std::cout << '\n';
		}else if(aTemp == "prezime"){
			std::cout << "Upisite novo prezime: ";
			std::string aPrezime;
			std::cin >> aPrezime;
			aStudent.setLastName(aPrezime);
			std::cout << '\n';
		}else if(aTemp == "brIndexa"){
			std::cout << "Upisite novi br indexa: ";
			std::string brIndexa;
			std::cin >> brIndexa;
			aStudent.setBrIndexa(brIndexa);
			std::cout << '\n';
		}else if(aTemp == "smjer"){
			std::cout << "Upisite novi smjer: ";
			std::string aSmjer;
			std::cin >> aSmjer;
			aStudent.setSmjer(aSmjer);
			std::cout << '\n';
		}else{
			std::cout << "Niste unijeli ispravan naziv varijable \n";
		}

		std::cout << "Upisite // kada zavrsite sa promjenama \n";
		std::cout << "Dostupno za promjenu: ime , prezime , brIndexa , smjer \n\n";

		std::cout << "Promjeni: ";
		std::cin.clear();
		std::cin >> aTemp;

	}

	std::cout << "Student poslije editovanja: \n\n";
	aStudent.ispisiPodatke();
}

void promjeniUsmjerenje(Usmjerenje &aUsmjerenje){
	std::cout << "Usmjerenje prije editovanja: \n\n";
	aUsmjerenje.ispisiPodatke();

	std::cout << "Sta zelite promjeniti? \n\n";
	std::cout << "Upisite // kada zavrsite sa promjenama \n";
	std::cout << "Dostupno za promjenu: kratica , puniNaziv , nazivStudijskogPrograma \n\n";

	std::cout << "Promjeni: ";
	std::string aTemp;
	std::cin >> aTemp;
	std::cout << '\n';

	while(aTemp != "//"){

		if( aTemp == "kratica"){
			std::cout << "Upisite novu kraticu (2 slova): ";
			std::string aKratica;
			std::cin >> aKratica;
			while(aKratica.length() <= 0 || aKratica.length() > 2){
				std::cout << "Ponovo upisite novu kraticu koje zelite\n";
				std::cout << "Ne smije biti veca od 2 slova \n";
				std::cout << "Nova kratica: ";
				std::cin.clear();
				std::cin >> aKratica;
				std::cout << '\n';
			}
			aUsmjerenje.setShortName(aKratica);
			std::cout << '\n';
		}else if(aTemp == "puniNaziv"){
			std::cout << "Upisite novi naziv: ";
			std::string puniNaziv;
			std::cin >> puniNaziv;
			aUsmjerenje.setFullName(puniNaziv);
			std::cout << '\n';
		}else if(aTemp == "nazivStudijskogPrograma"){
			std::cout << "Upisite novi naziv studijskog programa: ";
			std::string nazivPrograma;
			std::cin >> nazivPrograma;
			aUsmjerenje.setNazivSP(nazivPrograma);
			std::cout << '\n';
		}else{
			std::cout << "Niste unijeli ispravan naziv varijable \n";
		}

		std::cout << "Upisite // kada zavrsite sa promjenama \n";
		std::cout << "Dostupno za promjenu: kratica , puniNaziv , nazivStudijskogPrograma \n\n";

		std::cout << "Promjeni: ";
		std::cin.clear();
		std::cin >> aTemp;
		std::cout << '\n';

	}

	std::cout << "Usmjerenje poslije editovanja: \n\n";
	aUsmjerenje.ispisiPodatke();
}

void promjeniIspit(Ispit &aIspit){

	std::cout << "Ispit prije editovanja: \n\n";
	aIspit.ispisiPodatke();

	std::cout << "Sta zelite promjeniti? \n\n";
	std::cout << "Upisite // kada zavrsite sa promjenama \n";
	std::cout << "Dostupno za promjenu: sifraPredmeta , jmbgProfesora , brojIndexa , datum , ocjena \n\n";

	std::cout << "Promjeni: ";
	std::string aTemp;
	std::cin >> aTemp;
	std::cout << '\n';

	while(aTemp != "//"){

		if( aTemp == "sifraPredmeta"){
			std::cout << "Upisite novu sifru predmeta (2 slova): ";
			std::string aKratica;
			std::cin >> aKratica;
			while(aKratica.length() <= 0 || aKratica.length() > 2){
				std::cout << "Ponovo upisite novu sifru predmeta koju zelite\n";
				std::cout << "Ne smije biti duza od 2 slova \n";
				std::cout << "Nova sifra predmeta: ";
				std::cin.clear();
				std::cin >> aKratica;
				std::cout << '\n';
			}
			aIspit.setPredmetShort(aKratica);
			std::cout << '\n';
		}else if(aTemp == "jmbgProfesora"){
			std::cout << "Upisite novi naziv: ";
			std::string jmbgProfesora;
			std::cin >> jmbgProfesora;
			aIspit.setProfesorJmbg(jmbgProfesora);
			std::cout << '\n';
		}else if(aTemp == "brojIndexa"){
			std::cout << "Upisite novi broj indexa: ";
			std::string brojIndexa;
			std::cin >> brojIndexa;
			aIspit.setStudentIndexNr(brojIndexa);
			std::cout << '\n';
		}else if(aTemp == "datum"){
			std::cout << "Upisite novi datum: ";
			std::string datum;
			std::cin >> datum;
			aIspit.setTheDate(datum);
			std::cout << '\n';
		}else if(aTemp == "ocjena"){
			std::cout << "Upisite novu ocjenu: ";
			std::string ocjena;
			std::cin >> ocjena;
			aIspit.setTheGrade(ocjena);
			std::cout << '\n';
		}else{
			std::cout << "Niste unijeli ispravan naziv varijable \n";
		}

		std::cout << "Upisite // kada zavrsite sa promjenama \n";
		std::cout << "Dostupno za promjenu: sifraPredmeta , jmbgProfesora , brojIndexa , datum , ocjena \n\n";

		std::cout << "Promjeni: ";
		std::cin.clear();
		std::cin >> aTemp;
		std::cout << '\n';

	}

	std::cout << "Ispit poslije editovanja: \n\n";
	aIspit.ispisiPodatke();


}

void obrisiIzListeNastavnika(std::vector<Nastavnik> &listaNastavnika){
	std::cout << "Ulazite u obrisiIzListeNastavnika \n";
	std::cout << "Nadjite nastavnika kojeg zelite izbrisati po JMBG-u (13 znakova): \n\n";

	prikazListeNastavnika(listaNastavnika);
	std::cout << "\n\n";

	std::cout << "JMBG: ";
	std::string jmbgNastavnika;
	std::cin.clear();
	std::cin >> jmbgNastavnika;
	std::cout << '\n';

	while(jmbgNastavnika != "//"){
		bool nastavnikFound = false;

		for(unsigned int i = 0; i < listaNastavnika.size(); i++){
			if(listaNastavnika[i].getJmbg() == jmbgNastavnika){
				listaNastavnika[i] = listaNastavnika.back();
				listaNastavnika.pop_back();
				nastavnikFound = true;
				i--;
				break;
			}
		}

		if(!nastavnikFound){
			std::cout << "Nastavnik sa takvim JMBG-om ne postoji u bazi \n";
		}

		std::cout << "Za brisanje nastavnika, unesite novi JMBG \n";
		std::cout << "Za izlazak iz akcije brisanja, upisite // \n\n";
		std::cin.clear();
		std::cin >> jmbgNastavnika;
		std::cout << '\n';
	}
}

void obrisiIzListeStudijskihPrograma(std::vector<StudijskiProgram> &listaSP){
	std::cout << "Ulazite u obrisiIzListeStudijskihPrograma \n";
	std::cout << "Nadjite studijski program koji zelite izbrisati po kratici (2 znaka): \n\n";

	prikazListeStudijskihPrograma(listaSP);
	std::cout << "\n\n";

	std::cout << "Kratica: ";
	std::string kratica;
	std::cin.clear();
	std::cin >> kratica;
	std::cout << '\n';

	while(kratica != "//"){
		bool found = false;

		for(unsigned int i = 0; i < listaSP.size(); i++){
			if(listaSP[i].getShortTitle() == kratica){
				listaSP[i] = listaSP.back();
				listaSP.pop_back();
				found = true;
				i--;
				break;
			}
		}

		if(!found){
			std::cout << "Nastavnik sa takvim JMBG-om ne postoji u bazi \n";
		}

		std::cout << "Za brisanje nastavnika, unesite novu kraticu \n";
		std::cout << "Za izlazak iz akcije brisanja, upisite // \n\n";
		std::cin.clear();
		std::cin >> kratica;
		std::cout << '\n';
	}
}

void obrisiIzListePredmeta(std::vector<Predmet> &listaPredmeta){
	std::cout << "Ulazite u obrisiIzListePredmeta \n";
	std::cout << "Nadjite predmet koji zelite izbrisati po sifri predmeta (2 znaka): \n\n";

	prikazListePredmeta(listaPredmeta);
	std::cout << "\n\n";

	std::cout << "Sifra: ";
	std::string sifra;
	std::cin.clear();
	std::cin >> sifra;
	std::cout << '\n';

	while(sifra != "//"){
		bool found = false;

		for(unsigned int i = 0; i < listaPredmeta.size(); i++){
			if(listaPredmeta[i].getSifraP() == sifra){
				listaPredmeta[i] = listaPredmeta.back();
				listaPredmeta.pop_back();
				found = true;
				i--;
				break;
			}
		}

		if(!found){
			std::cout << "Nastavnik sa takvim JMBG-om ne postoji u bazi \n";
		}

		std::cout << "Za brisanje nastavnika, unesite novu sifru \n";
		std::cout << "Za izlazak iz akcije brisanja, upisite // \n\n";
		std::cin.clear();
		std::cin >> sifra;
		std::cout << '\n';
	}
}

void obrisiIzListeStudenata(std::vector<Student> &listaStudenata){
	std::cout << "Ulazite u obrisiIzListeStudenata \n";
	std::cout << "Nadjite studenta kojeg zelite izbrisati po JMBG-u (13 znakova): \n\n";

	prikazListeStudenata(listaStudenata);
	std::cout << "\n\n";

	std::cout << "JMBG: ";
	std::string jmbgS;
	std::cin.clear();
	std::cin >> jmbgS;
	std::cout << '\n';

	while(jmbgS != "//"){
		bool found = false;

		for(unsigned int i = 0; i < listaStudenata.size(); i++){
			if(listaStudenata[i].getJmbg() == jmbgS){
				listaStudenata[i] = listaStudenata.back();
				listaStudenata.pop_back();
				found = true;
				i--;
				break;
			}
		}

		if(!found){
			std::cout << "Nastavnik sa takvim JMBG-om ne postoji u bazi \n";
		}

		std::cout << "Za brisanje studenta, unesite novi JMBG \n";
		std::cout << "Za izlazak iz akcije brisanja, upisite // \n\n";
		std::cin.clear();
		std::cin >> jmbgS;
		std::cout << '\n';
	}
}

void obrisiIzListeUsmjerenja(std::vector<Usmjerenje> &listaUsmjerenja){
	std::cout << "Ulazite u obrisiIzListeUsmjerenja \n";
	std::cout << "Nadjite usmjerenje koje zelite izbrisati po kratici (2 znaka): \n\n";

	prikazListeUsmjerenja(listaUsmjerenja);
	std::cout << "\n\n";

	std::cout << "JMBG: ";
	std::string kratica;
	std::cin.clear();
	std::cin >> kratica;
	std::cout << '\n';

	while(kratica != "//"){
		bool found = false;

		for(unsigned int i = 0; i < listaUsmjerenja.size(); i++){
			if(listaUsmjerenja[i].getShortName() == kratica){
				listaUsmjerenja[i] = listaUsmjerenja.back();
				listaUsmjerenja.pop_back();
				found = true;
				i--;
				break;
			}
		}

		if(!found){
			std::cout << "Nastavnik sa takvim JMBG-om ne postoji u bazi \n";
		}

		std::cout << "Za brisanje nastavnika, unesite novi JMBG \n";
		std::cout << "Za izlazak iz akcije brisanja, upisite // \n\n";
		std::cin.clear();
		std::cin >> kratica;
		std::cout << '\n';
	}
}

void obrisiIzListeIspita(std::vector<Ispit> &listaIspita){
	std::cout << "Ulazite u obrisiIzListeUsmjerenja \n";
	std::cout << "Nadjite usmjerenje koje zelite izbrisati po kratici (2 znaka): \n\n";

	prikazListeIspita(listaIspita);
	std::cout << "\n\n";

	std::cout << "JMBG profesora: ";
	std::string jmbgP;
	std::cin.clear();
	std::cin >> jmbgP;
	std::cout << '\n';

	std::cout << "brIndexa Studenta: ";
	std::string brIndexa;
	std::cin.clear();
	std::cin >> brIndexa;
	std::cout << '\n';

	std::cout << "Kratica predmeta: ";
	std::string kraticaP;
	std::cin.clear();
	std::cin >> kraticaP;
	std::cout << '\n';

	while(jmbgP != "//"){
		bool found = false;

		for(unsigned int i = 0; i < listaIspita.size(); i++){
			if(listaIspita[i].getProfesorJmbg() == jmbgP &&
					listaIspita[i].getPredmetShort() == kraticaP &&
					listaIspita[i].getStudentIndexNr() == brIndexa
					){
				listaIspita[i] = listaIspita.back();
				listaIspita.pop_back();
				found = true;
				i--;
				break;
			}
		}

		if(!found){
			std::cout << "Nastavnik sa takvim JMBG-om ne postoji u bazi \n";
		}

		std::cout << "Za brisanje ispita, unesite novi JMBG profesora, brIndexa Studenta i kraticu predmeta \n";
		std::cout << "Za izlazak iz akcije brisanja, upisite // \n\n";

		std::cin.clear();
		std::cout << "JMBG profesora: ";
		std::cin >> jmbgP;
		std::cout << '\n';

		std::cout << "brIndexa Studenta: ";
		std::string brIndexa;
		std::cin.clear();
		std::cin >> brIndexa;
		std::cout << '\n';

		std::cout << "Kratica predmeta: ";
		std::string kraticaP;
		std::cin.clear();
		std::cin >> kraticaP;
		std::cout << '\n';
	}
}

void dodajUListuNastavnika(std::vector<Nastavnik> &listaNastavnika){

	std::cout << "Ulazite u dodajUListuNastavnika \n\n";

	prikazListeNastavnika(listaNastavnika);
	std::cout << "\n\n";

	std::cout << "Ulazite u prostor za dodavanje novog nastavnika: \n\n";
	std::cout << "Jeste li sigurni da zelite dodati novog nastavnika? \n";

	std::cout << "Potvrdite sa DA ili NE: ";
	std::string confirmation;
	std::cin >> confirmation;

	if(confirmation == "DA"){

		std::cout << "\n JMBG (13 znakova): ";
		std::string jmbgNastavnika;
		std::cin.clear();
		std::cin >> jmbgNastavnika;
		std::cout << '\n';
		while(jmbgNastavnika.length()!= 13){
			std::cout << "JMBG mora biti 13 znakova duzine\n";
			std::cout << "JMBG: ";
			std::cin.clear();
			std::cin >> jmbgNastavnika;
			std::cout << '\n';
		}

		int jmbgCheck = nadjiElement(listaNastavnika, jmbgNastavnika);

		if(jmbgCheck == 0){

			std::cout << "\n Ime: ";
			std::string firstName;
			std::cin.clear();
			std::cin >> firstName;
			std::cout << '\n';

			std::cout << "\n Prezime: ";
			std::string lastName;
			std::cin.clear();
			std::cin >> lastName;
			std::cout << '\n';

			std::cout << "\n Pozicija: ";
			std::string position;
			std::cin.clear();
			std::cin >> position;
			std::cout << '\n';

			std::cout << "\n Predmet: ";
			std::string subject;
			std::cin.clear();
			std::cin >> subject;
			std::cout << '\n';

			Nastavnik aNewNastavnik(
					jmbgNastavnika,
					firstName,
					lastName,
					position,
					subject
			);

			listaNastavnika.push_back(aNewNastavnik);

		}else{
			std::cout << "Nastavnik sa unijetim JMBG-om vec postoji u bazi \n\n";
		}
	}

	std::cout << "Izlazite iz dodajUListuNastavnika \n\n";

}

void dodajUListuStudijskihPrograma(std::vector<StudijskiProgram> &listaSP){

	std::cout << "Ulazite u dodajUListuStudijskihPrograma \n\n";

	prikazListeStudijskihPrograma(listaSP);
	std::cout << "\n\n";

	std::cout << "Ulazite u prostor za dodavanje novog studijskog programa: \n\n";
	std::cout << "Jeste li sigurni da zelite dodati novi studijski program? \n";

	std::cout << "Potvrdite sa DA ili NE: ";
	std::string confirmation;
	std::cin >> confirmation;

	if(confirmation == "DA"){

		std::cout << "\n Kratica (2 slova): ";
		std::string shortName;
		std::cin.clear();
		std::cin >> shortName;
		std::cout << '\n';
		while(shortName.length() > 2 || shortName.length() <= 0){
			std::cout << "Kratica moze biti maksimalno 2 slova duzine\n";
			std::cout << "Kratica: ";
			std::cin.clear();
			std::cin >> shortName;
			std::cout << '\n';
		}

		int checkShort = nadjiSPPoKratici(listaSP, shortName);

		if(checkShort == 0){

			std::cout << "\n Ime: ";
			std::string fullName;
			std::cin.clear();
			std::cin >> fullName;
			std::cout << '\n';

			StudijskiProgram aNewStudijskiProgram(
					shortName,
					fullName
			);

			listaSP.push_back(aNewStudijskiProgram);

		}else{
			std::cout << "Studijski Program sa unesenom kraticom vec postoji u bazi \n\n";
		}

	}

	std::cout << "Izlazite iz dodajUListuStudijskihPrograma \n\n";

}

void dodajUListuPredmeta(
		std::vector<Predmet> &listaPredmeta,
		std::vector<Usmjerenje> &listaUsmjerenja,
		std::vector<StudijskiProgram> &listaSP){
	std::cout << "Ulazite u dodajUListuPredmeta \n\n";

	prikazListePredmeta(listaPredmeta);
	std::cout << "\n\n";

	std::cout << "Ulazite u prostor za dodavanje novog predmeta: \n\n";
	std::cout << "Jeste li sigurni da zelite dodati novi predmet? \n";

	std::cout << "Potvrdite sa DA ili NE: ";
	std::string confirmation;
	std::cin >> confirmation;

	if(confirmation == "DA"){

		std::cout << "\n Sifra Predmeta (2 slova): ";
		std::string shortName;
		std::cin.clear();
		std::cin >> shortName;
		std::cout << '\n';
		while(shortName.length() > 2 || shortName.length() <= 0){
			std::cout << "Sifra Predmeta moze biti maksimalno 2 slova duzine\n";
			std::cout << "Sifra Predmeta: ";
			std::cin.clear();
			std::cin >> shortName;
			std::cout << '\n';
		}

		int shortCheck = nadjiPredmetPoKratici(listaPredmeta, shortName);

		if(shortCheck == 0){

			std::cout << "\n Naziv Predmeta: ";
			std::string fullName;
			std::cin.clear();
			std::cin >> fullName;
			std::cout << '\n';

			std::cout << "\n Studijski Program Kratica (2 slova): ";
			std::string studijskiP;
			std::cin.clear();
			std::cin >> studijskiP;
			std::cout << '\n';
			while(studijskiP.length() > 2 || studijskiP.length() <= 0){
				std::cout << "Studijski Program Kratica moze biti maksimalno 2 slova duzine\n";
				std::cout << "Studijski Program Kratica: ";
				std::cin.clear();
				std::cin >> studijskiP;
				std::cout << '\n';
			}

			int spCheck = nadjiSPPoKratici(listaSP, studijskiP);

			if(spCheck == 1){

				std::cout << "\n Usmjerenje Kratica (2 slova): ";
				std::string aUsmjerenje;
				std::cin.clear();
				std::cin >> aUsmjerenje;
				std::cout << '\n';
				while(aUsmjerenje.length() > 2 || aUsmjerenje.length() <= 0){
					std::cout << "Usmjerenje Kratica moze biti maksimalno 2 slova duzine\n";
					std::cout << "Usmjerenje Program 2 Kratica: ";
					std::cin.clear();
					std::cin >> aUsmjerenje;
					std::cout << '\n';
				}

				int usmjerenjeCheck = nadjiUsmjerenjePoKratici(listaUsmjerenja, aUsmjerenje);

				if(usmjerenjeCheck == 1){

					std::cout << "\n U semestru (broj): ";
					int uSemestru;
					std::cin.clear();
					if (std::cin >> uSemestru) {}else {
						uSemestru = 0;
						std::cout << "\n\n Unijeli ste nevažeći oblik podatka, vrijednost će biti upisana kao 0. \n\n ";
					}
					std::cout << '\n';

					std::cout << "\n Sedmicni sati predavanja: ";
					int aPredavanjaSati;
					std::cin.clear();
					if (std::cin >> aPredavanjaSati) {} else {
						aPredavanjaSati = 0;
						std::cout << "\n\n Unijeli ste nevažeći oblik podatka, vrijednost će biti upisana kao 0. \n\n ";
					}
					std::cout << '\n';

					std::cout << "\n Sedmicni sati auditornih vjezbi: ";
					int aAuditorneVjezbeS;
					std::cin.clear();
					if (std::cin >> aAuditorneVjezbeS) {} else {
						aAuditorneVjezbeS = 0;
						std::cout << "\n\n Unijeli ste nevažeći oblik podatka, vrijednost će biti upisana kao 0. \n\n ";
					}
					std::cout << '\n';

					std::cout << "\n Sedmicni sati laboratorijskih vjezbi: ";
					int aLabVjezbeS;
					std::cin.clear();
					if (std::cin >> aLabVjezbeS) {} else {
						aLabVjezbeS = 0;
						std::cout << "\n\n Unijeli ste nevažeći oblik podatka, vrijednost će biti upisana kao 0. \n\n ";
					}
					std::cout << '\n';

					std::cout << "\n Nosi Ects: ";
					int aNosiEcts;
					std::cin.clear();
					if (std::cin >> aNosiEcts) {} else {
						aNosiEcts = 0;
						std::cout << "\n\n Unijeli ste nevažeći oblik podatka, vrijednost će biti upisana kao 0. \n\n ";
					}
					std::cout << '\n';

					std::cout << "\n Traje semestara (broj): ";
					int aTrajeSemestara;
					std::cin.clear();
					if (std::cin >> aTrajeSemestara) {} else {
						aTrajeSemestara = 0;
						std::cout << "\n\n Unijeli ste nevažeći oblik podatka, vrijednost će biti upisana kao 0. \n\n ";
					}
					std::cout << '\n';

					Predmet aNewPredmet(
							shortName,
							fullName,
							studijskiP,
							aUsmjerenje,
							uSemestru,
							aPredavanjaSati,
							aAuditorneVjezbeS,
							aLabVjezbeS,
							aNosiEcts,
							aTrajeSemestara
					);

					listaPredmeta.push_back(aNewPredmet);

				}else{
					std::cout << "Usmjerenje sa unesenom kraticom ne postoji u bazi \n\n";
				}

			}else{
				std::cout << "Studijski Program sa unesenom kraticom ne postoji u bazi \n\n";
			}

		}else{
			std::cout << "Predmet sa unesenom kraticom vec postoji u bazi \n\n";
		}
	}

	std::cout << "Izlazite iz dodajUListuPredmeta \n\n";

}

void dodajUListuStudenata(std::vector<Student> &listaStudenata){

	std::cout << "Ulazite u dodajUListuStudenata \n\n";

	prikazListeStudenata(listaStudenata);
	std::cout << "\n\n";

	std::cout << "Ulazite u prostor za dodavanje novog studenta: \n\n";
	std::cout << "Jeste li sigurni da zelite dodati novog studenta? \n";

	std::cout << "Potvrdite sa DA ili NE: ";
	std::string confirmation;
	std::cin >> confirmation;

	if(confirmation == "DA"){

		std::cout << "\n Broj Indexa: ";
		std::string brIndex;
		std::cin.clear();
		std::cin >> brIndex;
		std::cout << '\n';

		int indexCheck = nadjiStudentaPoIndexu(listaStudenata, brIndex);

		if(indexCheck == 0){

			std::cout << "\n JMBG (13 znakova): ";

			std::string jmbgS;
			std::cin.clear();
			std::cin >> jmbgS;
			std::cout << '\n';
			while(jmbgS.length()!= 13){
				std::cout << "JMBG mora biti 13 znakova duzine\n";
				std::cout << "JMBG: ";
				std::cin.clear();
				std::cin >> jmbgS;
				std::cout << '\n';
			}

			std::cout << "\n Ime: ";
			std::string firstName;
			std::cin.clear();
			std::cin >> firstName;
			std::cout << '\n';

			std::cout << "\n Prezime: ";
			std::string lastName;
			std::cin.clear();
			std::cin >> lastName;
			std::cout << '\n';

			std::cout << "\n Smjer: ";
			std::string smjer;
			std::cin.clear();
			std::cin >> smjer;
			std::cout << '\n';

			Student aNewStudent(
					jmbgS,
					firstName,
					lastName,
					brIndex,
					smjer
			);

			listaStudenata.push_back(aNewStudent);
		}else{
			std::cout << "Student sa unijetim brojem indexa vec postoji u bazi \n\n";
		}

	}

	std::cout << "Izlazite iz dodajUListuStudenata \n\n";

}

void dodajUListuUsmjerenja(std::vector<Usmjerenje> &listaUsmjerenja){

	std::cout << "Ulazite u dodajUListuUsmjerenja \n\n";

	prikazListeUsmjerenja(listaUsmjerenja);
	std::cout << "\n\n";

	std::cout << "Ulazite u prostor za dodavanje novog usmjerenja: \n\n";
	std::cout << "Jeste li sigurni da zelite dodati novog usmjerenja? \n";

	std::cout << "Potvrdite sa DA ili NE: ";
	std::string confirmation;
	std::cin >> confirmation;

	if(confirmation == "DA"){

		std::cout << "\n Kratica Usmjerenja (2 slova): ";
		std::string shortName;
		std::cin.clear();
		std::cin >> shortName;
		std::cout << '\n';
		while(shortName.length() > 2 || shortName.length() <= 0){
			std::cout << "Kratica Usmjerenja moze biti maksimalno 2 slova duzine\n";
			std::cout << "Kratica Usmjerenja: ";
			std::cin.clear();
			std::cin >> shortName;
			std::cout << '\n';
		}

		int indexCheck = nadjiUsmjerenjePoKratici(listaUsmjerenja, shortName);

		if(indexCheck == 0){

			std::cout << "\n Naziv Usmjerenja: ";
			std::string fullName;
			std::cin.clear();
			std::cin >> fullName;
			std::cout << '\n';

			std::cout << "\n Studijski Program Kratica (2 slova): ";
			std::string studijskiP;
			std::cin.clear();
			std::cin >> studijskiP;
			std::cout << '\n';
			while(studijskiP.length() > 2 || studijskiP.length() <= 0){
				std::cout << "Studijski Program Kratica moze biti maksimalno 2 slova duzine\n";
				std::cout << "Studijski Program Kratica: ";
				std::cin.clear();
				std::cin >> studijskiP;
				std::cout << '\n';
			}

			Usmjerenje aNewUsmjerenje(
					shortName,
					fullName,
					studijskiP
			);

			listaUsmjerenja.push_back(aNewUsmjerenje);

		}else{
			std::cout << "Usmjerenje sa unesenom kraticom vec postoji u bazi \n\n";
		}
	}

	std::cout << "Izlazite iz dodajUListuUsmjerenja \n\n";

}

void dodajUListuIspita(
		std::vector<Ispit> &listaIspita,
		std::vector<Nastavnik> &listaNastavnika,
		std::vector<Student> &listaStudenata,
		std::vector<Predmet> &listaPredmeta){

	std::cout << "Ulazite u dodajUListuIspita \n\n";

	prikazListeIspita(listaIspita);
	std::cout << "\n\n";

	std::cout << "Ulazite u prostor za dodavanje novi ispit: \n\n";
	std::cout << "Jeste li sigurni da zelite dodati novi ispit? \n";

	std::cout << "Potvrdite sa DA ili NE: ";
	std::string confirmation;
	std::cin >> confirmation;

	if(confirmation == "DA"){

		std::cout << "\n Sifra Predmeta (2 slova): ";
		std::string shortName;
		std::cin.clear();
		std::cin >> shortName;
		std::cout << '\n';

		while(shortName.length() > 2 || shortName.length() <= 0){
			std::cout << "Sifra Predmeta moze biti maksimalno 2 slova duzine\n";
			std::cout << "Sifra Predmeta: ";
			std::cin.clear();
			std::cin >> shortName;
			std::cout << '\n';
		}

		int sifraCondition = nadjiPredmetPoKratici(listaPredmeta, shortName);

		if(sifraCondition == 1){

			std::cout << "\n Profesorov JMBG (13 znakova): ";
			std::string profesorJmbg;
			std::cin.clear();
			std::cin >> profesorJmbg;
			std::cout << '\n';

			while(profesorJmbg.length()!= 13){
				std::cout << "JMBG mora biti 13 znakova duzine\n";
				std::cout << "JMBG: ";
				std::cin.clear();
				std::cin >> profesorJmbg;
				std::cout << '\n';
			}

			int jmbgCondition = nadjiElement(listaNastavnika, profesorJmbg);

			if(jmbgCondition == 1){

				std::cout << "\n Broj Indexa: ";
				std::string brIndex;
				std::cin.clear();
				std::cin >> brIndex;
				std::cout << '\n';

				int brIndexaProvjera = nadjiStudentaPoIndexu(listaStudenata, brIndex);

				if(brIndexaProvjera == 1){

					std::cout << "\n Datum: ";
					std::string datum;
					std::cin.clear();
					std::cin >> datum;
					std::cout << '\n';

					int daLiIspitPostojiVec = nadjiIspitPoDatumuStudentuPredmetu(
							listaIspita,
							datum,
							brIndex,
							shortName);

					if(daLiIspitPostojiVec == 0){

						std::cout << "\n Ocjena: ";
						std::string ocjena;
						std::cin.clear();
						std::cin >> ocjena;
						std::cout << '\n';

						Ispit aNewIspit(
								shortName,
								profesorJmbg,
								brIndex,
								datum,
								ocjena
						);

						listaIspita.push_back(aNewIspit);
					}else{
						std::cout << "Ispit sa ovim vrijednostima vec postoji u bazi \n\n";
					}

				}else{
					std::cout << "Student sa unesenim brojem indexa ne postoji u bazi \n\n";
				}

			}else{
				std::cout << "Nastavnik sa unesenim jmbg-om ne postoji u bazi \n\n";
			}
		}else{
			std::cout << "Predmet sa takvom kraticom ne postoji u bazi \n\n";
		}

	}

	std::cout << "Izlazite iz dodajUListuIspita \n\n";

}

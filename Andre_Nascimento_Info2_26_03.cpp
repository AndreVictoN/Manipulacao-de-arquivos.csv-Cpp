/*
 * Andre_Nascimento_Info2_26_03.cpp
 *
 *  Created on: 26 de mar. de 2024
 *      Author: user
 */


#include <iostream>
#include <locale.h>
#include <locale>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

int main(){
	setlocale(LC_CTYPE,"");
	setbuf(stdout, NULL);

	string nomeAR;
	string fi;
	int s, id, i;
	int line = 0;
	string nome, sobrenome;
	int subturma;
	vector<int> sub;
	float nota;
	float soma1 = 0.0;
	float soma2 = 0.0;
	float soma3 = 0.0;
	int um = 0;
	int dois = 0;
	int tres = 0;

	float media1, media2, media3;

	cout << "Insira o nome do arquivo que deseja abrir COM sua extensão: " << endl;
	cin >> nomeAR;

	ifstream ar(nomeAR.c_str());

	char buffer[1000];
	while(ar.getline(buffer, 1000)){
		string strtemp(buffer);

		if(!isalpha(strtemp[0])){

			while(strtemp.find_first_of(',') < strtemp.length()){
				s = strtemp.find_first_of(',');
				strtemp.replace(s, 1, " ");
			}

			fi += strtemp;
			fi += "\n";

			stringstream stris(strtemp);

			stris >> id >> nome >> sobrenome >> subturma >> nota;

			switch(subturma){
			case 1:
				soma1 += nota;
				break;
			case 2:
				soma2 += nota;
				break;
			case 3:
				soma3 += nota;
				break;
			}

			sub.push_back(subturma);
			line++;
		}
	}

	for(i = 0; i < line; i++){
		switch(sub[i]){
		case 1:
			um++;
			break;
		case 2:
			dois++;
			break;
		case 3:
			tres++;
			break;
		}
	}

	media1 = soma1/um;
	media2 = soma2/dois;
	media3 = soma3/tres;

	cout << endl << "A media de cada subturma é: " << endl;
	cout << endl << "Subturma 1: " << media1 << endl << "Subturma 2: " << media2 << endl << "Subturma 3: " << media3 << endl;

	ar.close();
	return 0;
}

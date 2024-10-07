/*COMPILAR CON C++ 11, O NO COMPILA, DEBIDO AL USO DE RANDOM SIN LIBRERIA, ETC.*/
/*		g++ -std=c++11 TrieTree.cpp   		*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ABECEDARIO = 26;
const int CASE = 'a';
 
char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

class TrieNode {

public:
	TrieNode* papa = NULL;
	TrieNode* hijos_nodo [ABECEDARIO] = {};
	int conteo = 0;

};

class Trie_Tree {

public:
	
	void InsertNode(TrieNode* TrieRoot, char* palabra){
		
		TrieNode* CurrentNode = TrieRoot;

		while (*palabra != '\0') {

			if (CurrentNode->hijos_nodo[*palabra - CASE] == NULL) {

				CurrentNode->hijos_nodo[*palabra - CASE] = new TrieNode();
				CurrentNode->hijos_nodo[*palabra - CASE]->papa = CurrentNode;

			}

			CurrentNode = CurrentNode->hijos_nodo[*palabra - CASE];
			++palabra;

		}

		++CurrentNode->conteo;
	}

	TrieNode* Search(TrieNode* TrieRoot, char* palabra) {

		while(*palabra != '\0') {

			if(TrieRoot->hijos_nodo[*palabra -CASE] != NULL){

				TrieRoot = TrieRoot->hijos_nodo[*palabra - CASE];
				++palabra;

			}else {

				cout << "No se encuentra la palabra";
				return NULL;

			}

		}

		if (TrieRoot->conteo != 0) {

			//cout << "Palabra encontrada" << endl;
			return TrieRoot;

		} else {

			return NULL;

		}
	}
	
	void DeleteNode(TrieNode* TrieRoot, char* palabra) {

		TrieNode* CurrentNode = Search(TrieRoot, palabra);

		if(CurrentNode != NULL) {

			--CurrentNode->conteo;
			TrieNode* papi = NULL;
			bool esHoja = true;

			for(int i = 0; i < ABECEDARIO; ++i) {

				if (CurrentNode->hijos_nodo[i] != NULL) {

					esHoja = false;
					break;

				}

			}

			while (CurrentNode->papa != NULL && esHoja && CurrentNode->conteo == 0) {

				papi = CurrentNode->papa;
				for(int i = 0; i < ABECEDARIO; ++i) {

					if (papi->hijos_nodo[i] == CurrentNode) {

						papi->hijos_nodo[i] = NULL;
						delete CurrentNode;
						CurrentNode = papi;

					}else if(papi->hijos_nodo[i] != NULL) {

						esHoja = false;
						break;

					}
				
				}

			}

		}
	}

	void mostrar(TrieNode* TrieRoot, vector<char> palabra) {
		
		if(TrieRoot->conteo > 0) {

			for(auto iterador = palabra.begin(); iterador != palabra.end(); ++iterador) {

				cout << *iterador;

			}

			cout << " " << TrieRoot->conteo << endl;

		}

		for (int i = 0; i < ABECEDARIO; ++i) {

			if (TrieRoot->hijos_nodo[i] != NULL) {

				palabra.push_back(CASE + i);
				mostrar(TrieRoot->hijos_nodo[i], palabra);
				palabra.pop_back();

			}

		}

	}

};

char genRandom() {
	return alphanum[rand() % stringLength];
}

int main () {

	TrieNode* TrieRoot = new TrieNode();

	Trie_Tree TrieTree;

	std::vector<char> palabra;
	std::vector<string> cool;
	std::vector<string>::const_iterator iter;
	timespec qr_ini;
	timespec qr_fin;
	double time_eval;
	
	
	
	while (1) {

		string sss;
		string ssa;
		string ssb;
		int opcion;
		cout << "1--- Agregar Palabra" << endl;
		cout << "2--- Eliminar Palabra" << endl;
		cout << "3--- Buscar Palabra" << endl;
		cout << "4--- Imprimir Arbol" << endl;
		cout << "5--- Pruebas de Busqueda" << endl;
		cout << "6--- Llenado del arbol con largo" << endl;
		cout << "7--- Llenado del arbol aleatorio" << endl;
		cout << "0--- Exit" << endl;

		cout << "Opcion: ";
		cin >> opcion;


		if (opcion == 0) {
			exit(0);
		}else if (opcion == 1) {

			cout << "Que palabra desea agregar?" << endl;
			cout << "Palabra: ";
			cin >> sss;
			char* kor = (char*)sss.c_str();
			TrieTree.InsertNode(TrieRoot, kor);
		
		} else if (opcion == 2){

			int loco;
			cout << "Cuantas palabras desea eliminar" << endl;
			cin >> loco;
			string Str_3;
			for (int i = 0; i < loco; ++i){
				int numeroaleatorio = rand() % cool.size();
				Str_3 = cool[numeroaleatorio];
				vector<string>::iterator jojo = find(cool.begin(), cool.end(), Str_3);
				char* bon = (char*)Str_3.c_str();
				TrieTree.DeleteNode(TrieRoot, bon);
				cool.erase(jojo);
				
			}

		} else if(opcion == 3) {

			cout << "Que palabra desea buscar?" << endl;
			cout << "Palabra: ";
			cin >> ssb;
			char* koran = (char*)ssb.c_str();
			TrieTree.Search(TrieRoot, koran);

		} else if(opcion == 4){

			TrieTree.mostrar(TrieRoot, palabra);

		} else if (opcion == 5) {

			int shiki;
			cout << "Cuantas busquedas?" << endl;
			cin >> shiki;

			string Str_2;
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &qr_ini);

			for (int i = 0; i < shiki; ++i) {

				int numeroaleatorio = rand() % cool.size();
				Str_2 = cool[numeroaleatorio];
				char* fortnite = (char*)Str_2.c_str();
				TrieTree.Search(TrieRoot, fortnite);
			}

			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &qr_fin);

			time_eval = (1.0 * qr_fin.tv_sec - 1.0 * qr_ini.tv_sec);
			cout << time_eval << endl;

		} else if(opcion == 6) {


			srand(time(NULL));
			string Str;
			int largo;
			int cant;
			cout << "largo de las palabras? " << endl;
			cin >> largo;
			cout << "cantidad de palabras" << endl;
			cin >> cant;
			
			for (int k = 0; k < cant; ++k){ //cantidad de palabras dentro del arbol
	
				for (int i = 0; i < largo; ++i) {
					Str += genRandom();
				}

				char* nani = (char*)Str.c_str();
				TrieTree.InsertNode(TrieRoot, nani);
				cool.push_back(Str);
				Str = "";
			}
			

			
			
			

		} else if (opcion == 7) {

			srand(time(NULL));
			string Str;
			for (int k = 0; k < 200000; ++k){ //cantidad de palabras dentro del arbol
				int length = rand() % 51;
				if(length == 0) {
					length = 1;
				}
				for (int i = 0; i < length; ++i) {
					Str += genRandom();
				}

				char* nani = (char*)Str.c_str();
				TrieTree.InsertNode(TrieRoot, nani);
				cool.push_back(Str);
				Str = "";
			}

			cout << "Palabras dentro" << endl;

		} else {

			cout << "Please, choose wisely" << endl;

		}


	}

}
#include "Contraintes.h"

Contraintes::Contraintes()
{
}


Contraintes::~Contraintes()
{
}


Graph Contraintes::create_graph() {
	int nbSommets, nbArcs = 0;
	int start, finish, tmp;
	string line;
	int word;
	int count;
	Arcs tmp_arc;
	vector <Arcs> arcs;
	Graph graphe;
	vector<int> durees;
	durees.push_back(0);

	cout << "Veuillez choisir un fichier de contraintes (nombre : 1 -> 122)" << endl;
	cout << "fichier de contrainte : ";
	string file2 = "AB";
	string file;
	cin >> file;                          //L'utilisateur doit rentrer un nombre allant de 01 à 122

	if (file != "-1") {
		file2 += file;
		file2 += ".txt";                     //on ajoute le .txt
											 //cout << endl;                   //file stock -> racine du fichier
		ifstream fichier(file2.c_str());     //ifstream -> accès en lecture du fichier

		if (fichier) {

			fichier >> nbSommets; /// on stocke les 2 premiers caractères dans ces 3 variables

								  /// puis on les enregistre dans la structure graphe
			graphe.setNbSommets(nbSommets);
			vector<int>duree;
			for (int i = 0; i < nbSommets; i++) {
				fichier >> tmp >> tmp;
				durees.push_back(tmp);
				duree.push_back(tmp);
			}

			
			/// On stocke toutes les transitions
			while (getline(fichier, line)) {
				stringstream ss(line);

				count = 0;
				// extract all words from line
				while (ss >> word) {

					if (count == 0) {
						start = NULL;
						/// le sommet d'arrivée
						tmp_arc.setFinish(word);
						start = word;

					}
					else if(word != 0) {
						tmp_arc.setStart(word);   /// le sommet de départ

						tmp_arc.setDuree(duree[word - 1]); /// la durée de l'arc

						if (tmp_arc.getFinish() != 0)
							arcs.push_back(tmp_arc);

						cout << endl;
						cout << endl;
					}
					count++;
				}

			}
		}
		graphe.setDurees(durees);
		/// On met les résultats dans l'objet graphe
		graphe.setNbArcs(arcs.size());
		graphe.setArcs(arcs);
	}

	return graphe;
}

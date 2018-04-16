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

	cout << "Veuillez choisir un fichier de contraintes (nombre : 1 -> 122)" << endl;
	cout << "fichier de contrainte : ";
	string file2 = "CO";
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

			vector <int> duree;
			for (int i = 0; i < nbSommets; i++) {
				fichier >> tmp >> tmp;
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
						/// le sommet de départ
						tmp_arc.setStart(word);
						start = word;

					}
					else {
						tmp_arc.setFinish(word);   /// le sommet d'arrivée

						tmp_arc.setDuree(duree[start - 1]); /// la durée de l'arc

						if (tmp_arc.getFinish() != 0)
							arcs.push_back(tmp_arc);

						cout << endl;
						cout << endl;
					}
					count++;
				}

			}
		}

		/// On met les résultats dans l'objet graphe
		graphe.setNbArcs(arcs.size());
		graphe.setArcs(arcs);
	}

	return graphe;
}

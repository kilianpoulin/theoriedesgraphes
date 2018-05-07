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
	vector<vector<int>>contraintes;
	vector<int>contr;
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
				// extraction de tous les éléments d'une ligne
				while (ss >> word) {

					if (count == 0) {
						start = NULL;
						/// le sommet d'arrivée
						tmp_arc.setFinish(word);
						start = word;

					}
					else if(word != 0) {
						tmp_arc.setStart(word);   /// le sommet de départ
						
						contr.push_back(word); // la contrainte;
						
						tmp_arc.setDuree(duree[word - 1]); /// la durée de l'arc

						if (tmp_arc.getFinish() != 0)
							arcs.push_back(tmp_arc);

						cout << endl;
						cout << endl;
					}
					count++;
				}
				contraintes.push_back(contr);
				contr.clear();

			}
		}
		graphe.setDurees(durees);
		graphe.setContraintes(contraintes);
		/// On met les résultats dans l'objet graphe
		graphe.setNbArcs(arcs.size());
		graphe.setArcs(arcs);
	}

	return graphe;
}



Graph Contraintes::regenerate_graph(Graph graphe) {
	Arcs tmp_arc;
	vector <Arcs> arcs;

	// on réinitialisise les arcs du graph
	graphe.deleteArcs();

	// on réinitialise le nombre de sommets (sans alpha et omega)
	graphe.setNbSommets(graphe.m_contraintes.size() - 1);
	
	vector<int>duree;
	for (int i = 0; i < graphe.m_contraintes.size(); i++) {
		for (int j = 0; j < graphe.m_contraintes[i].size(); j++) {
			tmp_arc.setFinish(i);
			tmp_arc.setDuree(graphe.m_durees[graphe.m_contraintes[i][j]]);
			tmp_arc.setStart(graphe.m_contraintes[i][j]);
			arcs.push_back(tmp_arc);
		}
	}
	/// On met les résultats dans l'objet graphe
	graphe.setNbArcs(arcs.size());
	graphe.setArcs(arcs);

	return graphe;
}

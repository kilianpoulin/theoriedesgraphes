#include "Source.h"

Graph create_graph()
{
	int nbArcs, nbSommets;
	int start, finish, duree;
	string  file = "0";
	Graph graphe;

	cout << "Bonjour, veuillez choisir un graphe (nombre : 0 -> 16)" << endl;
	cout << "graphe : ";
	cin >> file;                          //L'utilisateur doit rentrer un nombre allant de 0 à 16

	file += ".txt";                     //on ajoute le .txt
	cout << file << endl;
	cout << endl;                   //file stock -> racine du fichier
	ifstream fichier(file.c_str());     //ifstream -> accès en lecture du fichier

	if (fichier) {

		fichier >> nbSommets >> nbArcs; /// on stocke les 2 premiers caractères dans ces 3 variables

										/// puis on les enregistre dans la structure graphe
		graphe.setNbSommets(nbSommets);
		graphe.setNbArcs(nbArcs);

		/// On stocke toutes les transitions
		vector <Arcs> arcs(nbArcs);
		for (int i = 0; i < nbArcs; i++) {
			fichier >> start;                   /// le sommet de départ
			arcs[i].setStart(start);

			fichier >> finish;
			arcs[i].setFinish(finish);   /// le sommet d'arrivée

			fichier >> duree;                  /// la duree de l'arc
			arcs[i].setDuree(duree);

		}
	
	/// On met les résultats dans l'objet graphe

	graphe.setArcs(arcs);

	}

		return graphe;
}

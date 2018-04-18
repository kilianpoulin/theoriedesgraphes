#include "Source.h"

Graph create_graph()
{
	int nbArcs, nbSommets;
	int start, finish, duree;
	string  file = "0";
	Graph graphe;

	cout << "Bonjour, veuillez choisir un graphe (nombre : 0 -> 16)" << endl;
	cout << "graphe : ";
	cin >> file;                          //L'utilisateur doit rentrer un nombre allant de 0 � 16

	file += ".txt";                     //on ajoute le .txt
	cout << file << endl;
	cout << endl;                   //file stock -> racine du fichier
    ifstream fichier(file.c_str());     //ifstream -> accËs en lecture du fichier

	if (fichier) {

		fichier >> nbSommets >> nbArcs; /// on stocke les 2 premiers caract�res dans ces 3 variables

										/// puis on les enregistre dans la structure graphe
		graphe.setNbSommets(nbSommets);
		graphe.setNbArcs(nbArcs);

		/// On stocke toutes les transitions
		vector <Arcs> arcs(nbArcs);
		for (int i = 0; i < nbArcs; i++) {
			fichier >> start;                   /// le sommet de d�part
			arcs[i].setStart(start);

			fichier >> finish;
			arcs[i].setFinish(finish);   /// le sommet d'arriv�e

			fichier >> duree;                  /// la duree de l'arc
			arcs[i].setDuree(duree);

		}
	
	/// On met les r�sultats dans l'objet graphe

	graphe.setArcs(arcs);

    }else{
        cout << "Erreur importation du fichier" << endl;
    }

		return graphe;
}

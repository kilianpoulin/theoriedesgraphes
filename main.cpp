#include <iostream>

#include "main.h"

using namespace std;

int main()
{
	int niv = 0;    //Niveau que l'utilisateur sera amené à choisir
	Graph graphe;
	int nbSommets, nbArcs;
	cout << "****** Projet de theorie des graphes ******" << endl << endl << endl;

	cout << "Bonjour, veuillez choisir un graphe (nombre : 01 -> 122)" << endl;
	cout << "graphe : ";
	string  file;
	cin >> file;                          //L'utilisateur doit rentrer un nombre allant de 01 à 122

	while (file != "-1") /// boucle while pour lire autant de fois que l'on veut un fichier
	{
		file += ".txt";                     //on ajoute le .txt
		cout << file << endl;
		cout << endl;                   //file stock -> racine du fichier
		ifstream fichier(file.c_str());     //ifstream -> accès en lecture du fichier

		if (fichier) {

			fichier >> nbSommets >> nbArcs; /// on stocke les 2 premiers caractères dans ces 3 variables

											/// puis on les enregistre dans la structure graphe
			graphe.setNbSommets(nbSommets);
			graphe.setNbArcs(nbArcs);

			int start, finish, duree;

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
			///Affichage du graphe (contenu du fichier)
			//Optionnel
			for (int i = 0; i<graphe.getNbArcs(); i++)
			{
				cout << graphe.m_arcs[i].getStart();
				cout << graphe.m_arcs[i].getFinish();
				cout << graphe.m_arcs[i].getDuree() << endl;
			}

			cout << endl;
			cout << endl;
			cout << endl;

			///Affichage de la Matrice d'adjacence
			graphe.setMatriceAdjacence(arcs);
			graphe.showMatriceAdjacence();

		} /// fin lecture du fichier

		  /// Demande à l'utilisateur quel niveau il souhaite évaluer le graphe (condition switch)
		cout << "Niveau souhaite :" << endl;
		cin >> niv;


		while (niv != -1)// Tant que l'on veut examiner les niveaux
		{
			switch (niv)
			{
			case 1: ///Niveau 1: Matrice d'adjacence, Matrice de Valeurs, Détection de circuit, Calcul de Rang
				cout << "Niveau 1" << endl;
				cout << endl;
				//Algo à effectuer au niveau 1

				/*Affichage de la Matrice d'adjacence

				graphe.setMatriceAdjacence(arcs);
				graphe.showMatriceAdjacence();*/

				cout << endl;
				cout << "Autre niveau?" << endl;
				cout << "-1 pour quitter" << endl;
				cin >> niv;
				cout << endl;
				break;
			case 2:
				cout << "Niveau 2" << endl;
				cout << endl;
				//Algo à effectuer au niveau 2
				cout << endl;
				cout << "Autre niveau?" << endl;
				cout << "-1 pour quitter" << endl;
				cin >> niv;
				cout << endl;
				break;
			case 3:
				cout << "Niveau 3" << endl;
				cout << endl;
				//Algo à effectuer au niveau 3
				cout << endl;
				cout << "Autre niveau?" << endl;
				cout << "-1 pour quitter" << endl;
				cin >> niv;
				cout << endl;
				break;
			case 4:
				cout << "Niveau 4" << endl;
				cout << endl;
				//Algo à effectuer au niveau 4
				cout << endl;
				cout << "Autre niveau?" << endl;
				cout << "-1 pour quitter" << endl;
				cin >> niv;
				cout << endl;
				break;
			default:
				cout << "Niveau incorrect" << endl;
				cin >> niv;
				break;
			}
		}
		file = "";
		cout << "Bonjour, veuillez choisir un graphe (nombre : 01 -> 122)" << endl;
		cout << "graphe : ";
		cin >> file;
	}/// fin du while de lecture de fichier

	return 0;
}
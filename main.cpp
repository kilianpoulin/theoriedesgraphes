#include <iostream>

#include "main.h"

using namespace std;

// fichier principal 

int main()
{
	int niv = 0;    //Niveau que l'utilisateur sera amen� � choisir
	Graph graphe;
	int nbSommets, nbArcs;
	string tmp;
	cout << "****** Projet de theorie des graphes ******" << endl << endl << endl;

	cout << "Bonjour, veuillez choisir un graphe (nombre : 01 -> 122)" << endl;
	cout << "graphe : ";
	string  file;
	cin >> file;                          //L'utilisateur doit rentrer un nombre allant de 01 � 122

	while (file != "-1") /// boucle while pour lire autant de fois que l'on veut un fichier
	{
		file += ".txt";                     //on ajoute le .txt
		cout << file << endl;
		cout << endl;                   //file stock -> racine du fichier
		ifstream fichier(file.c_str());     //ifstream -> acc�s en lecture du fichier

		if (fichier) {

			fichier >> nbSommets >> nbArcs; /// on stocke les 2 premiers caract�res dans ces 3 variables

											/// puis on les enregistre dans la structure graphe
			graphe.setNbSommets(nbSommets);
			graphe.setNbArcs(nbArcs);

			int start, finish, duree;

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
			///Affichage du graphe (contenu du fichier)
			//Optionnel
			cout << '\t' << graphe.getNbSommets() << '\t' << '\t' << '\t' << "Nombre de sommets du graphe" << endl;
			cout << '\t' << graphe.getNbArcs() << '\t' << '\t' << '\t' << "Nombre d'arcs du graphe" << endl;
			for (int i = 0; i<graphe.getNbArcs(); i++)
			{
				cout << '\t' << graphe.m_arcs[i].getStart();
				cout << '\t' << graphe.m_arcs[i].getFinish();
				cout << '\t' << graphe.m_arcs[i].getDuree() << endl;
			}

			cout << endl;
			cout << endl;
			cout << endl;


			/// Demande � l'utilisateur quel niveau il souhaite �valuer le graphe (condition switch)
			cout << "Niveau souhaite :" << endl;
			cin >> niv;


			while (niv != -1)// Tant que l'on veut examiner les niveaux
			{
				switch (niv)
				{
				case 1: ///Niveau 1: Matrice d'adjacence, Matrice de Valeurs, D�tection de circuit, Calcul de Rang
					cout << "Niveau 1" << endl;
					cout << endl;
					//Algo � effectuer au niveau 1

					///Affichage de la Matrice d'adjacence
					cout << "Affichage de la Matrice d'adjacence" << endl;
					graphe.setMatriceAdjacence(arcs);
					graphe.showMatriceAdjacence();

					cout << endl;

					cout << "Affichage de la Matrice de Valeurs" << endl;
					/*Code
					�
					ins�rer*/
					cout << endl;

					cout << "D�tection de circuits" << endl;
					/*Code
					�
					ins�rer*/
					cout << endl;

					cout << "Calcul de Rangs" << endl;
					/*Code
					�
					ins�rer*/
					cout << endl;

					cout << "Autre niveau?" << endl;
					cout << "-1 pour quitter" << endl;
					cin >> niv;
					cout << endl;
					break;
				case 2:
					cout << "Niveau 2" << endl;
					cout << endl;

					/// on initialise les outils du niveau 1
					graphe.setMatriceAdjacence(arcs);

					cout << "Verifications " << endl;
					cout << endl;

					if (graphe.verifMaxUneEntree())
						tmp = "Oui";
					else
						tmp = "Non";
					cout << "Le graphe ne possede qu'une seule entree (max) : " << tmp << endl;
						
					if (graphe.verifMaxUneSortie())
						tmp = "Oui";
					else
						tmp = "Non";
					cout << "Le graphe ne possede qu'une seule sortie (max) : " <<  tmp << endl;

					if (graphe.getNbEntrees() == 0)
						tmp = "Non, il n'y a pas de point d'entree";
					else if (graphe.getNbEntrees() > 1)
						tmp = "Il y a plusieurs points d'entrees";
					else if (graphe.verifAccessibleDepuisEntree())
						tmp = "Oui";
					else
						tmp = "Non";
					cout << "Tous les sommets sont accessibles de puis le point d'entree : " << tmp << endl;

					if (graphe.getNbSorties() == 0)
						tmp = "Non, il n'y a pas de point de sortie";
					else if (graphe.getNbSorties() > 1)
						tmp = "Il y a plusieurs points de sortie";
					else if (graphe.verifAccessibleDepuisSortie())
						tmp = "Oui";
					else
						tmp = "Non";
					cout << "Le point de sortie est accessible depuis tous les autres sommets : " << tmp << endl;

					if (graphe.verifValeursArcs())
						tmp = "Oui";
					else
						tmp = "Non";
					cout << "Les valeurs des arcs sont positives ou nulles : " << tmp << endl;

					if (graphe.verifMemeSommetMemeValeur())
						tmp = "Oui";
					else
						tmp = "Non";
					cout << "Tous les arcs sortant d'un meme sommet une meme valeur : " << tmp << endl;

					//Algo � effectuer au niveau 2
					cout << endl;
					cout << "Autre niveau?" << endl;
					cout << "-1 pour quitter" << endl;
					cin >> niv;
					cout << endl;
					break;
				case 3:
					cout << "Niveau 3" << endl;
					cout << endl;

					//Algo � effectuer au niveau 3
					cout << endl;
					cout << "Autre niveau?" << endl;
					cout << "-1 pour quitter" << endl;
					cin >> niv;
					cout << endl;
					break;
				case 4:
					cout << "Niveau 4" << endl;
					cout << endl;
					//Algo � effectuer au niveau 4
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
		} /// fin lecture du fichier
		file = "";
		cout << "Bonjour, veuillez choisir un graphe (nombre : 01 -> 122)" << endl;
		cout << "graphe : ";
		cin >> file;
	}/// fin du while de lecture de fichier

	return 0;
}

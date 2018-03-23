#include <iostream>

#include "main.h"

using namespace std;
//test
// fichier principal 

int main()
{
	int niv = 0;    //Niveau que l'utilisateur sera amené à choisir
	Graph graphe;
	Contraintes contrainte;
	string tmp;
	cout << "****** Projet de theorie des graphes ******" << endl << endl << endl;                  

	while (niv != -1)// Tant que l'on veut examiner les niveaux
	{
		/// Demande à l'utilisateur quel niveau il souhaite évaluer le graphe (condition switch)
		cout << "Niveau souhaite (de 1 a 4) :" << endl;

		cin >> niv;

		switch (niv)
		{
		case 1: ///Niveau 1: Matrice d'adjacence, Matrice de Valeurs, Détection de circuit, Calcul de Rang
			cout << "Niveau 1" << endl;
			cout << endl;
					
			/// On créer le graphe à partir d'un fichier
			graphe = create_graph();
					
			/// On affiche le graph
			graphe.show_graph();


			///Affichage de la Matrice d'adjacence
			cout << "Affichage de la Matrice d'adjacence" << endl;
			graphe.setMatriceAdjacence();
			graphe.showMatriceAdjacence();

			cout << endl;

			cout << "Affichage de la Matrice de Valeurs" << endl;
			/*Code
			à
			insérer*/
			cout << endl;

			cout << "Détection de circuits" << endl;
			/*Code
			à
			insérer*/
			cout << endl;

			cout << "Calcul de Rangs" << endl;
			/*Code
			à
			insérer*/
			cout << endl;
			break;
		case 2:
			cout << "Niveau 2" << endl;
			cout << endl;

			/// On créer le graphe à partir d'un fichier
			graphe = create_graph();

			/// On affiche le graph
			graphe.show_graph();

			/// on initialise les outils du niveau 1
			graphe.setMatriceAdjacence();

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

			cout << endl;
			break;
		case 3:
			cout << "Niveau 3" << endl;
			cout << endl;
					
			graphe = contrainte.create_graph();

			graphe.show_graph();

			cout << endl;
			break;
		case 4:
			cout << "Niveau 4" << endl;
			cout << endl;
			//Algo à effectuer au niveau 4
			cout << endl;
			break;
		default:
			cout << "Niveau incorrect" << endl;
			cin >> niv;
			break;
		}

		cout << endl << "---------------------------------------------------------------" << endl << endl;
		cout << "Autre niveau?" << endl;
		cout << "-1 pour quitter" << endl;
		cout << endl << "---------------------------------------------------------------" << endl << endl;
	}

	return 0;
}

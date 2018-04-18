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
            graphe.setMatriceIncidence();
            graphe.showMatriceIncidence();
			cout << endl;

			cout << "Detection de circuits" << endl;
			graphe.circuitDetection();
			cout << endl;

			cout << "Calcul de Rangs" << endl;
			graphe.showRang();

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

			if (graphe.showVerifications()) {
				cout << "Calcul des calendriers et marges : " << endl;
				graphe.circuitDetection();
				graphe.calcDatePlusTot(); ;
				graphe.calcDatePlusTard();
				graphe.calcMargeTotale();
				graphe.calcMargeLibre();

				graphe.calcDatePlusTard();

				graphe.showCalendrier();
			}
			else {
				cout << '\t' << "Toutes les proprietes necessaire du graphe ne sont pas presentes (voir ci-dessus)" << endl << endl;
				cout << '\t' << "Le calcul du rang, des calendriers et des marges n'est pas possible" << endl;
			}


			
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

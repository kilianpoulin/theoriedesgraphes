#include <iostream>

#include "main.h"

using namespace std;
//test
// fichier principal 

void affichage(int niveau, Graph graphe) {
	Contraintes contrainte;
	if (niveau == 1 || niveau == 2) {
		/// On créer le graphe à partir d'un fichier
		graphe = create_graph();

		/// On affiche le graph
		graphe.show_graph();


		///Affichage de la Matrice d'adjacence
		cout << "  => Affichage de la Matrice d'adjacence" << endl << endl;
		graphe.setMatriceAdjacence();
		graphe.showMatriceAdjacence();

		cout << endl;

		cout << "  => Affichage de la Matrice de Valeurs" << endl << endl;

		graphe.setMatriceIncidence();
		graphe.showMatriceIncidence();
		cout << endl;

		cout << "  => Detection de circuits" << endl << endl;

		graphe.circuitDetection();
		cout << endl;

		cout << "  => Suivi de la detection et de l'elimination des sommets" << endl << endl;
		graphe.showAntecedents();
		cout << endl;

		cout << "  => Calcul de Rangs" << endl << endl;
		graphe.showRang();

		if (niveau == 2) {
			if (graphe.showVerifications()) {
				cout << endl;

				cout << "Calcul des calendriers et marges : " << endl << endl;

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
		}
	}
	else if (niveau == 3 || niveau == 4 || niveau == 5) {

		if (niveau == 5)
			graphe = contrainte.regenerate_graph(graphe);
		else
			graphe = contrainte.create_graph();

		graphe.show_graph();

		// matrice d'adjacence sans alpha et omega
		graphe.contrainteSetMatriceAdjacence();
		graphe.contrainteSetMatriceIncidence();

		graphe.contrainteSetEntrees();
		graphe.contrainteSetSorties();


		graphe.createAlpha();
		graphe.createOmega();
		

		// matrice d'adjacence avec apha et omega
		graphe.contrainteSetMatriceAdjacence();
		//graphe.contrainteSetMatriceIncidence();

		graphe.show_graph();

		///Affichage de la Matrice d'adjacence
		cout << "  => Affichage de la Matrice d'adjacence" << endl << endl;
		graphe.showMatriceAdjacence();

		cout << endl;

		//cout << "  => Affichage de la Matrice d'incidence" << endl << endl;
		//graphe.showMatriceIncidence();

		cout << endl;

		cout << "  => Detection de circuits" << endl << endl;

		// si le graphe contient un circuit
		if (graphe.circuitDetection() && niveau != 3) {
			cout << endl << endl;
			graphe.showProblem();
			affichage(5, graphe);
		}
		else {

			graphe.circuitDetection();
			cout << endl;

			cout << "  => Suivi de la detection et de l'elimination des sommets" << endl << endl;
			graphe.showAntecedents();
			cout << endl;

			cout << "  => Calcul de Rangs" << endl << endl;
			graphe.showRang();

			if (graphe.showVerifications()) {
				cout << endl;
			}

			cout << "Calcul des calendriers et marges : " << endl << endl;

			graphe.calcDatePlusTot();
			graphe.calcDatePlusTard();
			graphe.calcMargeTotale();
			graphe.calcMargeLibre();
			graphe.showCalendrier();
			cout << endl;
		}

	}
}
int main()
{
	Graph graphe;
	int niv = 0;    //Niveau que l'utilisateur sera amené à choisir
	string tmp;
	cout << "****** Projet de theorie des graphes ******" << endl << endl << endl;                  

	while (niv != -1)// Tant que l'on veut examiner les niveaux
	{
		/// Demande à l'utilisateur quel niveau il souhaite évaluer le graphe (condition switch)
		cout << '\t' << "Niveau souhaite (de 1 a 4) :" << endl;
		cout << "  => Niveau : ";

		cin >> niv;

		switch (niv)
		{
		case 1: ///Niveau 1: Matrice d'adjacence, Matrice de Valeurs, Détection de circuit, Calcul de Rang
			cout << "  => Niveau 1" << endl;
			cout << endl;
					
			affichage(1, graphe);
			
			cout << endl << endl;

			cout << endl;
			break;
		case 2:
			cout << "Niveau 2" << endl;
			cout << endl;

			affichage(2, graphe);
			
			cout << endl;
			break;
		case 3:
			cout << "Niveau 3" << endl;
			cout << endl;
					
			affichage(3, graphe);

			cout << endl;
			break;
		case 4:
			cout << "Niveau 4" << endl;
			cout << endl;
			cout << endl;

			affichage(4, graphe);

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



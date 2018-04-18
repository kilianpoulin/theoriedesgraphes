#include "Graph.h"
#include <iostream>

// Toutes les fonctions des graph
Graph::Graph()
{
	//ctor
}

Graph::~Graph()
{
	//dtor
}

void Graph::setNbArcs(int val)
{
	m_nbArcs = val;
}
void Graph::setNbSommets(int val)
{
	m_nbSommets = val;
}
int Graph::getNbArcs()
{
	return m_nbArcs;
}
int Graph::getNbSommets()
{
	return m_nbSommets;
}
int Graph::getNbEntrees()
{
	return m_nbEntrees;
}
int Graph::getNbSorties()
{
	return m_nbSorties;
}
void Graph::setArcs(vector <Arcs> arcs) {

	Arcs arcVide;
	for (int i = 0; i < arcs.size(); i++) {
		m_arcs.push_back(arcVide);
	}
	m_arcs = arcs;
}

void Graph::show_graph() {
	///Affichage du graphe (contenu du fichier)
	//Optionnel
	cout << '\t' << m_nbSommets << '\t' << '\t' << '\t' << "Nombre de sommets du graphe" << endl;
	cout << '\t' << m_nbArcs << '\t' << '\t' << '\t' << "Nombre d'arcs du graphe" << endl;
	for (int i = 0; i< m_nbArcs; i++)
	{
		cout << '\t' << m_arcs[i].getStart();
		cout << '\t' << m_arcs[i].getFinish();
		cout << '\t' << m_arcs[i].getDuree() << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
}

void Graph::setMatriceAdjacence() {
	/**
	* Generate the adjustment matrix with the transition arcs.
	*/

	for (int i = 0; i < m_nbSommets; i++) {
		m_matriceAdjacence.push_back(vector<bool>(m_nbSommets, false));
	}

	for (int i = 0; i < m_nbArcs; i++) {
		m_matriceAdjacence[m_arcs[i].getStart()][m_arcs[i].getFinish()] = true;
	}
}

void Graph::showMatriceAdjacence() {
	for (int i = 0; i < m_nbSommets; i++) {
		for (int j = 0; j < m_nbSommets; j++) {
			cout << '\t' << m_matriceAdjacence[i][j];
		}
		cout << endl;
	}

}

void Graph::showMatriceAdjacence2() {
	for (int i = 0; i < m_nbSommets; i++) {
		for (int j = 0; j < m_nbSommets; j++) {
			cout << '\t' << m_adj2[i][j];
		}
		cout << endl;
	}

}

bool Graph::verifMaxUneEntree() {
	// on initialise le compteur du nombre d'entrées
	int nb_entree = 0;
	int entree;
	int tmp_entree = NULL;

	// on parcourt la matrice d'adjacence
	for (int s = 0; s < m_nbSommets; s++) {
		entree = true; // on part du principe que c'est une entree
		for (int i = 0; i < m_nbSommets; i++) {
			/// si le sommet a un prédécesseur (autre que lui-même) --> ce n'est pas une entree
			if (i != s && m_matriceAdjacence[i][s] == 1) {
				entree = false;
				break;
			}
		}
		if (entree) {
			nb_entree++;
			tmp_entree = s;
		}
			
	}
	m_nbEntrees = nb_entree; // on stocke le nombre d'entrées
	if (nb_entree <= 1) {
		m_pointEntree = tmp_entree; // on stocke l'entrée (ou NULL s'il n'y en a pas)
		return true;
	}
	else
		return false;
}

bool Graph::verifMaxUneSortie() {
	// on initialise le compteur du nombre d'entrées
	int nb_sortie = 0;
	bool sortie;
	int tmp_sortie = NULL;

	// on parcourt la matrice d'adjacence
	for (int s = 0; s < m_nbSommets; s++) {
		sortie = true; // on part du prince que c'est une sortie
		for (int i = 0; i < m_nbSommets; i++) {
			/// si le sommet a un successeur (autre que lui-même) --> ce n'est pas une sortie
			if (i != s && m_matriceAdjacence[s][i] == 1) {
				sortie = false;
				break;
			}
		}
		if (sortie) {
			tmp_sortie = s;
			nb_sortie++;
		}
			
	}
	m_nbSorties = nb_sortie; // on stocke le nombre de sorties
	if (nb_sortie <= 1) {
		m_pointSortie = tmp_sortie; // on stocke la sortie (ou NULL s'il n'y en a pas)
		return true;
	}
		
	else
		return false;
}

bool Graph::verifAccessibleDepuisEntree() {
	for (int j = 0; j < m_nbSommets; j++) {
		/// si l'entree n'est pas relié à l'un des points du graphe (sauf lui-même) --> faux
		if (m_matriceAdjacence[m_pointEntree][j] == 0)
			return false;
	}

	return true;
}

bool Graph::verifAccessibleDepuisSortie() {
	for (int i = 0; i < m_nbSommets; i++) {
		/// si l'entree n'est pas relié à l'un des points du graphe (sauf lui-même) --> faux
		if (m_matriceAdjacence[i][m_pointSortie] == 0)
			return false;
	}

	return true;
}

bool Graph::verifValeursArcs() {
	for (int i = 0; i < m_nbArcs - 1; i++) {
		if (m_arcs[i].getDuree() < 0)
			return false;
	}
	return true;
}

bool Graph::verifMemeSommetMemeValeur() {
	int tmp_val;
	for (int s = 0; s < m_nbSommets; s++) {
		tmp_val = NULL; // on initialise la valeur des arcs pour un sommet
		for (int i = 0; i < m_nbArcs; i++) {
			if (m_arcs[i].getStart() == s) {
				if (tmp_val == NULL)
					tmp_val = m_arcs[i].getDuree();
				else if (m_arcs[i].getDuree() != tmp_val)
					return false;
			}
		}
	}
	return true;
}

bool Graph::MatrAdjEqualstoZero() {
	for (int i = 0; i < m_nbSommets; i++) {
		for (int j = 0; j < m_nbSommets; j++) {
			if (m_adj2[i][j] != 0)
				return false;
		}
	}
	return true;
}

void Graph::showRang() {
	for (int i = 0; i < m_tmp_rang - 1; i++) {
		cout << "*********************" << endl;
		cout << "Rang " << i + 1 << endl;
		for (int j = 0; j < m_rang[i].size() - 1; j++) {
			cout << m_rang[i][j];
			if (j != m_rang[i].size() - 2)
				cout << ", ";
		}
		cout << endl;
	}
}

void Graph::circuitDetection() {
	m_circuit = true;
	for (int x = 0; x < m_nbSommets; x++) //initialise le vector m_tmp
	{
		m_tmp.push_back(0);
	}
	m_adj2 = m_matriceAdjacence;

	/// nombre d'antécédents par sommet i
	for (int i = 0; i < m_nbSommets; i++) {
		for (int j = 0; j < m_nbSommets; j++) {
			if (m_adj2[j][i] == 1)
			{
				m_tmp[i] += 1;
			}
		}
		if (m_tmp[i] == 0)
			m_entrees.push_back(i);
	}
	if (detectionRang() == true)
	{
		cout << "Ce graphe contient un ou plusieurs circuits" << endl;
	}
	else
	{
		cout << "Ce graphe ne contient pas de circuits" << endl;
	}
}

bool Graph::detectionRang()
{
	int nbetats = 1;
		if (m_entrees.size() == 0) { // il n'y a pas d'entrées donc circuit
			cout << "ERREUR --> le graph n'a pas d'entrée" << endl;
			return true;
		}
		
		cout << "Elimination : " << endl;
		m_rang.push_back(vector<int>(m_entrees.size() + 1, NULL)); // on connait le nombre d'états dans le rang
		for (int i = 0; i < m_entrees.size(); i++) { // on traite d'abord les entrées
			// on les met au rang 1
			m_rang[0][i] = m_entrees[i];
			cout << "sommet : " << m_entrees[i] << endl;
		}
		// on supprime les sommets petit à petit
		if (elimination()) {
			// renvoie true donc il y a un circuit
			return true;
		}
		return false;
}

bool Graph::elimination()	
{
	int final_z, z, i;
	do {
		cout << "--------------------------------" << endl;
		z = 0;
		i = 0;
		std::vector<int> tmp_etat;
		for (int k = 0; k < m_rang[m_tmp_rang - 1].size(); k++) {
			i = m_rang[m_tmp_rang - 1][k];
			for (int j = 0; j < m_nbSommets; j++) { // on se place à l'état j
				if (m_tmp[j] == 0) { // l'état j n'a déjà plus d'antécédents
					// on ne fait rien
				}
				else {
					if (m_adj2[i][j] == 1) { /// si l'état qu'on supprime fait parti des prédécesseurs de j

						m_tmp[j]--; // un prédécesseur en moins

						if (m_tmp[j] == 0) { // si maintenant il n'a plus de prédécesseurs, on a son rang
							tmp_etat.push_back(j);
							z++;
						}
						m_adj2[i][j] = false; // l'état qu'on supprime n'est plus un prédécesseur de j
					}
				}

			}
		}
		m_rang.push_back(vector<int>(tmp_etat.size() + 1, NULL)); // on connait le nombre d'états dans le rang
		cout << "Elimination : " << endl;
		for (int n = 0; n < tmp_etat.size(); n++) {
			m_rang[m_tmp_rang][n] = tmp_etat[n];
			cout << "sommet : " << m_rang[m_tmp_rang][n] << endl;
		}
		m_tmp_rang++; // on passe au calcul du rang suivants
		final_z = z;
		} while(final_z != 0);

	if(MatrAdjEqualstoZero()) 
		return false;
	return true;		
} 

int Graph::getMaxDureeAntecedent(int sommet) {
	int tmp = 0;
	int max = 0;
	for (int i = 0; i < m_arcs.size(); i++) {
		if (m_arcs[i].getFinish() == sommet) {
			tmp = m_arcs[i].getDuree() + getMaxDureeAntecedent(m_arcs[i].getStart());
			if (tmp > max)
				max = tmp;
		}
	}
	return max;
}

void Graph::initializeDatePlusTot() {
	int j = 0;
	for (int i = 0; i < m_tmp_rang - 1; i++) {
		for (j = 1; j< m_rang[i].size() - 1; j++) {
		}
		m_date_plus_tot.push_back(vector<int>(j, 0));
	}
}

void Graph::calcDatePlusTot() {
	// on initialise le vecteur date au plus tot
	initializeDatePlusTot();
	for (int i = 0; i < m_tmp_rang - 1; i++) {
		for (int j = 0; j < m_rang[i].size() - 1; j++) {
			// on recherche la duree la plus grande entre l'état et ses antécédents
			m_date_plus_tot[i][j] = getMaxDureeAntecedent(m_rang[i][j]);
		}
	}

}

void Graph::showCalendrier() {
	cout << '\t' << "Rang" << '\t' << "Sommet" << '\t' << "D+tot" << '\t' << "D+tard" << '\t' 
		<< "Marge Totale" << '\t' << "Marge Libre" << endl;
	for (int i = 0; i < m_date_plus_tot.size(); i++) {
		for (int j = 0; j < m_date_plus_tot[i].size(); j++) {
			// on affiche le rang, le sommet et sa date au plus tôt
			cout << '\t' << i + 1 << '\t' << m_rang[i][j] << '\t' << m_date_plus_tot[i][j] <<
				'\t' << m_date_plus_tard[i][j] << '\t' << m_marge_totale[i][j] << 
				'\t' << m_marge_libre[i][j] << endl;
		}
		cout << '\t' << "--------------------------------------------------------" << endl;
	}

}

void Graph::initializeDatePlusTard() {
	int j = 0;
	for (int i = 0; i < m_tmp_rang - 1; i++) {
		for (j = 1; j< m_rang[i].size() - 1; j++) {
		}
		m_date_plus_tard.push_back(vector<int>(j, 0));
	}
}

int Graph::TardTemp(int sommet, int rang) {
	int count = 0;
	for (int s = 0; s < m_rang[rang + 1].size() - 1; s++) { // on regarde tous les sommets appartenant au rang superieur
		for (int i = 0; i < m_arcs.size(); i++) { // on regarde s'il y a un arc existant entre le sommet actuel et l'un du rang superieur
			if (m_arcs[i].getStart() == sommet && m_arcs[i].getFinish() == m_rang[rang + 1][s]) {
				count++;
			}
				
		}
	}
	return count;
}

int Graph::TardFinal(int var_tmp, int sommet, int rang) {
	int tmp = 0;
	int i_tmp = 0;
	int count = 0;
	bool test = false;

	if (rang + 1 > (m_tmp_rang - 2)) {
		m_var = 0;
		m_rollback = true;
		return 0;
	}
	for (int s = 0; s < m_rang[rang + 1].size() - 1; s++) { // on regarde tous les sommets appartenant au rang superieur
		for (int i = 0; i < m_arcs.size(); i++) { // on regarde s'il y a un arc existant entre le sommet actuel et l'un du rang superieur
			if (m_arcs[i].getStart() == sommet && m_arcs[i].getFinish() == m_rang[rang + 1][s]) {

				if (m_rollback == true) {
					m_var = var_tmp;
					m_rollback = false;
				}
				if (TardTemp(sommet, rang) > 1) {
					var_tmp = m_var;
				}

				if ((m_var + m_arcs[i].getDuree()) > m_duree)
					m_duree = m_var + m_arcs[i].getDuree();
				m_var += m_arcs[i].getDuree();
				m_var += TardFinal(var_tmp, m_arcs[i].getFinish(), rang + 1);
				
				if (m_arcs[i].getDuree() > tmp) {
					tmp = m_arcs[i].getDuree();
					i_tmp = i;
				}

			}
		}
	}
	if(tmp == 0)
		return tmp + TardFinal(var_tmp, sommet, rang + 1);

}

void Graph::calcDatePlusTard() {
	// on initialise le vecteur date au plus tot
	initializeDatePlusTard();
	for (int i = m_tmp_rang - 1; i > -1; i--) {
		for (int j = 0; j < m_rang[i].size() - 1; j++) {
			m_var_tmp = 0;

			TardFinal(0, m_rang[i][j], i);

			m_date_plus_tard[i][j] = m_date_plus_tot[m_tmp_rang - 2][0] - m_duree;
			m_var = 0;
			m_duree = 0;
		}
	}
}

void Graph::initializeMargeTotale() {
	int j = 0;
	for (int i = 0; i < m_tmp_rang - 1; i++) {
		for (j = 1; j< m_rang[i].size() - 1; j++) {
		}
		m_marge_totale.push_back(vector<int>(j, 0));
	}
}

void Graph::calcMargeTotale() {
	initializeMargeTotale();
	for (int i = 0; i < m_date_plus_tot.size(); i++) {
		for (int j = 0; j < m_date_plus_tot[i].size(); j++) {
			m_marge_totale[i][j] = m_date_plus_tard[i][j] - m_date_plus_tot[i][j];
		}
	}
}

void Graph::initializeMargeLibre() {
	int j = 0;
	for (int i = 0; i < m_tmp_rang - 1; i++) {
		for (j = 1; j< m_rang[i].size() - 1; j++) {
		}
		m_marge_libre.push_back(vector<int>(j, 0));
	}

}
void Graph::calcMargeLibre() {
	initializeMargeLibre();
	for (int i = 0; i < m_date_plus_tot.size(); i++) {
		for (int j = 0; j < m_date_plus_tot[i].size(); j++) {
			m_marge_libre[i][j] = m_date_plus_tard[i][j] - m_date_plus_tot[i][j];
		}
	}
}

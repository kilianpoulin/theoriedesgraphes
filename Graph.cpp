#include "Graph.h"
#include <iostream>
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

void Graph::setMatriceAdjacence(vector <Arcs> arcs) {
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
	for (int i = 0; i < m_nbArcs; i++) {
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
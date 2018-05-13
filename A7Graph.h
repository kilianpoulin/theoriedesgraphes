#pragma once
#define A7GRAPH_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "A7Arcs.h"

using namespace std;

class Graph
{
public:
	Graph();
	virtual ~Graph();
	void setNbSommets(int val);
	void setNbArcs(int val);
	int getNbSommets();
	int getNbArcs();
	int getNbEntrees();
	int getNbSorties();
	void setArcs(std::vector <Arcs> arcs);
	void show_graph();

	// enregistrement du nom du fichier (pour nommer le fichier trace)
	void setFileName(string name);

	// enregistrement des durées et contraintes (niveau 3, 4)
	void setDurees(std::vector<int> durees);
	void setContraintes(std::vector<vector<int>> contraintes);

	// matrice d'adjacence
	void setMatriceAdjacence();
	void contrainteSetMatriceAdjacence();
	void showMatriceAdjacence();

	// matrice de valeurs
	void setMatriceValeurs();
	void contrainteSetMatriceValeurs();
	void showMatriceValeurs();
	
	// Enregistrement + retour des entrées et sorties
	void contrainteSetEntrees();
	void contrainteSetSorties();
	void getSorties();


	void calcDurees();	// dans le cas d'un graph construit sans contraintes

	// Vérifications
	bool verifMaxUneEntree();
	bool verifMaxUneSortie();
	bool verifAccessibleDepuisEntree();
	void getNextSommet(int sommet, int j);
	bool verifAccessibleDepuisSortie();
	void getNextSommetSortie(int sommet, int j);
	bool verifValeursArcs();
	bool verifMemeSommetMemeValeur();
	bool showVerifications();


	// détection de circuits
	bool elimination(bool comments); // le booléen comments permet d'afficher ou non des commentaires
	bool circuitDetection(bool comments);
	bool MatrAdjEqualstoZero();
	void showAntecedents();
	void initializeAdjacenceTmp();
	bool showEliminations(int rang, int sommet);
	void showEliminate();
	bool AdjacenceTmpEqualstoZero();

	// calcul du rang
	bool detectionRang(bool comments);
	void showRang();

	// calcul des calendriers et marges
	int getMaxDureeAntecedent(int sommet);
	void showCalendrier();
		// création des états alpha et omega (1 entrée, 1 sortie)
	void createAlpha();
	void createOmega();
		// date au plus tôt
	void initializeDatePlusTot();
	void calcDatePlusTot();
		// date au plus tard
	void initializeDatePlusTard(float retard);
	void calcDatePlusTard(float retard);
		// marge totale
	void initializeMargeTotale(bool retard);
	void calcMargeTotale(bool retard);
		// marge libre
	void initializeMargeLibre();
	void calcMargeLibre();
	
	char erreur(std::string tmp);
	// fonctions d'affichage
	std::string create_line(int size, int max_size);
	std::string create_space(int size);

	// résolution de problèmes de contraintes (niveau 4)
	std::vector<int> getProblem(std::vector<int>pb_contr);
	void solveProblem(int sommet, std::vector<int> hist_contr);
	void showProblem();
	void deleteArcs();

	std::vector<vector<int>>m_contraintes;
	std::vector<int> m_durees;

protected:
private:
	int m_nbSommets;
	int m_nbArcs;
	int m_nbEntrees;
	int m_nbSorties;
	int m_pointEntree;
	int m_pointSortie;
	std::string  m_fileName; // nom du fichier ouvert
	// contient tous les arcs du graphe (départ, arrivée, durée)
	std::vector <Arcs> m_arcs;

	// matrice d'adjacence
	std::vector< vector<bool> > m_matriceAdjacence;	
	std::vector<vector<bool>> m_adj2;	//Copie de la Matrice d'adjacence sur laquelle on va appliquer la détéction de circuit par suppression d'état

	// matrice de valeurs
	std::vector<vector<string>> m_matriceValeurs;

	std::vector<int> m_tmp;	//vector qui stock le nombre d'états entrant dans un état i (i, index du vector)
	
	// liste des entrées et sorties du graphe
	std::vector<int> m_entrees;
	std::vector<int> m_sorties;

	// détection de circuit
	std::vector<vector<int>>m_eliminations; // contient la liste chronologique des éliminations
	bool m_circuit; // vrai si le graphe possède un circuit, faux sinon

	// contient tous les rangs et leurs sommets
	std::vector<vector<int>> m_rang;
	int m_tmp_rang = 1; // contiendra la valeur du rang le plus grand

	// claendriers et marges	
	std::vector<vector<int>>m_date_plus_tot;
	std::vector<vector<int>>m_date_plus_tard;
	std::vector<vector<float>>m_date_plus_tard2; // pour les 110% de la date au plus tot
	std::vector<vector<int>>m_marge_totale;
	std::vector<vector<float>>m_marge_totale2; // avec les 110% de la date au plus tot
	std::vector<vector<int>>m_marge_libre;
	int m_var = 0;
	int m_var_tmp = 0;
	int m_duree = 0;
	
	std::vector<vector<bool>>m_matriceAdjacence2;
	
	std::vector<int>m_list_sommets;

};

// A7GRAPH_H

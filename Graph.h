#pragma once
#define GRAPH_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Arcs.h"

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
	void setMatriceAdjacence();
	void showMatriceAdjacence();
	void contrainteSetMatriceAdjacence();
	void contrainteshowMatriceAdjacence();
	void contrainteSetMatriceIncidence();
    void setMatriceIncidence();
    void showMatriceIncidence();
	bool verifMaxUneEntree();
	bool verifMaxUneSortie();
	bool verifAccessibleDepuisEntree();
	bool verifAccessibleDepuisSortie();
	bool verifValeursArcs();
	bool verifMemeSommetMemeValeur();
	bool elimination();
	bool detectionRang();
	bool circuitDetection();
	bool MatrAdjEqualstoZero();
	void showRang();
	int getMaxDureeAntecedent(int sommet);
	void showCalendrier();
	void calcDatePlusTot();
	void initializeDatePlusTot();
	void calcDatePlusTard();
	void initializeDatePlusTard();
	void calcMargeTotale();
	void initializeMargeTotale();
	void initializeMargeLibre();
	void calcMargeLibre();
	bool showVerifications();
	char erreur(std::string tmp);
	std::string create_line(int size, int max_size);
	std::string create_space(int size);
	void showAntecedents();
	void initializeAdjacenceTmp();
	bool showEliminations(int rang, int sommet);
	void showEliminate();
	bool AdjacenceTmpEqualstoZero();
	void contrainteSetEntrees();
	void contrainteSetSorties();
	void getSorties();
	void createAlpha();
	void createOmega();
	void setDurees(std::vector<int> durees);
	void setContraintes(std::vector<vector<int>> contraintes);
	void showProblem();
	std::vector<int> getProblem(std::vector<int>pb_contr);
	void solveProblem(int sommet, std::vector<int> hist_contr);
	void deleteArcs();
	void setFileName(string name);


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
	std::vector <Arcs> m_arcs;
	std::vector< vector<bool> > m_matriceAdjacence;
    std::vector< vector<int> > m_matriceIncidence;
	std::vector<vector<bool>> m_adj2;	//Copie de la Matrice d'adjacence sur laquelle on va appliquer la détéction de circuit par suppression d'état
	std::vector<int> m_tmp;	//vector qui stock le nombre d'états entrant dans un état i (i, index du vector)
	std::vector<vector<int>> m_rang;
	bool m_circuit;
	std::vector<int> m_entrees;
	std::vector<int> m_sorties;
	int m_tmp_rang = 1;
	std::vector<vector<int>>m_date_plus_tot;
	std::vector<vector<int>>m_date_plus_tard;
	std::vector<vector<int>>m_marge_totale;
	std::vector<vector<int>>m_marge_libre;
	int m_var = 0;
	int m_var_tmp = 0;
	int m_duree = 0;
	std::vector<vector<int>>m_eliminations;
	std::vector<vector<bool>>m_matriceAdjacence2;
	std::string  m_fileName;

};

// GRAPH_H

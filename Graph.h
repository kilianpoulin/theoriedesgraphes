#define GRAPH_H

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
	std::vector <Arcs> m_arcs;
	void setMatriceAdjacence(std::vector <Arcs> arcs);
	void showMatriceAdjacence();
	bool verifMaxUneEntree();
	bool verifMaxUneSortie();
	bool verifAccessibleDepuisEntree();
	bool verifAccessibleDepuisSortie();

protected:

private:
	int m_nbSommets;
	int m_nbArcs;
	int m_nbEntrees;
	int m_nbSorties;
	int m_pointEntree;
	int m_pointSortie;
	std::vector< vector<bool> > m_matriceAdjacence;

};

// GRAPH_H

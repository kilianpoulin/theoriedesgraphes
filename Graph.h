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
	void setArcs(std::vector <Arcs> arcs);
	std::vector <Arcs> m_arcs;
	void setMatriceAdjacence(std::vector <Arcs> arcs);
	void showMatriceAdjacence();

protected:

private:
	int m_nbSommets;
	int m_nbArcs;
	std::vector< vector<bool> > m_matriceAdjacence;

};

// GRAPH_H

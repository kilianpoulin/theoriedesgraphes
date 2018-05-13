#include <iostream>
#include <fstream>
#include "A7Graph.h"
#include "A7Arcs.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Contraintes
{
public:
	Contraintes();
	~Contraintes();
	
	Graph create_graph();
	Graph regenerate_graph(Graph graph);
};




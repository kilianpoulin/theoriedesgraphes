#include "A7Arcs.h"

Arcs::Arcs()
{
	//ctor
}


void Arcs::setStart(int val) {
	m_start = val;
}

void Arcs::setDuree(int val) {
	m_duree = val;
}

void Arcs::setFinish(int val) {
	m_finish = val;
}

int Arcs::getStart() {
	return m_start;
}

int Arcs::getDuree() {
	return m_duree;
}

int Arcs::getFinish() {
	return m_finish;
}

Arcs::~Arcs()
{
	//dtor
}



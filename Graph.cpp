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
	for (int i = 0; i < m_nbArcs; i++)
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

void Graph::contrainteSetMatriceAdjacence() {
	for (int i = 0; i < m_nbSommets + 1; i++) {
		m_matriceAdjacence.push_back(vector<bool>(m_nbSommets + 1, false));
	}

	for (int i = 0; i < m_nbArcs; i++) {
		m_matriceAdjacence[m_arcs[i].getStart()][m_arcs[i].getFinish()] = true;
	}
}


void Graph::contrainteshowMatriceAdjacence() {
	cout << '\t';
	for (int i = 1; i < m_nbSommets + 1; i++) {
		cout << '\t' << i;
	}
	cout << endl;
	cout << '\t';
	for (int i = 1; i < (m_nbSommets + 1) * 8; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 1; i < (m_nbSommets + 1); i++) {
		cout << '\t' << i << "  |";
		for (int j = 0; j < m_nbSommets; j++) {
			cout << '\t' << m_matriceAdjacence[i][j];
		}
		cout << endl;
	}

}

void Graph::setMatriceIncidence() {
	/**
	* Generate the incidence matrix with the transition arcs.
	*/
	for (int i = 0; i < m_nbSommets; i++) {
		m_matriceIncidence.push_back(vector<int>(m_nbArcs, false));
	}
	for (int j = 0; j < m_nbSommets; j++) {
		for (int i = 0; i < m_nbArcs; i++) {
			if (m_arcs[i].getFinish() == j)
				m_matriceIncidence[j][i] = -1;
		}
	}
	for (int j = 0; j < m_nbSommets; j++) {
		for (int i = 0; i < m_nbArcs; i++) {
			if (m_arcs[i].getStart() == j)
				m_matriceIncidence[j][i] = 1;
		}
	}
}



void Graph::showMatriceAdjacence() {
	cout << '\t';
	for (int i = 0; i < m_nbSommets; i++) {
		cout << '\t' << i;
	}
	cout << endl;
	cout << '\t';
	for (int i = 0; i < m_nbSommets * 8; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < m_nbSommets; i++) {
		cout << '\t' << i << "  |";
		for (int j = 0; j < m_nbSommets; j++) {
			cout << '\t' << m_matriceAdjacence[i][j];
		}
		cout << endl;
	}

}

void Graph::showMatriceIncidence() {
	cout << '\t';
	for (int i = 0; i < m_nbArcs; i++) {
		cout << '\t' << i;
	}
	cout << endl;
	cout << '\t';
	for (int i = 0; i < m_nbArcs * 8; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < m_nbSommets; i++) {
		cout << '\t' << i << "  |";
		for (int j = 0; j < m_nbArcs; j++) {
			cout << '\t' << m_matriceIncidence[i][j];
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
	cout << '\t' << "Rang" << '\t' << '|' << "   Sommets" << endl;
	cout << '\t' << "------------------------" << endl;
	for (int i = 0; i < m_tmp_rang - 1; i++) {
		cout << '\t' << i + 1 << '\t' << '|' << '\t';
		for (int j = 0; j < m_rang[i].size() - 1; j++) {
			cout << m_rang[i][j];
			if (j != m_rang[i].size() - 2)
				cout << ", ";
		}
		cout << '\t' << '|' << endl;
		cout << '\t' << "------------------------" << endl;
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
		cout << '\t' << "RESULTAT  ==> " << "Ce graphe contient un ou plusieurs circuits" << endl;
	}
	else
	{
		cout << '\t' << "RESULTAT  ==> " << "Ce graphe ne contient pas de circuits" << endl;
	}
}

bool Graph::detectionRang()
{
	int nbetats = 1;
	if (m_entrees.size() == 0) { // il n'y a pas d'entrées donc circuit
		cout << '\t' << "ERREUR --> le graph n'a pas d'entree" << endl;
		return true;
	}

	cout << '\t' << "Elimination au rang 1 : " << endl;
	m_rang.push_back(vector<int>(m_entrees.size() + 1, NULL)); // on connait le nombre d'états dans le rang
	m_eliminations.push_back(vector<int>(0, 0));
	for (int i = 0; i < m_entrees.size(); i++) { // on traite d'abord les entrées
												 // on les met au rang 1
		m_rang[0][i] = m_entrees[i];
		cout << '\t' << '\t' << "sommet : " << m_entrees[i] << endl;
		m_eliminations[0].push_back(m_entrees[i]);
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
	bool change = false;
	do {
		m_eliminations.push_back(vector<int>(0, 0));
		cout << '\t' << "________________________" << endl;
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
		if(tmp_etat.size() != 0)
			cout << '\t' << "Elimination au rang " << m_tmp_rang + 1 << " : "<< endl;
		for (int n = 0; n < tmp_etat.size(); n++) {
			m_rang[m_tmp_rang][n] = tmp_etat[n];
			cout << '\t' << '\t' << "sommet : " << m_rang[m_tmp_rang][n] << endl;
			m_eliminations[m_tmp_rang].push_back(m_rang[m_tmp_rang][n]);
			change = true;
		}
		m_tmp_rang++; // on passe au calcul du rang suivants
		if (change == false)
			m_eliminations.pop_back();
		change = false;
		final_z = z;
	} while (final_z != 0);

	if (MatrAdjEqualstoZero())
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
	if (tmp == 0)
		return tmp + TardFinal(var_tmp, sommet, rang + 1);
	else
		return -1;

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

char Graph::erreur(string tmp) {
	if (tmp == "Oui")
		return 'O';
	else
		return 'X';
}

string Graph::create_line(int size, int max_size) {
	string line = "";
	max_size += 9; // on inclut la tabulation
	for (int i = 0; i < size; i++) {
		if (i == 0 || i == max_size || i == (max_size + 16) || i == (max_size + 32))
			line += "+";
		else
			line += "-";
	}
	return line;
}

string Graph::create_space(int size) {
	string space = " ";
	for (int i = 0; i < size; i++) {
		space += " ";
	}
	return space;
}

bool Graph::showVerifications() {
	string tmp = "";
	bool result = true;
	int max_size = 0;
	cout << '\t' << "Verifications " << endl;
	cout << endl;

	string conditions[10];
	conditions[0] = "Le graphe ne possede qu'une seule entree (max)";
	conditions[1] = "Le graphe ne possede qu'une seule sortie (max)";
	conditions[2] = "Tous les sommets sont accessibles depuis le point d'entree";
	conditions[3] = "Le point de sortie est accessible depuis tous les autres sommets";
	conditions[4] = "Les valeurs des arcs sont positives ou nulles";
	conditions[5] = "Tous les arcs sortant d'un meme sommet ont une meme valeur";

	for (int i = 0; i < 6; i++) {
		if (conditions[i].length() > max_size)
			max_size = conditions[i].length();
	}

	cout << '\t' << create_space((max_size - 4) / 2) << "Condition" << create_space((max_size - 4) / 2) << "\t" <<
		" | " << create_space(2) << "Resultat" << create_space(2) << "|"
		<< create_space(1) << "Continuer ?" << create_space(1) << "| " << endl;


	cout << '\t' << create_line(max_size + 5 * 8 + 2, max_size) << endl;

	if (verifMaxUneEntree())
		tmp = "Oui";
	else {
		tmp = "Non";
		result = false;
	}
	cout << '\t' << conditions[0] << create_space(max_size - conditions[0].length()) << '\t'
		<< " | " << '\t' << tmp << '\t'
		<< " | " << create_space(5) << erreur(tmp) << create_space(5) << " |" << endl;

	cout << '\t' << create_line(max_size + 5 * 8 + 2, max_size) << endl;

	if (verifMaxUneSortie())
		tmp = "Oui";
	else {
		tmp = "Non";
		result = false;
	}

	cout << '\t' << conditions[1] << create_space(max_size - conditions[1].length()) << '\t'
		<< " | " << '\t' << tmp << '\t'
		<< " | " << create_space(5) << erreur(tmp) << create_space(5) << " |" << endl;

	cout << '\t' << create_line(max_size + 5 * 8 + 2, max_size) << endl;

	if (verifAccessibleDepuisEntree())
		tmp = "Oui";
	else {
		tmp = "Non";
		result = false;
	}
	cout << '\t' << conditions[2] << create_space(max_size - conditions[2].length()) << '\t'
		<< " | " << '\t' << tmp << '\t'
		<< " | " << create_space(5) << erreur(tmp) << create_space(5) << " |" << endl;

	cout << '\t' << create_line(max_size + 5 * 8 + 2, max_size) << endl;

	if (verifAccessibleDepuisSortie())
		tmp = "Oui";
	else {
		tmp = "Non";
		result = false;
	}

	cout << '\t' << conditions[3] << create_space(max_size - conditions[3].length()) << '\t'
		<< " | " << '\t' << tmp << '\t'
		<< " | " << create_space(5) << erreur(tmp) << create_space(5) << " |" << endl;

	cout << '\t' << create_line(max_size + 5 * 8 + 2, max_size) << endl;

	if (verifValeursArcs())
		tmp = "Oui";
	else {
		tmp = "Non";
		result = false;
	}

	cout << '\t' << conditions[4] << create_space(max_size - conditions[4].length()) << '\t'
		<< " | " << '\t' << tmp << '\t'
		<< " | " << create_space(5) << erreur(tmp) << create_space(5) << " |" << endl;

	cout << '\t' << create_line(max_size + 5 * 8 + 2, max_size) << endl;

	if (verifMemeSommetMemeValeur())
		tmp = "Oui";
	else {
		tmp = "Non";
		result = false;
	}
	cout << '\t' << conditions[5] << create_space(max_size - conditions[5].length()) << '\t'
		<< " | " << '\t' << tmp << '\t'
		<< " | " << create_space(5) << erreur(tmp) << create_space(5) << " |" << endl;

	cout << '\t' << create_line(max_size + 5 * 8 + 2, max_size) << endl;

	cout << endl;

	return result;

}

void Graph::showAntecedents() {
	initializeAdjacenceTmp();
	int z = 0;
	int size;
	int size_left;
	int size_right;
	int def = 4;
	vector<int> tmp;
	cout << '\t' << "Sommet" << '\t' << '\t' << "T-1" << endl;
	cout << '\t';
	for (int i = 0; i < (m_eliminations.size() * 10); i++) {
		cout << '-';
	}
	cout << endl;

	for (int i = 0; i < m_matriceAdjacence.size(); i++) {
		cout << '\t' << i << '\t' << "|" << '\t';
		for (int j = 0; j < m_matriceAdjacence[i].size(); j++) { // l'état initial
			if (m_matriceAdjacence[j][i] == 1) {
				cout << j;
			}
		}
		cout << '\t';
		while (showEliminations(z, i) == true) {
			for (int j = 0; j < m_matriceAdjacence2[i].size(); j++) {
				if (m_matriceAdjacence2[j][i] == true) {
					tmp.push_back(j);
				}
			}
			size = tmp.size() / 2;
			if (size % 2 == 1) {
				size_left = trunc(size);
				size_right = trunc(size - 1);
			}
			else {
				size_left = size;
				size_right = size;
			}
			if (tmp.size() == 0)
				size_right = -1;
			cout << "|" << create_space(def - size_left);
			for (int k = 0; k < tmp.size(); k++) {
				cout << tmp[k];
			}
			cout << create_space(def - size_right);
			tmp.clear();
			z++;
			def = 4;
		}
		cout << endl;
		z = 0;
	}
}

void Graph::showEliminate() {
	for (int i = 0; i < m_eliminations.size(); i++) {
		cout << i << '\t';
		for (int j = 0; j < m_eliminations[i].size(); j++) {
			cout << m_eliminations[i][j] << '\t';
		}
		cout << endl;
	}
}

bool Graph::showEliminations(int rang, int sommet) {
	if (rang < m_eliminations.size()) {
		for (int i = 0; i < m_matriceAdjacence2.size(); i++) {
			for (int z = 0; z < m_eliminations[rang].size(); z++) { // l'état initial
				if (m_matriceAdjacence2[i][sommet] == true && i == m_eliminations[rang][z]) {
					m_matriceAdjacence2[i][sommet] = false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}

}

void Graph::initializeAdjacenceTmp() {
	for (int i = 0; i < m_matriceAdjacence.size(); i++) {
		m_matriceAdjacence2.push_back(vector<bool>(m_matriceAdjacence[i].size(), false));
		for (int j = 0; j < m_matriceAdjacence[i].size(); j++) {
			m_matriceAdjacence2 = m_matriceAdjacence;
		}
	}
}

bool Graph::AdjacenceTmpEqualstoZero() {
	for (int i = 0; i < m_matriceAdjacence2.size(); i++) {
		for (int j = 0; j < m_matriceAdjacence2[i].size(); j++) {
			if (m_matriceAdjacence2[i][j] == true)
				return false;
		}
	}
	return true;
}

void Graph::contrainteSetEntrees() {
	int tmp = 0;
	for (int i = 1; i < m_nbSommets + 1; i++) {
		tmp = 0;
		for (int j = 1; j < m_nbSommets + 1; j++) {
			if (m_matriceAdjacence[j][i] == 1)
			{
				tmp += 1;
			}
		}
		if (tmp == 0) // il n'y a pas prédécesseurs
			m_entrees.push_back(i);
	}
}

void Graph::contrainteSetSorties() {
	int tmp = 0;
	for (int i = 1; i < m_nbSommets + 1; i++) {
		tmp = 0;
		for (int j = 1; j < m_nbSommets + 1; j++) {
			if (m_matriceAdjacence[i][j] == 1)
			{
				tmp += 1;
			}
		}
		if (tmp == 0) // il n'y a pas de successeurs
			m_sorties.push_back(i);
	}
}

void Graph::getSorties() {
	for (int i = 0; i < m_sorties.size(); i++) {
		cout << m_sorties[i] << endl;
	}
}

void Graph::createAlpha() {
	Arcs tmp_arc;
	int duree = 0;
	for (int i = 0; i < m_entrees.size(); i++) {
		tmp_arc.setStart(0);
		tmp_arc.setFinish(m_entrees[i]);
		tmp_arc.setDuree(0);
		m_arcs.push_back(tmp_arc);
		m_nbArcs++;
	}
}

void Graph::createOmega() {
	Arcs tmp_arc;
	for (int i = 0; i < m_entrees.size(); i++) {
		tmp_arc.setStart(m_sorties[i]);
		tmp_arc.setFinish(m_nbSommets + 1);
		tmp_arc.setDuree(m_durees[m_sorties[i]]);
		m_arcs.push_back(tmp_arc);
		m_nbArcs++;

	}
}

void Graph::setDurees(vector<int> durees) {
	for (int i = 0; i < durees.size(); i++) {
		m_durees.push_back(durees[i]);
	}
}









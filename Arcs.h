#ifndef ARCS_H
#define ARCS_H

using namespace std;

class Arcs
{
public:
	Arcs();
	virtual ~Arcs();
	void setStart(int val);
	void setDuree(int val);
	void setFinish(int val);
	int getDuree();
	int getStart();
	int getFinish();

protected:

private:
	int m_start;
	int m_duree;
	int m_finish;
};

#endif // ARCS_H
#pragma once

#define INVALID_INDEX -1

class BGGraphEdge
{
	BGGraphEdge(int from, int to, double cost = 1.0) : m_dCost(cost), m_iFrom(from), m_iTo(to) {}
	BGGraphEdge() : m_dCost(1.0), m_iFrom(INVALID_INDEX), m_iTo(INVALID_INDEX) {}

	virtual ~BGGraphEdge() {}

	int   From()const { return m_iFrom; }
	void  SetFrom(int NewIndex) { m_iFrom = NewIndex; }

	int   To()const { return m_iTo; }
	void  SetTo(int NewIndex) { m_iTo = NewIndex; }

	double Cost()const { return m_dCost; }
	void  SetCost(double NewCost) { m_dCost = NewCost; }

	bool operator==(const BGGraphEdge& rhs)
	{
		return rhs.m_iFrom == this->m_iFrom &&
			rhs.m_iTo == this->m_iTo   &&
			rhs.m_dCost == this->m_dCost;
	}

	bool operator!=(const BGGraphEdge& rhs)
	{
		return !(*this == rhs);
	}

protected:
	int m_iFrom;
	int m_iTo;
	double m_dCost;
};
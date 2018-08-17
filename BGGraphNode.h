#pragma once

#define INVALID_INDEX -1

struct Position
{
	int x, y;
};

class BGGraphNode
{
	
public:
	BGGraphNode() : m_Index(INVALID_INDEX) {}
	BGGraphNode(int idx) : m_Index(idx) {}
	virtual ~BGGraphNode() {}

	int Index() const { return m_Index; }
	int SetIndex(int idx) { m_Index = idx; }

protected:
	int m_Index;
};

class BGNavGraphNode : public BGGraphNode
{
public:
	BGNavGraphNode() {}
	BGNavGraphNode(int idx, Position pos) : BGGraphNode(idx), m_Position(pos) {}
	virtual ~BGNavGraphNode() {}

	Position GetPosition() const { return m_Position; }
	void SetPosition(Position pos) { m_Position = pos; }

protected:
	Position m_Position;
	
};
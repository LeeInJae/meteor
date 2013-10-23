#pragma once
class CGameObject
{
public:
	CGameObject(void);
	virtual ~CGameObject(void);

	bool Render();
	bool Update();

	bool SetPosition(int x, int y){
		m_X = x;
		m_Y = y;
	};
	bool Move(int x, int y){
		m_X += x;
		m_Y += y;
	};
	int GetX(){return m_X;};
	int GetY(){return m_Y;};

protected:
	int m_X;
	int m_Y;

};


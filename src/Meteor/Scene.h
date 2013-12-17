#pragma once

class CScene
{
public:
	virtual ~CScene(void) {}

	virtual bool Update( float deltaTime ) = 0;
	virtual void Render() = 0;
};
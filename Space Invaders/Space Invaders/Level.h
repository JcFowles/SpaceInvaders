/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : Level.h
* Description : Header file for the Level class
* Author :	Callan Moore
* Author :	Jc Fowles
* Mail :	Callan.moore@mediadesign.school.nz
* Mail :	JC.Fowles@mediadesign.school.nz
*/

#pragma once

#if !defined(__LEVEL_H__)
#define __LEVEL_H__

// Library Includes
#include <vector>
#include <string>
#include <locale>
#include <codecvt>

// Local Includes
#include "Game.h"
#include "Utilities.h"
#include "backbuffer.h"
#include "PlayerShip.h"
#include "PlayerProjectile.h"
#include "AlienColumn.h"

class CPlayerProjectile;
class CPlayerShip;
class CLevel
{
	// Member Functions
public:
	CLevel(void);
	~CLevel(void);
	virtual bool Initialise(int _iWidth, int _iHeight);
	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	CPlayerShip* GetPlayerShip() const;
	CPlayerProjectile* GetPlayerProjectile() const;

	bool ProjectileCollisionCheck();
	bool CLevel::AlienCollision();

	void UpdatePlayerScore(float _fScore);
	float GetPlayerScore();

	void DrawScore();

	void UpdateScoreText();
protected:
	//void ProcessCheckForWin();
	//void DrawScore();
	//void UpdateScoreText();

private:
	// Disallowing copies
	CLevel(const CLevel& _kr);
	CLevel& operator= (const CLevel& _kr);

	// Member Variables
private:
	int m_iWidth;
	int m_iHeight;

protected:
	float m_fTimeElapsed;
	float m_fLastMove;

	CPlayerShip* m_pPlayerShip;
	CPlayerProjectile* m_pProjectile;

	float m_fScore;
	 std::string m_strScore;

	vector<CAlienColumn*>* m_pAlienColumns;
	int m_iAlienSpeed;

};

#endif // __LEVEL_H__

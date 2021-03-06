/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : PlayerProjectile.h
* Description : Header file for the PlayerProjectile class
* Author :	Jc Fowles
* Mail :	JC.Fowles@mediadesign.school.nz
*/

#pragma once

#if !defined(__PLAYERPROJECTILE_H__)

#define __PLAYERPROJECTILE_H__
// Library Includes

// Local Includes
#include "entity.h"
#include "Sprite.h"
#include "resource.h"
#include "utilities.h"

// Types

// Constants

// Prototypes
class CPlayerProjectile : public CEntity
{
	// Member Functions
public:
	

	// Singleton Methods
	static CPlayerProjectile& GetInstance();
	static void DestroyInstance();
	
	virtual ~CPlayerProjectile(void);
	virtual bool Initialise();
	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	float GetSpeed();
	void SetSpeed(float _fSleep);

	void fly();

	bool Fired();
	void setFired(bool _bFired);
	
private:
	CPlayerProjectile(void);
	CPlayerProjectile(const CPlayerProjectile& _kr);
	CPlayerProjectile& operator= (const CPlayerProjectile& _kr);

	// Member Variables
protected:
	float m_fSpeed;
	bool m_bFired;

	float m_fTimeElapsed;
	float m_fLastMove;

	// Singleton Instance
	static CPlayerProjectile* s_pProjectile;


};

#endif //__PLAYERPROJECTILE_H__
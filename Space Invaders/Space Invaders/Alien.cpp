/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : Alien.cpp
* Description : Implementation file for the Alien class
* Author :	Callan Moore
* Mail :	Callan.moore@mediadesign.school.nz	
*/

// Local Includes
#include "resource.h"
#include "Utilities.h"

// This Includes
#include "Alien.h"

/***********************
* CAlien: Contructor for the Alien class
* @author: Callan Moore
********************/
CAlien::CAlien(void)
{
	m_bAlive = true;
}

/***********************
* ~CAlien: Destructor for the Alien class
* @author: Callan Moore
********************/
CAlien::~CAlien(void)
{
}

/***********************
* Initialise: Initialise the Alien using Entities Initialise with the its Sprite and Mask IDs
* @author: Callan Moore
* @parameter: _iType: Integer representing the type of Alien to initialise
* @return: bool: Always returns true
********************/
bool CAlien::Initialise(int _iType)
{
	switch(_iType)
	{
	case (1):
		{
			m_iMaskID = IDB_MASKA_ALIEN1;
			m_iSpriteID = IDB_SPRITEA_ALIEN1;
			m_iPointValue = 10;
		}
		break;
	case (2):
		{
			m_iMaskID = IDB_MASKA_ALIEN2;
			m_iSpriteID = IDB_SPRITEA_ALIEN2;
			m_iPointValue = 20;
		}
		break;
	case (3):
		{
			m_iMaskID = IDB_MASKA_ALIEN3;
			m_iSpriteID = IDB_SPRITEA_ALIEN3;
			m_iPointValue = 40;
		}
		break;
	default:	// Any other value creates Load Error Sprite
		{
			// m_iMaskID = IDB_MASK_LOADERROR;
			// m_iSpriteID = IDB_SPRITE_LOADERROR;
			// m_iPointValue = 0;
		}
	} // End Switch

	VALIDATE(CEntity::Initialise(m_iSpriteID, m_iMaskID));
	return (true);
}

/***********************
* Draw: Draws the Sprite using Entities Draw function only if the Alien is alive
* @author: Callan Moore
* @return: void
********************/
void CAlien::Draw()
{
	if (m_bAlive == true)
	{
		CEntity::Draw();
	}
}

/***********************
* Process: Process the changes to the Alien for the current delta tick if the Alien is alive
* @author: Callan Moore
* @parameter: _fDeltaTick: The time elapsed during the last frame
* @return: void
********************/
void CAlien::Process(float _fDeltaTick)
{
	if (m_bAlive == true)
	{
		CEntity::Process(_fDeltaTick);
	}
}

/***********************
* SetAlive: Sets the Aliens Alive state to the input state
* @author: Callan Moore
* @parameter: _bAlive: boolean value to set the state of the Alien (alive of dead)
* @return: void
********************/
void CAlien::SetAlive(bool _bAlive)
{
	m_bAlive = _bAlive;
}

/***********************
* IsAlive: Returns true or false dependent on whether the Alien is alive
* @author: Callan Moore
* @return: bool: Returns true if the Alien is alive
********************/
bool CAlien::IsAlive() const
{
	return m_bAlive;
}


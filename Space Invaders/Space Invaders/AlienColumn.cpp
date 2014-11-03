/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : AlienColumn.cpp
* Description : Implementation file for the AlienColumn class
* Author :	Callan Moore
* Mail :	Callan.moore@mediadesign.school.nz	
*/

// This Includes
#include "AlienColumn.h"

/***********************
* CAlienColumn: Contructor for the AlienColumn class
* @author: Callan Moore
********************/
CAlienColumn::CAlienColumn(void)
{
	m_vecpAliens = new vector<CAlien*>;
}

/***********************
* ~CAlienColumn: Destructor for the AlienColumn class
* @author: Callan Moore
********************/
CAlienColumn::~CAlienColumn(void)
{
	vector<CAlien*>::iterator iterAliens = m_vecpAliens->begin();
	vector<CAlien*>::iterator iterAliensEnd = m_vecpAliens->end();

	while( iterAliens != iterAliensEnd)
	{
		delete (*iterAliens);
		(*iterAliens) = 0;

		iterAliens++;
	}
	delete m_vecpAliens;
	m_vecpAliens = 0;
}

/***********************
* Initialise: Initialise the AlienColumn with all its member variables
* @author: Callan Moore
* @parameter: _fX: The X coordinate that the column starts at
* @parameter: _fY: The Y coordinate that the top of the column starts at
* @return: bool: Always returns true
********************/
bool CAlienColumn::Initialise(float _fX, float _fY)
{
	CAlien* pTempAlien;
	pTempAlien = new CAlien;
	VALIDATE(pTempAlien->Initialise(3));
	m_vecpAliens->push_back(pTempAlien);
	pTempAlien = new CAlien;
	VALIDATE(pTempAlien->Initialise(2));
	m_vecpAliens->push_back(pTempAlien);
	pTempAlien = new CAlien;
	VALIDATE(pTempAlien->Initialise(2));
	m_vecpAliens->push_back(pTempAlien);
	pTempAlien = new CAlien;
	VALIDATE(pTempAlien->Initialise(1));
	m_vecpAliens->push_back(pTempAlien);
	pTempAlien = new CAlien;
	VALIDATE(pTempAlien->Initialise(1));
	m_vecpAliens->push_back(pTempAlien);

	const int kiGap = 16;
	float fCurrentX = _fX;
	float fCurrentY = _fY;

	for( unsigned int i = 0; i < m_vecpAliens->size(); i++)
	{
		((*m_vecpAliens)[i])->SetX(fCurrentX);
		((*m_vecpAliens)[i])->SetY(fCurrentY);

		fCurrentY += (pTempAlien->GetHeight() + kiGap);
	}

	return (true);
}

/***********************
* Draw: Draws all the Aliens in the column
* @author: Callan Moore
* @author: JC Fowles
* @return: void
********************/
void CAlienColumn::Draw()
{
	for( unsigned int i = 0; i < m_vecpAliens->size(); i++)
	{
		((*m_vecpAliens)[i])->Draw();
	}
}

/***********************
* Process: Process the changes to the AlienColumn for the current delta tick
* @author: Callan Moore
* @parameter: _fDeltaTick: The time elapsed during the last frame
* @return: void
********************/
void CAlienColumn::Process(float _fDeltaTick)
{
	for( unsigned int i = 0; i < m_vecpAliens->size(); i++)
	{
		((*m_vecpAliens)[i])->Process(_fDeltaTick);
	}
}

/***********************
* GetAliens: Retrieves the Alien Columns of Aliens
* @author: Callan Moore
* @return: vector<CAlien*>* : Pointer to the AlienColumns Aliens
********************/
vector<CAlien*>* CAlienColumn::GetAliens()
{
	return m_vecpAliens;
}
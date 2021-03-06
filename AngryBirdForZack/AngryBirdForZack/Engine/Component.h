#pragma once

// Global Include
#include "Utility.h"

// Forward Declare
class CGameObject;

class CComponent
{
public:
	CComponent();
	virtual ~CComponent();

protected:

	CGameObject* m_owner;
	bool m_isActive;

// Membre Funciton
public:

	virtual void Awake() {}
	virtual void BeginPlay() {}
	virtual void OnDestroy() {}
	virtual void Update(float _tick) {}
	virtual void LateUpdate(float _tick) {}

	/**
	 * Getter and setter of the "owner" property of the component
	 */
	void SetOwner(CGameObject* _gameObject);
	CGameObject* GetOwner() const;

	/**
	 * Getter and setter of the "active" property of the component
	 */
	void SetActive(bool);
	bool IsActive() const;
};


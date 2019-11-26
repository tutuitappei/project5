#pragma once
#include "Obj.h"
class bullet :
	public Obj
{
public:
	bullet();
	bullet(UNIT_ID unitID, Vector2db pos);
	void Update(/*sharedOdj plObj*/) override;
	~bullet();
private:
	int Init();
	void destroy();
};


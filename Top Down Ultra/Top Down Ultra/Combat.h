#pragma once
class Combat
{
public:
	Combat(int healthPoints, int armorPoints, int shieldPoints) 
	{
		totalHealthPoints = currentHealthPoints = healthPoints;
		totalArmorPoints = currentArmorPoints = armorPoints;
		totalShieldPoints = currentShieldPoints = shieldPoints;
	};

protected:
	int totalHealthPoints;
	int totalArmorPoints;
	int totalShieldPoints;
	int currentHealthPoints;
	int currentArmorPoints;
	int currentShieldPoints;
};
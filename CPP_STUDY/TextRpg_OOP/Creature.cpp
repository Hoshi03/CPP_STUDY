#include "Creature.h"

void Creature::onattacked(Creature* attacker) //attacker �� �޴� �갡 ����
{
	int damage = attacker->_attack - _defence;
	if (damage < 0)
		damage = 0;

	_hp -= damage;
	if (_hp < 0)
		_hp = 0;
}

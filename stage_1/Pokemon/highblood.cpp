#include "highblood.h"

HighBlood::HighBlood(uint qualification,SKILL skillIndex)
{
    this->name="HIGH_BLOOD";
    this->kind=HIGH_BLOOD;
    this->skill=skillIndex;

    srand((unsigned)time(NULL));
    switch (qualification)//资质越高，属性越高
    {
        case R:
            this->setValues(qrand()%BASE+BASE,qrand()%BASE+MAINR,qrand()%BASE+BASE,qrand()%BASE+BASE);
            break;
        case SR:
            this->setValues(qrand()%MINORBASE+MINORSR,qrand()%BASE+MAINSR,qrand()%MINORBASE+MINORSR,qrand()%MINORBASE+MINORSR);
            break;
        case SSR:
            this->setValues(qrand()%MINORBASE+MINORSSR,qrand()%BASE+MAINSSR,qrand()%MINORBASE+MINORSSR,qrand()%MINORBASE+MINORSSR);
            break;
        default:
            break;
    }
}

uint HighBlood::Attack()
{
    qsrand (QTime::currentTime ().msec ());
    uint probability=qrand ()%10;
    if(probability<8)//普通攻击
        return NormalAttack;
    else             //20%几率使用技能
        return this->skill;
}

void HighBlood::LevelUP()
{
    this->level++;

    this->attack+=50;
    this->blood+=100;
    this->currentBlood=this->blood;//升级后当前的血量回复满血
    this->defense+=50;
    this->speed+=50;
}

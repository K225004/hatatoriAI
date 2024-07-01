#include "MaedaAI.h"

MaedaAI::MaedaAI(){

}

MaedaAI::~MaedaAI()
{
}

void MaedaAI::Update()
{
	player->Input(target);
}

void MaedaAI::Draw(){
	DrawFormatString(100,300,GetColor(100,100,0),"v2 x %f y %f ",V2Norm(V2Get(1, 2)).x, V2Norm(V2Get(1, 1)).y);
}



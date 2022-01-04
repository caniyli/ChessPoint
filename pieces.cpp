#include "pieces.h"

Pieces::Pieces()
{

}

float Pieces::getPoint()
{
	if(data.isMarked == true)
		return  data.point / 2;
	return data.point;
}



#include "kOctree.h"

kOctree::kOctree(Point _origin, float _hd) : originP(_origin), halfDimension(_hd)
{
	for (int i = 0; i < 8; i++) {
		children[i] == nullptr;
	}
	for (int i = 0; i < MAX_POINTS_NUM; i++) {
		data[0] == nullptr;
	}
}

kOctree::~kOctree()
{
}

int kOctree::getOctentIndex(const Point& p) const
{
	return 0;
}

bool kOctree::isLeafNode()
{
	return false;
}

void kOctree::insert(Point* p)
{
}

void kOctree::getPointsByBounding(Point bmin, Point bmax, std::vector<Point*>& result)
{
}

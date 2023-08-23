#include "kOctree.h"

kOctree::kOctree(Point _origin, float _hd) : originP(_origin), halfDimension(_hd)
{
	for (int i = 0; i < 8; i++) {
		children[i] == nullptr;
	}
}

kOctree::~kOctree()
{
	if (!isLeafNode()) 
	{
		delete[] children;
	}
}

int kOctree::getOctentIndex(const Point& p) const
{
	int index = 0;
	if (p.x > originP.x) index += 4;
	if (p.y > originP.y) index += 2;
	if (p.z > originP.z) index += 1;
	return index;
	return 0;
}

bool kOctree::isLeafNode()
{
	return children[0] = nullptr;
}

void kOctree::insert(Point* p)
{
	if (isLeafNode()) 
	{
		if(data.size() < MAX_POINTS_NUM) 
		{
			data.push_back(p);
			return;
		}
		else
		{
			std::vector<Point*> points = data;
			data.clear();
			points.push_back(p);

			for (int i = 0; i < 8; i++)
			{
				Point newOrigin;
				newOrigin.x = originP.x + (i & 4 ? +0.5f : -0.5f) * halfDimension;
				newOrigin.y = originP.y + (i & 2 ? +0.5f : -0.5f) * halfDimension;
				newOrigin.z = originP.z + (i & 1 ? +0.5f : -0.5f) * halfDimension;
				children[i] = new kOctree(newOrigin, 0.5f * halfDimension);
			}
			for (auto& p : points) 
			{
				children[getOctentIndex(*p)]->insert(p);
			}
		}
	}
	else
	{
		int index = getOctentIndex(*p);
		children[index]->insert(p);
	}
}

void kOctree::getPointsByBounding(Point bmin, Point bmax, std::vector<Point*>& result)
{

}

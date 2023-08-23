#include "iostream"
#include "kOctree.h"
#include <chrono>
#include <random>


bool isPointInBounding(Point* p, Point* bmin, Point* bmax) 
{
	return
		p->x >= bmin->x &&
		p->y >= bmin->y &&
		p->z >= bmin->z &&
		p->x <= bmax->x &&
		p->y <= bmax->y &&
		p->z <= bmax->z;
}

void testQuery(std::vector<Point*> points, Point* bmin, Point* bmax)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "Query run" << std::endl;
	std::vector<Point*> result;
	for (auto& p : points)
	{
		if (isPointInBounding(p, bmin, bmax))
		{
			result.push_back(p);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	double seconds = duration.count();

	std::cout << "testQuery found " << result.size() << " points in " << seconds << " s" << std::endl;
}

void testOctree(std::vector<Point*> points, Point* bmin, Point* bmax)
{
	kOctree tree = kOctree(Point(0, 0, 0), 10);
	for (auto& p : points)
	{
		tree.insert(p);
	}

	//std::cout << tree.getPointsNum(0) << std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "octree run" << std::endl;

	std::vector<Point*> result;
	tree.getPointsByBounding(bmin, bmax, result);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	double seconds = duration.count();
	std::cout << "testOctree found " << result.size() << " points in " << seconds << " s" << std::endl;
}

int main() 
{
	std::cout << "Hello KOctree!" << std::endl;
	
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_real_distribution<float> distribution(-10.0f, 10.0f); 

	std::vector<Point*> points;

	for (int i = 0; i < 10000000; ++i) {
		points.push_back(new Point(distribution(gen), distribution(gen), distribution(gen)));
	}

	Point* bmin = new Point(-2, -2, -2);
	Point* bmax = new Point(6, 6, 6);

	
	testOctree(points, bmin, bmax);
	testQuery(points, bmin, bmax);

	return 0;
}
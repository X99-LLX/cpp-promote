#include "iostream"
#include <vector>

static const int MAX_POINTS_NUM = 4;

struct Point {
    float x, y, z;
    Point() {}
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

class kOctree {
public:
    kOctree(Point _origin, float _hd);
    ~kOctree();

    int getOctentIndex(const Point& p) const;
    bool isLeafNode();
    void insert(Point* p);
    void getPointsByBounding(Point bmin, Point bmax, std::vector<Point*>& result);
private:
    Point originP;
    float halfDimension;

    kOctree* children[8];
    std::vector<Point*> data;
};


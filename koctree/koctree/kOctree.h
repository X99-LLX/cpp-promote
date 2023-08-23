#include "iostream"
#include <vector>

static const int MAX_POINTS_NUM = 4;

struct Point {
    float x, y, z;
    Point() 
    {
        x = y = z = 0;
    }
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Point& operator+(float l) 
    {
        Point temp = Point(x + l, y + l, z + l);
        return temp;
    }
    Point& operator-(float l)
    {
        Point temp = Point(x - l, y - l, z - l);
        return temp;
    }
};

class kOctree {
public:
    kOctree(Point _origin, float _hd);
    ~kOctree();

    int getOctentIndex(const Point& p) const;
    bool isLeafNode();
    void insert(Point* p);
    void getPointsByBounding(Point* bmin, Point* bmax, std::vector<Point*>& result);
    int getPointsNum(int result);
private:
    Point originP;
    float halfDimension;

    std::vector<kOctree*> children;
    std::vector<Point*> data;
};


class Circle
{
    int center_x, center_y, radius;

public:
    Circle(int x = 0, int y = 0, int r = 0);
    void getO(int &x, int &y) const { x = center_x; y = center_y; }
    int getR() const { return radius; }

    void move(int move_x, int move_y);
    void setR(int new_r);
};

Circle::Circle(int x, int y, int r)
    :center_x{ x }, center_y{ y }, radius{ r } { }

void Circle::move(int move_x, int move_y)
{
    center_x += move_x;
    center_y += move_y;
}

void Circle::setR(int new_r)
{
    if (new_r >= 0)
        radius = new_r;
}
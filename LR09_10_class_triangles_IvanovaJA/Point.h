#ifndef POINT_H
#define POINT_H
//���������� ������������ ��������� ORIENT
enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };
//����� Point ��������� �� ����� Triangle, ������ Triangle ������ ���� �������� �� Point
class Triangle;
//�������� ������ Point

class Point {
public:
    //����������� � ����� �����������
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}// x=_x; y=_y;
    Point operator +(Point&);//��������-������� ���������� ��������� ��������
    Point operator -(Point&);//��������-������� ���������� ��������� ���������
    //���������� ����� ������� ����� � �������� ������� ���������
    double Length() const;
    //���������� ��������� ����� ������������ �������, ��������� ����� �������
    ORIENT Classify(Point&, Point&) const;
    //����������, ��������� �� ����� ������ ������������

    bool InTriangle(Triangle&) const;//��������� ����� �������� - ������???????????????
    void Show() const;
    void operator +=(Point&);//��������-������� ���������� ��������� �������� � �������������
//public:
    double x, y;
};

#endif /*POINT_H*/
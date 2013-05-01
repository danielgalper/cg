#include <gtest/gtest.h>
#include <cg/operations/contains/triangle_point.h>

#include <cg/operations/contains/contour_point.h>

#include <cg/operations/contains/rectangle_point.h>
#include <cg/operations/contains/contour_point.h>
#include <initializer_list>
#include <vector>

using namespace cg;

// ---- START point in triangle --
TEST(triangle_test, t1)
{
    point_2 p1(0, 0), p2(2, 2), p3(4, 0);

    triangle_2 tr(p1, p2, p3);
    point_2 p(2, 1);
    EXPECT_EQ(contains(tr, p), true);
}

TEST(triangle_test, t2)
{
    point_2 p1(0, 0), p2(2, 2), p3(4, 0);

    triangle_2 tr(p1, p2, p3);
    point_2 p(0, 0);
    EXPECT_EQ(contains(tr, p), true);
}

TEST(triangle_test, t3)
{
    point_2 p1(0, 0), p2(2, 2), p3(4, 0);

    triangle_2 tr(p1, p2, p3);
    point_2 p(1, 0);
    EXPECT_EQ(contains(tr, p), true);
}

TEST(triangle_test, t4)
{
    point_2 p1(0, 0), p2(2, 2), p3(4, 0);

    triangle_2 tr(p1, p2, p3);
    point_2 p(0, 1);
    EXPECT_EQ(contains(tr, p), false);
}

TEST(triangle_test, t5)
{
    point_2 p1(0, 0), p2(2, 2), p3(4, 0);

    triangle_2 tr(p1, p2, p3);
    point_2 p(1, 1);
    EXPECT_EQ(contains(tr, p), true);
}

TEST(triangle_test, t6)
{
    point_2 p1(0, 0), p2(2, 2), p3(2, 0);

    triangle_2 tr(p1, p2, p3);
    point_2 p(1, 0.5);
    EXPECT_EQ(contains(tr, p), true);
}

TEST(triangle_test, t7)
{
    point_2 p1(0, 0), p2(0, 2), p3(2, 0);

    triangle_2 tr(p1, p2, p3);
    point_2 p(1, 1);
    EXPECT_EQ(contains(tr, p), true);
}
// ---- END point in triangle --

// -- START point in convex contour --
TEST(convex_contour_point, t1)
{
   contour_2 contour( {{2, 0}, {2, 2}, {0, 0}});
   point_2 p {1, 0.5};
   EXPECT_EQ(convex_contains(contour, p), true);
}

TEST(convex_contour_point, t2)
{
   contour_2 contour( {{2, 0}, {2, 2}, {0, 2}, {0, 0}});
   point_2 p {1, 1};
   EXPECT_EQ(convex_contains(contour, p), true);
}


TEST(convex_contour_point, t3)
{
   contour_2 contour( {{2, 0}, {2, 2}, {0, 2}, {0, 0}});
   point_2 p {-1, 1};
   EXPECT_EQ(convex_contains(contour, p), false);
}

TEST(convex_contour_point, t4)
{
   contour_2 contour( {{2, 0}, {4, 1}, {5, 3}, {4, 5}, {2, 4}, {0, 2}, {0, 0}});
   point_2 p {4, 4};
   EXPECT_EQ(convex_contains(contour, p), true);
}

TEST(convex_contour_point, t5)
{
   contour_2 contour( {{2, 0}, {4, 1}, {5, 3}, {4, 5}, {2, 4}, {0, 2}, {0, 0}});
   point_2 p {1, 3};
   EXPECT_EQ(convex_contains(contour, p), true);
}

TEST(convex_contour_point, t6)
{
   contour_2 contour( {{2, 0}, {4, 1}, {5, 3}, {4, 5}, {2, 4}, {0, 2}, {0, 0}});
   point_2 p {1, 4};
   EXPECT_EQ(convex_contains(contour, p), false);
}

TEST(convex_contour_point, t7)
{
   contour_2 contour( {{2, 0}, {0, 2}, {0, 0}});
   point_2 p {1, 0};
   EXPECT_EQ(convex_contains(contour, p), true);
}

TEST(convex_contour_point, t8)
{
   contour_2 contour( {{2, 0}, {0, 2}, {0, 0}});
   point_2 p {0, 1};
   EXPECT_EQ(convex_contains(contour, p), true);
}
// -- END point in convex contour --

// -- START point in arbitrary contour --
TEST(contour_point, t1)
{
   contour_2 contour( {{0, 0}, {2, 2}, {2, 0}});
   point_2 p {1, 0.5};
   EXPECT_EQ(contains(contour, p), true);
}


TEST(contour_point, t2)
{
   contour_2 contour( {{0, 0}, {0, 2}, {2, 2}, {2, 0}});
   point_2 p {1, 1};
   EXPECT_EQ(contains(contour, p), true);
}


TEST(contour_point, t3)
{
   contour_2 contour( {{0, 0}, {0, 2}, {2, 2}, {2, 0}});
   point_2 p {-1, 1};
   EXPECT_EQ(contains(contour, p), false);
}

TEST(contour_point, t4)
{
   contour_2 contour( {{0, 0}, {0, 2}, {2, 4}, {4, 5}, {5, 3}, {4, 1}, {2, 0}});
   point_2 p {4, 4};
   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t5)
{
   contour_2 contour( {{0, 0}, {0, 2}, {2, 4}, {4, 5}, {5, 3}, {4, 1}, {2, 0}});
   point_2 p {1, 3};
   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t6)
{
   contour_2 contour( {{0, 0}, {0, 2}, {2, 4}, {4, 5}, {5, 3}, {4, 1}, {2, 0}});
   point_2 p {1, 4};
   EXPECT_EQ(contains(contour, p), false);
}

TEST(contour_point, t7)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {1, 0};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t8)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {3, 0};

   EXPECT_EQ(contains(contour, p), false);
}

TEST(contour_point, t9)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {0, 0};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t10)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {5, 1};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t11)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {3, 1};

   EXPECT_EQ(contains(contour, p), false);
}


TEST(contour_point, t12)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {0, 1};

   EXPECT_EQ(contains(contour, p), false);
}

TEST(contour_point, t13)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {7, 3};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t14)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {7, 2};

   EXPECT_EQ(contains(contour, p), false);
}

TEST(contour_point, t15)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {7.00001, 3};

   EXPECT_EQ(contains(contour, p), false);
}

TEST(contour_point, t16)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {3, 2};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t17)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {3.00001, 2};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t18)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 3}});
   point_2 p {2.9999, 2};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t19)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 4}});
   point_2 p {3, 4};

   EXPECT_EQ(contains(contour, p), true);
}

TEST(contour_point, t20)
{
   contour_2 contour( {{0, 0}, {2, 0}, {3, 2}, {4, 0}, {6, 0}, {7, 3}, {3, 4}});
   point_2 p {3.00001, 4};

   EXPECT_EQ(contains(contour, p), false);
}


TEST(contains, non_convex_contour_point_test1)
{
   std::vector<cg::point_2> v;
   v.push_back(cg::point_2(0, 0));
   v.push_back(cg::point_2(10, 0));
   v.push_back(cg::point_2(10, 10));
   cg::point_2 p2(3, 3);
   cg::contour_2 tr(v);
   EXPECT_EQ(contains(tr, p2), true);
}

TEST(contains, non_convex_contour_point_test2)
{
   std::vector<cg::point_2> v;
   v.push_back(cg::point_2(2, 3));
   v.push_back(cg::point_2(2, 2));
   v.push_back(cg::point_2(3, 1));
   v.push_back(cg::point_2(5, 1));
   v.push_back(cg::point_2(8, 4));
   v.push_back(cg::point_2(6, 6));
   v.push_back(cg::point_2(4, 6));
   v.push_back(cg::point_2(3, 5));
   cg::contour_2 tr(v);
   EXPECT_EQ(contains(tr, cg::point_2(2, 2)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3, 1)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3, 2)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3, 5)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3, 6)), false);
   EXPECT_EQ(contains(tr, cg::point_2(5, 1)), true);
   EXPECT_EQ(contains(tr, cg::point_2(5, 2)), true);
   EXPECT_EQ(contains(tr, cg::point_2(8, 4)), true);
   EXPECT_EQ(contains(tr, cg::point_2(8, 3)), false);
   EXPECT_EQ(contains(tr, cg::point_2(8, 5)), false);
   EXPECT_EQ(contains(tr, cg::point_2(6, 7)), false);
   EXPECT_EQ(contains(tr, cg::point_2(2.5, 3.5)), true);
}


TEST(contains, non_convex_contour_point_test3)
{
   std::vector<cg::point_2> v;
   v.push_back(cg::point_2(1, 0));
   v.push_back(cg::point_2(2, -2));
   v.push_back(cg::point_2(3, 0));
   v.push_back(cg::point_2(4, -2));
   v.push_back(cg::point_2(5, 1));
   v.push_back(cg::point_2(6, -1));
   v.push_back(cg::point_2(7, 0));
   v.push_back(cg::point_2(7, 1));
   v.push_back(cg::point_2(5, 2));
   v.push_back(cg::point_2(4, 0));
   v.push_back(cg::point_2(2, 2));
   cg::contour_2 tr(v);
   EXPECT_EQ(contains(tr, cg::point_2(1, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(2, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(4, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(5, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(6, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(7, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(8, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(0, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(1, 1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(2, 1)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3.5, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(4, 1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(5, -1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(4, -0.5)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3.5, 0.001)), true);
}

TEST(contains, non_convex_contour_point_test4)
{
   std::vector<cg::point_2> v;
   v.push_back(cg::point_2(6, -1));
   v.push_back(cg::point_2(7, 0));
   v.push_back(cg::point_2(7, 1));
   v.push_back(cg::point_2(5, 2));
   v.push_back(cg::point_2(4, 0));
   v.push_back(cg::point_2(2, 2));
   v.push_back(cg::point_2(1, 0));
   v.push_back(cg::point_2(2, -2));
   v.push_back(cg::point_2(3, 0));
   v.push_back(cg::point_2(4, -2));
   v.push_back(cg::point_2(5, 1));   
   cg::contour_2 tr(v);
   EXPECT_EQ(contains(tr, cg::point_2(1, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(2, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(4, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(5, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(6, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(7, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(8, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(0, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(1, 1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(2, 1)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3.5, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(4, 1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(5, -1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(4, -0.5)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3.5, 0.001)), true);
}

TEST(contains, non_convex_contour_point_test5)
{
   std::vector<cg::point_2> v;
   v.push_back(cg::point_2(1, 0));
   v.push_back(cg::point_2(2, -2));
   v.push_back(cg::point_2(3, 0));
   v.push_back(cg::point_2(4, -2));
   v.push_back(cg::point_2(5, 1));
   v.push_back(cg::point_2(6, -1));
   v.push_back(cg::point_2(7, 0));

   v.push_back(cg::point_2(9, 0));
   v.push_back(cg::point_2(10, -2));
   v.push_back(cg::point_2(11, 0));
   v.push_back(cg::point_2(13, 0));
   v.push_back(cg::point_2(14, 1));
   v.push_back(cg::point_2(15, 0));
   v.push_back(cg::point_2(15, 3));

   v.push_back(cg::point_2(7, 1));
   v.push_back(cg::point_2(5, 2));
   v.push_back(cg::point_2(4, 0));
   v.push_back(cg::point_2(2, 2));
   cg::contour_2 tr(v);
   EXPECT_EQ(contains(tr, cg::point_2(1, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(2, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(4, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(5, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(6, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(7, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(8, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(9, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(10, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(11, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(12, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(13, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(14, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(15, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(16, 0)), false);

   EXPECT_EQ(contains(tr, cg::point_2(0, 0)), false);
   EXPECT_EQ(contains(tr, cg::point_2(1, 1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(2, 1)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3.5, 0)), true);
   EXPECT_EQ(contains(tr, cg::point_2(4, 1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(5, -1)), false);
   EXPECT_EQ(contains(tr, cg::point_2(4, -0.5)), true);
   EXPECT_EQ(contains(tr, cg::point_2(3.5, 0.001)), true);
}


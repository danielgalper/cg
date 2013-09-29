#include <QColor>
#include <QApplication>

#include <boost/optional.hpp>

#include <cg/visualization/viewer_adapter.h>
#include <cg/visualization/draw_util.h>

#include <cg/io/point.h>

#include <cg/primitives/point.h>
#include <cg/simplification/duglas-pekker.h>

using cg::point_2f;
using cg::point_2;


struct simplify_viewer : cg::visualization::viewer_adapter
{
   simplify_viewer()
   {}

   void draw(cg::visualization::drawer_type & drawer) const
   {
       if (points.empty()) return;
        drawer.set_color(Qt::white);
        {
            auto p = points.begin();
            auto q = std::next(p);
            while (q != points.end()) {
                drawer.draw_line(*p++, *q++);
            }
        }

        drawer.set_color(Qt::blue);
        {
            auto p = ans.begin();
            auto q = std::next(p);
            while (q != ans.end()) {
                drawer.draw_line(*p++, *q++);
            }
        }
   }

   void print(cg::visualization::printer_type & p) const
   {

   }


   bool on_release(const point_2f & p)
   {
        points.push_back({p.x, p.y});
        ans.clear();
        cg::simplify(points.begin(),points.end(),std::back_inserter(ans),25);
        for (auto t: ans)
        {
            std::cout << t.x << " " << t.y << std::endl;
        }
        std::cout << "---------";
        return true;
   }

    bool on_double_click(const point_2f &)
    {
        points.clear();
        ans.clear();
    }

private:
   std::vector<point_2> points;
   std::vector<point_2> ans;
};

int main(int argc, char ** argv)
{
   QApplication app(argc, argv);
   simplify_viewer viewer;
   cg::visualization::run_viewer(&viewer, "convex hull");
}


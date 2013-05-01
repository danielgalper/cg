#pragma once

#include <boost/range/algorithm/sort.hpp>
#include<cstdio>
#include <cg/operations/orientation.h>
#include <cg/convex_hull/graham.h>
namespace cg {
bool cmp(point_2 const & a, point_2 const & b){
    return a.x < b.x;
}
template <class BidIter>
BidIter contour_andrew_hull(BidIter p, BidIter q)
{
   if (p == q)
      return p;

   BidIter b = p;

   BidIter pt = p++;

   if (p == q)
      return p;

   BidIter t = p++;

   if (p == q)
      return p;
//шаманство по итеррированию
   for (; p != q; )
   {
      switch (orientation(*pt, *t, *p))
      {
      case CG_LEFT:
         pt = t++;
         std::iter_swap(t, p++);
         break;
      case CG_RIGHT:
         t = pt--;
         break;
      case CG_COLLINEAR:
         std::iter_swap(t, p++);
      }
   }

   while (orientation(*pt, *t, *b) != CG_LEFT)
      t = pt--;

   return ++t;
}

    template <class BidIter>
    BidIter andrew_hull(BidIter p, BidIter q)
    {
       if (p == q)
          return p;

       std::iter_swap(p, std::min_element(p, q));
       BidIter sc = p;
       sc++;
       if(sc == q)
           return p;
       std:iter_swap(sc,std::max_element(p,q));

       BidIter th = sc;
       th++;
       BidIter bound = std::partition(th,q,[p,sc] (point_2 const & a)
               {
                  return (orientation(*p, *sc, a) == CG_RIGHT);
               }
        );
        bound--;
        std::iter_swap(sc,bound);
        std::sort(p, bound);
        bound++;
        std::sort(bound,q,std::greater<point_2>());


       return contour_andrew_hull(p, q);
    }
}

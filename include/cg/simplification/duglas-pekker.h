#pragma once
#include<cmath>
#include<cg/primitives/vector.h>
#include<cg/primitives/point.h>
namespace cg {
    double Distance(point_2 a, point_2 b, point_2 c){
        vector_2 v1 = a - b;
        vector_2 v2 = c - b;
        double proj = v1*v2 /( v2.dist * v2.dist);
        if(proj > 1 ) {
            return (a - c).dist;
        }
        if(proj < 0){
            return (a - b).dist;
        }
        else{
            return fabs((v1 ^ v2)/v2.dist);
        }

    }
    template <typename BidIter, typename OutIter>
    OutIter simplify(BidIter p, BidIter q,OutIter out, double eps){
        if(std::distance(p,q) == 2 ) {
            *out++ = *p;
            *out++ = *std::next(p);
            return out;
        }
        *out = *p;

        return douglaspeucker(p,q,out,eps);

    }

    template <typename BidIter, typename OutIter>
    OutIter douglaspeucker(BidIter p, BidIter q,OutIter out, double eps){
        q--;
        if(p == q ){

            return out;
        }

        point_2 begin(*p);
        point_2 end(*q);

        BidIter max =  std::max_element(std::next(p) ,q, [begin,end] (point_2 const & a, point_2 const & b)
        {
            return Distance(a,begin,end) < Distance(b,begin,end);

        });
        if(Distance(*max,begin,end) < eps){
            *(out) = *q;
            return out;
        } else {
            out = douglaspeucker(p,std::next(max),out,eps);
            out = douglaspeucker(max,++q,out,eps);
        }
        return out;
     }
}



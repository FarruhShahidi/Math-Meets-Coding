/*
Problem.  A delivery company wants to build a new service centre in a new city.
The company knows the positions of all the customers in this city on a 2D-Map and wants to build
the new centre in a position such that the sum of the euclidean distances to all customers is minimum.

Given an array positions where positions[i] = [xi, yi] is the position of the ith customer on the map,
return the minimum sum of the euclidean distances to all customers.

Answr within 1e-5 of the actual value is accepted.



Solution. The idea is to use the gradient descent algorithm.
Given a variable point, compute the sum of distances from the point to each
of the positions and minimize the function of two variables.
Minimization can be done in the following way.
Set the initial point v = (0.1, 0.1) (we assume that there is no such point in positions,
otherwise we can slightly change the distance). Then replace v with v- alpha * grad(v),
where alpha is the learning rate and  grad(v) is the gradient vector of the function at v.
When the point comes close the global(the total distance function is concave) minimum,
the convergence might jump around. Therefore, starting from the learing rate = 1 we later
decrease the value of the learning rate to 1e-7 accuracy. The idea of the following code is taken
from https://leetcode.com/problems/best-position-for-a-service-centre/discuss/733559/C%2B%2BJavaPython-Gradient-Descent


Time complexity: the algorithm runs in C*n for some constant C, where n is the length of positions.


*/


/*necesssry libraries should be included*/

class Solution {
public:
    double dist(vector<double>&p, vector<double>&q)
    {
        return sqrt((p[0]- q[0]) * (p[0]- q[0])  + (p[1]- q[1]) * (p[1]- q[1]) );
    }
    double dist_total( vector<vector<double>> &positions, vector<double>&v)
    {
        double ans = 0.0;
        for ( auto p:positions)
        {
            ans += dist(v, p);
        }
        return ans;
    }
    vector<double> grad( vector<vector<double>> &positions, vector<double> &v)
    {
        vector<double> ans(2);
        for ( auto p:positions)
        {
            ans[0] += (v[0] - p[0]) / dist(v,p);
            ans[1] += (v[1]- p[1]) / dist(v,p);
        }
        return ans;
    }



    double getMinDistSum(vector<vector<double>>& positions) {
        int n = positions.size();
        double alpha = 1;

        vector<double>v(2, 0.1);

        while (alpha> 1e-7)
        {
            double d = dist_total(positions, v);
            vector<double> g = grad(positions, v);
            vector<double>w(2);
            w[0] = v[0] - alpha * g[0];
            w[1] = v[1] - alpha * g[1];
            if (dist_total(positions, w) < d)
                v = w;
            else
                alpha *= 0.5;

        }
        return dist_total(positions,v);

    }
};

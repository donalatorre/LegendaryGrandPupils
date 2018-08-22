#include <bits/stdc++.h>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define pb push_back

using namespace std;

typedef long long ll;

double degToRad(double theta){
    return theta * PI / 180.0;
}

double radToDeg(double theta){
    return theta * 180 / PI;
}

// ******************** Struct: Punto **************************************
struct point {
    double x, y;

    point() {}
    point(double xx, double yy) {
        x = xx;
        y = yy;
    }
    point inf() {
        x = INF;
        y = INF;
    }

    double dist(point p) {
        return hypot(x - p.x, y - p.y);
    }

    void swap() {
        double aux = x;
        x = y;
        y = aux;
    }

    void swap(point &a, point &b) {
        point aux = a;
        a = b;
        b = aux;
    }

    point punto(point const &p) const {
        return point(x * p.x, y * p.y);
    }

    double cruz(point const &p) const {
        return x * p.y - y * p.x;
    }

    double cruz(point const &p1, point const &p2) const {
        return (p1.x - x) * (p2.y - y) - (p1.y - y) * (p2.x - x);
    }

    point operator +(point const &p) const {
        return point(x + p.x, y + p.y);
    }

    point operator -(point const &p) const {
        return point(x + p.x, y + p.y);
    }

    point operator /(double d) const {
        return point(x / d, y / d);
    }

    bool operator <(point const &p) const {
        return (x - p.x) > EPS && x < p.x ||
                fabs(x - p.x) < EPS && (y - p.y) > EPS && y < p.y;
    }

    bool operator ==(point p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};
// *************************************************************************

// ******************** Struct: line ***************************************
struct line {
    point p1, p2;
    double a, b, c;

    line() {
        p1.inf();
        p2.inf();
    }
    line(point pp1, point pp2) {
        p1 = pp1;
        p2 = pp2;

        if (p2 < p1)
            swap(p1, p2);

        if(fabs(p1.x - p2.x) < EPS) {
            a = 1.0;
            b = 0.0;
            c = -p1.x;
        }
        else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(double)(a * p1.x) - (b * p1.y);
        }
    }

    bool sonParalelas(line l1, line l2){
        return fabs(l1.a - l2.a) < EPS &&
                fabs(l1.b - l2.b) < EPS;
    }

    bool sonIguales(line l1, line l2){
        return sonParalelas(l1, l2) &&
                fabs(l1.c - l2.c) < EPS;
    }

    bool insideLine(point p) {
        return ((p1.x - EPS <= p.x && p.x <= p2.x + EPS ||
            p2.x - EPS <= p.x && p.x <= p1.x + EPS)     &&

            (p1.y - EPS <= p.y && p.y <= p2.y + EPS ||
            p2.y - EPS <= p.y && p.y <= p1.y + EPS));
    }

    bool intercectan(line l1, line l2, point &p){
        if (sonParalelas(l1, l2))
            return false;

        p.x = (l2.b * l1.c - l1.b * l2.c) /
                (l2.a * l1.b - l1.a * l2.b);

        if(fabs(l1.b) > EPS)
            p.y = -(l1.a * p.x + l1.c) / l1.b;
        else
            p.y = -(l2.a * p.x + l2.c) / l2.b;

        return l2.insideLine(p);
    }
};
// *************************************************************************

// ******************** Struct: triangle ***********************************
struct triangle {
    point p1, p2, p3;
    double a, b, c;
    double A, B, C;
    double area, perimetro;
    int type; // equilatero=1, isoseles=2, equilatero=3
    bool rect; // triangulo rectangulo o no

    triangle() {}
    triangle(double aa, double bb, double cc) {
        a = aa;
        b = bb;
        c = cc;
        sort();

        act();
    }

    triangle(point pp1, point pp2, point pp3) {
        p1 = pp1;
        p2 = pp2;
        p3 = pp3;

        a = p1.dist(p2);
        b = p1.dist(p3);
        c = p2.dist(p3);
        sort();

        act();
    }

    double innerCircleRadio(){
        return area / (perimetro * 2.0);
    }

    double outterCircleRadio(){
        return a * b * c / (4 * area);
    }

    int getType() {
        if(a==b && b==c)        return 1;
        else if(a==b || b==c)   return 2;
        return 3;
    }

    bool isRight(){
        return (a*a + b*b - c*c < EPS);
    }

    void sort() {
        if (a > b)
            swap(a, b);
        if (a > c)
            swap(a, c);
        if (b > c)
            swap(b, c);
    }

    double getPerimetro() {
        return a + b + c;
    }

    double getArea() {
        double s = perimetro / 2.0;
        return sqrt(s * (s-a) *(s-b) * (s-c));
    }

    double getAngles() {
        double aa = a * a;
        double bb = b * b;
        double cc = c * c;

        A = acos(bb + cc - aa) / (2 * b * c);
        B = acos(aa + cc - bb) / (2 * a * c);
        C = acos(aa + bb - cc) / (2 * a * b);
    }

    void act() {
        type = getType();
        rect = isRight();
        perimetro = getPerimetro();
        area = getArea();
        getAngles();
    }
};
// *************************************************************************


// ******************** Struct: circle *************************************
struct circle {
    point c;
    double r, circ, area;

    circle() {
        c.x = c.y = 0;
        r=1;

        act();
    }
    circle(point p, double rr){
        c = p;
        r = rr;

        act();
    }

    circle(point o, point p, point q) {
        double aux = -(q.x * q.x + q.y * q.y);
        vector<double> v(3);
        vector<vector<double> > vv;
        v[0] = 2.0 * (-o.x + q.x);
        v[1] = 2.0 * (-o.y + q.y);
        v[2] = -(o.x * o.x + o.y * o.y) - aux;
        vv.pb(v);

        v[0] = 2.0 * (-p.x + q.x);
        v[1] = 2.0 * (-p.y + q.y);
        v[2] = -(p.x * p.x + p.y * p.y) - aux;
        vv.pb(v);

        vector<double> vd = gaussJordan(vv);

        c.x = vd[0];
        c.y = vd[1];
        r = sqrt((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y));
    }

    vector<double> gaussJordan(vector<vector<double> > v) {
        int n = v.size();
        double val;
        FOR(i, 0, n) {
            if (v[i][i] == 0) {
                bool b = 1;
                FOR(j, i+1, n) {
                    if (v[i][j] != 0) {
                        swap(v[i], v[j]);
                        b = 0;
                        break;
                    }
                }
                if (b) return vector<double>();
            }

            val = v[i][i];
            FOR(j, i, n+1) {
                v[i][j] /= val;
            }

            FOR(k, 0, n) {
                if (i == k)     continue;
                val = -v[k][i];
                FOR(j, i, n+1) {
                    v[k][j] += v[i][j] * val;
                }
            }
        }

        vector<double> vd(n);
        FOR(i, 0, n)    vd[i] = v[i][n];
        return vd;
    }

    int insideCircle(point p){// 0-Dentro, 1-Borde, 2-Fuera
        int dx = p.x - c.x, dy = p.y - c.y;
        int Euc = dx*dx + dy*dy, rSq=r*r;
        double dist = c.dist(p);
        if (fabs(dist - r) < EPS)   return 1;
        if (dist < r)               return 0;
        return 2;
    }

    double getArc(double deg) {
        return circ * deg / 360.0;
    }
    double getChord(double deg) {
        return 2.0 * r * r * (1 - cos(degToRad(deg)));
    }
    double getSector(double deg) {
        return area * deg / 360.0;
    }
    double getSegment(double deg) {
        triangle t(r, r, getChord(deg));
        return getSector(deg) - t.getArea();
    }

    // 0 - No intercectan
    // 1 - Intersecta 1 punto
    // 2 - Intersecta 2 puntos
    // 3 - Mismo circulo
    // 4 - Circulo dentro del otro
    int intersectCirc(circle const &cir, point &p1, point &p2) {
        double d = c.dist(cir.c);

        if (d > r + cir.r)                      // No se tocan
            return 0;
        if ((r - cir.r) < EPS && c == cir.c)    // Mismo circulo
            return 3;
        if (d + min(r, cir.r) < max(r, cir.r))  // Circulo contiene otro
            return 4;

        double a = (r * r - cir.r * cir.r + d * d) / (2.0 * d);
        double h = sqrt(r * r - a * a);

        // find p2
        point pp1(c.x + (a * (cir.c.x - c.x)) / d, c.y + (a * (cir.c.y - c.y)) / d);

        // find intersection points p3
        p1 = point(pp1.x + (h * (cir.c.y - c.y)/ d),
                pp1.y - (h * (cir.c.x - c.x)/ d));

        p2 = point(pp1.x - (h * (cir.c.y - c.y)/ d),
                pp1.y + (h * (cir.c.x - c.x)/ d));

        if(fabs(d - r - cir.r) < EPS)
            return 1;
        return 2;
    }

    double getArea() {
        return PI * r * r;
    }

    double getCirc() {
        return PI * 2. * r;
    }

    bool operator ==(circle const &cir) const{
        return c == cir.c && fabs(r - cir.r) < EPS;
    }

    void act() {
        area = getArea();
        circ = getCirc();
    }
};

// *************************************************************************

typedef vector<point> vp;
typedef vector<line> vl;
typedef vector<triangle> vt;
typedef vector<circle> vc;

// ********************** Convex Hull **************************************
point p0;

int orientation(point p, point q, point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool compAng(const point p1, const point p2) {
    int o = orientation(p0, p1, p2);

    return (o == 0 &&
            hypot(p0.x - p2.x, p0.y - p2.y) >= hypot(p0.x - p1.x, p0.y - p1.y)) ||
            (o == 2);
}

bool compY(const point p1, const point p2) {
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

vp convexHull(vp v) {
    vp c = v;
    int n = v.size(), mini = 0;
    p0 = c[0];

    FOR(i, 1, n) {
        int y = c[i].y;

        if (compY(c[i], p0)) {
            p0 = c[i];
            mini = i;
        }
    }

    swap(c[0], c[mini]);

    sort(c.begin() + 1, c.end(), compAng);

    vp ans;
    ans.pb(c[0]);
    ans.pb(c[1]);
    ans.pb(c[2]);

    FOR (i, 3, n) {
        while (orientation(ans[ans.size()-2], ans[ans.size()-1], c[i]) != 2) {
            ans.erase(ans.end());
        }
        ans.pb(c[i]);
    }
    ans.pb(ans[0]);

    return ans;
}
// *************************************************************************


// ********************** Convex Hull v2 ***********************************
double cross(const point &O, const point &A, const point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vp convexHull(vp &P) {
    int n = P.size(), k = 0;
    vp H(2*n);
    sort(P.begin(), P.end());
    FOR(i, 0, n) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}
// *************************************************************************



// ********************** Revisa si es CW **********************************
bool cw(vp v) {
    double ret = 0;
    FOR(i, 1, v.size()) {
        ret += v[i].x * v[i-1].y - v[i-1].x * v[i].y;
    }
    return ret < 0;
}
// *************************************************************************


// ********* Revisa si un punto esta dentro en un poligono *****************
bool PointInPolygon(vp v, point p) {
    bool ret = 0;
    int j = 0;
    FOR(i, 1, v.size()) {
        if(((v[i].y > p.y) != (v[j].y > p.y)) &&
            (p.x < (v[j].x - v[i].x) * (p.y - v[i].y) / (v[j].y - v[i].y) + v[i].x)
            )
            ret = !ret;
        j++;
    }
    return ret;
}
// *************************************************************************


// ************* Calcular perimetro de un poligono *************************
double perimetro(vp v) {
    double ret = 0;
    FOR(i, 0, v.size() - 1) {
        ret += v[i].dist(v[i + 1]);
    }
    return ret;
}
// *************************************************************************


// ****************** Calcular area de un poligono *************************
double area(vp v) {
    double ret = 0;
    FOR(i, 1, v.size()) {
        ret += v[i].x * v[i-1].y - v[i-1].x * v[i].y;
    }
    return fabs(ret) / 2.0;
}
// *************************************************************************




int main () { _
	point p(1, 2), p2(2,3);
	cout << p.x << " " << p.y << endl;
}

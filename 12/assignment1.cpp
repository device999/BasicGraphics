#include <vector>
#include <numeric>
#include <algorithm>

#include "SimpleGraph.h"
#include "SimpleImage.h"
#include "tools_10.h"
#include "gradient_descent_nd.h"


using namespace std;

vector<double> samplesX;
vector<double> samplesY;

double g(double x, double c1, double c2) {
	return c1*sin(2 * PI*c2*x) + c2*cos(2 * PI*c1*x);
}

void sampleG() {
	for (double i = 0; i < 101; i++) {
		samplesX.push_back(i / 100);
		samplesY.push_back(g(i / 100, 3, 10));
	}
}

double polynomial(double x, const vector<double> &a) {
	return a[0] *x*x*x + a[1] * x*x + a[2] * x + a[3];
}


double polynomial_fit_energy(const vector<double> &a, vector<double> &gradient) {
	double energy = 0.0;
	double error = 0.0;
	for (int i = 0; i<4; i++)
		gradient.push_back(0.0);
	for (int i = 0; i<samplesX.size(); i++) {
		error = (polynomial(samplesX[i], a) - samplesY[i]);
		energy += error*error;
		gradient[3] += error * 2;
		gradient[2] += error * 2 * samplesX[i];
		gradient[1] += error * 2 * samplesX[i] * samplesX[i];
		gradient[0] += error * 2 * pow(samplesX[i], 3);
	}

	return energy;
}
int main() {
	sampleG();


	SimpleGraph* ubung1a = SimpleGraph::getInstance();
	ubung1a->setData(samplesX, samplesY);
	ubung1a->show();
	vector<double> grad1;
	vector<double> grad2;
	vector<double> grad3;
	vector<double> grad4;

	vector<double> a1;
	a1.push_back(0);a1.push_back(0);a1.push_back(0);a1.push_back(1);
	vector<double> a2;
	a2.push_back(0);a2.push_back(0);a2.push_back(1);a2.push_back(0);
	vector<double> a3;
	a3.push_back(0);a3.push_back(1);a3.push_back(0);a3.push_back(0);
	vector<double> a4;
	a4.push_back(1);a4.push_back(0);a4.push_back(0);a4.push_back(0);
	
	polynomial_fit_energy(a1, grad1);
	polynomial_fit_energy(a2, grad2);
	polynomial_fit_energy(a3, grad3);
	polynomial_fit_energy(a4, grad4);
	
	vector<double> gradient;
	vector<double> a;
	a.push_back(0);a.push_back(0);a.push_back(0);a.push_back(0);
	gradient = gradient_descent_nd(a, polynomial_fit_energy, 50000);
	vector<double> fs;
	for (int i = 0; i < samplesX.size(); i++)
		fs.push_back(polynomial(samplesX[i], gradient));
	ubung1a->addData(samplesX, fs);
	ubung1a->show();


	for (int i = 0; i < 10; i++) {
		vector<double> my_vector;
		create_random(123456 + i, 4, 0, 10000, my_vector);
		vector<double> temp = gradient_descent_nd(my_vector, polynomial_fit_energy, 50000, 0);
	}
	
	return 0;
}


#include <vector>
#include <numeric>
#include <algorithm>

#include "SimpleGraph.h"
#include "SimpleImage.h"
#include "tools_10.h"
#include "gradient_descent_nd.h"




using namespace std;
vector<double> sampleXs, sampleYs;
double g(double x, double c1, double c2){ 
	return c1*sin(2 * PI*c2*x) + c2*cos(2 * PI*c1*x);
}

void sampleG() {
	for (double i = 0; i < 101; i++) {
		sampleXs.push_back(i / 100);
		sampleYs.push_back(g(i / 100, 3, 10));
	}
}

void print(vector<double> &vec) {
	for (int i = 0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

double g_fit_energy(const vector<double> &c, vector<double>& gradient) {
	gradient.push_back(0);
	gradient.push_back(0);
	double energy = 0, error, x;
	for (int i = 0; i < sampleXs.size(); i++) { 
		x = sampleXs[i];
		error = g(x, c[0], c[1]) - sampleYs[i];
		energy += error*error;
		gradient[0] += 2 * error*(sin(2 * PI*c[1] * x) - 2 * PI*c[1] * x*sin(2 * PI*c[0] * x));
		gradient[1] += 2 * error*(2 * PI*c[0] * x*cos(2 * PI*c[1] * x) + cos(2 * PI*c[0] * x)); 
	}
	return energy;
}

int main() {

	//SimpleGraph* plot = SimpleGraph::getInstance();
	sampleG();
	//plot->setData(sampleXs, sampleYs);
	//plot->show();
	vector<double> c;
	c.push_back(3);
	c.push_back(10);
	vector<double> grad;
	g_fit_energy(c, grad);
	cout << "(" << c[0] << "," << c[1] << ") => (" << grad[0] << "," << grad[1] << ")" << endl;

	vector<double> c2;
	c2.push_back(3.5);
	c2.push_back(10);
	vector<double> grad2;
	g_fit_energy(c2, grad2);
	cout << "(" << c2[0] << "," << c2[1] << ") => (" << grad2[0] << "," << grad2[1] << ")" << endl;

	vector<double> c3;
	c3.push_back(4);
	c3.push_back(10);
	vector<double> grad3;
	g_fit_energy(c3, grad3);
	cout << "(" << c3[0] << "," << c3[1] << ") => (" << grad3[0] << "," << grad3[1] << ")" << endl;
	
	vector<double> c4;
	c4.push_back(3);
	c4.push_back(10.5);
	vector<double> grad4;
	g_fit_energy(c4, grad4);
	cout << "(" << c4[0] << "," << c4[1] << ") => (" << grad4[0] << "," << grad4[1] << ")" << endl;
	
	vector<double> c5;
	c5.push_back(3);
	c5.push_back(11);
	vector<double> grad5;
	g_fit_energy(c5, grad5);
	cout << "(" << c5[0] << "," << c5[1] << ") => (" << grad5[0] << "," << grad5[1] << ")" << endl;


	cout << "\n\n**************** Gradient descent results: ****************\n";
	vector<double> new_coefficcients = gradient_descent_nd(c, g_fit_energy, 50000,0);
	vector<double> new_coefficcients2 = gradient_descent_nd(c2, g_fit_energy, 50000,0);
	vector<double> new_coefficcients3 = gradient_descent_nd(c3, g_fit_energy, 50000,0);
	vector<double> new_coefficcients4 = gradient_descent_nd(c4, g_fit_energy, 50000,0);
	vector<double> new_coefficcients5 = gradient_descent_nd(c5, g_fit_energy, 50000,0);
	cout << "(" << c[0] << "," << c[1] << ") => (" << new_coefficcients[0] << "," << new_coefficcients[1] << ")" << endl;
	cout << "(" << c2[0] << "," << c2[1] << ") => (" << new_coefficcients2[0] << "," << new_coefficcients2[1] << ")" << endl;
	cout << "(" << c3[0] << "," << c3[1] << ") => (" << new_coefficcients3[0] << "," << new_coefficcients3[1] << ")" << endl;
	cout << "(" << c4[0] << "," << c4[1] << ") => (" << new_coefficcients4[0] << "," << new_coefficcients4[1] << ")" << endl;
	cout << "(" << c5[0] << "," << c5[1] << ") => (" << new_coefficcients5[0] << "," << new_coefficcients5[1] << ")" << endl;


	////Create an image 𝐼 and plot the energy levels (resolution of at least 300 × 300).
	//SimpleImage& vis = *SimpleImage::getInstance();
	//vis.create(300, 300);//create an image with 300x300 pixels
	//for (int i = 0; i < 300; i++)
	//	for (int j = 0; j < 300; j++) {
	//		c[0] = i*20.0 / 300; c[1]= j*20.0 / 300;
	//		vis(i, j) = g_fit_energy(c, grad); //set pixel (15,10) to value 0.5
	//	}
	//vis.show(); //close window to continue


	//SimpleImage& vis2 = *SimpleImage::getInstance();
	//vis2.create(300, 300);//create an image with 300x300 pixels
	//for (int i = 0; i < 300; i++)
	//	for (int j = 0; j < 300; j++) {
	//		c[0] = i*20.0 / 300; c[1] = j*20.0 / 300;
	//		vis2(i, j) =log( g_fit_energy(c, grad)+1); //set pixel (15,10) to value 0.5)
	//	}
	//vis2.show(); //close window to continue

	//SimpleImage& vis3 = *SimpleImage::getInstance();
	//vis3.create(100, 100);//create an image with 300x300 pixels
	//for (int i = 0; i < 100; i++)
	//	for (int j = 0; j < 100; j++) {
	//		c[0] =1+i*4.0/ 100; c[1] = 5+j*10.0 / 100;
	//		vis3(i, j) = log(g_fit_energy(c, grad) + 1); //set pixel (15,10) to value 0.5)
	//	}
	//vis3.show(); //close window to continue

	SimpleImage& vis4 = *SimpleImage::getInstance();
	vis4.create(20, 20);//create an image with 300x300 pixels
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++) {
			cout << i*20 + j << endl;
			c[0] = 1 + i*4.0 / 20; c[1] = 5 + j*10.0 / 20;
			vector<double> new_coeff = gradient_descent_nd(c,g_fit_energy,50000,0);
			vector<double> new_grad;
			vis4(i, j) = log(g_fit_energy(new_coeff, new_grad) + 1); //set pixel (15,10) to value 0.5)
		}
	vis4.show(); //close window to continue
}
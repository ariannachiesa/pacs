#include "tridiagonal.hpp"
#include<iostream>

tridiagonal_matrix::tridiagonal_matrix(int n, std::vector<double> diag, std::vector<double> up, std::vector<double> down){
	
	if(n<=1){
		std::cout<<"Error: dimension must be major than 1"<<std::endl;
		exit(EXIT_FAILURE);
	}
	if(diag.size()!=n){
		std::cout<<"Error: dimensions wrong"<<std::endl;
		exit(EXIT_FAILURE);
	}
	if(up.size()!=(n-1)){
		std::cout<<"Error: dimensions wrong"<<std::endl;
		exit(EXIT_FAILURE);
	}
	if(down.size()!=(n-1)){
		std::cout<<"Error: dimensions wrong"<<std::endl;
		exit(EXIT_FAILURE);
	}

	_n = n ;
	_diag = diag ;
	_up = up ;
	_down = down ;

}

void tridiagonal_matrix::thomas_factorize(){

	_c.reserve(_n-1);
	_c.push_back(_up[0]/_diag[0]);

	for(int i=1; i<_n-1; i++){
		_c.push_back(_up[i]/(_diag[i]-_down[i-1]*_c[i-1])); //down[i]
	}

        // controllo
//        for(int i=0; i<_n-1; i++){
//		std::cout<<_c[i]<<std::endl;	
//	}

}

std::vector<double> tridiagonal_matrix::thomas_solve(std::vector<double> f){

	std::vector<double> d;
	d.reserve(_n);

	d.push_back(f[0]/_diag[0]);
	for(int i=1; i<_n; i++){
		d.push_back((f[i]-(_down[i-1]*d[i-1]))/(_diag[i]-(_down[i-1]*_c[i-1]))); //down[i]
	}
	
	std::vector<double> x;
	x.reserve(_n-1);

	x.push_back(d.back());
	for(int i=_n-2; i>=0; i--){
                x.insert(x.begin(),d[i]-_c[i]*x.front());
	}

	return x;

}

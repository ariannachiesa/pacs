#include<iostream>
#include "tridiagonal.hpp"

int main(){

//	tridiagonal_matrix mat;
//	std::vector<double> diag(3,1);
//	std::vector<double> up(2,1);
//	std::vector<double> down(2,1);
//	tridiagonal_matrix mat1(3,diag,up,down);

//! Precomputed coefficient for adimensional form of equation
	int a1=4;
	int a2=50;
	double hc=200.0e-6;
	int L=40;
	double k=0.164;
	int M=11;
	double To=46.;
	double Te=20.;
  const auto act=2.*(a1+a2)*hc*L*L/(k*a1*a2);

  // mesh size
  const auto h=1./M;
  
  // Solution vector
  std::vector<double> theta(M+1);

  // Thomas algorithm  
  std::vector<double> diag(M+1,2+h*h*act) ;
  std::vector<double> up(M,-1);
  std::vector<double> down(M,-1);
  std::vector<double> b(M+1,0);
  b[0] = To-Te ;
  diag[M] = 1 ;

	for(int i=0; i<M+1; i++){
		std::cout<<"diag : "<<diag[i]<<std::endl;	
	}
for(int i=0; i<M; i++){
		std::cout<<"up : "<<up[i]<<std::endl;	
	}
for(int i=0; i<M; i++){
		std::cout<<"down : "<<down[i]<<std::endl;	
	}
for(int i=0; i<M+1; i++){
		std::cout<<"b : "<<b[i]<<std::endl;	
	}

  tridiagonal_matrix mat1(M+1,diag,up,down);


	mat1.thomas_factorize();

	theta=mat1.thomas_solve(b);

	for(int i=0; i<M+1; i++){
		std::cout<<"x : "<<theta[i]<<std::endl;	
	}

	return 0;

}

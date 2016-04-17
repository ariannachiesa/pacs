#ifndef TRIDIAGONAL_HPP
#define TRIDIAGONAL_HPP

#include <vector>

class tridiagonal_matrix{

    private:
	    int _n;
	    std::vector<double> _diag;
	    std::vector<double> _up;
	    std::vector<double> _down;
        std::vector<double> _c;

	public:
        // default constructor
        tridiagonal_matrix(): _n(2),_diag(2,1),_up(1,0),_down(1,0){
        }

        // constructor
        tridiagonal_matrix(int n, std::vector<double> diag, std::vector<double> up, std::vector<double> down);

        // metodi
        void thomas_factorize();
        std::vector<double> thomas_solve(std::vector<double> f);

};
#endif

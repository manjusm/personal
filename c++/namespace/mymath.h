#include <iostream>

#pragma once

namespace MyMath
{
	class math
	{
		public:
		    static int pow(int base, int exp){
			    int result = 1;
                if (exp < 0){
                    std::cout<<"Please enter exp > 0"<<std::endl;
                    return 0;
                }
                for (int i = 0; i < exp; i++){
                    result = result * base;
                }
                return result;
		    }
	};
};

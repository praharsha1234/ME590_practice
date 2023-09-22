#include <iostream>
#include <vector>
// #include <cmath>
#include <string>
#include <unistd.h>

/*Global Variable definitions*/
float x;
float x_square = 64.0f;
float x_triple = 1000.0f;
bool solved = false;

/* Function prototype*/
void HAL_Delay(float sec);
float naive_abs(float num);
void solve(void);

int main(int argc, char const *argv[])
{
    /*Local Variable definitions*/

    /* Code before loop*/
    //choose a random x, but I will cheat and choose x = 0
    x = 0;

    /*Super loop*/
    while(!solved){
        solve();
    }

    return 0;
}


void HAL_Delay(float sec){
    usleep(sec * 1000000);
}

float naive_abs(float num){
    return (num >0 ) ? num : (-num);
}

void solve(void){
    //like a count for a timer
    static int count = 0;

    //Looks like a Newton method to solve f(x) = y, but maybe not
    //cuz I forgot how I implemented Newton's method in MATLAB
    //and im too lazy to open the pdf lecture again
    // will do it next time, for now just be simple
    float tolerance = 0.2f;
    float x_step = 0.01f;

    //new x
    x = x + x_step;
    float x_updated = x;

    //output check
    float output_check = x_updated * x_updated * x_updated;

    //Naive condition solver but it is ok in this case
    if ( naive_abs(output_check - x_triple ) <= tolerance){
        std::cout << "====Solved==== \n\n\n\n" << std::endl;
        // x = x_updated;
        std::cout << "x = " << x << std::endl;
        solved = true;
    }else{
        std::cout << "Finding x ... === " << count << 
         "% ===="
        // << x_updated << " output = "
        //  << output_check  
        //  << " compare : " 
        //  << naive_abs(output_check - x_square ) 
         << std::endl; //haha 
    }

    count++; // of course

    //reset counter
    if(count >= 100) count = 0;
    
    HAL_Delay(0.001/2);
}

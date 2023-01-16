#include<sycl/sycl.hpp>
#include<iostream>

using namespace sycl;
using namespace std;
#define N 100

using namespace sycl;


#define N 999999999

int main(){

    queue Q(accelerator_selector_v);
    cout << "\nRunning on " << Q.get_device().get_info<info::device::name>() << "\n";
    
    auto R = range<1>{ N };
    
    dx = 1.0/N;
	x = 0.0;
	area = 0.0;
    
    Q.submit([&](handler& h){
        accessor outarea(area,h,write_only);
        h.parallel_for(R, [=](auto idx) {
            double dx, x, area, y;
            dx = 1.0/R
            x += dx
            y = sqrt(1-x*x);
            area += y*dx;            
        });
    });

    host_accessor outarea(area,read_only);
    cout << outarea;
    double pi = 4.0;
	
}


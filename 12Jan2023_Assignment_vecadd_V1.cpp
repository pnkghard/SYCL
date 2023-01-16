#include<sycl/sycl.hpp>

using namespace sycl;
using namespace std;
#define N 100

using namespace sycl;

int main(int argc, char** argv) {  
    queue Q(accelerator_selector_v);
    cout << "\nRunning on " << Q.get_device().get_info<info::device::name>() << "\n";
    
    auto R = range<1>{ N };
    buffer<int> A{ R }, B{ R }, C{ R };

    Q.submit([&](handler& h){
        accessor outa(A,h,write_only);
        accessor outb(B,h,write_only);
        h.parallel_for(R, [=](auto idx) {
            outa[idx] = 1;
            outb[idx] = 1;
        });
    });
    host_accessor outA(A,read_only);
    cout << "Value in A : \n";
    for (int i=0; i<N; ++i){
        cout << "\t" << outA[i]; 
    }
    cout << "\n";
    cout << "Value in B : \n";
    host_accessor outB(B,read_only);
    for (int i=0; i<N; ++i){
        cout << "\t" << outB[i]; 
    }

    Q.submit([&](handler& h){
        accessor ina(A,h,read_only);
        accessor inb(B,h,read_only);
        accessor outc(C,h,write_only);
        h.parallel_for(R, [=](auto idx) {
            outc[idx] = ina[idx] + inb[idx];
        });
    });
    host_accessor outC(C,read_only);
    cout << "\n";
    cout << "Value in C after addition : \n";
    for (int i=0; i<N; ++i){
        cout << "\t" << outC[i]; 
    }

    cout << "\n\n";
    return 0;
}
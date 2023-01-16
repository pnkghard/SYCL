#include <sycl/sycl.hpp>

using namespace sycl;

int main() {
    //# Create a device queue with device selector
    queue q;
    device my_device=q.get_device();
    std::cout<<"Device:"<<my_device.get_info<info::device::name>()<<"\n";

  return 0;
}
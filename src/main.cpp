#include <iostream>
#include "./../include/loadParams.hpp"

int main(int argc, char* argv[])
{
  LoadParams *load;
  load = new LoadParams();

  float test_num = 0;
  double test_double = 0;
  //char test_error = 0;
  std::string test_str;
  bool test_bool = true;

  load->get_param<float>("test3", test_num);
  load->get_param<double>("test4", test_double);
  //load->get_param<char>("test4", test_error);
  load->get_param<std::string>("set_string", test_str);
  load->get_param<bool>("set_bool", test_bool);
  load->get_param<bool>("error_bool", test_bool);

  std::cout << test_num << std::endl;
  std::cout << test_double << std::endl;
  std::cout << test_str << std::endl;
  std::cout << test_bool << std::endl;

  return 0;
}

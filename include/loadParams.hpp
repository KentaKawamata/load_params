
#include <iostream>
#include <string>
#include <typeinfo>
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class LoadParams
{
private:

    void set_param(const std::string param_string, bool &param);

    //未実装
    //void set_param(const std::string param_string, short int &param);
    //未実装
    //void set_param(const std::string param_string, unsigned short int &param);
    void set_param(const std::string param_string, int &param);
    //未実装
    //void set_param(const std::string param_string, unsigned int &param);
    void set_param(const std::string param_string, long int &param);
    void set_param(const std::string param_string, unsigned long int &param);
    void set_param(const std::string param_string, long long int &param);
    void set_param(const std::string param_string, unsigned long long int &param);

    //未実装
    //void set_param(const std::string param_string, char &param);
    //未実装
    //void set_param(const std::string param_string, signed char &param);
    //未実装
    //void set_param(const std::string param_string, unsigned char &param);

    void set_param(const std::string param_string, float &param);
    void set_param(const std::string param_string, double &param);
    void set_param(const std::string param_string, long double &param);
    
    void set_param(const std::string param_string, std::string &param);

    template<typename Param>
    void set_param(std::string param_string, Param &param);

public:

    LoadParams();
    ~LoadParams();

    template<typename Param>
    void get_param(std::string id, Param &param);
    void change_type(float &param);

};
    
LoadParams::LoadParams()
{}

LoadParams::~LoadParams()
{}

void LoadParams::set_param(const std::string param_string, bool &param)
{
    if(param_string == "1" || param_string == "true")
    {
        param = true;
    }
    else if(param_string == "0" || param_string == "false")
    {
        param = false;
    }
    else
    {
        std::cout << "[ERROR]: " << "param is typed as 'bool'. But param's type is not bool" << "\n"
                  << "Check the xml file" << std::endl;
        exit(0);
    }
}

void LoadParams::set_param(const std::string param_string, int &param)
{
    param = std::stoi(param_string);
}

void LoadParams::set_param(const std::string param_string, unsigned long int &param)
{
    param = std::stoul(param_string);
}

void LoadParams::set_param(const std::string param_string, unsigned long long int &param)
{
    param = std::stoull(param_string);
}

void LoadParams::set_param(const std::string param_string, float &param)
{
    param = std::stof(param_string);
}

void LoadParams::set_param(const std::string param_string, double &param)
{
    param = std::stod(param_string);
}

void LoadParams::set_param(const std::string param_string, long double &param)
{
    param = std::stold(param_string);
}

void LoadParams::set_param(const std::string param_string, std::string &param)
{
    param = param_string;
}

template<typename Param>
void LoadParams::set_param(const std::string param_string, Param &param)
{
    std::cout << "[ERROR]: " << typeid(param).name() << " is not defined in loadParams.hpp" << std::endl;
    exit(0);
}

template<typename Param>
void LoadParams::get_param(std::string param_name, Param &param)
{
    using namespace boost::property_tree;

    ptree pt;
    xml_parser::read_xml("./../launch/setting.xml", pt);

    BOOST_FOREACH(ptree::value_type &v, pt.get_child("data"))
    {
        std::string name = v.second.get_child("<xmlattr>.name").data();
        if(name == param_name)
        {
            std::string p = v.second.get_child("<xmlattr>.value").data();
            set_param(p, param);
        }
    }
}

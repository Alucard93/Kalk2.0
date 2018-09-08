/**
 * @file illegalcolorexception.h
 * @author Giuseppe Bitetti & Gianmarco Pettinato
 * @date 20/7/2018
 * @brief this class is the main exception in this program exstends runtime_error
 * */
#ifndef ILLEGALColorEXCEPTION_H
#define ILLEGALColorEXCEPTION_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
using namespace std;
class IllegalColorException: public runtime_error{
public:
    IllegalColorException(std::string e):runtime_error(e){}
};

#endif // ILLEGALColorEXCEPTION_H

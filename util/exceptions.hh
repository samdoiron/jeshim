#ifndef JESH_EXCEPTIONS_H_
#define JESH_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

namespace jesh {

#define throw_error(arg) throw std::runtime_error(std::string("\n") + arg + std::string("\n\tat ") + std::string(__FILE__) + ":" + std::to_string(__LINE__));

}

#endif // JESH_EXCEPTIONS_H_






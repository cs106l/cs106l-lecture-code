#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <functional>
#include <optional>
#include <ostream>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>

/* ========================================================================= *
 * Printing typenames/demangling                                             *
 * ========================================================================= */

namespace demangling
{

  static std::optional<std::string> execute(const std::string &command, int* exit_status = nullptr)
  {
    std::string result;

    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe)
      return std::nullopt;
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
      result += buffer;
    }
    int status = pclose(pipe);
    if (exit_status) *exit_status = status;
    if (status != 0)
      return std::nullopt;

    return result;
  }

  static bool can_demangle()
  {
    static std::optional<bool> available;

    if (available.has_value())
      return *available;

    int exec_status;
    execute("c++filt --version", &exec_status);
    available = (exec_status == 0);

    if (!available)
      std::cerr << "\033[33mWarning: c++filt could not be found, so type names will be mangled.\033[0m\n\n";

    return *available;
  }

  static std::string demangle(const std::string &mangled)
  {
    if (!can_demangle())
      return mangled;
    auto demangled = execute("echo " + mangled + " | c++filt -t");
    if (!demangled.has_value())
      return mangled;

    auto rstrip = [](std::string str){
      auto end = std::find_if_not(str.rbegin(), str.rend(), isspace).base();
      str.erase(end, str.end());
      return str;
    };

    return rstrip(*demangled);
  }

  template <typename T>
  struct Demangle
  {
    friend std::ostream &operator<<(std::ostream &os, const Demangle &t)
    {
      return os << t.name();
    }

    static const std::string& name() {
      static auto name = demangle(typeid(T).name());
      return name;
    }
  };

}

template <typename T>
static auto type()
{
  return demangling::Demangle<T>{};
}

template <typename T>
static auto type(T&& v)
{
  return type<std::remove_cvref_t<T>>();
}

template <typename Container>
std::string pit(Container &c, typename Container::iterator it)
{
  using Iterator = typename Container::iterator;

  std::stringstream ss;
  ss << "Iterator{ ";

  ss << "pos = ";
  if (std::begin(c) != std::end(c) && it == std::end(c))
    ss << "end()";
  else
  {
    auto pos = std::distance(std::begin(c), it);
    ss << "begin()";
    if (pos > 0)
      ss << " + " << pos;
  }

  if (it != std::end(c))
  {
    ss << ", ";
    ss << "element = " << *it;
  }

  ss << " }";

  return ss.str();
}

/* ========================================================================= *
 * Test functions/output                                                     *
 * ========================================================================= */

static std::ostream& out() {
  return std::cout << "\033[90m" << std::left << std::setw(60);
}

static constexpr auto result = "\033[0m";
static constexpr auto end = "\n";

namespace testing
{

  struct Test
  {
    std::string name;
    std::function<void()> func;
  };

  static std::vector<Test> tests;

  struct TestRegistrar
  {
    TestRegistrar(std::string name, std::function<void()> func) { tests.push_back({name, func}); }
  };

  static int run_tests()
  {
    demangling::can_demangle();
    const std::string style_bg = "\033[48;5;45m";
    const std::string style_reset = "\033[0m";

    for (const auto &test : tests)
    {
      std::cout << style_bg
                << std::setw(100) << std::setfill(' ')
                << std::left << test.name
                << style_reset << std::endl;

      test.func();
      std::cout << "\n\n";
    }

    return 0;
  }

#define test(func) static testing::TestRegistrar registrar_##func(#func, func)

}

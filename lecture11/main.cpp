#include <iostream>
#include <type_traits>
#include <unordered_set>
#include <vector>

#include "utils.hpp"

/* ========================================================================= *
 * Template Functions:                                                       *
 * Min function                                                              *
 * ========================================================================= */

/* This is a simple function to return the min of two values.
 * Notice that it takes in it's parameters by value and assumes
 * that both parameters have the same type. */
template <typename T>
T min_basic(T a, T b) {
  return a < b ? a : b;
}

void test_min_basic() {
  // Explicit instantiation
  int int_min = min_basic<int>(106, 107);
  out() << "min_basic<int>(106, 107): " << result << int_min << end;
  
  double double_min = min_basic<double>(42.5, 3.14);
  out() << "min_basic<double>(42.5, 3.14): " << result << double_min << end;

  std::string string_min = min_basic<std::string>("Jacob", "Fabio");
  out() << "min_basic<std::string>(\"Jacob\", \"Fabio\"): " << result << string_min << end;

  // Careful using implicit instantiation
  std::string expr { "min_basic(\"Jacob\", \"Fabio\"): "};
  auto string_min_bad = min_basic("Jacob", "Fabio");
  out() << "Type of " + expr << result << type(string_min_bad) << end;
  out() << expr << result << string_min_bad << end;
}

/* Here is another version of the same function.
 * Note that we are taking `a` and `b` in by reference,
 * so we'd expect to see a performance improvement for more complex
 * types like `std::string`. */
template <typename T>
T min_ref(const T& a, const T& b) {
  return a < b ? a : b;
}

void test_min_ref() {
  // Implicit Instantiation
  int int_min = min_ref(106, 107);
  out() << "min_ref<int>(106, 107): " << result << int_min << end;
  
  double double_min = min_ref(42.5, 3.14);
  out() << "min_ref<double>(42.5, 3.14): " << result << double_min << end;

  // Must use explicit instantiation here
  std::string string_min = min_ref<std::string>("Arwen", "Aragorn");
  out() << "min_ref<std::string>(\"Arwen\", \"Aragorn\"): " << result << string_min << end;
}

/* Here is a more flexible min function that will work
 * even if the types differ (as long as they can be converted
 * to the same type). 
 * 
 * Notice that it uses an auto return type:
 * we will let the compile figure out what the return type
 * depending on the type of what gets returned.  */
template <typename U, typename V>
auto min_flex(const U& a, const V& b) {
  return a < b ? a : b;
}

void test_min_flex() {
  std::string expr { "min_flex(106, 107.5): " };
  auto min_elem = min_flex(106, 107.5);

  out() << "Type of " + expr << result << type(min_elem) << end;
  out() << expr << result << min_elem << end;
}


/* ========================================================================= *
 * Code Demo:                                                                *
 * `find` function                                                           *
 * ========================================================================= */

/* Here is a generic version of a find function that will work
 * for any container and any value type. */
template <typename TIterator, typename TValue>
TIterator find(TIterator begin, TIterator end, TValue value) {
  for (auto it = begin; it != end; ++it) {
    if (*it == value) return it;
  }
  return end;
}

void test_find() {
  // We could use explicit instantiation, although this is cumbersome
  //
  // Notice that we are calling `find` as `::find` in these examples.
  // This is because of a feature called ADL (argument-dependent lookup).
  //
  // Basically, C++ says "if the arguments to a fucntion are in `namespace std`,
  // then most likely the function is in `namespace std` too!". Since `v.begin()`
  // and `v.end()` are `std::vector<int>::iterator`, it thinks that `find`
  // is actually `std::find` (not the `find` we defined above).
  //
  // To get it to select the right find, we explicitly tell it to search
  // the *global namespace* by prefixing it with ::
  //
  std::vector<int> v { 1, 2, 3, 4, 5 };
  auto it1 = ::find<std::vector<int>::iterator, int>(v.begin(), v.end(), 3);
  out() << "find<std::vector<int>::iterator, int>(v.begin(), v.end(), 3): " << result << pit(v, it1) << end;

  // In practice, we will usually use implicit instantiation!
  std::string expr2 { "find(v.begin(), v.end(), 10): " };
  auto it2 = ::find(v.begin(), v.end(), 10); // Should be end()


  using TIterator2 = decltype(it2);
  using TValue2 = typename std::iterator_traits<TIterator2>::value_type;
  out() << expr2 << result << "TIterator = " << type<TIterator2>() << end;
  out() << expr2 << result << "TValue = " << type<TValue2>() << end;
  out() << expr2 << result << pit(v, it2) << end;

  // Notice, because we're using templates, `find` generalizes to other
  // container types/values seamlessly!

  std::unordered_set<std::string> us { "hello", "there", "welcome", "to", "cs106l!" };
  std::string expr3 { "find(us.begin(), us.end(), \"welcome\"): "};
  auto it3 = ::find(us.begin(), us.end(), "welcome");

  using TIterator3 = decltype(it3);
  using TValue3 = typename std::iterator_traits<TIterator3>::value_type;
  out() << expr3 << result << "TIterator = " << type<TIterator3>() << end;
  out() << expr3 << result << "TValue = " << type<TValue3>() << end;
  out() << expr3 << result << pit(us, it3) << end;
}

/* ========================================================================= *
 * Concepts                                                                  *
 * ========================================================================= */

/* Concepts are a way to constrain what types a template parameter can represent.
 * By default, writing `typename T` allows `T` to be instantiated with any type!
 * That doesn't mean, however, that after instantiation, a specific choice of `T`
 * won't necessarily cause a compiler error.
 * 
 * For example, if we tried to instantiate `min<std::ifstream>`, the function
 * would still be instantiated with `T = std::ifstream`, however, when it tries 
 * to compare the two `std::ifstream` using `operator<`, we'd get a compiler error!
 * 
 * Concepts are a way to constrain these types, so that `min` for example doesn't
 * even get instantiated in the first place if `T` doesn't have an `operator<`.
 * This leads to all around better error messages, faster compile times, etc. */

template <typename T>
concept Comparable = requires(T a, T b) {
  // For T to model Comparable, a < b must a valid expression at compile time
  // Furthermore, we require that the result type of `a < b` models `std::convertible_to<bool>`.
  // 
  // Aside: `std::convertible_to<From, To>` is actually a concept that takes in two type
  // parameters and says whether `From` can be converted to `To`. Notice, however, that 
  // in the constraint below, `From` is implicitly replaced with the type of `a < b`,
  // e.g. `decltype(a < b)`.
  { a < b } -> std::convertible_to<bool>;

  // You can put more constraints here if you'd like!
};

/* Here's how we can use the Comparable concept.
 * Another way to write this is:
 *
 *  template <typename T> requires Comparable<T>
 * 
 */
template <Comparable T>
T min_constrained(const T& a, const T& b) {
  return a < b ? a : b;
}

void test_min_constrained() {
  // This works: `int` has `operator<`
  min_constrained(10, 20);

  // This does not: `std::stringstream` lacks `operator<`
  // Try uncommenting this line and re-compiling
  // min_constrained(std::stringstream(), std::stringstream());

  // We can check, at compile time, whether a type satisfies a concept
  auto satisfies = [](auto val){
    using T = decltype(val);
    out() << type(val).name() + " is Comparable<T>: " << result;

    // `if constexpr` evaluates an if statement at compile time
    if constexpr (Comparable<T>) std::cout << "Yes!";
    else std::cout << "No!";

    std::cout << end;
  };

  satisfies(5);
  satisfies(std::stringstream {});
  satisfies("Hello World!");
  satisfies(std::vector<int> { 1, 2, 3 });
}


/* ========================================================================= *
 * Variadic Templates:                                                       *
 * Building a variadic min function                                          *
 * ========================================================================= */

/* Variadic functions support any number of arguments. 
 * They work by recursively generating overloads for a function at instantiation
 * time. */

/* Here is our base case function:
 * The min of a single `v` is just `v` */
template <Comparable T>
T min_var(const T& v) { return v; }


/* Here is our recursive case function:
 * The min of `v, ...rest` is just `min(v, min_var(rest...))`
 * Notice that the `...` **unpacks** its arguments at compile time. */
template <Comparable T, Comparable... Args>
T min_var(const T& v, const Args&... rest) {
  auto m = min_var<T>(rest...); 
  return v < m ? v : m;
}

void test_min_var() {
  auto m1 = min_var(1);
  out() << "min_var(1): " << result << m1 << end;

  auto m2 = min_var(2, 1);
  out() << "min_var(2, 1): " << result << m2 << end;

  // This works for other types too!
  auto m3 = min_var<std::string>("cool", "variadic", "template!");
  out() << "min_var<std::string>(\"cool\", \"variadic\", \"template!\"): " << result << m3 << end;

  // We can technically have different types for each parameter,
  // but due to how the recursive case is defined, the type of the
  // first parameter determines the type of the result
  std::string expr4 { "min_var(10, 2.5, 3.0f): " };
  auto m4 = min_var(10, 2.5, 3.0f);
  out() << expr4 << result << m4 << end;
  out() << "Type of " + expr4 << result << type(m4) << end;

  // To get the right type, we should explicitly instantiate
  //
  // Notice that the recursive case function also explicitly instantiates
  // for the same reason!
  std::string expr5 { "min_var<double>(10, 2.5, 3.0f): " };
  auto m5 = min_var<double>(10, 2.5, 3.0f);
  out() << expr5 << result << m5 << end;
  out() << "Type of " + expr5 << result << type(m5) << end;
}


/* ========================================================================= *
 * Harness for these examples                                                *
 * ========================================================================= */


test(test_min_basic);
test(test_min_ref);
test(test_min_flex);
test(test_find);
test(test_min_constrained);
test(test_min_var);

int main() {
  return testing::run_tests();
}
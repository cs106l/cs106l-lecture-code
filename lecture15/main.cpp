#include <iostream>
#include <functional>
#include <cmath>
#include <utility>

class Photo {
public:
	Photo(int width, int height, const char* tag = nullptr);
	Photo(const Photo& other);
	Photo& operator=(const Photo& other);
	~Photo();

#ifdef ENABLE_MOVE_SEMANTICS
  // Move SMFs
  Photo(Photo&& other);
  Photo& operator=(Photo&& other);
#endif

private:
	int width;
	int height;
	int* data;

  std::ostream& log() const;
  const char* tag = nullptr;
};

Photo::Photo(int width, int height, const char* tag)
	: width(width)
	, height(height)
  , data(new int[width * height])
  , tag(tag)
{
  log() << "Photo(" << width << ", " << height << ")" << std::endl;
}

Photo::Photo(const Photo& other)
	: width(other.width)
	, height(other.height)
	, data(new int[width * height])
{
  log() << "Photo(const Photo&)" << std::endl;
  log() << "  ↪ copying " << width << "x" << height << " pixels..." << std::endl;
	std::copy(other.data, other.data + width * height, data);
}

Photo& Photo::operator=(const Photo& other) {
  log() << "Photo::operator=(const Photo&)" << std::endl;
	// Check for self assignment
	if (this == &other) return *this;

  log() << "  ↪ cleaning up " << width << "x" << height << " pixels..." << std::endl;
	delete[] data; // Clean up old pixels!

	// Copy over new pixels!
	width = other.width;
	height = other.height;
	data = new int[width * height];

  log() << "  ↪ copying " << width << "x" << height << " pixels..." << std::endl;
	std::copy(other.data, other.data + width * height, data);
	return *this;
}

Photo::~Photo()
{
  log() << "~Photo()" << std::endl;
	delete[] data;
}

#ifdef ENABLE_MOVE_SEMANTICS

Photo::Photo(Photo&& other)
  : width(other.width)
  , height(other.height)
  , data(other.data)
{
  log() << "Photo(Photo&&)" << std::endl;
  other.data = nullptr;
}

Photo& Photo::operator=(Photo&& other)
{
  log() << "Photo::operator=(Photo&&)" << std::endl;

  // Clean up our data before assigning into this
  delete[] data;

  width = other.width;
  height = other.height;
  data = other.data;
  other.data = nullptr;

  return *this;
}

#endif

std::ostream& Photo::log() const
{
  static std::ostream null(nullptr);
  if (!tag) return null;
  return std::cout << "[" << tag << "] \t\t";
}

template <typename Func>
void time_func(Func f, size_t invocations)
{
  // Temporarily disable logging
  std::cout.setstate(std::ios_base::failbit);

  auto start = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < invocations; ++i)
    f();
  auto end = std::chrono::high_resolution_clock::now();

  // Re-enable logging
  std::cout.clear();

  std::cout << "Average time spent per call: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / invocations << "ns" << std::endl;
}

Photo take_photo()
{
  Photo photo(500, 500, "take_photo()");
  return photo;
}

void run_example()
{
  Photo selfie(0, 0, "selfie");
  selfie = take_photo();
}

int main() {
  std::cout << "Example run:\n\n";
  run_example();
  std::cout << "\n\n";

  constexpr size_t invocations = 10000;
  std::cout << "Timing " << invocations << " attempts to move/copy a Photo..." << std::endl;
  time_func(run_example, invocations);
  return 0;
}

#include <gtest/gtest.h>

enum Color { BLACK, RED, WHITE };
const char* animals[] = { "Cat", "Dog" };

// "Cat" - BLACK / RED / WHITE
// "Dog" - BLACK / RED / WHITE

class AnimalTest : public testing::TestWithParam<std::tuple<const char*, Color>> {
};

using testing::Values;
using testing::ValuesIn;
using testing::Combine;

INSTANTIATE_TEST_SUITE_P(AnimalVariations, AnimalTest, 
	Combine(ValuesIn(animals), Values(BLACK, RED, WHITE)));

TEST_P(AnimalTest, AnimalLooks) {
	std::tuple<const char*, Color> data = GetParam();

	const char* animal = std::get<0>(data);
	Color color = std::get<1>(data);

	printf("%s(%d)\n", animal, color);
}

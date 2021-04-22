
#include <gtest/gtest.h>

enum Color { BLACK, RED, WHITE };
const char* animals[] = { "Cat", "Dog" };
int ages[] = { 10, 20, 30 };

// "Cat" - BLACK / RED / WHITE
// "Dog" - BLACK / RED / WHITE
class AnimalTest : public testing::TestWithParam<std::tuple<const char*, Color, int>> {
};

using testing::Values;
using testing::ValuesIn;
using testing::Combine;

INSTANTIATE_TEST_SUITE_P(AnimalVariations, AnimalTest, 
	Combine(ValuesIn(animals), Values(BLACK, RED, WHITE), ValuesIn(ages)));

TEST_P(AnimalTest, AnimalLooks) {
	// std::tuple<const char*, Color, int> data = GetParam();
	auto data = GetParam();

	const char* animal = std::get<0>(data);
	Color color = std::get<1>(data);
	int age = std::get<2>(data);

	printf("%s(%d) - %d\n", animal, color, age);
}

#pragma once

#include <vector>
#include <string>
#include <cstdint>

struct Metadata {
	std::string title;
	std::string artist;
	std::string genre;
	std::string mood;
	std::vector<std::string> keywords;
};

struct Stripe {
	enum Switch state {Switch::OFF};
	std::int16_t vol {100};
	std::int16_t lo_key {24};
	std::int16_t hi_key {72};
	std::int16_t trans {0};
};
struct Scene {
	std::string label;
	std::vector<Stripe> stripes;
};

struct Performance {
	Metadata metadata;
	std::vector<Scene> scenes;
	std::int16_t default_scene {0};
};

class Database {
	private:
		std::vector<Performance> performances;
};

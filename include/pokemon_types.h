#ifndef TYPES_H
#define TYPES_H

/**
 * @file pokemon_types.h
 * @brief Pokémon types values
 *
 * Define the values that represent the Pokémon types and
 * their effectiveness.
 */

typedef enum PokemonType {
	TYPE_NORMAL = 0x0,
	TYPE_FIGHT = 0x1,
	TYPE_FLY = 0x2,
	TYPE_POIS = 0x3,
	TYPE_GROUND = 0x4,
	TYPE_ROCK = 0x5,
	TYPE_BUG = 0x6,
	TYPE_GHOST = 0x7,
	TYPE_STEEL = 0x8,
	TYPE_FIRE = 0x9,
	TYPE_WATER = 0xA,
	TYPE_GRASS = 0xB,
	TYPE_ELEC = 0xC,
	TYPE_PSY = 0xD,
	TYPE_ICE = 0xE,
	TYPE_DRAGON = 0xF,
	TYPE_DARK = 0x10,
	TYPE_NULL = 0x11,
} PokemonType;

typedef enum TypeEffectiveness {
	EFFECTIVENESS_IMMUNE = 0,
	EFFECTIVENESS_1_4 = 1,
	EFFECTIVENESS_1_2 = 2,
	EFFECTIVENESS_1 = 3,
	EFFECTIVENESS_2 = 4,
	EFFECTIVENESS_4 = 5,
} TypeEffectiveness;

/**
 * @brief Pokémon type effectiveness message
 *
 * This values are used when deciding what message to show to
 * display the effectiveness of a move.
 */
#define NOT_EFFECTIVE 0
#define NOT_VERY_EFFECTIVE 2
#define EFFECTIVE 4
#define SUPER_EFFECTIVE 8

#endif // TYPES_H
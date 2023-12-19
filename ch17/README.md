# Chapter 17. Specialized Library Facilities

## [Exercise 17.1](ex17_01.cpp)

## [Exercise 17.2](ex17_02.cpp)

## [Exercise 17.3](ex17_03.h)

## [Exercise 17.4](ex17_04.cpp)

## [Exercise 17.5](ex17_05.cpp)

## [Exercise 17.6](ex17_06.cpp)

## Exercise 17.7

> Explain which version of findBook you prefer and why.

The version using tuple is prefered.It's more flexible, campared to other versions.

## Exercise 17.8

> What would happen if we passed Sales_data() as the third parameter to accumulate in the last code example in this section?

If so, the output should be 0, as the Sales_data is default constructed.

## [Exercise 17.9](ex17_09.cpp)

## [Exercise 17.10](ex17_10.cpp)

## [Exercise 17.11](ex17_11.cpp)

## Exercise 17.12:

> Why didn’t we use in-class initializers in PersonInfo?

Cause we need a aggregate class here. so it should have no in-class initializers.

## [Exercise 17.13](ex17_13.cpp)

## Exercise 17.14:

> Why did we declare entry and nums as const auto &?

- cause they are all class type, not the built-in type. so **reference** more effective.
- output shouldn't change their values. so we added the `const`.

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

## Exercise 17.9

> Explain the bit pattern each of the following bitset objects contains:

```c++
(a) bitset<64> bitvec(32);
(b) bitset<32> bv(1010101);
(c) string bstr; cin >> bstr; bitset<8> bv(bstr);
```

```c++
(a) Initialize with unsigned value: 000000 000000 000000 000000 000000 000000 000000 000000 00000 100000;
(b) Initialize with unsigned value: 000000 0111110110100110110101;
(c) Initialize with string: depends on the cin.
```

## [Exercise 17.10](ex17_10.cpp)

## [Exercise 17.11](ex17_11.cpp)

## [Exercise 17.12](ex17_12.cpp)

## [Exercise 17.13](ex17_13.cpp)

## [Exercise 17.14](ex17_14.cpp)

## [Exercise 17.15](ex17_15.cpp)

## [Exercise 17.16](ex17_16.cpp)

## [Exercise 17.17](ex17_17.cpp)

## [Exercise 17.18](ex17_18.cpp)

## Exercise 17.19:

> Why is it okay to call m[4].str() without first checking whether m[4] was matched?

We expect that the two delimiters in m[4] andm[6] are the same. If m[4](orm[6]) is mismatched, m[4].str()(orm[6].str() respectively) returns an empty string which can also be compared with the other delimiter.

## [Exercise 17.20](ex17_20.cpp)

## [Exercise 17.21](ex17_21.cpp)

## [Exercise 17.22](ex17_22.cpp)

## [Exercise 17.23](ex17_23.cpp)

## [Exercise 17.24](ex17_24.cpp)

## [Exercise 17.25](ex17_25.cpp)

## [Exercise 17.26](ex17_26.cpp)

## [Exercise 17.27](ex17_27.cpp)

## [Exercise 17.28](ex17_28.cpp)

## [Exercise 17.29](ex17_28.cpp)

## [Exercise 17.30](ex17_28.cpp)

## Exercise 17.31:

> What would happen if we defined b and e inside the do loop of the game-playing program from this section?

The random number is the same every time.

## Exercise 17.32:

> What would happen if we defined resp inside the loop?

Error will be reported, no resp defined, notice Scope of Action

## [Exercise 17.33](ex17_33.cpp)

## [Exercise 17.34](ex17_34.cpp)

## [Exercise 17.35](ex17_35.cpp)

## [Exercise 17.36](ex17_36.cpp)

## [Exercise 17.37](ex17_37.cpp)

## [Exercise 17.38](ex17_38.cpp)

## [Exercise 17.39](ex17_39.cpp)

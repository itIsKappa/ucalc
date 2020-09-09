
# Log of updates staring from:
## Version 2.95, May 21 2020, Minor:
### Added base converter:
  * Ternary Converter
  * Reverse Ternary Converter

## Version 3.0, May 21 2020, Minor:
### Added more constants:
  * Faraday Constant
  * Avogadro's Number
  * Speed of Light in Vacuum
  * Boltzmann Constant

## Version 3.0, May 25 2020, Minor:
### Fixed path-to-log bug in deb package
  * Fixed the bug that causes ucalcLog.txt
    to be made on the current working directory

## Version 4.0, May 26 2020, Major:
### Added interactive mode
  * Added interactive mode for continuous use
### Fixed asterisk bug
  * Fixed the bug that makes UCalc not
    consider an asterisk as multiplication
### Created Debian package
  * Created Debian package for version 4.0

## Version 4.1, May 30 2020, Minor:
### Added support for Windows
  * Can run on Windows from the ucalc source file
  * Also can be run by using python3
  * From 4.3 in the future, requires GNU GCC
### Added interactive mode help
  * Added help for interactive mode in
    the global help 

## Version 4.102, June 2 2020, Minor:
### Fixed factorial error
  * Fixed error when calling factorial by exclamation
    interactive mode
  * Created Debian package for Version 4.102

## Version 4.2, June 29 2020, Minor:
### Fixed hexadecimal bug
  * Fixed error when calling hexadecimal converters in
    interactive mode
### Instant log writer
  * Added instant log writing after each question
    in interactive mode

## Version 4.3, July 11 2020, Major:
### Integration of Factoriser
  * Finding factors of a number feature has been
    added through the integration of Factoriser
    into UCalc
### Factorial Symbol Problem
  * Factorial symbols are now entered after the
    number, the error has been fixed

## Version 4.4, July 17 2020, Major:
### Integration of XY
  * Find product-sum factor feature has been
    added through integration XY into UCalc

## Version 4.5.9, September 9 2020, Major
### Added Prime Finder
  * Fetching prime numbers upto the specified value
    with the addition of prime finder
### Better Brackets
  * Deep nesting of brackets
  * One more type of bracket -- "()" among with, "[]" & "{}"
  * Deep nesting with same type or different
### Negation
  * Added ad hoc feature to negate answers for functions that do not
    take negative values
  * Fixed a much critical calculation fault -- Not checking
    if a value is preceded by a substraction sign and considering
    it negative. (This is excluding the ~ negation)
### Last Reply Variable
 * A variable for quickly accessing the reply's value
 * Later, file creation for the variable was fixed
### Formatted Square Roots
 * Added a function to find formatted square root rather than
   absolute square root
 * Later, a better function implemented
### Better Logging
 * A better and faster method to log implemented
### Easy Access Constants
 * An option added which allow for displaying simple and clean
   version of '--constants' options, with only the constants and
   not its <em>about</em>
   


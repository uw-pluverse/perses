package org.perses.util

data class Fraction(val numerator: Int, val denominator: Int) {
  init {
    assert(
        numerator >= 0,
        { "The numerator should be within [0,100]. ${numerator}" })
    assert(denominator > 0,
        { "The denominator should be positive ${denominator}" })
    assert(numerator <= denominator,
        { "The numerator cannot be greater than denominator: ${numerator}/${denominator}" })
  }

  fun multiply(value: Int) = value * numerator / denominator

  companion object {
    @JvmStatic
    fun parse(string: String): Fraction {
      val separatorIndex = string.indexOf('/')
      if (separatorIndex < 0) {
        return Fraction(numerator = Integer.parseInt(string.trim()), denominator = 1)
      }
      val numerator = Integer.parseInt(string.substring(0, separatorIndex).trim())
      val denominator = Integer.parseInt(string.substring(separatorIndex + 1).trim())
      return Fraction(numerator, denominator)
    }
  }
}

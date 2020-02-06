package org.perses.util

data class Percentage(val numerator: Int) {
  init {
    assert(
        numerator >= 0 && numerator <= 100,
        { "The numerator should be within [0,100]. ${numerator}" })
  }

  fun multiply(value: Int) = value * numerator / 100
}

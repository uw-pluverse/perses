package org.perses.util;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public class PercentageTest {

  @Test
  public void test_one() {
    Fraction p = new Fraction(1, 100);
    Truth.assertThat(p.getNumerator()).isEqualTo(1);
    Truth.assertThat(p.multiply(1000)).isEqualTo(10);
  }

  @Test
  public void test_zero() {
    Fraction p = new Fraction(0, 100);
    Truth.assertThat(p.getNumerator()).isEqualTo(0);
    Truth.assertThat(p.multiply(100)).isEqualTo(0);
  }

  @Test
  public void test_100() {
    Fraction p = new Fraction(100, 100);
    Truth.assertThat(p.getNumerator()).isEqualTo(100);
    Truth.assertThat(p.multiply(100)).isEqualTo(100);
  }

  @Test
  public void test_parsePercentage() {
    Fraction p = Fraction.parse("1 / 100");
    Truth.assertThat(p.getNumerator()).isEqualTo(1);
    Truth.assertThat(p.getDenominator()).isEqualTo(100);
  }
}

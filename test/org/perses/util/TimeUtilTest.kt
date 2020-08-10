package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.time.ZoneId

@RunWith(JUnit4::class)
class TimeUtilTest {

  @Test
  fun testFormatDateForFileName() {
    val epochMillis = 1569287074745L
    // BAZEL uses UTC as the system timezone.
    assertThat(TimeUtil.formatDateForFileName(epochMillis))
      .isEqualTo("20190924_010434")
  }

  @Test
  fun testFormatDateForDisplay() {
    val epochMillis = 1569287074745L
    // BAZEL uses UTC as the system timezone.
    assertThat(TimeUtil.formatDateForDisplay(epochMillis))
      .isEqualTo("01:04:34 2019/09/24")
  }

  @Test
  fun testConvertToLocalDateTime() {
    val epochMillis = 1569287074745L
    val time = TimeUtil.converToLocalDateTime(
      epochMillis,
      ZoneId.of("America/Indiana/Indianapolis")
    )
    assertThat(time.toString()).isEqualTo("2019-09-23T21:04:34.745")
  }

  @Test
  fun test_toMillisFromSeconds() {
    assertThat(TimeUtil.toMillisFromSeconds(2)).isEqualTo(2000)
  }

  @Test
  fun test_toMillisFromMinutes() {
    assertThat(TimeUtil.toMillisFromMinutes(2)).isEqualTo(120000)
  }
}

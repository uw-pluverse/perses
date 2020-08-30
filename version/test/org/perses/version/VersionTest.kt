package org.perses.version

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class VersionTest {

  @Test
  fun test() {
    Truth.assertThat(Version.MAJOR_VERSION).isNotEmpty()
    Integer.parseInt(Version.MAJOR_VERSION)

    Truth.assertThat(Version.MINOR_VERSION).isNotEmpty()
    Integer.parseInt(Version.MINOR_VERSION)
  }
}

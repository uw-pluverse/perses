/*
 * Copyright (C) 2018-2020 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.util;

import com.google.common.io.Files;
import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;
import com.google.common.truth.Truth;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.ArrayList;
import java.util.LinkedList;

/** Test for {@link Util} */
@RunWith(JUnit4.class)
public class UtilTest {

  @Test
  public void testRemoveNullFromList() {
    {
      ArrayList<Integer> list = new ArrayList<>();
      Util.removeNullFromList(list);
      Assert.assertEquals(0, list.size());

      list.add(1);
      Util.removeNullFromList(list);
      Assert.assertEquals(1, list.size());

      list.add(null);
      Util.removeNullFromList(list);
      Assert.assertEquals(1, list.size());

      list.add(null);
      Util.removeNullFromList(list);
      Assert.assertEquals(1, list.size());

      list.set(0, null);
      Util.removeNullFromList(list);
      Assert.assertEquals(0, list.size());
    }
    {
      ArrayList<Integer> list = new ArrayList<>();
      list.add(1);
      list.add(2);
      list.add(3);
      list.add(4);

      Util.removeNullFromList(list);
      Assert.assertEquals(4, list.size());

      list.set(1, null);
      Util.removeNullFromList(list);
      Assert.assertEquals(3, list.size());
    }
  }

  @Test
  public void testRemoveElementBySwappingLastElement() {
    ArrayList<Integer> list = new ArrayList<>();
    {
      list.clear();
      list.add(1);
      Util.removeElementBySwappingLastElement(list, 0);
      Assert.assertEquals(0, list.size());
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      Util.removeElementBySwappingLastElement(list, 0);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(2, list.get(0).intValue());
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      Util.removeElementBySwappingLastElement(list, 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(1, list.get(0).intValue());
    }
  }

  @Test
  public void testRemoveElementsFromLinkedList() {
    LinkedList<Integer> list = new LinkedList<>();
    {
      list.clear();
      list.add(1);
      Util.removeElementsFromLinkedList(list, i -> i == 1);
      Assert.assertEquals(0, list.size());
    }

    {
      list.clear();
      list.add(1);
      list.add(2);
      Util.removeElementsFromLinkedList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      Util.removeElementsFromLinkedList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      list.add(1);
      list.add(1);
      Util.removeElementsFromLinkedList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }

    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      list.add(1);
      list.add(1);
      Util.removeElementsFromLinkedList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      Util.removeElementsFromLinkedList(list, i -> i == 1);
      Assert.assertEquals(2, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
      Assert.assertEquals(list.get(1).intValue(), 2);
    }
  }

  @Test
  public void testRemoveElementsFromList() {
    ArrayList<Integer> list = new ArrayList<>();
    {
      list.clear();
      list.add(1);
      Util.removeElementsFromList(list, i -> i == 1);
      Assert.assertEquals(0, list.size());
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      Util.removeElementsFromList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      Util.removeElementsFromList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }
    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      list.add(1);
      list.add(1);
      Util.removeElementsFromList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }

    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      list.add(1);
      list.add(1);
      Util.removeElementsFromList(list, i -> i == 1);
      Assert.assertEquals(1, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
    }

    {
      list.clear();
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      list.add(2);
      list.add(1);
      list.add(1);
      Util.removeElementsFromList(list, i -> i == 1);
      Assert.assertEquals(2, list.size());
      Assert.assertEquals(list.get(0).intValue(), 2);
      Assert.assertEquals(list.get(1).intValue(), 2);
    }
  }

  @Test
  public void testComputePercentage() {
    Truth.assertThat(Util.computePercentage(100, 100)).isEqualTo("100.00%");
    Truth.assertThat(Util.computePercentage(50, 100)).isEqualTo("50.00%");
    Truth.assertThat(Util.computePercentage(2525, 10000)).isEqualTo("25.25%");
  }

  @Test
  public void testFormatDateForFileName() {
    long epochMillis = 1569287074745l;
    // BAZEL uses UTC as the system timezone.
    Truth.assertThat(Util.formatDateForFileName(epochMillis)).isEqualTo("20190924_010434");
  }

  @Test
  public void testFormatDateForDisplay() {
    long epochMillis = 1569287074745l;
    // BAZEL uses UTC as the system timezone.
    Truth.assertThat(Util.formatDateForDisplay(epochMillis)).isEqualTo("01:04:34 2019/09/24");
  }

  @Test
  public void testConvertToLocalDateTime() {
    long epochMillis = 1569287074745l;
    LocalDateTime time =
        Util.converToLocalDateTime(epochMillis, ZoneId.of("America/Indiana/Indianapolis"));
    Truth.assertThat(time.toString()).isEqualTo("2019-09-23T21:04:34.745");
  }

  private File tempDir;

  @Before
  public void setup() {
    tempDir = Files.createTempDir();
  }

  @After
  public void teardown() throws IOException {
    MoreFiles.deleteRecursively(tempDir.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
  }
  @Test
  public void testIsEmptyDirectory() throws IOException {
    Truth.assertThat(Util.isEmptyDirectory(tempDir.toPath())).isTrue();
    Files.touch(new File(tempDir, "temp.txt"));
    Truth.assertThat(Util.isEmptyDirectory(tempDir.toPath())).isFalse();
  }
}

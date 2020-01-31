/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;

import java.io.IOException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Objects;
import java.util.function.Predicate;

public final class Util {

  private static final DateTimeFormatter DATE_FORMAT_FOR_DISPLAY =
      DateTimeFormatter.ofPattern("HH:mm:ss yyyy/MM/dd");
  private static final DateTimeFormatter DATE_FORMAT_FOR_FILE_NAME =
      DateTimeFormatter.ofPattern("yyyyMMdd_HHmmss");

  public static String computePercentage(int numerator, int denominator) {
    return String.format("%.2f%%", numerator * 100.0 / denominator);
  }

  public static String formatDateForFileName(final LocalDateTime datetime) {
    return DATE_FORMAT_FOR_FILE_NAME.format(datetime);
  }

  public static String formatDateForFileName(final long epochMillis) {
    return formatDateForFileName(converToLocalDateTime(epochMillis, ZoneId.systemDefault()));
  }

  @VisibleForTesting
  static LocalDateTime converToLocalDateTime(final long epochMillis, ZoneId zone) {
    Instant instant = Instant.ofEpochMilli(epochMillis);
    LocalDateTime datetime = instant.atZone(zone).toLocalDateTime();
    return datetime;
  }

  public static String formatDateForDisplay(final long epochMillis) {
    return formatDateForDisplay(converToLocalDateTime(epochMillis, ZoneId.systemDefault()));
  }

  public static String formatDateForDisplay(final LocalDateTime datetime) {
    return DATE_FORMAT_FOR_DISPLAY.format(datetime);
  }

  public static <T> void removeElementsFromLinkedList(
      LinkedList<T> list, Predicate<T> removalCondition) {
    if (list == null || list.isEmpty()) {
      return;
    }
    for (Iterator<T> iterator = list.iterator(); iterator.hasNext(); ) {
      final T t = iterator.next();
      if (removalCondition.test(t)) {
        iterator.remove();
      }
    }
  }

  public static <T> void swap(ArrayList<T> list, int i, int j) {
    final T temp = list.get(i);
    list.set(i, list.get(j));
    list.set(j, temp);
  }

  public static <T> void removeElementBySwappingLastElement(ArrayList<T> list, int index) {
    Preconditions.checkArgument(list.size() > 0);
    final int last = list.size() - 1;
    if (index != last) {
      swap(list, index, last);
    }
    list.remove(last);
  }

  public static <T> void removeElementsFromList(ArrayList<T> list, Predicate<T> removalCondition) {
    if (list == null || list.isEmpty()) {
      return;
    }
    int start = 0;
    final int size = list.size();
    for (int i = 0; i < size; ++i) {
      final T element = list.get(i);
      if (removalCondition.test(element)) {
        continue;
      }
      if (start != i) list.set(start, element);
      ++start;
    }

    for (int i = size - 1; i >= start; --i) {
      list.remove(i);
    }
  }

  public static <T> void removeNullFromList(ArrayList<T> list) {
    removeElementsFromList(list, Objects::isNull);
  }

  public static boolean isEmptyDirectory(Path path) throws IOException {
    try (DirectoryStream<Path> stream = Files.newDirectoryStream(path)) {
      return !stream.iterator().hasNext();
    }
  }
}

/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.grammar.rust;

import static com.google.common.base.Preconditions.checkState;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import org.perses.TestUtility;

public class RustParserFailListGenerator {

  public static void main(String[] args) throws IOException, InterruptedException {
    ExecutorService executorService = Executors.newFixedThreadPool(40);
    final ConcurrentLinkedQueue<String> failList = new ConcurrentLinkedQueue<>();
    try {
      final PnfRustParserFacade facade = new PnfRustParserFacade();
      for (Path f : TestUtility.getRustTestFiles()) {
        executorService.submit(
            () -> {
              try {
                facade.parseWithOrigRustParser(f);
              } catch (Throwable e) {
                failList.add(f.toString());
              }
            });
      }
    } finally {
      executorService.shutdown();
      checkState(executorService.awaitTermination(60, TimeUnit.MINUTES), "Time out!!!");
    }
    ArrayList<String> result = new ArrayList<>(failList);
    Collections.sort(result);
    try (BufferedWriter writer =
        Files.newBufferedWriter(Paths.get(args[0]), StandardCharsets.UTF_8)) {
      for (String file : result) {
        writer.append(file).append('\n');
      }
    }
  }
}

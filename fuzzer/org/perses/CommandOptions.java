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

package org.perses.fuzzer;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;

/** Parser for command line arguments. */
public class CommandOptions {

  public final RandomMutationFlag randomMutationFlag = new RandomMutationFlag();

  @Parameter(
      names = "--help",
      description = "print help message",
      help = true,
      order = FlagOrder.HELP)
  public boolean help;

  public CommandOptions() {}

  public JCommander createJCommander(Class<?> mainClass) {
    final JCommander commander =
        JCommander.newBuilder()
            .programName(mainClass.getCanonicalName())
            .addObject(this)
            .addObject(randomMutationFlag)
            .build();
    return commander;
  }

  public void validate() {
    randomMutationFlag.validate();
  }

  public static final class RandomMutationFlag {
    @Parameter(
        names = "--random-seed",
        description = "random seed for nondeterministic functions",
        order = FlagOrder.PROFILING_CONTROL)
    public long randomSeed = System.currentTimeMillis();

    @Parameter(names = "--seed-file", description = "", order = FlagOrder.PROFILING_CONTROL + 1)
    public String seedFile;

    public void validate() {}
  }

  private static class FlagOrder {
    public static final int HELP = 4000;
    public static final int PROFILING_CONTROL = 10000;
  }
}

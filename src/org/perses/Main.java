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

package org.perses;

import static com.google.common.base.Preconditions.checkArgument;

import com.google.common.collect.ImmutableList;
import org.perses.grammar.AbstractParserFacadeFactory;
import org.perses.grammar.SingleParserFacadeFactory;
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil;
import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.c.LanguageC;
import org.perses.grammar.c.PnfCParserFacade;
import org.perses.reduction.IReductionDriver;
import org.perses.reduction.ReducerFactory;
import org.perses.reduction.RegularProgramReductionDriver;

public class Main extends AbstractMain<CommandOptions> {

  public Main(String[] args) {
    super(args);
  }

  protected CommandOptions createCommandOptions() {
    return new CommandOptions(ReducerFactory.getDefaultReductionAlgName());
  }

  @Override
  protected SingleParserFacadeFactory.ParserFacadeFactoryCustomizer createCustomizer() {
    return (language, defaultParserFacadeCreator) -> {
      if (language == LanguageC.INSTANCE) {
        return cmd.getAlgorithmControlFlags().useOptCParser
            ? CParserFacade::new
            : PnfCParserFacade::new;
      } else {
        return defaultParserFacadeCreator;
      }
    };
  }

  @Override
  protected AbstractParserFacadeFactory createExtFacadeFactory() {
    // Cannot close this file, as the file has class loader to load the parser facade classes.
    return AdhocParserFacadeFactoryUtil.INSTANCE.createParserFacadeFactory(
        cmd.getLanguageExtFlags().languageJarFiles);
  }

  @Override
  protected void validateCommandOptions() {
    super.validateCommandOptions();
    checkArgument(
        ReducerFactory.isValidReducerName(
            cmd.getAlgorithmControlFlags().getReductionAlgorithmName()),
        "Invalid reduction algorithm %s",
        cmd.getAlgorithmControlFlags().getReductionAlgorithmName());
  }

  @Override
  protected HelpRequestProcessingDecision processHelpRequests() {
    if (cmd.getAlgorithmControlFlags().listAllReductionAlgorithms) {
      System.out.println("All available reduction algorithms: ");
      System.out.println(ReducerFactory.printAllReductionAlgorithms());
      return HelpRequestProcessingDecision.EXIT;
    }
    return HelpRequestProcessingDecision.NO_EXIT;
  }

  @Override
  protected IReductionDriver createReductionDriver(AbstractParserFacadeFactory facadeFactory) {
    return RegularProgramReductionDriver.Companion.create(cmd, facadeFactory, ImmutableList.of());
  }

  public static void main(String[] args) {
    new Main(args).run();
  }
}

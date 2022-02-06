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

import com.beust.jcommander.Parameter;
import com.beust.jcommander.converters.PathConverter;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import org.antlr.v4.runtime.Token;
import org.perses.cmd.LanguageExtFlags;
import org.perses.grammar.AbstractParserFacade;
import org.perses.grammar.AbstractParserFacadeFactory;
import org.perses.grammar.CompositeParserFacadeFactory;
import org.perses.grammar.SingleParserFacadeFactory;
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil;
import org.perses.program.LanguageKind;
import org.perses.program.SourceFile;
import org.perses.util.cmd.AbstractCommandOptions;
import org.perses.util.cmd.ICommandLineFlags;

public class TokenCounterMain
    extends org.perses.util.cmd.AbstractMain<TokenCounterMain.CommandOptions> {

  public TokenCounterMain(String[] args) {
    super(args);
  }

  @Override
  protected CommandOptions createCommandOptions() {
    return new CommandOptions();
  }

  private CompositeParserFacadeFactory createParserFacadeFactory() {
    final SingleParserFacadeFactory builtin =
        SingleParserFacadeFactory.builderWithBuiltinLanguages(
                SingleParserFacadeFactory.IDENTITY_CUSTOMIZER)
            .build();
    final AbstractParserFacadeFactory ext =
        AdhocParserFacadeFactoryUtil.INSTANCE.createParserFacadeFactory(
            cmd.extFlags.languageJarFiles);
    return new CompositeParserFacadeFactory(builtin, ext);
  }

  @Override
  protected void internalRun() {
    final Path file = cmd.flags.file;
    final AbstractParserFacadeFactory parserFacadeFactory = createParserFacadeFactory();
    final LanguageKind language = parserFacadeFactory.computeLanguageKindWithFileName(file);
    final SourceFile sourceFile = new SourceFile(file, language);
    final AbstractParserFacade parserFacade =
        parserFacadeFactory.createParserFacade(sourceFile.getLanguageKind());
    final ImmutableList<Token> tokens = parserFacade.parseIntoTokens(sourceFile.getFile());
    int count = 0;
    for (Token token : tokens) {
      if (token.getChannel() == Token.DEFAULT_CHANNEL) {
        ++count;
      }
    }
    System.out.println();
    System.out.printf("The number of tokens in file '%s' is:\n", file);
    System.out.println(count);
  }

  public class CommandOptions extends AbstractCommandOptions {

    private final RequiredFlags flags = registerFlags(new RequiredFlags());
    private final LanguageExtFlags extFlags = registerFlags(new LanguageExtFlags());

    class RequiredFlags implements ICommandLineFlags {
      @Parameter(description = "source file", required = true, converter = PathConverter.class)
      private Path file = null;

      @Override
      public void validate() {
        Preconditions.checkNotNull(file);
        Preconditions.checkState(Files.isRegularFile(file));
      }
    }
  }

  public static void main(String[] args) throws IOException {
    new TokenCounterMain(args).run();
  }
}

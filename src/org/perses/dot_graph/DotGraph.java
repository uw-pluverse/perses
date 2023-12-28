/*
 * Copyright (C) 2018-2024 University of Waterloo.
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

package org.perses.dot_graph;

import com.google.common.base.Charsets;
import com.google.common.io.Files;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import org.apache.commons.lang3.StringEscapeUtils;
import org.perses.util.shell.CmdOutput;
import org.perses.util.shell.Shells;

public class DotGraph<T> {

  private static int NODE_SEQUENCE = 0;

  private final LinkedHashSet<Edge<T>> edges;

  public DotGraph() {
    this.edges = new LinkedHashSet<>();
  }

  public void addEdge(T source, T target) {
    this.edges.add(new Edge<T>(source, target));
  }

  public void dotify(File file, NodeLabelProvider<T> labelProvider) throws IOException {
    final String dot = this.dotifyToString(labelProvider);
    File dotFile = new File(file.getParentFile(), file.getName() + ".dot");
    Files.write(dot, dotFile, Charsets.UTF_8);
    CmdOutput output =
        Shells.getSingleton()
            .run(
                "dot -Tpdf " + dotFile.getAbsolutePath() + " -o " + file.getAbsolutePath(),
                true,
                Shells.CURRENT_ENV);
    System.out.println(output.getStderr());
  }

  public String dotifyToString(NodeLabelProvider<T> labelProvider) {
    final StringBuilder builder = new StringBuilder();
    builder.append("digraph G {").append('\n');

    final LinkedHashSet<T> nodes = new LinkedHashSet<T>();
    this.edges.forEach(
        e -> {
          nodes.add(e.source);
          nodes.add(e.target);
        });
    nodes.forEach(
        n -> {
          builder
              .append(labelProvider.getID(n))
              .append(" [label=")
              .append("\"")
              .append(StringEscapeUtils.escapeJava(labelProvider.getLabel(n)))
              .append("\"")
              .append("];" + "")
              .append("\n");
        });

    this.edges.forEach(
        e -> {
          builder
              .append(labelProvider.getID(e.source))
              .append(" -> ")
              .append(labelProvider.getID(e.target))
              .append("\n");
        });

    builder.append('}').append('\n');
    return builder.toString();
  }

  public abstract static class NodeLabelProvider<T> {

    private static int NODE_ID_SEQ = 0;

    private final Map<T, String> ids;

    private final Map<T, String> labels;

    public NodeLabelProvider() {
      this.labels = new HashMap<>();
      this.ids = new HashMap<T, String>();
    }

    public String getID(T node) {
      String id = this.ids.get(node);
      if (id == null) {
        id = "n" + (NODE_ID_SEQ++);
        this.ids.put(node, id);
      }
      return id;
    }

    public String getLabel(T node) {
      String label = this.labels.get(node);
      if (label == null) {
        label = computeNodeLabel(node);
        this.labels.put(node, label);
      }
      return label;
    }

    protected abstract String computeNodeLabel(T node);
  }

  private static class Edge<T> {

    private final T source;

    private final T target;

    public Edge(T source, T target) {
      this.source = source;
      this.target = target;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;

      Edge<?> edge = (Edge<?>) o;

      if (source != null ? !source.equals(edge.source) : edge.source != null) return false;
      return target != null ? target.equals(edge.target) : edge.target == null;
    }

    @Override
    public int hashCode() {
      int result = source != null ? source.hashCode() : 0;
      result = 31 * result + (target != null ? target.hashCode() : 0);
      return result;
    }
  }
}
